/**
 * @file specimen_05_typescript.ts
 * @brief Optimized and fully type-safe ledger processing engine.
 */

export interface LedgerEntry {
    readonly id: string;
    readonly amount: number;
    readonly committed: boolean;
}

/**
 * Calculates the total net amount across all ledger entries.
 *
 * @param entries - Array of ledger entries to sum.
 * @returns The total sum of entry amounts, or 0 if empty.
 */
export function netAmount(entries: LedgerEntry[]): number {
    let sum = 0;
    const len = entries.length;
    for (let i = 0; i < len; i++) {
        sum += entries[i].amount;
    }
    return sum;
}

/**
 * Safely checks if a ledger entry at a specific index is committed.
 *
 * @param entries - Array of ledger entries.
 * @param index - Target array index.
 * @returns True if entry exists and is committed, false otherwise.
 */
export function isCommitted(entries: LedgerEntry[], index: number): boolean {
    if (!Number.isInteger(index) || index < 0 || index >= entries.length) {
        return false;
    }
    return entries[index]?.committed ?? false;
}

/**
 * Scales a numeric value by a multiplication factor.
 *
 * @param value - The base numeric value.
 * @param factor - Multiplication factor.
 * @returns The scaled product.
 */
export function scale(value: number, factor: number): number {
    return value * factor;
}