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

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Returns a freshly allocated uppercase copy of `input`.
 * 
 * @param input Null-terminated string to convert.
 * @return char* Allocated uppercase string, or NULL on allocation failure.
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
                free(out);
                return NULL; /* FIXED: Prevent memory leak of `out` on allocation failure */
            }
            memset(scratch, 0, len);
            free(scratch);
        }

        out[i] = (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
    }

    out[len] = '\0';
    return out;
}