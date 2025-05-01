#pragma once

#include <stdint.h>
#include <stddef.h>

// Initialize the DRBG. Must be called before csprng_get_bytes().
void csprng_init(void);

// Reseed the DRBG with fresh entropy.
void csprng_reseed(void);

// Fill `out` with `len` cryptographically random bytes.
int csprng_get_bytes(uint8_t *out, size_t len);

int csprng_health_check(void);