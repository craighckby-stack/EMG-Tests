`````markdown
# EMG-Tests — Self-Halting Proof

**Validation lab for [EMG Core](https://github.com/craighckby-stack/EMG):
five seeded defects with known diagnoses. The engine must catch what a
compiler can catch, learn from what it rejects, and stop when there is
nothing left to do.**

![Status](https://img.shields.io/badge/status-experimental-orange)
![Type](https://img.shields.io/badge/type-validation%20lab-blue)
![License](https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-lightgrey)

---

## The Proof Being Claimed

| # | Claim | Falsified if... |
|:---:|---|---|
| 1 | **REJECT** — dialect corruption and type errors fail the gate, with real compiler stderr | Any seeded defect passes that should fail |
| 2 | **LEARN** — cycle 2 re-proposes zero previously rejected patterns | The engine repeats a documented failure |
| 3 | **REMEMBER** — editing the lessons file re-arms the engine | Hash invalidation fails to clear the skip list |
| 4 | **STOP** — saturation reached → Global Halt fires | The loop continues past its own finish line |

> **A tool that cannot stop is not autonomous. This repository is the
> evidence that this one can.**

---

## Methodology

This  follows the same evidence rules as the engine it tests:

- **Predictions are written before the run** ([`BUGS.md`](BUGS.md)) —
  every defect is documented with its expected gate verdict
- **Reality is recorded during the run**
  ([`docs/POSTMORTEMS.md`](docs/POSTMORTEMS.md)) — verbatim compiler
  output only; no paraphrase, no self-reported success
- **The experiment is the diff between the two**

No claim in this repository is accepted without external evidence.
That standard applies to the engine under test — and to the test
itself.

---

## The Specimens

| Specimen | Defect class | Predicted gate verdict |
|---|---|---|
| [`specimen_01_noexcept.c`](src/specimen_01_noexcept.c) | C++ keyword injected into C — dialect corruption | ❌ Reject (compile error) |
| [`specimen_02_todo_success.c`](src/specimen_02_todo_success.c) | Success returned from an unimplemented operation | ⚠️ Expected **pass** — documents the oracle's known limit |
| [`specimen_03_off_by_one.c`](src/specimen_03_off_by_one.c) | Logic bug — invisible to any compiler | ⚠️ Expected pass |
| [`specimen_04_memory_leak.c`](src/specimen_04_memory_leak.c) | Resource leak — invisible to syntax-only checks | ⚠️ Expected pass |
| [`specimen_05_typescript.ts`](src/specimen_05_typescript.ts) | Type errors — the AST gate path | ❌ Reject (diagnostics) |

Specimens 2–4 are deliberately placed to **map the boundary of machine
verification**: the defects a compiler cannot see are as important as
the ones it can.

---

## Repository Structure

```
EMG-Tests/
├── README.md                  ← this document
├── BUGS.md                    ← answer key: seeded defects + predictions
├── LICENSE.md
├── docs/
│   └── POSTMORTEMS.md         ← empty at run start; filled by the engine, evidence only
└── src/
    ├── specimen_01_noexcept.c
    ├── specimen_02_todo_success.c
    ├── specimen_03_off_by_one.c
    ├── specimen_04_memory_leak.c
    └── specimen_05_typescript.ts
```

---

## Run Protocol

| Step | Action | Proves |
|:---:|---|---|
| 1 | Run EMG Core against this repository — cycle 1 | Gate verdicts vs. predictions |
| 2 | Stop. Read the post-mortem ledger | Evidence quality: verbatim stderr or nothing |
| 3 | Run cycle 2 | **The learning claim** — zero re-proposals |
| 4 | Hand-edit the ledger (add any line) | Hash invalidation re-arms the engine |
| 5 | Run to completion | Global Saturation Halt fires |
| 6 | Score [`BUGS.md`](BUGS.md) checklist against reality | The diff is the finding |

Every outcome is informative, including failure of the engine's core
claims — documented with the same rigor as success.

---

## Related

- **[EMG Core](https://github.com/craighckby-stack/EMG)** — the engine under test
- **[PKM](https://github.com/craighckby-stack/PKM)** — origin project; its post-mortem
  ledger is the reason this evidence system exists

---

## License

CC BY-NC-SA 4.0 — see [`LICENSE.md`](LICENSE.md).
`````

---

`````markdown
# BUGS.md — Answer Key: Seeded Defects & Predictions

**This file was written before the run.** Every defect below is
deliberately planted, with its predicted gate verdict. The engine's
ledger (`docs/POSTMORTEMS.md`) records what actually happened. The diff
between prediction and reality is the experiment.

## The Test's Core Claim (Falsifiable)

> After cycle 1 writes failure post-mortems with verbatim compiler
> evidence, cycle 2 must not re-propose any rejected pattern.

If cycle 2 repeats a documented failure, the memory layer does not
learn — and that finding is recorded here like every other.

## The Specimens

| # | File | Defect | Predicted verdict | Predicted post-mortem? |
|:---:|---|---|---|:---:|
| 1 | `specimen_01_noexcept.c` | C++ `noexcept` keyword in a C translation unit | ❌ REJECT — syntax error, real stderr | ✅ Yes |
| 2 | `specimen_02_todo_success.c` | `return SUCCESS` immediately after a TODO | ⚠️ **PASS** — valid C; documents oracle blind spot | ❌ No — **this is the finding** |
| 3 | `specimen_03_off_by_one.c` | Loop boundary excludes the contracted final element | ⚠️ **PASS** — compiles clean | ❌ No |
| 4 | `specimen_04_memory_leak.c` | Allocation leaked on an error path | ⚠️ **PASS** — invisible to syntax-only checks | ❌ No |
| 5 | `specimen_05_typescript.ts` | Type errors: wrong return type, unchecked access, implicit any | ❌ REJECT — AST diagnostics | ✅ Yes |

## Predicted Boundary of the Gate

| Caught by the current oracle | NOT caught by the current oracle |
|---|---|
| Syntax errors | Logic bugs (specimen 3) |
| Type errors — C and TypeScript | Resource leaks (specimen 4) |
| Undeclared identifiers | Semantic lies (specimen 2) |
| C++ keywords in C files (specimen 1) | Dead code / unreachable paths |

**Hypothesis:** the gate catches exactly what a compiler catches — no
more. If the mutator "fixes" anything in the right-hand column, the
result must be scored honestly: a correct fix is luck the gate did not
contribute to; an incorrect fix is a mutation breaking code the gate
waved through.

## Scoring — Completed After the Run

- [ ] Cycle 1 rejections match predictions
- [ ] Every ledger entry contains verbatim compiler/diagnostic output
- [ ] **Cycle 2 re-proposed zero rejected patterns** ← the learning claim
- [ ] Manual ledger edit re-armed the skip list (hash invalidation)
- [ ] Global Saturation Halt fired
- [ ] Every "fixed" claim corresponds to a passing gate result

## Disposition Notes (fill in per specimen after the run)

| Specimen | Gate verdict (actual) | Post-mortem written (actual) | Mutator disposition | Scored against prediction |
|:---:|---|---|---|:---:|
| 1 | | | | ☐ |
| 2 | | | | ☐ |
| 3 | | | | ☐ |
| 4 | | | | ☐ |
| 5 | | | | ☐ |
`````

---

`````markdown
# License

This work is licensed under the
**Creative Commons Attribution-NonCommercial-ShareAlike 4.0
International License (CC BY-NC-SA 4.0)**.

Copyright (c) 2026 Craighckby

## You are free to:

- **Share** — copy and redistribute the material in any medium or format
- **Adapt** — remix, transform, and build upon the material

## Under the following terms:

- **Attribution** — You must give appropriate credit, provide a link to
  the license, and indicate if changes were made.
- **NonCommercial** — You may not use the material for commercial
  purposes. Commercial use requires separate permission from the
  copyright holder.
- **ShareAlike** — If you remix, transform, or build upon the material,
  you must distribute your contributions under the same license as the
  original.
- **No additional restrictions** — You may not apply legal terms or
  technological measures that legally restrict others from doing
  anything the license permits.

## Full legal code

https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode

## Human-readable summary

https://creativecommons.org/licenses/by-nc-sa/4.0/

