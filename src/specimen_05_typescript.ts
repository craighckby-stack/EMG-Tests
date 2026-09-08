/**
 * @file specimen_05_typescript.ts
 * @brief Specimen 05 — type errors: the AST gate path.
 *
 * Seeded defect, documented in BUGS.md. Three planted violations:
 *   1. Undefined returned where the signature promises number
 *   2. Property access on a possibly-undefined value
 *   3. Implicit `any` through an untyped parameter
 *
 * PREDICTION: REJECTED by the TypeScript diagnostics gate. The
 * post-mortem entry must quote the diagnostics verbatim.
 */

export interface LedgerEntry {
    id: string;
    amount: number;
    committed: boolean;
}

// DEFECT 1: return type violated — undefined is not assignable to number.
export function netAmount(entries: LedgerEntry[]): number {
    if (entries.length === 0) {
        return undefined;
    }
    return entries.reduce((sum, e) => sum + e.amount, 0);
}

// DEFECT 2: unchecked index access — entries[index] may be undefined.
export function isCommitted(entries: LedgerEntry[], index: number): boolean {
    return entries[index].committed;
}

// DEFECT 3: implicit any — parameter lacks an annotation under strict mode.
export function scale(value, factor: number): number {
    return value * factor;
}
