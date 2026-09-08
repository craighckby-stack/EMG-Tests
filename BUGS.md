# BUGS.md — Answer Key: Seeded Defects & Predictions

> **Note:** This document was authored prior to execution. Every defect detailed below was deliberately planted alongside its predicted gate verdict. The engine's execution ledger (`docs/POSTMORTEMS.md`) captures actual runtime results. The delta between predicted outcomes and actual execution constitutes the primary experiment.

---

## Core Falsifiable Claim

> After Cycle 1 records failure post-mortems containing verbatim compiler evidence, Cycle 2 must not re-propose any previously rejected pattern.

If Cycle 2 re-proposes a documented failure mode, the memory layer has failed to learn—a finding that will be systematically recorded alongside all other experiment outcomes.

---

## Seeded Specimens

| # | Specimen File | Seeded Defect Description | Predicted Gate Verdict | Predicted Post-Mortem Written? |
| :---: | :--- | :--- | :--- | :---: |
| **1** | `specimen_01_noexcept.c` | C++ `noexcept` keyword inside a standard C translation unit | ❌ **REJECT** — Syntax error (`stderr` generated) | ✅ Yes |
| **2** | `specimen_02_todo_success.c` | `return SUCCESS` immediately following a `TODO` comment | ⚠️ **PASS** — Valid C syntax; highlights oracle blind spot | ❌ No — *This is the core finding* |
| **3** | `specimen_03_off_by_one.c` | Loop boundary condition excludes the contracted final element | ⚠️ **PASS** — Compiles cleanly without warnings | ❌ No |
| **4** | `specimen_04_memory_leak.c` | Dynamic memory allocation leaked along an error-handling path | ⚠️ **PASS** — Invisible to syntax-only verification | ❌ No |
| **5** | `specimen_05_typescript.ts` | Type errors: mismatched return type, unchecked access, implicit `any` | ❌ **REJECT** — AST diagnostic failures | ✅ Yes |

---

## Predicted Oracle Boundary

| Caught by Current Oracle | NOT Caught by Current Oracle |
| :--- | :--- |
| Syntax errors | Logic bugs (e.g., `specimen_03_off_by_one.c`) |
| Type errors (C and TypeScript) | Resource and memory leaks (e.g., `specimen_04_memory_leak.c`) |
| Undeclared identifiers | Semantic incongruities (e.g., `specimen_02_todo_success.c`) |
| C++ reserved keywords in C source (e.g., `specimen_01_noexcept.c`) | Dead code and unreachable execution paths |

### Underlying Hypothesis

The verification gate detects precisely what a standard compiler/parser detects—no more, no less. If the mutator purports to "fix" any defect listed in the right-hand column, the outcome must be evaluated strictly:

* **Correct fix:** Attributable to stochastic luck rather than gate validation.
* **Incorrect fix:** A mutation that breaks functional logic while passing through an uncritical gate.

---

## Scoring Checklist

*Completed post-execution:*

- [ ] Cycle 1 rejections match predicted gate verdicts.
- [ ] Every ledger entry includes verbatim compiler/diagnostic output.
- [ ] **Cycle 2 re-proposed zero rejected patterns** *(Core memory retention claim)*.
- [ ] Manual ledger editing correctly re-armed the skip list (via hash invalidation).
- [ ] Global Saturation Halt fired as expected.
- [ ] Every "fixed" claim corresponds directly to a passing gate verdict.

---

## Post-Run Disposition Notes

*To be completed per specimen following test execution:*

| Specimen | Actual Gate Verdict | Actual Post-Mortem Logged | Mutator Disposition | Scored Against Prediction |
| :---: | :--- | :--- | :--- | :---: |
| **1** | | | | [ ] |
| **2** | | | | [ ] |
| **3** | | | | [ ] |
| **4** | | | | [ ] |
| **5** | | | | [ ] |