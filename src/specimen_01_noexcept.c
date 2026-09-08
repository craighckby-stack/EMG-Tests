/**
 * @file specimen_01_noexcept.c
 * @brief Specimen 01 — dialect corruption (C++ keyword in a C translation unit).
 *
 * SEeded defect, documented in BUGS.md. This is a recreation of a real
 * failure produced by an AI refactoring pass: a later "type safety"
 * iteration injected `noexcept` — not a C keyword — into previously
 * valid C, while the generating tool logged the result as verified.
 *
 * PREDICTION: rejected by the GCC oracle (-fsyntax-only) with a real
 * syntax error. Post-mortem entry with verbatim stderr is expected.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*
 * The poison: `noexcept` on a function definition is a C++ construct.
 * In a C translation unit this is a syntax error, which is the point —
 * the gate must produce external, quotable evidence.
 */
static inline void buffer_reset(volatile uint8_t *buf, size_t len) noexcept
{
    for (size_t i = 0u; i < len; ++i) {
        buf[i] = 0u;
    }
}

static inline bool span_is_empty(size_t len) noexcept
{
    return len == 0u;
}

uint32_t specimen_checksum(const volatile uint8_t *data, size_t len)
{
    uint32_t sum = 0u;

    for (size_t i = 0u; i < len; ++i) {
        sum = (sum << 1u) | (sum >> 31u);
        sum ^= (uint32_t)data[i];
    }

    (void)buffer_reset(NULL, 0u);
    (void)span_is_empty(0u);

    return sum;
}
