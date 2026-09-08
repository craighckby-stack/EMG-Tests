# EMG-Tests — Self-Halting Proof

> **Validation lab for [EMG Core](https://github.com/craighckby-stack/EMG)**: Five seeded defects with known diagnoses. The engine must catch what a compiler can catch, learn from what it rejects, and halt when system saturation is achieved.

[![Status](https://img.shields.io/badge/status-experimental-orange.svg)](https://github.com/craighckby-stack/EMG)
[![Type](https://img.shields.io/badge/type-validation%20lab-blue.svg)](https://github.com/craighckby-stack/EMG)
[![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-lightgrey.svg)](LICENSE.md)

---

## Claims & Falsification Criteria

| # | Core Claim | Falsification Condition (`Falsified if...`) |
| :---: | :--- | :--- |
| **1** | **REJECT** — Dialect corruption and type errors fail the gate with authentic compiler `stderr` output. | Any seeded defect passes that should fail. |
| **2** | **LEARN** — Cycle 2 re-proposes zero previously rejected patterns. | The engine repeats a documented failure pattern. |
| **3** | **REMEMBER** — Editing the post-mortem ledger re-arms the engine skip list via hash invalidation. | Hash invalidation fails to clear the skip list. |
| **4** | **STOP** — Saturation reached $\rightarrow$ Global Saturation Halt fires automatically. | The evaluation loop continues past its termination criteria. |

> **Crucial Axiom:** A tool that cannot stop is not autonomous. This repository provides concrete empirical evidence that EMG Core achieves self-halting verification.

---

## Verification Methodology

This validation lab follows the exact evidence rules as the engine it tests:

1. **Pre-Run Predictions** ([`BUGS.md`](BUGS.md)): Every defect is documented with its expected gate verdict prior to execution.
2. **Execution Ledger** ([`docs/POSTMORTEMS.md`](docs/POSTMORTEMS.md)): Recorded live during execution using verbatim compiler outputs—no paraphrasing or self-reported success.
3. **Empirical Evaluation**: The experiment is defined strictly by the diff between prediction and reality.

No claim in this repository is accepted without external, verifiable evidence. This standard applies equally to the engine under test and the evaluation suite itself.

---

## The Specimens

| Specimen File | Defect Class | Predicted Gate Verdict |
| :--- | :--- | :--- |
| [`src/specimen_01_noexcept.c`](src/specimen_01_noexcept.c) | C++ keyword injected into C — dialect corruption | ❌ **Reject** (Compile Error) |
| [`src/specimen_02_todo_success.c`](src/specimen_02_todo_success.c) | Success status returned from an unimplemented operation | ⚠️ **Expected Pass** (Documents oracle limit) |
| [`src/specimen_03_off_by_one.c`](src/specimen_03_off_by_one.c) | Logic boundary error — invisible to syntax checkers | ⚠️ **Expected Pass** |
| [`src/specimen_04_memory_leak.c`](src/specimen_04_memory_leak.c) | Resource leak — invisible to static syntax checks | ⚠️ **Expected Pass** |
| [`src/specimen_05_typescript.ts`](src/specimen_05_typescript.ts) | Type errors — target for the AST gate path | ❌ **Reject** (Diagnostics Failure) |

*Note: Specimens 2–4 are deliberately designed to **map the boundaries of machine verification**: identifying defects a compiler cannot detect is just as critical as identifying those it can.*

---

## Repository Structure

```text
EMG-Tests/
├── README.md                  # Main overview and verification claims
├── BUGS.md                    # Answer key: Seeded defects and predictions
├── LICENSE.md                 # CC BY-NC-SA 4.0 license terms
├── docs/
│   └── POSTMORTEMS.md         # Verbatim engine execution log (populated during run)
└── src/
    ├── specimen_01_noexcept.c
    ├── specimen_02_todo_success.c
    ├── specimen_03_off_by_one.c
    ├── specimen_04_memory_leak.c
    └── specimen_05_typescript.ts
```

---

## Run Protocol

| Step | Action | Verification Target |
| :---: | :--- | :--- |
| **1** | Execute EMG Core against this repository (Cycle 1). | Gate verdicts vs. baseline predictions in [`BUGS.md`](BUGS.md). |
| **2** | Inspect the generated post-mortem ledger (`docs/POSTMORTEMS.md`). | Ensure evidence contains verbatim `stderr` output. |
| **3** | Execute Cycle 2. | Verify the **learning claim**: zero re-proposals of rejected patterns. |
| **4** | Manually edit the ledger (modify any line). | Confirm hash invalidation re-arms the skip list. |
| **5** | Run execution to completion. | Verify that the Global Saturation Halt fires as expected. |
| **6** | Score [`BUGS.md`](BUGS.md) against experimental reality. | Analyze experimental diff and document findings. |

Every outcome is informative: failures in the engine's core claims are documented with the exact same rigor as successes.

---

## Related Projects

- **[EMG Core](https://github.com/craighckby-stack/EMG)** — The self-halting code optimization engine under test.
- **[PKM](https://github.com/craighckby-stack/PKM)** — Originating project whose post-mortem ledger design informed this evidence framework.

---

## License

This project is licensed under **CC BY-NC-SA 4.0**. See [`LICENSE.md`](LICENSE.md) for details.

---

# BUGS.md — Answer Key: Seeded Defects & Predictions

> **Note:** This file was authored before engine execution. Every defect detailed below was intentionally seeded alongside its predicted gate verdict. The actual execution ledger is logged at [`docs/POSTMORTEMS.md`](docs/POSTMORTEMS.md).

## Core Verification Claim (Falsifiable)

> After Cycle 1 writes failure post-mortems backed by verbatim compiler evidence, Cycle 2 must not re-propose any previously rejected mutation pattern.

If Cycle 2 repeats a documented failure, the memory layer has failed to learn—a outcome that will be recorded here with complete transparency.

## Specimen Matrix

| # | Specimen File | Defect Description | Predicted Verdict | Predicted Post-Mortem |
| :---: | :--- | :--- | :--- | :---: |
| **1** | `specimen_01_noexcept.c` | C++ `noexcept` keyword inside C translation unit | ❌ **REJECT** — Syntax error (`stderr`) | ✅ Yes |
| **2** | `specimen_02_todo_success.c` | Immediate `return SUCCESS` following `TODO` | ⚠️ **PASS** — Valid C (oracle blind spot) | ❌ No |
| **3** | `specimen_03_off_by_one.c` | Loop boundary condition excludes final array element | ⚠️ **PASS** — Compiles cleanly | ❌ No |
| **4** | `specimen_04_memory_leak.c` | Allocation leaked along error exit path | ⚠️ **PASS** — Invisible to syntax checks | ❌ No |
| **5** | `specimen_05_typescript.ts` | Type errors: invalid return type, unchecked access, implicit `any` | ❌ **REJECT** — AST diagnostic errors | ✅ Yes |

## Predicted Gate Boundaries

| Detected by Current Oracle | NOT Detected by Current Oracle |
| :--- | :--- |
| Syntax errors | Logic bugs (e.g., Specimen 3) |
| Type errors (C and TypeScript) | Resource leaks (e.g., Specimen 4) |
| Undeclared identifiers | Semantic inconsistencies (e.g., Specimen 2) |
| C++ keywords in C source files (Specimen 1) | Unreachable code / dead paths |

**Hypothesis:** The gate catches exactly what a compiler catches—no more and no less. If the mutator fixes an issue in the right-hand column, it must be evaluated objectively: a successful fix represents unguided luck rather than gate enforcement; an unsuccessful fix is a mutation that corrupted code passed by the gate.

## Post-Run Scoring Checklist

- [ ] Cycle 1 rejections strictly match predictions.
- [ ] Every ledger entry contains verbatim compiler/diagnostic output.
- [ ] **Cycle 2 re-proposed zero rejected patterns** (Learning Claim).
- [ ] Manual ledger modification successfully re-armed the skip list via hash invalidation.
- [ ] Global Saturation Halt fired automatically upon task completion.
- [ ] Every "fixed" status corresponds to a passing gate result.

## Disposition Ledger (Post-Run Evaluation)

| Specimen | Gate Verdict (Actual) | Post-Mortem Written (Actual) | Mutator Disposition | Scored Against Prediction |
| :---: | :---: | :---: | :---: | :---: |
| **1** | | | | [ ] |
| **2** | | | | [ ] |
| **3** | | | | [ ] |
| **4** | | | | [ ] |
| **5** | | | | [ ] |

---

# License

This work is licensed under the **Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License (CC BY-NC-SA 4.0)**.

Copyright (c) 2026 Craighckby

## Standard Permissions

- **Share** — Copy and redistribute the material in any medium or format.
- **Adapt** — Remix, transform, and build upon the material.

## License Terms

- **Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made.
- **NonCommercial** — You may not use the material for commercial purposes without explicit permission from the copyright holder.
- **ShareAlike** — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
- **No Additional Restrictions** — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.

## References

- **Full Legal Code:** [CC BY-NC-SA 4.0 Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
- **Human-Readable Summary:** [CC BY-NC-SA 4.0 Commons Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/)