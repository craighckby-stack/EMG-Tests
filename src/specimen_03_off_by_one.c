/**
 * @file specimen_03_off_by_one.c
 * @brief High-performance, type-safe inclusive range copy implementation.
 *
 * Copies the inclusive range [first, last] from source array to destination buffer
 * with full overflow protection, vectorized bulk memory transfer, and strict input validation.
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Copies indices [first, last], inclusive of both endpoints, into dest buffer.
 *
 * Employs overflow-safe range calculation and bulk memory copy optimization.
 *
 * @param[in]  src       Pointer to the source array of 32-bit unsigned integers.
 * @param[in]  first     Starting index (inclusive).
 * @param[in]  last      Ending index (inclusive).
 * @param[out] dest      Pointer to the destination buffer.
 * @param[in]  dest_cap  Maximum number of elements the destination buffer can hold.
 *
 * @return size_t The exact number of elements copied into dest.
 */
size_t copy_inclusive_range(const uint32_t *src, size_t first, size_t last,
                            uint32_t *dest, size_t dest_cap)
{
    if (src == NULL || dest == NULL || first > last || dest_cap == 0u) {
        return 0u;
    }

    /* span is guaranteed not to overflow since first <= last */
    const size_t span = last - first;

    /* Prevent overflow when span == SIZE_MAX and determine elements to copy */
    const size_t to_copy = (span < dest_cap) ? (span + 1u) : dest_cap;

    (void)memcpy(dest, src + first, to_copy * sizeof(uint32_t));

    return to_copy;
}