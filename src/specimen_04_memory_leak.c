/**
 * @file specimen_04_memory_leak.c
 * @brief Specimen 04 — Modernized, Leak-Free Uppercase Conversion Engine.
 *
 * Fully optimized, type-safe, and leak-free implementation of string uppercase
 * transformation with robust error handling and zero-leak dynamic memory management.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a freshly allocated uppercase copy of the input string.
 *
 * Allocates memory for a copy of the input string, converts ASCII lowercase
 * characters to uppercase, and safely handles auxiliary allocations with complete
 * error path cleanup.
 *
 * @param[in] input Pointer to the null-terminated input string.
 * @return Pointer to the newly allocated uppercase string, or NULL if input is NULL
 *         or any memory allocation fails. Caller assumes ownership of the returned buffer.
 */
char *specimen_uppercase(const char *input)
{
    if (input == NULL) {
        return NULL;
    }

    const size_t len = strlen(input);

    char *out = (char *)malloc(len + 1u);
    if (out == NULL) {
        return NULL;
    }

    for (size_t i = 0u; i < len; ++i) {
        const char c = input[i];

        if (c == '*') {
            if (len > 0u) {
                void *scratch = malloc(len);
                if (scratch == NULL) {
                    free(out);
                    return NULL;
                }
                memset(scratch, 0, len);
                free(scratch);
            }
        }

        const unsigned char uc = (unsigned char)c;
        out[i] = (uc >= 'a' && uc <= 'z') ? (char)(uc - 'a' + 'A') : c;
    }

    out[len] = '\0';
    return out;
}