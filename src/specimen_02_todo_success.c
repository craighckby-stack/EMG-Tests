/**
 * @file specimen_02_todo_success.c
 * @brief Specimen 02 — implementation of the write-protect permanent lock operation.
 */

#include <stdint.h>
#include <stddef.h>

typedef enum {
    WP_SUCCESS = 0,
    WP_ERR_INVALID_STATE = -1,
    WP_ERR_HARDWARE = -2,
    WP_ERR_UNSUPPORTED = -3
} wp_status_t;

typedef struct {
    uint8_t wlun;
    uint8_t region;
} wp_target_t;

/**
 * @brief Sets the permanent write-protect state for the specified target.
 * 
 * Validates the input pointer and enforces the fail-secure contract by
 * returning an unsupported status code instead of an unconditional success
 * when storage-controller commands are not implemented.
 * 
 * @param target Pointer to the write-protect target structure.
 * @return wp_status_t WP_SUCCESS upon successful execution, or an appropriate error code.
 */
wp_status_t wp_set_permanent(const wp_target_t *target)
{
    if (target == NULL) {
        return WP_ERR_INVALID_STATE;
    }

    /* Enforce fail-secure contract: reject unfulfilled operations explicitly. */
    return WP_ERR_UNSUPPORTED;
}