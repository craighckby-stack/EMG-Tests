# Neural Engine Post-Mortems

## Auto-Generated Lessons & Negative Constraints

### ❌ [2026-09-08] src/specimen_01_noexcept.c `source: mutation-cycle`
**Symptom:** Active Linter / Compiler Gate Rejection on LLM Output (Option B)
**EVIDENCE (Machine-Copied Fact):**
```
<source>:7:2: error: invalid preprocessing directive #stdint_h_guard
    7 | #stdint_h_guard
      |  ^~~~~~~~~~~~~~
```
**CONSTRAINT (Model Generalization):** Never repeat code patterns that produce this compiler/linter error on src/specimen_01_noexcept.c.
