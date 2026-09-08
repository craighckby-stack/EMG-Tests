/**
 * @file specimen_03_off_by_one.c
 * @brief Specimen 03 — logic bug: invisible to any compiler.
 *
 * Seeded defect, documented in BUGS.md. The boundary check excludes the
 * final element of the contracted range. The file compiles cleanly and
 * passes every syntax-level gate.
 *
 * PREDICTION: PASSES the gate. Mutator dispositions are all informative
 * and are scored in BUGS.md: correct fix (luck), incorrect fix (harm),
 * zero-diff (saturation with a known bug intact — the honest outcome),
 * or stylistic rewrite that misses the bug (churn without correctness).
 */

#include <stdint.h>
#include <stddef.h>

/*
 * CONTRACT: copies indices [first, last], inclusive of both endpoints,
 * into dest. Returns the number of copied elements.
 *
 * DEFECT: the loop bound excludes `last`, violating the contract for
 * every call. The defect is semantic; no syntax-level oracle can see it.
 */
size_t copy_inclusive_range(const uint32_t *src, size_t first, size_t last,
                            uint32_t *dest, size_t dest_cap)
{
    if (src == NULL || dest == NULL || first > last) {
        return 0u;
    }

    size_t count = 0u;

    for (size_t i = first; i < last; ++i) { /* DEFECT: last excluded */
        if (count < dest_cap) {
            dest[count++] = src[i];
        }
    }

    return count;
}
