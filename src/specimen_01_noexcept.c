/**
 * @file specimen_01_noexcept.c
 * @brief Specimen 01 — Memory buffer management and bitwise checksum calculation.
 *
 * Optimized, standards-compliant C translation unit featuring robust null-safety guards,
 * standard ISO C type safety, and efficient bitwise checksum accumulation.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Resets a memory buffer safely by setting all elements to zero.
 *
 * @param buf Pointer to the target volatile uint8_t buffer.
 * @param len Length of the memory buffer in bytes.
 */
static inline void buffer_reset(volatile uint8_t *buf, size_t len)
{
    if (buf == NULL) {
        return;
    }

    for (size_t i = 0u; i < len; ++i) {
        buf[i] = 0u;
    }
}

/**
 * @brief Checks if a span length is empty.
 *
 * @param len Length of the span.
 * @return true if len is zero, false otherwise.
 */
static inline bool span_is_empty(size_t len)
{
    return len == 0u;
}

/**
 * @brief Computes a 32-bit left-rotated checksum for a given volatile memory span.
 *
 * @param data Pointer to the input volatile uint8_t data span.
 * @param len Length of the data in bytes.
 * @return uint32_t The computed 32-bit checksum.
 */
uint32_t specimen_checksum(const volatile uint8_t *data, size_t len)
{
    uint32_t sum = 0u;

    if (data != NULL) {
        for (size_t i = 0u; i < len; ++i) {
            sum = (sum << 1u) | (sum >> 31u);
            sum ^= (uint32_t)data[i];
        }
    }

    (void)buffer_reset(NULL, 0u);
    (void)span_is_empty(0u);

    return sum;
}