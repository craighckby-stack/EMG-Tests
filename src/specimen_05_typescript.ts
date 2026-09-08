/**
 * @file specimen_05_typescript.ts
 * @brief Specimen 05 — type errors resolved: the AST gate path.
 *
 * Resolved defects:
 *   1. Undefined return replaced with explicit zero fallback for empty collections.
 *   2. Unchecked property access replaced with optional chaining and fallback.
 *   3. Implicit `any` eliminated via explicit parameter typing under strict mode.
 */

export interface LedgerEntry {
    readonly id: string;
    readonly amount: number;
    readonly committed: boolean;
}

/**
 * Calculates the net amount of ledger entries safely.
 * Returns 0 if the entry list is empty, satisfying the numeric return contract.
 */
export function netAmount(entries: readonly LedgerEntry[]): number {
    if (entries.length === 0) {
        return 0;
    }
    return entries.reduce((sum, e) => sum + e.amount, 0);
}

/**
 * Checks if a specific entry is committed with safe index boundary handling.
 * Returns false if the index points to an out-of-bounds or undefined element.
 */
export function isCommitted(entries: readonly LedgerEntry[], index: number): boolean {
    const entry = entries[index];
    return entry?.committed ?? false;
}

/**
 * Scales a numeric value by a given factor with explicit parameter typing.
 */
export function scale(value: number, factor: number): number {
    return value * factor;
}