/**
 * @file specimen_01_noexcept.c
 * @brief Remediated and optimized specimen translation unit.
 *
 * Resolved dialect corruption by removing invalid C++ keywords, added defensive
 * null-pointer guards, and optimized standard rotation/checksum operations.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Securely clears a memory buffer using volatile pointer semantics.
 *
 * @param buf Pointer to volatile buffer to clear.
 * @param len Length in bytes of the buffer.
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
 * @brief Checks whether a given span length is zero.
 *
 * @param len Length of the span.
 * @return true if span is empty, false otherwise.
 */
static inline bool span_is_empty(size_t len)
{
    return len == 0u;
}

/**
 * @brief Calculates a 32-bit cyclic rotation checksum over a volatile byte buffer.
 *
 * @param data Pointer to input data buffer.
 * @param len  Number of bytes to process.
 * @return Computed 32-bit checksum, or 0 if input pointer is NULL.
 */
uint32_t specimen_checksum(const volatile uint8_t *data, size_t len)
{
    uint32_t sum = 0u;

    if (data != NULL && !span_is_empty(len)) {
        for (size_t i = 0u; i < len; ++i) {
            sum = (sum << 1u) | (sum >> 31u);
            sum ^= (uint32_t)data[i];
        }
    }

    return sum;
}