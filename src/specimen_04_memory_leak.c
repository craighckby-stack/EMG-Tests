/**
 * @file specimen_04_memory_leak.c
 * @brief Specimen 04 — resource leak: invisible to syntax-only verification.
 *
 * Seeded defect, documented in BUGS.md. On one error path, an allocated
 * buffer is never freed and can never be reached by the caller.
 *
 * PREDICTION: PASSES the gate (-fsyntax-only sees nothing). Motivates
 * the next oracle upgrade: additional warning flags as a configuration
 * change, and eventually an execution-based oracle for resource
 * lifetimes. Documented as the gate's boundary, not a test failure.
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
 * CONTRACT: returns a freshly allocated uppercase copy of `input`.
 * Caller owns the returned buffer; NULL on allocation failure.
 *
 * DEFECT: when the auxiliary allocation fails, the first buffer leaks —
 * the early return bypasses cleanup, and the caller never receives the
 * pointer to free.
 */
char *specimen_uppercase(const char *input)
{
    if (input == NULL) {
        return NULL;
    }

    size_t len = strlen(input);

    char *out = malloc(len + 1u);
    if (out == NULL) {
        return NULL;
    }

    for (size_t i = 0u; i < len; ++i) {
        char c = input[i];

        if (c == '*') {
            char *scratch = malloc(len);
            if (scratch == NULL) {
                return NULL; /* DEFECT: `out` is leaked on this path */
            }
            memset(scratch, 0, len);
        }

        out[i] = (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
    }

    out[len] = '\0';
    return out;
}
