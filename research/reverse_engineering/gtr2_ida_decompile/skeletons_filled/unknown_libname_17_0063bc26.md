## unknown_libname_17_0063bc26 — CRT long-double reduction (FPREM) pre-check helper

**Summary:** MSVC CRT x87 math helper: inspects a pair of extended-precision (long double) operands, classifies the exponent bits against a small lookup table, and — for large-exponent finite operands — performs argument reduction either by a scaled subtract loop or by repeated `__FPREM__` while the exponent difference is large. Finishes by reloading the x87 environment when flag bits in DL are set and returns a fragment of the FPU status word.

**Called by:** SceneGraphQuery [structural] (0063be2c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 009131cc | byte_9131CC | R | 16-entry class lookup table indexed by the operand's top exponent bits; nonzero entry allows the reduction path, zero skips it |
| 009131ec | dbl_9131EC | R | CRT x87-helper constant-pool double read by this routine; its role is not visible in the decompiled body (consumed on a path not expanded by IDA) |
| 009131fc | dbl_9131FC | R | Scale factor multiplied into the running remainder operand each iteration of the subtract-loop reduction path |
| 00913204 | tbyte_913204 | R | CRT x87-helper constant-pool 10-byte constant (long double) referenced by this routine; role not visible in the decompiled body |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- Entry check: `((dword[a2+6] ^ 0x700) & 0x700) == 0` — processing only proceeds when bits 8..10 of that dword equal 0x700; otherwise every step is skipped and control goes directly to the FPU-env tail.
- Table check: `byte_9131CC[(bits >> 11) & 0xF]` must be nonzero, else the block is skipped.
- Operand checks: `dword[a2+6] & 0x7FFF0000 != 0x7FFF0000` (a2 not inf/NaN) and `dword[a5+6] & 0x7FFF0000` nonzero and `!= 2147418112` (a5 finite nonzero); `2*DWORD1(a5) == 0` and `2*DWORD1(a2) == 0` (mantissa top bits clear).
- Reduction branch: if `(exp(a5) & 0x7FFF) > (exp(a2) & 0x7FFF) + 63` → scaled subtract loop with counter `((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1`, subtracting v7 from v9 when the x87 C0 flag (bit 0x100) is clear and scaling v7 by `dbl_9131FC` each pass. Else → loop `a5 = __FPREM__(a5, a2)` while `(exp(a5) & 0x7FFF) >= (exp(a2) & 0x7FFF) + 10`.
- Tail: if `(a1 & 3) != 0`, executes fnstenv followed by fldenv (x87 environment reload) and returns `status & 0x4300`; otherwise returns the last computed result value.
