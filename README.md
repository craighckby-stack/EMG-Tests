# EMG-Tests — Self-Halting Proof

**Validation lab for [EMG Core](https://github.com/craighckby-stack/EMG): five seeded defects with known diagnoses. The engine must catch what a compiler can catch, learn from what it rejects, and stop when there is nothing left to do.**

![Status](https://img.shields.io/badge/status-experimental-orange)
![Type](https://img.shields.io/badge/type-validation%20lab-blue)
![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-lightgrey)

---

## The Proof Being Claimed

| # | Claim | Falsified if... |
| :---: | --- | --- |
| **1** | **REJECT** — Dialect corruption and type errors fail the gate, accompanied by real compiler `stderr` diagnostics. | Any seeded defect passes that should fail. |
| **2** | **LEARN** — Cycle 2 re-proposes zero previously rejected patterns. | The engine repeats a documented failure pattern. |
| **3** | **REMEMBER** — Editing the post-mortem ledger re-arms the engine. | Hash invalidation fails to clear the skip list. |
| **4** | **STOP** — Saturation reached $\rightarrow$ Global Halt fires automatically. | The mutation/validation loop continues past its defined finish line. |

> **Key Takeaway:** A tool that cannot stop is not autonomous. This repository provides concrete evidence that EMG Core is self-halting and deterministic.

---

## Methodology

This test suite follows the same strict evidence rules as the engine it evaluates:

- **Predictions are written prior to execution** ([`BUGS.md`](BUGS.md)) — every defect is documented alongside its expected gate verdict.
- **Reality is recorded live during execution** ([`docs/POSTMORTEMS.md`](docs/POSTMORTEMS.md)) — captured using verbatim compiler and diagnostic output only (no paraphrasing or self-reported success).
- **The experiment is the diff between the two.**

No claim in this repository is accepted without external, verifiable evidence. That standard applies strictly to the engine under test as well as to the test suite itself.

---

## The Specimens

| Specimen | Defect Class | Predicted Gate Verdict |
| --- | --- | --- |
| [`specimen_01_noexcept.c`](src/specimen_01_noexcept.c) | C++ keyword injected into C — dialect corruption | ❌ Reject (compilation error) |
| [`specimen_02_todo_success.c`](src/specimen_02_todo_success.c) | Success status returned from an unimplemented operation | ⚠️ Expected **Pass** — documents oracle limit |
| [`specimen_03_off_by_one.c`](src/specimen_03_off_by_one.c) | Logic bug — boundary error invisible to syntax checkers | ⚠️ Expected **Pass** |
| [`specimen_04_memory_leak.c`](src/specimen_04_memory_leak.c) | Resource leak — invisible to static syntax-only checks | ⚠️ Expected **Pass** |
| [`specimen_05_typescript.ts`](src/specimen_05_typescript.ts) | Type errors — caught during AST gate parsing | ❌ Reject (type diagnostics) |

*Note: Specimens 2–4 are intentionally positioned to map the boundary of machine verification: identifying defects a compiler cannot see is as crucial as catching those it can.*

---

## Repository Structure

```text
EMG-Tests/
├── README.md                  ← Master overview & system documentation
├── BUGS.md                    ← Answer key: seeded defects + predictions
├── LICENSE.md                 ← License details (CC BY-NC-SA 4.0)
├── docs/
│   └── POSTMORTEMS.md         ← Evidence ledger (empty at start; populated by engine)
└── src/
    ├── specimen_01_noexcept.c
    ├── specimen_02_todo_success.c
    ├── specimen_03_off_by_one.c
    ├── specimen_04_memory_leak.c
    └── specimen_05_typescript.ts
```

---

## Run Protocol

| Step | Action | Verifies |
| :---: | --- | --- |
| **1** | Execute EMG Core against this repository (Cycle 1). | Gate verdicts vs. baseline predictions |
| **2** | Halt execution and inspect the post-mortem ledger. | Evidence quality: verbatim `stderr` outputs |
| **3** | Execute Cycle 2. | **Learning capability** — zero re-proposed failures |
| **4** | Manually modify the ledger (append any line). | Hash invalidation re-arming the skip list |
| **5** | Resume execution to completion. | Global Saturation Halt triggering |
| **6** | Score [`BUGS.md`](BUGS.md) checklist against actual execution. | The diff represents the experiment findings |

Every outcome is informative—including any failure of the engine's core claims—and is documented with equal rigor.

---

## Related Projects

- **[EMG Core](https://github.com/craighckby-stack/EMG)** — The underlying engine under test.
- **[PKM](https://github.com/craighckby-stack/PKM)** — Origin project whose post-mortem ledger inspired this evidence system.

---

## BUGS.md — Answer Key: Seeded Defects & Predictions

**This section serves as the pre-run answer key.** Every defect detailed below is deliberately planted alongside its predicted gate verdict. The engine's ledger (`docs/POSTMORTEMS.md`) records actual execution output. The diff between prediction and reality forms the core experiment.

### The Test's Core Claim (Falsifiable)

> After Cycle 1 writes failure post-mortems with verbatim compiler evidence, Cycle 2 must not re-propose any previously rejected pattern.

If Cycle 2 repeats a documented failure, the memory layer has failed to learn—and that finding will be recorded here alongside all other results.

### Predictions Table

| # | File | Defect | Predicted Verdict | Predicted Post-Mortem? |
| :---: | --- | --- | --- | :---: |
| **1** | `specimen_01_noexcept.c` | C++ `noexcept` keyword inside a C translation unit | ❌ REJECT — syntax error, real `stderr` | ✅ Yes |
| **2** | `specimen_02_todo_success.c` | `return SUCCESS` immediately following a TODO | ⚠️ **PASS** — valid C; highlights oracle blind spot | ❌ No — **Key Finding** |
| **3** | `specimen_03_off_by_one.c` | Loop boundary excludes contracted final element | ⚠️ **PASS** — compiles cleanly | ❌ No |
| **4** | `specimen_04_memory_leak.c` | Allocation leak along error path | ⚠️ **PASS** — invisible to syntax checks | ❌ No |
| **5** | `specimen_05_typescript.ts` | Type errors: wrong return type, unchecked access, implicit `any` | ❌ REJECT — AST diagnostics | ✅ Yes |

### Predicted Boundary of the Gate

| Caught by Current Oracle | NOT Caught by Current Oracle |
| --- | --- |
| Syntax errors | Logic bugs (`specimen_03`) |
| Type errors (C & TypeScript) | Resource leaks (`specimen_04`) |
| Undeclared identifiers | Semantic flaws / fake implementations (`specimen_02`) |
| C++ keywords in C source files (`specimen_01`) | Dead code / unreachable execution paths |

**Hypothesis:** The gate catches exactly what a compiler or language server catches—no more, no less. If the mutator "fixes" an issue in the right-hand column, it must be evaluated objectively: a correct fix represents luck unassisted by the gate; an incorrect fix represents a mutation breaking code that passed gate checks.

### Scoring Checklist (To Be Completed Post-Run)

- [ ] Cycle 1 rejections match predictions.
- [ ] Every ledger entry contains verbatim compiler/diagnostic output.
- [ ] **Cycle 2 re-proposed zero rejected patterns** *(The core learning claim)*.
- [ ] Manual ledger edit successfully re-armed the skip list via hash invalidation.
- [ ] Global Saturation Halt fired as expected.
- [ ] Every "fixed" claim corresponds to a passing gate result.

### Disposition Notes (Post-Run Template)

| Specimen | Gate Verdict (Actual) | Post-Mortem Written (Actual) | Mutator Disposition | Scored Against Prediction |
| :---: | --- | --- | --- | :---: |
| **1** | | | | ☐ |
| **2** | | | | ☐ |
| **3** | | | | ☐ |
| **4** | | | | ☐ |
| **5** | | | | ☐ |

---

## License

This work is licensed under the **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License (CC BY-NC-SA 4.0)**.

Copyright (c) 2026 Craighckby

### You are free to:

- **Share** — Copy and redistribute the material in any medium or format.
- **Adapt** — Remix, transform, and build upon the material.

### Under the following terms:

- **Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made.
- **NonCommercial** — You may not use the material for commercial purposes without prior permission.
- **ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license.
- **No Additional Restrictions** — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.

### Reference Links

- Full legal code: [https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
- Human-readable summary: [https://creativecommons.org/licenses/by-nc-sa/4.0/](https://creativecommons.org/licenses/by-nc-sa/4.0/)