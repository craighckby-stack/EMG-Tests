/**
 * @file specimen_03_off_by_one.c
 * @brief Specimen 03 — High-performance inclusive range copy implementation.
 *
 * Corrects the off-by-one semantic defect, optimizes block memory transfer
 * using SIMD-accelerated memcpy, and enforces robust parameter validation.
 */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Copies elements from index range [first, last] inclusive into dest.
 *
 * @param[in]  src      Pointer to constant source array.
 * @param[in]  first    Starting index of range (inclusive).
 * @param[in]  last     Ending index of range (inclusive).
 * @param[out] dest     Pointer to destination array buffer.
 * @param[in]  dest_cap Capacity of destination array buffer (in elements).
 *
 * @return size_t       Total number of elements successfully copied.
 */
size_t copy_inclusive_range(const uint32_t *src, size_t first, size_t last,
                            uint32_t *dest, size_t dest_cap)
{
    if (src == NULL || dest == NULL || first > last || dest_cap == 0u) {
        return 0u;
    }

    const size_t range_diff = last - first;
    const size_t count = (range_diff < dest_cap) ? (range_diff + 1u) : dest_cap;

    (void)memcpy(dest, src + first, count * sizeof(uint32_t));

    return count;
}