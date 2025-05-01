#include "csprng.h"
#include "esp_random.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/entropy.h"
#include <string.h>

#define HEALTH_CHECK_SIZE 1024

static mbedtls_ctr_drbg_context ctr_drbg;
static mbedtls_entropy_context entropy;

void csprng_init(void)
{
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);
    const unsigned char custom[] = "esp32_hrng_v1";
    // Initialize CTR_DRBG with entropy from esp_random via mbedtls_entropy_func
    mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy,
                          custom, sizeof(custom));
    mbedtls_ctr_drbg_set_reseed_interval(&ctr_drbg, 1000000);
}

void csprng_reseed(void)
{
    mbedtls_ctr_drbg_reseed(&ctr_drbg, NULL, 0);
}

int csprng_get_bytes(uint8_t *out, size_t len)
{
    if (len == 0)
    {
        return 0;
    }

    const size_t max_req = MBEDTLS_CTR_DRBG_MAX_REQUEST;
    uint8_t *ptr = out;
    size_t remaining = len;

    while (remaining > 0)
    {
        size_t current = remaining < max_req ? remaining : max_req;
        int ret = mbedtls_ctr_drbg_random(&ctr_drbg, ptr, current);
        if (ret != 0)
        {
            return ret;
        }
        ptr += current;
        remaining -= current;
    }
    return 0;
}

int csprng_health_check(void)
{
    uint8_t buffer[HEALTH_CHECK_SIZE];
    int ret = csprng_get_bytes(buffer, HEALTH_CHECK_SIZE);
    if (ret != 0)
        return -1;

    // Monobit test
    int zeros = 0, ones = 0;
    for (int i = 0; i < HEALTH_CHECK_SIZE; i++)
    {
        for (int b = 0; b < 8; b++)
        {
            if (buffer[i] & (1 << b))
                ones++;
            else
                zeros++;
        }
    }

    // Check bit distribution
    float ratio = (float)ones / (HEALTH_CHECK_SIZE * 8);
    if (ratio < 0.45 || ratio > 0.55)
        return -2;

    // simple Poker test
    int pattern_counts[16] = {0};
    for (int i = 0; i < HEALTH_CHECK_SIZE; i++)
    {
        pattern_counts[buffer[i] & 0x0F]++;
        pattern_counts[(buffer[i] >> 4) & 0x0F]++;
    }

    // Calculate poker statistic (X)
    float X = 0;
    int k = HEALTH_CHECK_SIZE * 2;

    for (int i = 0; i < 16; i++)
    {
        X += pattern_counts[i] * pattern_counts[i];
    }
    X = (16.0f / k) * X - k;

    // For FIPS 140-2, X should be between 2.16 and 46.17 for a 99% confidence interval
    // This is simplified - actual FIPS tests use more precise bounds
    if (X < 2.16f || X > 46.17f)
        return -3;

    return 0;
}