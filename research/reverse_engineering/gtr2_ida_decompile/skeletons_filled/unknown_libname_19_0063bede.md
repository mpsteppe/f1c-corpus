## unknown_libname_19_0063bede — CRT long-double reduction (FPREM) pre-check helper (variant)

**Summary:** MSVC CRT x87 math helper, structurally a sibling/variant of unknown_libname_17: checks the exponent class of a long-double operand via a lookup table and, for large-exponent finite operand pairs, reduces with either a scaled subtract loop or repeated `__FPREM__`; then reloads the x87 environment when DL flag bits are set and returns a fragment of the FPU status word.

**Called by:** SceneGraphQuery [structural] (0063c0e4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 009131cc | byte_9131CC | R | 16-entry class lookup table indexed by the operand's top exponent bits; nonzero entry allows the reduction path, zero skips it |
| 009131ec | dbl_9131EC | R | CRT x87-helper constant-pool double read by this routine; role not visible in the decompiled body |
| 009131fc | dbl_9131FC | R | Scale factor multiplied into the running subtrahend each iteration of the scaled subtract-loop reduction path |
| 00913204 | tbyte_913204 | R | CRT x87-helper constant-pool 10-byte (long double) constant referenced by this routine; role not visible in the decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Entry check: `((dword[a2+6] ^ 0x700) & 0x700) == 0` — reduction block entered only when bits 8..10 of that dword equal 0x700; otherwise skipped entirely.
- Table check: `byte_9131CC[(result >> 11) & 0xF] != 0`, else skip.
- Operand checks: a2 exponent field (`& 0x7FFF0000`) `!= 0x7FFF0000` (not inf/NaN); a5 exponent field nonzero and `!= 2147418112` (finite nonzero); `2*DWORD1(a5) == 0` and `2*DWORD1(a2) == 0` (top mantissa bits clear).
- Branch by exponents: if `(exp(a5) & 0x7FFF) > (exp(a2) & 0x7FFF) + 63` (compared via `v6 = (exp(a2) & 0x7FFF) + 63`) → scaled subtract loop with counter `((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1`, subtracting v8 from v10 only when x87 C0 (bit 0x100) is clear, scaling v8 by `dbl_9131FC` each pass. Else → `a5 = __FPREM__(a5, a2)` loop while `(exp(a5) & 0x7FFF) >= (exp(a2) & 0x7FFF) + 10`.
- Tail: if `(a1 & 3) != 0`, executes fnstenv then fldenv (x87 environment reload) and returns `status & 0x4300`; otherwise returns the last result value.
