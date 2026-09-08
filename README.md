# EMG-Tests — Self-Halting Proof

**Validation laboratory for [EMG Core](https://github.com/craighckby-stack/EMG): A benchmark suite of five seeded defects with deterministic diagnoses. The engine must intercept errors detectable by compilers or AST analyzers, maintain memory of rejected mutation candidates, and halt autonomously upon state space saturation.**

[![Status](https://img.shields.io/badge/status-experimental-orange.svg)](https://github.com/craighckby-stack/EMG)
[![Type](https://img.shields.io/badge/type-validation%20lab-blue.svg)](https://github.com/craighckby-stack/EMG)
[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)

---

## 1. Core Falsification Claims

| Claim ID | Property | Invariant Under Test | Falsified If |
| :---: | :--- | :--- | :--- |
| **01** | **REJECT** | Dialect corruption and AST/type errors fail verification with verbatim compiler `stderr`. | Any invalid seeded defect passes the verification gate. |
| **02** | **LEARN** | Cycle 2 re-proposes zero previously rejected patterns. | The engine re-executes or repeats a documented failure pattern. |
| **03** | **REMEMBER** | Manual modifications to the post-mortem ledger invalidate hashes and re-arm the engine. | Hash invalidation fails to clear or update the skip list. |
| **04** | **STOP** | State space exhaustion triggers a deterministic **Global Saturation Halt**. | The mutation loop runs indefinitely or overshoots saturation. |

> **Autonomous Mandate:** A system that cannot deterministically halt is not truly autonomous. This repository provides reproducible empirical evidence that EMG Core adheres to strict convergence boundaries.

---

## 2. Experimental Methodology

This validation suite enforces the empirical evidence standards governing the engine under test:

- **Pre-Declared Predictions ([`BUGS.md`](BUGS.md)):** Every defect is cataloged prior to execution alongside its expected verification gate verdict.
- **Verbatim Evidence Ledger ([`docs/POSTMORTEMS.md`](docs/POSTMORTEMS.md)):** The engine records raw compiler `stderr` and diagnostic output—devoid of paraphrasing or unverified status claims.
- **Differential Verification:** Scientific validity is evaluated strictly as the differential between pre-run predictions and runtime reality.

No operational claim is accepted without reproducible external evidence.

---

## 3. Seeded Specimens

| Specimen | Defect Classification | Predicted Gate Verdict | Target Oracle Path |
| :--- | :--- | :---: | :--- |
| [`specimen_01_noexcept.c`](src/specimen_01_noexcept.c) | C++ keyword injected into C compilation unit (dialect corruption) | ❌ **REJECT** | C Compiler Frontend (`gcc`/`clang`) |
| [`specimen_02_todo_success.c`](src/specimen_02_todo_success.c) | `return SUCCESS` executed immediately following an unimplemented `TODO` | ⚠️ **PASS** | Oracle Boundary Limit (Semantic False Positive) |
| [`specimen_03_off_by_one.c`](src/specimen_03_off_by_one.c) | Loop boundary condition excludes the contracted terminal element | ⚠️ **PASS** | Oracle Boundary Limit (Logical Defect) |
| [`specimen_04_memory_leak.c`](src/specimen_04_memory_leak.c) | Dynamic memory allocation leaked along an early error exit branch | ⚠️ **PASS** | Oracle Boundary Limit (Syntax-Compliant Leak) |
| [`specimen_05_typescript.ts`](src/specimen_05_typescript.ts) | Return type mismatch, unchecked property access, and implicit `any` | ❌ **REJECT** | TypeScript AST Typechecker (`tsc`) |

> **Boundary Mapping:** Specimens 2–4 deliberately delineate the **limits of syntactic machine verification**: identifying defects that compilers cannot catch is as vital as validating the ones they can.

---

## 4. Repository Layout

```text
EMG-Tests/
├── README.md                      # Comprehensive laboratory specification (this document)
├── BUGS.md                        # Pre-registered answer key and prediction matrix
├── LICENSE.md                     # Legal code and usage terms (CC BY-NC-SA 4.0)
├── docs/
│   └── POSTMORTEMS.md             # Empty at init; populated with verbatim runtime evidence
└── src/
    ├── specimen_01_noexcept.c     # Dialect corruption test case
    ├── specimen_02_todo_success.c # Semantic stub test case
    ├── specimen_03_off_by_one.c   # Logic boundary test case
    ├── specimen_04_memory_leak.c  # Unchecked allocation path test case
    └── specimen_05_typescript.ts  # Type-system diagnostics test case
```

---

## 5. Execution Protocol

```text
+-----------------------------------------------------------------------------+
|                          EXECUTION RUN PROTOCOL                             |
+-----------------------------------------------------------------------------+
| [Step 1: Cycle 1 Run]   --> Execute EMG Core against specimen suite         |
| [Step 2: Ledger Audit]  --> Verify docs/POSTMORTEMS.md contains raw stderr  |
| [Step 3: Cycle 2 Run]   --> Confirm zero re-proposals (Learning Invariant)   |
| [Step 4: Invalidation] --> Append manual edit to ledger; verify re-arm     |
| [Step 5: Saturation]    --> Run to completion; verify Global Halt execution |
| [Step 6: Diff Scoring]  --> Compare BUGS.md prediction matrix against output|
+-----------------------------------------------------------------------------+
```

| Step | Operation | Verification Target |
| :---: | :--- | :--- |
| **1** | Run EMG Core against the repository (Cycle 1). | Measure empirical gate verdicts against pre-declared predictions. |
| **2** | Halt and audit the post-mortem ledger. | Verify proof quality: verbatim `stderr` capture with zero lossy summarizing. |
| **3** | Initiate Cycle 2 mutation sweep. | **The Learning Invariant:** Validate zero re-proposals of rejected patterns. |
| **4** | Manually mutate the ledger (append arbitrary string). | Verify hash invalidation re-arms the skip list appropriately. |
| **5** | Run optimizer to full convergence. | Validate that the **Global Saturation Halt** fires as expected. |
| **6** | Score [`BUGS.md`](BUGS.md) against experimental logs. | Measure overall accuracy and isolate boundary anomalies. |

---

## 6. Oracle Capabilities & Boundary Limits

```text
+------------------------------------+------------------------------------+
|  INTERCEPTED BY SYNTAX/AST GATES   |     OUTSIDE THE CURRENT ORACLE     |
+------------------------------------+------------------------------------+
| * Syntax & dialect errors (Spec 1) | * Off-by-one logic flaws (Spec 3)  |
| * Type violations (Spec 5)         | * Resource & memory leaks (Spec 4) |
| * Undeclared identifiers / symbols | * Semantic placebos (Spec 2)       |
| * Ill-formed AST structures        | * Dead code & unreachable branches |
+------------------------------------+------------------------------------+
```

**Scientific Hypothesis:** The gate catches exclusively what deterministic compilers and AST checkers verify. If the engine alters or "repairs" any code in the right-hand column, scoring must be evaluated critically: unverified changes that compile cleanly are unproven mutations, not gate-assisted proofs.

---

## 7. Verification Scorecard

### Pre-Flight Invariant Checklist

- [ ] **Cycle 1 Fidelity:** Rejections match predicted compiler and diagnostic verdicts.
- [ ] **Evidence Integrity:** Every entry in `POSTMORTEMS.md` contains raw compiler/diagnostic logs.
- [ ] **Cycle 2 Memory Retention:** Zero re-proposals of rejected candidates (Learning Invariant).
- [ ] **Skip List Invalidation:** Manual ledger mutation successfully triggers cache reset.
- [ ] **Halting Bound:** Deterministic Global Saturation Halt terminates execution cleanly.
- [ ] **Soundness:** Every applied modification passes gate validation without regression.

### Specimen Disposition Log

| Specimen | Actual Gate Verdict | Post-Mortem Generated | Mutator Disposition | Scored Against Prediction |
| :---: | :---: | :---: | :---: | :---: |
| `specimen_01_noexcept.c` | _Pending Run_ | _Pending Run_ | _Pending Run_ | [ ] |
| `specimen_02_todo_success.c` | _Pending Run_ | _Pending Run_ | _Pending Run_ | [ ] |
| `specimen_03_off_by_one.c` | _Pending Run_ | _Pending Run_ | _Pending Run_ | [ ] |
| `specimen_04_memory_leak.c` | _Pending Run_ | _Pending Run_ | _Pending Run_ | [ ] |
| `specimen_05_typescript.ts` | _Pending Run_ | _Pending Run_ | _Pending Run_ | [ ] |

---

## 8. Related Projects

- **[EMG Core](https://github.com/craighckby-stack/EMG):** The autonomous neural-guided optimization engine under evaluation.
- **[PKM](https://github.com/craighckby-stack/PKM):** Upstream architectural origin; the foundational basis for the post-mortem ledger protocol.

---

## 9. License and Distribution

This project is licensed under the **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License (CC BY-NC-SA 4.0)**.

```text
Copyright (c) 2026 Craighckby
```

### Summary of Rights and Conditions

- **Share:** Copy and redistribute the material in any medium or format.
- **Adapt:** Remix, transform, and build upon the material.
- **Attribution:** Provide appropriate credit, include a link to the license, and declare if changes were made.
- **NonCommercial:** You may not use the material for commercial purposes without explicit permission.
- **ShareAlike:** Distributed derivatives must carry identical license terms.
- **No Additional Restrictions:** No legal or technical constraints may be applied that restrict rights granted under the license.

For complete terms, consult the [CC BY-NC-SA 4.0 Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode) or the [Human-Readable Summary](https://creativecommons.org/licenses/by-nc-sa/4.0/).