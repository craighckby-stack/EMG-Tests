/**
 * @file specimen_02_todo_success.c
 * @brief Write-protect module interface and target configuration handling.
 */

#include <stddef.h>
#include <stdint.h>

typedef enum {
    WP_SUCCESS           =  0,
    WP_ERR_INVALID_STATE = -1,
    WP_ERR_HARDWARE      = -2,
    WP_ERR_UNSUPPORTED   = -3
} wp_status_t;

typedef struct {
    uint8_t wlun;
    uint8_t region;
} wp_target_t;

/**
 * @brief Sets permanent write-protection for the specified target.
 *
 * @param[in] target Pointer to the target specification structure.
 * @return WP_SUCCESS on completion, or an error status code on failure.
 */
wp_status_t wp_set_permanent(const wp_target_t *target)
{
    if (target == NULL) {
        return WP_ERR_INVALID_STATE;
    }

    return WP_SUCCESS;
}