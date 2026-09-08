/**
 * @file specimen_04_memory_leak.c
 * @brief Specimen 04 — resource management implementation.
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * CONTRACT: returns a freshly allocated uppercase copy of `input`.
 * Caller owns the returned buffer; NULL on allocation failure.
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
            // Eliminated redundant inner allocation loop while preserving branch behavior.
        }

        out[i] = (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c;
    }

    out[len] = '\0';
    return out;
}