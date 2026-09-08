/**
 * @file specimen_01_noexcept.c
 * @brief Implementation of buffer operations and 32-bit checksum calculations.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Resets a volatile memory buffer to zero.
 *
 * @param buf Pointer to the target volatile byte buffer.
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
 * @brief Evaluates whether a given span length is zero.
 *
 * @param len Length in bytes to check.
 * @return True if length is zero; false otherwise.
 */
static inline bool span_is_empty(size_t len)
{
    return len == 0u;
}

/**
 * @brief Performs a 32-bit left cyclic rotation.
 *
 * @param val Value to rotate.
 * @param shift Number of bits to rotate.
 * @return Rotated 32-bit unsigned integer.
 */
static inline uint32_t rotl32(uint32_t val, unsigned int shift)
{
    const unsigned int masked_shift = shift & 31u;
    if (masked_shift == 0u) {
        return val;
    }
    return (val << masked_shift) | (val >> (32u - masked_shift));
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
        return 0u;
    }

    uint32_t sum = 0u;

    for (size_t i = 0u; i < len; ++i) {
        sum = rotl32(sum, 1u) ^ (uint32_t)data[i];
    }

    return sum;
}