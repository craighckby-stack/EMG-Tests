/**
 * @file specimen_05_typescript.ts
 * @brief Specimen 05 — Type-safe, memory-efficient, and optimized ledger operations.
 */

/**
 * Represents a immutable ledger entry record.
 */
export interface LedgerEntry {
    readonly id: string;
    readonly amount: number;
    readonly committed: boolean;
}

/**
 * Calculates the total net amount of all ledger entries using a zero-allocation loop.
 *
 * @param entries - Array of ledger entries
 * @returns Total aggregate net amount, returning 0 for empty arrays
 */
export function netAmount(entries: readonly LedgerEntry[]): number {
    let total = 0;
    const len = entries.length;
    for (let i = 0; i < len; i++) {
        total += entries[i].amount;
    }
    return total;
}

/**
 * Safely determines whether the ledger entry at the specified index is committed.
 *
 * @param entries - Array of ledger entries
 * @param index - Index of entry to inspect
 * @returns Boolean indicating commitment status, or false if index is out of bounds
 */
export function isCommitted(entries: readonly LedgerEntry[], index: number): boolean {
    if (index < 0 || index >= entries.length) {
        return false;
    }
    return entries[index]?.committed ?? false;
}

/**
 * Scales a numeric value by a specified multiplication factor.
 *
 * @param value - Target numeric value to scale
 * @param factor - Multiplier factor
 * @returns Resulting scaled value
 */
export function scale(value: number, factor: number): number {
    return value * factor;
}