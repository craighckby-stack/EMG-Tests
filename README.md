# EMG-Tests: Self-Halting & Verification Proof

An empirical test corpus evaluating closed-loop neural code mutation, 
external compiler/lint gates, negative-constraint memory ledgers, 
and automated self-halting.

---

## 🎯 Verified System Claims & Empirical Scorecard

| Headline Claim | Status | Machine Evidence / Artifact |
|:---|:---:|:---|
| **REJECT** (Compiler & Lint Gate) | **PROVEN** | Verbatim GCC `stderr` (e.g. `noexcept` keyword rejection, missing `<stddef.h>`) and active linter vetoes recorded with authentic diagnostic tags. |
| **LEARN** (Negative Constraints) | **PROVEN (Syntactic)** | Cycle 2 ingested `docs/POSTMORTEMS.md` constraints and produced zero re-proposals while preserving correct language semantics. |
| **REMEMBER** (Cryptographic Hash Invalidation) | **PROVEN** | `SHA-256` hash-chain tracking (`NONE → hash_a → hash_b`) triggered dynamic memory re-arming and skip-list invalidation. |
| **STOP** (Deterministic Saturation Halt) | **PROVEN** | `[GLOBAL SATURATION REACHED]` cleanly fired upon reaching zero-diff idempotency across all files. |
| **SEMANTIC FIDELITY** | **FRONTIER MAPPED** | Revealed that syntactic compiler gates select for disguised parameter checks (PM#7), establishing the boundary where AST verification ends and semantic contract oracles begin. |

---

## 🔬 Key Architectural Post-Mortems (The Findings)

* **PM#6 (The Evaluation Paradox):** Compiler gates test mutator *output*, not prompt *input*.
* **PM#7 (Semantic Attractors):** Syntactic verification pressure without a semantic oracle forces admitted fictions (TODOs) into disguised parameter validations (`wp_verify_locked_state`).
* **PM#8 (Bidirectional Documentation Honesty):** Verifiers must catch stale defect claims and leaked lab predictions, not just self-praise.
* **PM#9 (Apparatus Write-Protection):** Test fixtures and scorecards must be permanently write-protected against examinee wordsmithing.
