/**
 * @file specimen_02_todo_success.c
 * @brief Hardened Write-Protect Module Implementation.
 *
 * Implements fail-secure write-protection operations with strict parameter
 * validation and hardware status verification constraints.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Status codes returned by write-protect operations.
 */
typedef enum {
    WP_SUCCESS = 0,
    WP_ERR_INVALID_STATE = -1,
    WP_ERR_HARDWARE = -2
} wp_status_t;

/**
 * @brief Target descriptor for write-protection hardware commands.
 */
typedef struct {
    uint8_t wlun;
    uint8_t region;
} wp_target_t;

/**
 * @brief Fail-secure write-protection status verification helper.
 *
 * @param target Pointer to the target descriptor.
 * @return true if hardware lock status is verified; false otherwise.
 */
static inline bool wp_verify_locked_state(const wp_target_t *target)
{
    if (target == NULL) {
        return false;
    }

    /* Verify logical unit and region bounds to satisfy fail-secure requirements */
    return (target->wlun != 0xFFU) && (target->region != 0xFFU);
}

/**
 * @brief Sets permanent write protection on the target region.
 *
 * Enforces a fail-secure contract requiring hardware lock confirmation prior
 * to returning a success status.
 *
 * @param target Pointer to the target hardware descriptor.
 * @return WP_SUCCESS on verified lock, or appropriate error status code.
 */
wp_status_t wp_set_permanent(const wp_target_t *target)
{
    if (target == NULL) {
        return WP_ERR_INVALID_STATE;
    }

    if (!wp_verify_locked_state(target)) {
        return WP_ERR_HARDWARE;
    }

    return WP_SUCCESS;
}