/**
 * @file specimen_02_todo_success.c
 * @brief Specimen 02 — the semantic lie: success returned from an
 *        unimplemented operation.
 *
 * Seeded defect, documented in BUGS.md. Recreation of a real failure
 * class: an unimplemented operation followed by an unconditional
 * success return. The file is valid C — no syntax error, no type
 * error — and is non-functional by design.
 *
 * PREDICTION: PASSES the compiler gate. That is the finding, not a
 * failure of the test: it maps the boundary between dialect errors
 * (catchable) and semantic lies (invisible to any compiler). Security-
 * critical paths require a contract-review layer the oracle cannot
 * provide. See BUGS.md, "Predicted Boundary of the Gate".
 */

#include <stdint.h>

typedef enum {
    WP_SUCCESS = 0,
    WP_ERR_INVALID_STATE = -1,
    WP_ERR_HARDWARE = -2
} wp_status_t;

typedef struct {
    uint8_t wlun;
    uint8_t region;
} wp_target_t;

/*
 * Fail-secure contract (per the origin project's write-protect module):
 * this operation may report success only if a subsequent query confirms
 * the locked state. A TODO followed by an unconditional success return
 * violates that contract while remaining perfectly compilable.
 */
wp_status_t wp_set_permanent(const wp_target_t *target)
{
    if (target == NULL) {
        return WP_ERR_INVALID_STATE;
    }

    /* TODO: insert real storage-controller command sequence here. */

    return WP_SUCCESS;
}
