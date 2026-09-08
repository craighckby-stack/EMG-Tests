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

### ❌ [2026-09-08] src/specimen_02_todo_success.c `source: mutation-cycle`
**Symptom:** Active Linter / Compiler Gate Rejection on LLM Output (Option B)
**EVIDENCE (Machine-Copied Fact):**
```
<source>: In function 'wp_set_permanent':
<source>:44:19: error: 'NULL' undeclared (first use in this function)
   44 |     if (target == NULL) {
      |                   ^~~~
<source>:12:1: note: 'NULL' is defined in header '<stddef.h>'; did you forget to '#include <stddef.h>'?
   11 | #include <stdbool.h>
  +++ |+#include <stddef.h>
   12 | 
<source>:44:19: note: each undeclared identifier is reported only once for each function it appears in
   44 |     if (target == NULL) {
      |                   ^~~~
```
**CONSTRAINT (Model Generalization):** Never repeat code patterns that produce this compiler/linter error on src/specimen_02_todo_success.c.
