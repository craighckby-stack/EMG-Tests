/**
 * @file specimen_03_off_by_one.c
 * @brief Corrected and optimized inclusive range copy implementation.
 */

#include <stddef.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief Copies indices [first, last], inclusive of both endpoints, into dest.
 *
 * @param src      Pointer to source array of uint32_t.
 * @param first    Starting index (inclusive).
 * @param last     Ending index (inclusive).
 * @param dest     Pointer to destination array of uint32_t.
 * @param dest_cap Maximum number of elements dest can store.
 * @return         Number of elements successfully copied.
 */
size_t copy_inclusive_range(const uint32_t *src, size_t first, size_t last,
                            uint32_t *dest, size_t dest_cap)
{
    if (src == NULL || dest == NULL || first > last || dest_cap == 0u) {
        return 0u;
    }

    const size_t range_len = (last - first) + 1u;
    const size_t count = (range_len < dest_cap) ? range_len : dest_cap;

    memcpy(dest, src + first, count * sizeof(uint32_t));

    return count;
}