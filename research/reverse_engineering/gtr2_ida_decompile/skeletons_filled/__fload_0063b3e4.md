## __fload_0063b3e4 — CRT _fload: normalize special-encoded FP operand

**Summary:** MSVC CRT transcendental support helper: loads/validates a double operand, passing ordinary values through unchanged and re-encoding values whose exponent field is 0x7FF0 (the CRT's internal unnormal/extended form) by shifting the bit image right 21 positions to rebuild the normalized double. Used by __ctrandisp1/__ctrandisp2 before dispatching FPU operations.

**Called by:** __ctrandisp2 (0063b21b), __ctrandisp1 (0063b3b1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `(HIWORD(a1) & 0x7FF0) != 0x7FF0`. PASSES unchanged (returns `a1` as-is) when the exponent field is any normal/small value. When the exponent field equals exactly 0x7FF0, the value is treated as CRT-internal special encoding and the function rebuilds it: high dword of the result = low 32 bits of `bits(a1) >> 21` (original bits 21..52, carrying the exponent), low dword = original low 32 bits of `a1` — then returns that reconstructed double.
