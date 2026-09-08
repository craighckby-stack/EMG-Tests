/**
 * @file specimen_05_typescript.ts
 * @brief High-performance, type-safe ledger calculation utilities.
 */

/**
 * Represents an individual entry within the ledger.
 */
export interface LedgerEntry {
    readonly id: string;
    readonly amount: number;
    readonly committed: boolean;
}

/**
 * Calculates the total net sum of amounts across all provided ledger entries.
 * Iterates through the collection using an index-based loop.
 *
 * @param entries - Array of ledger entries to aggregate.
 * @returns The total sum of entry amounts, or 0 if empty.
 */
export function netAmount(entries: readonly LedgerEntry[]): number {
    if (!entries || entries.length === 0) {
        return 0;
    }

    let sum = 0;
    const len = entries.length;
    for (let i = 0; i < len; i++) {
        const entry = entries[i];
        if (entry !== undefined) {
            sum += entry.amount;
        }
    }
    return sum;
}

/**
 * Determines whether a ledger entry at a specific index is committed.
 * Performs bounds checking.
 *
 * @param entries - Target array of ledger entries.
 * @param index - Array index to inspect.
 * @returns True if the entry exists and is committed; false otherwise.
 */
export function isCommitted(entries: readonly LedgerEntry[], index: number): boolean {
    if (!entries || index < 0 || index >= entries.length) {
        return false;
    }
    return entries[index]?.committed ?? false;
}

/**
 * Scales a numerical value by a specified scaling factor.
 *
 * @param value - The numeric value to scale.
 * @param factor - The scaling multiplier.
 * @returns The product of the value and factor.
 */
export function scale(value: number, factor: number): number {
    return value * factor;
}