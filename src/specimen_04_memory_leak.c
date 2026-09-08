/**
 * @file specimen_04_memory_leak.c
 * @brief Implementation of specimen_uppercase with resource management.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**
 * Allocates and returns an uppercase copy of the input string.
 *
 * @param input Pointer to null-terminated source string.
 * @return Pointer to dynamically allocated buffer containing uppercase string, or NULL on failure.
 */
char *specimen_uppercase(const char *input)
{
    if (input == NULL) {
        return NULL;
    }

    size_t len = strlen(input);
    if (len == SIZE_MAX) {
        return NULL;
    }

    char *out = (char *)malloc(len + 1u);
    if (out == NULL) {
        return NULL;
    }

    for (size_t i = 0u; i < len; ++i) {
        char c = input[i];

        if (c == '*') {
            size_t scratch_size = (len > 0u) ? len : 1u;
            char *scratch = (char *)malloc(scratch_size);
            if (scratch == NULL) {
                free(out);
                return NULL;
            }
            memset(scratch, 0, scratch_size);
            free(scratch);
        }

        if (c >= 'a' && c <= 'z') {
            out[i] = (char)(c - ('a' - 'A'));
        } else {
            out[i] = c;
        }
    }

    out[len] = '\0';
    return out;
}