

### ❌ [2026-09-08] src/specimen_01_noexcept.c `source: oracle-harness`
**Symptom:** Direct Oracle Stress Injection (Option A Unit Test)
**EVIDENCE (Machine-Copied Fact):**
```
<source>: In function 'buffer_reset':
<source>:6:68: error: expected declaration specifiers before 'noexcept'
    6 | static inline void buffer_reset(volatile uint8_t *buf, size_t len) noexcept
      |                                                                    ^~~~~~~~
<source>:12: error: expected '{' at end of input
<source>:6:51: warning: unused parameter 'buf' [-Wunused-parameter]
    6 | static inline void buffer_reset(volatile uint8_t *buf, size_t len) noexcept
      |                                 ~~~~~~~~~~~~~~~~~~^~~
<source>:6:63: warning: unused parameter 'len' [-Wunused-parameter]
    6 | static inline void buffer_reset(volatile uint8_t *buf, size_t len) noexcept
      |                                                        ~~~~~~~^~~
```
**CONSTRAINT (Model Generalization):** Do NOT emit C++ keywords (e.g. noexcept, constexpr) in pure C translation units.
