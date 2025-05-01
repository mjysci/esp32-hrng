#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "mdns.h"

#include "rng_api_server.h"
#include "csprng.h"

static const char *SERVER_TAG = "esp32-hrng";

static void initialise_mdns(void)
{
    ESP_ERROR_CHECK(mdns_init());
    ESP_ERROR_CHECK(mdns_hostname_set(SERVER_TAG));
    ESP_ERROR_CHECK(mdns_instance_name_set("ESP32 HRNG API Server"));
    ESP_ERROR_CHECK(mdns_service_add(NULL, "_http", "_tcp", 80, NULL, 0));
    ESP_LOGI(SERVER_TAG, "mDNS initialized, hostname: esp32-hrng.local");
}

void app_main(void)
{
    esp_log_level_set("*", CONFIG_DEBUG == 0 ? ESP_LOG_NONE : CONFIG_DEBUG == 1 ? ESP_LOG_ERROR
                                                          : CONFIG_DEBUG == 2   ? ESP_LOG_WARN
                                                                                : ESP_LOG_INFO);

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(example_connect());
    initialise_mdns();
    heartbeat_led_init();
    ESP_LOGI(SERVER_TAG, "Running CSPRNG health check...");
    csprng_init();
    int health_result = csprng_health_check();
    if (health_result != 0)
    {
        ESP_LOGE(SERVER_TAG, "CSPRNG health check failed with code: %d", health_result);
    }
    ESP_LOGI(SERVER_TAG, "CSPRNG health check passed");
    ESP_ERROR_CHECK(start_api_server());
}