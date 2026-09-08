# BUGS.md — Answer Key: Seeded Defects & Predictions

> **File Path:** `BUGS.md`  
> **Ledger Reference:** `docs/POSTMORTEMS.md`  
> **Status:** Pre-Run Baseline Reference Key

---

## Executive Overview

This document was authored prior to the experimental run. Every defect detailed below has been deliberately introduced alongside an expected gate verdict. The post-mortem ledger (`docs/POSTMORTEMS.md`) records empirical outcomes during execution. The difference between predicted verdicts and observed execution outcomes provides the core evaluation dataset for this experiment.

---

## Core Falsifiable Hypothesis

> **Hypothesis:** After Cycle 1 records failure post-mortems containing verbatim compiler diagnostic evidence, Cycle 2 must not re-propose any previously rejected pattern.

If Cycle 2 re-proposes a documented failure pattern, the memory layer has failed to retain the constraint. That outcome is logged directly in the ledger alongside all other empirical execution results.

---

## Seeded Specimens

| Specimen # | File Path | Seeded Defect | Predicted Verdict | Predicted Post-Mortem |
| :---: | :--- | :--- | :---: | :---: |
| **1** | `specimen_01_noexcept.c` | C++ `noexcept` keyword in a standard C translation unit | ❌ **REJECT**<br>*(Syntax error, stderr captured)* | ✅ **Yes** |
| **2** | `specimen_02_todo_success.c` | Immediate `return SUCCESS;` following a `// TODO` annotation | ⚠️ **PASS**<br>*(Valid C; exposes oracle blind spot)* | ❌ **No**<br>*(Primary baseline finding)* |
| **3** | `specimen_03_off_by_one.c` | Loop boundary condition excludes the contracted final array element | ⚠️ **PASS**<br>*(Compiles without diagnostic errors)* | ❌ **No** |
| **4** | `specimen_04_memory_leak.c` | Memory allocation leaked along an early error exit path | ⚠️ **PASS**<br>*(Invisible to syntax-only checks)* | ❌ **No** |
| **5** | `specimen_05_typescript.ts` | Type errors: incorrect return type, unchecked property access, implicit `any` | ❌ **REJECT**<br>*(AST and type-checker diagnostics)* | ✅ **Yes** |

---

## Predicted Oracle Boundary

| Caught by Current Oracle | Not Caught by Current Oracle |
| :--- | :--- |
| Syntax errors | Logic bugs (e.g., `specimen_03_off_by_one.c`) |
| Type errors (C and TypeScript) | Resource leaks (e.g., `specimen_04_memory_leak.c`) |
| Undeclared identifiers | Semantic discrepancies and false flags (e.g., `specimen_02_todo_success.c`) |
| Invalid keywords across language standards (e.g., `specimen_01_noexcept.c`) | Unreachable paths and dead code |

> **Hypothesis Boundary:** The gate detects issues surfaced by static compiler and type diagnostics. If the mutator alters any issue listed in the right-hand column, the result must be evaluated strictly:
> - A valid modification represents **unassisted change** (the gate provided no diagnostic signal).
> - An invalid modification represents a **silent regression** (a logic error that bypasses the gate).

---

## Post-Run Verification & Scoring Checklist

- [ ] **Cycle 1 Verification:** Observed rejections match predicted verdicts.
- [ ] **Diagnostic Fidelity:** Every ledger entry in `docs/POSTMORTEMS.md` contains verbatim compiler diagnostic output.
- [ ] **Memory Persistence:** Cycle 2 re-proposes zero previously rejected patterns *(Core learning criterion)*.
- [ ] **Hash Invalidation:** Manual ledger modifications correctly re-arm the skip list.
- [ ] **Safety Mechanism:** The Global Saturation Halt triggers as configured.
- [ ] **Gate Consistency:** Every passing evaluation corresponds to a valid build state.

---

## Post-Run Disposition Notes

*To be completed per specimen following execution.*

| Specimen # | Actual Gate Verdict | Actual Post-Mortem Written? | Mutator Disposition | Scored Against Prediction |
| :---: | :---: | :---: | :--- | :---: |
| **1** | | | | [ ] |
| **2** | | | | [ ] |
| **3** | | | | [ ] |
| **4** | | | | [ ] |
| **5** | | | | [ ] |