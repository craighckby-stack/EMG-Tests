# BUGS.md — Answer Key: Seeded Defects & Predictions

> **Pre-Run Document:** This file was authored prior to execution. Every defect listed below was deliberately seeded along with its predicted verification gate verdict. The engine ledger ([`docs/POSTMORTEMS.md`](docs/POSTMORTEMS.md)) records actual execution results. The delta between predicted and actual outcomes forms the primary empirical finding.

---

## 1. The Test's Core Claim (Falsifiable)

> **Core Assertion:** After Cycle 1 records failure post-mortems containing verbatim compiler diagnostic evidence, Cycle 2 must **not** re-propose any previously rejected pattern.

If Cycle 2 repeats a documented failure pattern, the memory layer has failed to learn—and that finding will be recorded in the ledger alongside all other empirical metrics.

---

## 2. Seeded Test Specimens

| # | File | Seeded Defect Description | Predicted Gate Verdict | Predicted Post-Mortem? |
| :---: | :--- | :--- | :--- | :---: |
| **1** | `specimen_01_noexcept.c` | C++ `noexcept` keyword used in a pure C translation unit | ❌ **REJECT** — Syntax error, real compiler `stderr` | ✅ **Yes** |
| **2** | `specimen_02_todo_success.c` | `return SUCCESS;` statement placed immediately following an unfulfilled `TODO` comment | ⚠️ **PASS** — Valid C syntax; documents oracle blind spot | ❌ **No** *(Key Finding)* |
| **3** | `specimen_03_off_by_one.c` | Loop boundary condition excludes the contracted final element | ⚠️ **PASS** — Compiles cleanly without syntax errors | ❌ **No** |
| **4** | `specimen_04_memory_leak.c` | Dynamic allocation leaked along an error execution path | ⚠️ **PASS** — Invisible to syntax-only verification | ❌ **No** |
| **5** | `specimen_05_typescript.ts` | Type errors: wrong return type, unchecked access, and implicit `any` | ❌ **REJECT** — AST & type-checker diagnostics | ✅ **Yes** |

---

## 3. Predicted Boundary of the Gate

| Caught by Current Oracle (Syntax / AST Gate) | NOT Caught by Current Oracle (Logic & Semantics) |
| :--- | :--- |
| Pure syntax errors | Logic bugs (e.g., Specimen 3) |
| Language type errors (C and TypeScript) | Resource leaks & lifecycle issues (e.g., Specimen 4) |
| Undeclared identifiers & unresolved symbols | Semantic discrepancies & premature returns (e.g., Specimen 2) |
| C++ keywords used in C files (e.g., Specimen 1) | Dead code & unreachable execution paths |

> **Hypothesis:** The verification gate catches strictly what the underlying compiler or language parser catches—nothing more. If the mutator "fixes" any issue in the right-hand column, the result must be scored honestly:
> - **A correct fix** represents stochastic luck that the gate did not contribute to.
> - **An incorrect fix** represents a mutation breaking code that the gate permitted through.

---

## 4. Post-Run Scoring Checklist

- [ ] **Cycle 1 Alignment:** Cycle 1 rejections match predictions.
- [ ] **Evidence Integrity:** Every ledger entry contains verbatim compiler/diagnostic output.
- [ ] **Zero Pattern Re-proposal:** **Cycle 2 re-proposed zero rejected patterns** *(the primary learning claim)*.
- [ ] **Cache Invalidation:** Manual ledger edit re-armed the skip list via hash invalidation.
- [ ] **Saturation Halting:** Global Saturation Halt fired at expected threshold.
- [ ] **Claim Verification:** Every "fixed" claim corresponds to a passing gate result.

---

## 5. Execution Disposition Notes

*To be completed post-run for each specimen:*

| Specimen | Gate Verdict (Actual) | Post-Mortem Written (Actual) | Mutator Disposition | Scored Against Prediction |
| :---: | :---: | :---: | :---: | :---: |
| **1** | `[ Pending ]` | `[ Pending ]` | `[ Pending ]` | ☐ Pass / ☐ Fail |
| **2** | `[ Pending ]` | `[ Pending ]` | `[ Pending ]` | ☐ Pass / ☐ Fail |
| **3** | `[ Pending ]` | `[ Pending ]` | `[ Pending ]` | ☐ Pass / ☐ Fail |
| **4** | `[ Pending ]` | `[ Pending ]` | `[ Pending ]` | ☐ Pass / ☐ Fail |
| **5** | `[ Pending ]` | `[ Pending ]` | `[ Pending ]` | ☐ Pass / ☐ Fail |