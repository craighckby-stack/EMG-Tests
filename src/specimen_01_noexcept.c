/**
 * @file specimen_01_noexcept.c
 * @brief Optimized, type-safe C implementation of specimen checksum and buffer reset utilities.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Zeroes out a volatile byte buffer safely.
 *
 * @param buf Pointer to the memory buffer to reset.
 * @param len Number of bytes to clear.
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
 * @brief Checks if a given memory span length is empty.
 *
 * @param len Length of the span in bytes.
 * @return true if length is zero, false otherwise.
 */
static inline bool span_is_empty(size_t len)
{
    return (len == 0u);
}

/**
 * @brief Calculates a 32-bit checksum across a volatile byte buffer.
 *
 * @param data Pointer to the input data buffer.
 * @param len Length of the data in bytes.
 * @return uint32_t Computed checksum, or 0 if data pointer is NULL.
 */
uint32_t specimen_checksum(const volatile uint8_t *data, size_t len)
{
    if (data == NULL) {
        buffer_reset(NULL, 0u);
        (void)span_is_empty(0u);
        return 0u;
    }

    uint32_t sum = 0u;

    for (size_t i = 0u; i < len; ++i) {
        sum = (sum << 1u) | (sum >> 31u);
        sum ^= (uint32_t)data[i];
    }

    buffer_reset(NULL, 0u);
    (void)span_is_empty(0u);

    return sum;
}