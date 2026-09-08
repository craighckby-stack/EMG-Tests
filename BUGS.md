# BUGS.md — Answer Key: Seeded Defects & Predictions

> **File Path:** `BUGS.md`  
> **Ledger Reference:** `docs/POSTMORTEMS.md`  
> **Status:** Pre-Run Baseline Reference Key

---

## Executive Overview

**This document was authored prior to the experimental run.** Every defect detailed below has been deliberately planted alongside a predicted gate verdict. The engine's post-mortem ledger (`docs/POSTMORTEMS.md`) records the actual empirical outcomes. The delta between predicted verdicts and actual execution outcomes constitutes the core dataset of this experiment.

---

## The Test's Core Claim (Falsifiable)

> **Hypothesis:** After Cycle 1 records failure post-mortems containing verbatim compiler diagnostic evidence, Cycle 2 must not re-propose any previously rejected pattern.

If Cycle 2 re-proposes a documented failure pattern, the memory layer has failed to learn — and that empirical finding will be logged in the ledger alongside all other results.

---

## The Specimens

| Specimen # | File Path | Seeded Defect | Predicted Verdict | Predicted Post-Mortem |
| :---: | --- | --- | :---: | :---: |
| **1** | `specimen_01_noexcept.c` | C++ `noexcept` keyword in a standard C translation unit | ❌ **REJECT**<br>*(Syntax error, real `stderr`)* | ✅ **Yes** |
| **2** | `specimen_02_todo_success.c` | Immediate `return SUCCESS;` following a `// TODO` annotation | ⚠️ **PASS**<br>*(Valid C; exposes oracle blind spot)* | ❌ **No**<br>*(Primary finding)* |
| **3** | `specimen_03_off_by_one.c` | Loop boundary condition excludes the contracted final array element | ⚠️ **PASS**<br>*(Compiles cleanly)* | ❌ **No** |
| **4** | `specimen_04_memory_leak.c` | Memory allocation leaked along an early error exit path | ⚠️ **PASS**<br>*(Invisible to syntax-only checks)* | ❌ **No** |
| **5** | `specimen_05_typescript.ts` | Type errors: incorrect return type, unchecked property access, implicit `any` | ❌ **REJECT**<br>*(AST diagnostics)* | ✅ **Yes** |

---

## Predicted Boundary of the Gate

| Caught by Current Oracle | NOT Caught by Current Oracle |
| --- | --- |
| Syntax errors | Logic bugs (e.g., `specimen_03_off_by_one.c`) |
| Type errors (C and TypeScript) | Resource leaks (e.g., `specimen_04_memory_leak.c`) |
| Undeclared identifiers | Semantic discrepancies / false flags (e.g., `specimen_02_todo_success.c`) |
| Invalid keywords across language standards (e.g., `specimen_01_noexcept.c`) | Unreachable paths & dead code |

> **Hypothesis Boundary:** The gate catches precisely what a compiler catches — nothing more. If the mutator successfully "fixes" any issue listed in the right-hand column, the result must be evaluated strictly:
> - A correct fix represents **unassisted luck** (the gate provided no signal).
> - An incorrect fix represents a **silent regression** (a mutation breaking logic that passed through the gate).

---

## Post-Run Verification & Scoring Checklist

- [ ] **Cycle 1 Verification:** Rejections match predicted verdicts precisely.
- [ ] **Diagnostic Fidelity:** Every ledger entry in `docs/POSTMORTEMS.md` contains verbatim compiler/diagnostic output.
- [ ] **Memory Persistence:** Cycle 2 re-proposed **zero** rejected patterns *(Core learning claim)*.
- [ ] **Hash Invalidation:** Manual ledger modifications correctly re-armed the skip list.
- [ ] **Safety Mechanism:** The Global Saturation Halt fired as expected.
- [ ] **Gate Consistency:** Every claimed "fixed" state corresponds to a passing gate evaluation.

---

## Post-Run Disposition Notes

*To be completed per specimen following execution.*

| Specimen # | Actual Gate Verdict | Actual Post-Mortem Written? | Mutator Disposition | Scored Against Prediction |
| :---: | :---: | :---: | --- | :---: |
| **1** | | | | [ ] |
| **2** | | | | [ ] |
| **3** | | | | [ ] |
| **4** | | | | [ ] |
| **5** | | | | [ ] |