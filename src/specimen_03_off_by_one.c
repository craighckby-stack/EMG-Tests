/**
 * @file specimen_03_off_by_one.c
 * @brief Inclusive range copy implementation.
 *
 * Copies elements within the index range [first, last] from a source array
 * to a destination buffer with bounds validation and overflow checks.
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Copies indices [first, last], inclusive of both endpoints, into dest buffer.
 *
 * @param[in]  src       Pointer to the source array of 32-bit unsigned integers.
 * @param[in]  first     Starting index (inclusive).
 * @param[in]  last      Ending index (inclusive).
 * @param[out] dest      Pointer to the destination buffer.
 * @param[in]  dest_cap  Maximum number of elements the destination buffer can hold.
 *
 * @return The number of elements copied into dest.
 */
size_t copy_inclusive_range(const uint32_t *src, size_t first, size_t last,
                            uint32_t *dest, size_t dest_cap)
{
    if (src == NULL || dest == NULL || first > last || dest_cap == 0u) {
        return 0u;
    }

    const size_t span = last - first;

    /* Check for arithmetic overflow when calculating total elements */
    if (span == SIZE_MAX) {
        const size_t to_copy = dest_cap;
        (void)memcpy(dest, src + first, to_copy * sizeof(uint32_t));
        return to_copy;
    }

    const size_t total_elements = span + 1u;
    const size_t to_copy = (total_elements < dest_cap) ? total_elements : dest_cap;

    (void)memcpy(dest, src + first, to_copy * sizeof(uint32_t));

    return to_copy;
}