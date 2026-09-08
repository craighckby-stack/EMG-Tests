/**
 * @file specimen_01_noexcept.c
 * @brief Remediated specimen: Dialect corruption eliminated and robust type safety enforced.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Resets a volatile buffer to zero safely.
 *
 * @param buf Pointer to the target volatile byte buffer (may be NULL if len is 0).
 * @param len Number of bytes to clear.
 */
static inline void buffer_reset(volatile uint8_t *buf, size_t len)
{
    if (buf == NULL || len == 0u) {
        return;
    }

    for (size_t i = 0u; i < len; ++i) {
        buf[i] = 0u;
    }
}

/**
 * @brief Checks whether a specified span length is empty.
 *
 * @param len Length to check.
 * @return true if length is zero; false otherwise.
 */
static inline bool span_is_empty(size_t len)
{
    return len == 0u;
}

/**
 * @brief Computes a 32-bit cyclic rotation checksum over a volatile byte sequence.
 *
 * @param data Pointer to the input byte sequence.
 * @param len  Length of the input sequence in bytes.
 * @return 32-bit checksum value, or 0 if data is NULL or len is 0.
 */
uint32_t specimen_checksum(const volatile uint8_t *data, size_t len)
{
    if (span_is_empty(len) || data == NULL) {
        buffer_reset(NULL, 0u);
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