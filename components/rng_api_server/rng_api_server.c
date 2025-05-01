#include <string.h>
#include <ctype.h>
#include "esp_http_server.h"
#include "esp_random.h"
#include "esp_log.h"
#include "cJSON.h"
#include "driver/gpio.h"

#include "rng_api_server.h"
#include "csprng.h"

#define LED_GPIO CONFIG_LED_GPIO

static const char *SERVER_TAG = "esp32-hrng";

static esp_err_t handle_text_frame(httpd_req_t *req, httpd_ws_frame_t *ws_pkt, uint8_t *buf, size_t buffer_size);
static int parse_requested_length(const char *str);
typedef void (*random_fill_func)(void *dest, size_t len);
static esp_err_t generate_and_send_random_bytes(httpd_req_t *req, int len, random_fill_func fill_func);
static esp_err_t handle_close_frame(httpd_req_t *req);
static esp_err_t handle_ping_frame(httpd_req_t *req);

void heartbeat_led_init(void)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << LED_GPIO,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE};
    gpio_config(&io_conf);

    gpio_set_level(LED_GPIO, 0);
}

void heartbeat_blink_task(void *pvParameters)
{
    gpio_set_level(LED_GPIO, 1);
    vTaskDelay(pdMS_TO_TICKS(100));
    gpio_set_level(LED_GPIO, 0);
    vTaskDelete(NULL);
}

/*
 * Structure holding server handle
 * and internal socket fd in order
 * to use out of request send
 */
struct async_resp_arg
{
    httpd_handle_t hd;
    int fd;
};

/*
 * async send function, which we put into the httpd work queue
 */
static void ws_async_send(void *arg)
{
    static const char *data = "Async data";
    struct async_resp_arg *resp_arg = arg;
    httpd_handle_t hd = resp_arg->hd;
    int fd = resp_arg->fd;
    httpd_ws_frame_t ws_pkt;
    memset(&ws_pkt, 0, sizeof(httpd_ws_frame_t));
    ws_pkt.payload = (uint8_t *)data;
    ws_pkt.len = strlen(data);
    ws_pkt.type = HTTPD_WS_TYPE_TEXT;

    httpd_ws_send_frame_async(hd, fd, &ws_pkt);
    free(resp_arg);
}

static esp_err_t trigger_async_send(httpd_handle_t handle, httpd_req_t *req)
{
    struct async_resp_arg *resp_arg = malloc(sizeof(struct async_resp_arg));
    if (resp_arg == NULL)
    {
        return ESP_ERR_NO_MEM;
    }
    resp_arg->hd = req->handle;
    resp_arg->fd = httpd_req_to_sockfd(req);
    esp_err_t ret = httpd_queue_work(handle, ws_async_send, resp_arg);
    if (ret != ESP_OK)
    {
        free(resp_arg);
    }
    return ret;
}

uint32_t csprng_random(void)
{
    uint8_t buf[4];
    if (csprng_get_bytes(buf, sizeof(buf)) != 0)
    {
        return -1;
    }
    // Combine bytes into a 32-bit unsigned integer (big-endian)
    return ((uint32_t)buf[0] << 24) |
           ((uint32_t)buf[1] << 16) |
           ((uint32_t)buf[2] << 8) |
           ((uint32_t)buf[3]);
}

static void esp_random_wrapper(void *dest, size_t len)
{
    esp_fill_random(dest, len);
}

static void csprng_wrapper(void *dest, size_t len)
{
    csprng_get_bytes(dest, len);
}

static esp_err_t random_ws_handler(httpd_req_t *req, random_fill_func fill_func)
{
    esp_err_t ret = ESP_OK;

    if (req == NULL)
    {
        ESP_LOGE(SERVER_TAG, "Invalid request handle");
        return ESP_ERR_INVALID_ARG;
    }

    if (req->method == HTTP_GET)
    {
        ESP_LOGI(SERVER_TAG, "WebSocket handshake completed, connection established");
        return ESP_OK;
    }

    const size_t buffer_size = 1024;
    uint8_t *buf = heap_caps_calloc(1, buffer_size + 1, MALLOC_CAP_8BIT);
    if (buf == NULL)
    {
        ESP_LOGE(SERVER_TAG, "Failed to allocate receive buffer");
        return ESP_ERR_NO_MEM;
    }

    httpd_ws_frame_t ws_pkt;
    memset(&ws_pkt, 0, sizeof(httpd_ws_frame_t));
    ws_pkt.type = HTTPD_WS_TYPE_TEXT;
    ws_pkt.payload = buf;

    ret = httpd_ws_recv_frame(req, &ws_pkt, 0);
    if (ret != ESP_OK)
    {
        ESP_LOGE(SERVER_TAG, "Failed to get frame length: %s", esp_err_to_name(ret));
        free(buf);
        return ESP_OK;
    }

    ESP_LOGI(SERVER_TAG, "Received frame: type=%d, len=%d", ws_pkt.type, ws_pkt.len);

    switch (ws_pkt.type)
    {
    case HTTPD_WS_TYPE_TEXT:
        ret = handle_text_frame(req, &ws_pkt, buf, buffer_size);
        break;

    case HTTPD_WS_TYPE_BINARY:
        ESP_LOGW(SERVER_TAG, "Binary frames not implemented");
        break;

    case HTTPD_WS_TYPE_CLOSE:
        ret = handle_close_frame(req);
        break;

    case HTTPD_WS_TYPE_PING:
        ret = handle_ping_frame(req);
        break;

    default:
        ESP_LOGW(SERVER_TAG, "Ignoring unsupported frame type: %d", ws_pkt.type);
        break;
    }

    free(buf);

#if CONFIG_DEBUG >= 3
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGI("RNG_API", "Free heap: %lu bytes, Min free: %lu bytes",
             (unsigned long)free_heap, (unsigned long)min_free_heap);
#endif

    return ESP_OK;
}

static esp_err_t esp_fill_random_ws_handler(httpd_req_t *req)
{
    return random_ws_handler(req, esp_random_wrapper);
}

static esp_err_t csprng_fill_random_ws_handler(httpd_req_t *req)
{
    return random_ws_handler(req, csprng_wrapper);
}

static esp_err_t hrng_get_handler(httpd_req_t *req)
{
    xTaskCreate(heartbeat_blink_task, "heartbeat_blink_task", 1024, NULL, 5, NULL);

    uint32_t random_number = esp_random();

    cJSON *json = cJSON_CreateObject();
    if (json == NULL)
    {
        return httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Failed to create JSON object");
    }

    cJSON_AddNumberToObject(json, "random", random_number);
    const char *json_str = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (json_str == NULL)
    {
        return httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Failed to print JSON");
    }

    httpd_resp_set_type(req, "application/json");
    esp_err_t ret = httpd_resp_send(req, json_str, strlen(json_str));
    free((void *)json_str);
    return ret;
}

static esp_err_t csprng_get_handler(httpd_req_t *req)
{
    xTaskCreate(heartbeat_blink_task, "heartbeat_blink_task", 1024, NULL, 5, NULL);

    uint32_t random_number = csprng_random();

    cJSON *json = cJSON_CreateObject();
    if (json == NULL)
    {
        return httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Failed to create JSON object");
    }

    cJSON_AddNumberToObject(json, "random", random_number);
    const char *json_str = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);

    if (json_str == NULL)
    {
        return httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Failed to print JSON");
    }

    httpd_resp_set_type(req, "application/json");
    esp_err_t ret = httpd_resp_send(req, json_str, strlen(json_str));
    free((void *)json_str);
    return ret;
}

static esp_err_t handle_text_frame(httpd_req_t *req, httpd_ws_frame_t *ws_pkt, uint8_t *buf, size_t buffer_size)
{
    esp_err_t ret;

    if (ws_pkt->len == 0)
    {
        ESP_LOGW(SERVER_TAG, "Empty text frame received");
        return ESP_OK;
    }

    if (ws_pkt->len > buffer_size)
    {
        ESP_LOGE(SERVER_TAG, "Frame too large (%d bytes), max supported is %d bytes",
                 ws_pkt->len, buffer_size);
        return ESP_ERR_INVALID_SIZE;
    }

    ret = httpd_ws_recv_frame(req, ws_pkt, ws_pkt->len);
    if (ret != ESP_OK)
    {
        ESP_LOGE(SERVER_TAG, "Failed to receive text payload: %s", esp_err_to_name(ret));
        return ret;
    }

    buf[ws_pkt->len] = 0;

#if CONFIG_DEBUG >= 3
    ESP_LOGI(SERVER_TAG, "Raw bytes received (%d bytes):", ws_pkt->len);
    for (int i = 0; i < ws_pkt->len && i < 32; i++)
    {
        printf("%02X ", buf[i]);
    }
    printf("\n");
#endif

    ESP_LOGI(SERVER_TAG, "Received text message: %s", buf);

    int requested_len = parse_requested_length((char *)buf);
    ESP_LOGI(SERVER_TAG, "Requested random bytes: %d", requested_len);

    return generate_and_send_random_bytes(req, requested_len, esp_random_wrapper);
}

static int parse_requested_length(const char *str)
{
    const int DEFAULT_LEN = 4;
    const int MIN_LEN = 1;
    const int MAX_LEN = 65536;

    if (str == NULL)
    {
        return DEFAULT_LEN;
    }

    while (*str && !isdigit((unsigned char)*str))
    {
        str++;
    }

    if (*str == '\0')
    {
        return DEFAULT_LEN;
    }

    long value = strtol(str, NULL, 10);
    if (value < MIN_LEN || value > MAX_LEN)
    {
        ESP_LOGW(SERVER_TAG, "Requested length %ld out of range [%d-%d], using default",
                 value, MIN_LEN, MAX_LEN);
        return DEFAULT_LEN;
    }

    return (int)value;
}

static esp_err_t generate_and_send_random_bytes(httpd_req_t *req, int len, random_fill_func fill_func)
{
    esp_err_t ret;

    uint8_t *random_bytes = heap_caps_malloc(len, MALLOC_CAP_8BIT);
    if (random_bytes == NULL)
    {
        ESP_LOGE(SERVER_TAG, "Failed to allocate random bytes buffer");
        return ESP_ERR_NO_MEM;
    }

    fill_func(random_bytes, len);
    ret = ESP_OK;

    httpd_ws_frame_t resp = {
        .final = true,
        .fragmented = false,
        .type = HTTPD_WS_TYPE_BINARY,
        .payload = random_bytes,
        .len = len};

    ESP_LOGI(SERVER_TAG, "Sending %d random bytes...", len);
    ret = httpd_ws_send_frame(req, &resp);

    free(random_bytes);

    if (ret != ESP_OK)
    {
        ESP_LOGE(SERVER_TAG, "Failed to send random bytes: %s", esp_err_to_name(ret));
        return ret;
    }

    ESP_LOGI(SERVER_TAG, "Successfully sent random bytes");
    return ESP_OK;
}

static esp_err_t handle_close_frame(httpd_req_t *req)
{
    ESP_LOGI(SERVER_TAG, "Received close frame");

    httpd_ws_frame_t resp = {
        .final = true,
        .fragmented = false,
        .type = HTTPD_WS_TYPE_CLOSE,
        .payload = NULL,
        .len = 0};

    return httpd_ws_send_frame(req, &resp);
}

static esp_err_t handle_ping_frame(httpd_req_t *req)
{
    ESP_LOGI(SERVER_TAG, "Received ping frame");

    httpd_ws_frame_t resp = {
        .final = true,
        .fragmented = false,
        .type = HTTPD_WS_TYPE_PONG,
        .payload = NULL,
        .len = 0};

    return httpd_ws_send_frame(req, &resp);
}

esp_err_t start_api_server(void)
{
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.uri_match_fn = httpd_uri_match_wildcard;

    ESP_LOGI(SERVER_TAG, "Starting HTTP Server");
    if (httpd_start(&server, &config) != ESP_OK)
    {
        ESP_LOGI(SERVER_TAG, "Failed to start server");
        return ESP_FAIL;
    }

    httpd_uri_t hrng_get_uri = {
        .uri = "/api/v1/random",
        .method = HTTP_GET,
        .handler = hrng_get_handler,
        .user_ctx = NULL};
    httpd_register_uri_handler(server, &hrng_get_uri);

    httpd_uri_t rng_get_uri = {
        .uri = "/api/v1/csprng",
        .method = HTTP_GET,
        .handler = csprng_get_handler,
        .user_ctx = NULL};
    httpd_register_uri_handler(server, &rng_get_uri);

    httpd_uri_t ws_uri = {
        .uri = "/api/v1/esp_fill_random",
        .method = HTTP_GET,
        .handler = esp_fill_random_ws_handler,
        .is_websocket = true,
        .user_ctx = NULL};
    httpd_register_uri_handler(server, &ws_uri);

    httpd_uri_t ws_csprng_uri = {
        .uri = "/api/v1/csprng_fill_random",
        .method = HTTP_GET,
        .handler = csprng_fill_random_ws_handler,
        .is_websocket = true,
        .user_ctx = NULL};
    httpd_register_uri_handler(server, &ws_csprng_uri);

    return ESP_OK;
}