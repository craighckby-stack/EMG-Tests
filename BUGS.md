# BUGS.md — Answer Key: Seeded Defects & Predictions

**This file was written before the run.** Every defect below is deliberately planted, with its predicted gate verdict. The engine's ledger (`docs/POSTMORTEMS.md`) records what actually happened. The diff between prediction and reality is the experiment.

## The Test's Core Claim (Falsifiable)

> After cycle 1 writes failure post-mortems with verbatim compiler evidence, cycle 2 must not re-propose any rejected pattern.

If cycle 2 repeats a documented failure, the memory layer does not learn — and that finding is recorded here like every other.

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

**Hypothesis:** the gate catches exactly what a compiler catches — no more. If the mutator "fixes" anything in the right-hand column, the result must be scored honestly: a correct fix is luck the gate did not contribute to; an incorrect fix is a mutation breaking code the gate waved through.

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
