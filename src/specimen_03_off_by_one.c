/**
 * @file specimen_03_off_by_one.c
 * @brief Optimized implementation of inclusive range copying.
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Copies elements in the inclusive index range [first, last] from source to destination.
 *
 * @param src      Pointer to the source array of uint32_t elements.
 * @param first    Zero-based start index (inclusive).
 * @param last     Zero-based end index (inclusive).
 * @param dest     Pointer to the destination buffer.
 * @param dest_cap Maximum number of elements the destination buffer can receive.
 * @return size_t  The number of elements successfully copied into dest.
 */
size_t copy_inclusive_range(const uint32_t *src, size_t first, size_t last,
                            uint32_t *dest, size_t dest_cap)
{
    if (src == NULL || dest == NULL || first > last || dest_cap == 0U) {
        return 0U;
    }

    /* Verify span calculation avoids overflow and maps accurately */
    const size_t diff = last - first;
    if (diff > SIZE_MAX - 1U) {
        return 0U;
    }

    const size_t total_elements = diff + 1U;
    const size_t to_copy = (total_elements < dest_cap) ? total_elements : dest_cap;

    (void)memmove(dest, src + first, to_copy * sizeof(uint32_t));

    return to_copy;
}