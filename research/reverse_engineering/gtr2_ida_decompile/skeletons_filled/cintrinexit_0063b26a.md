## cintrinexit_0063b26a — CRT _cintrinexit: x87 exception post-processing for cintrin dispatch

**Summary:** MSVC CRT x87 helper that finishes a "cintrin" (convert-to-int transcendental) dispatch: it examines the recorded FPU exception state byte, classifies overflow/underflow/inexact conditions (possibly rescaling the result with __FSCALE__), builds an exception record from the caller's saved argument words, and invokes _87except to run the user math error handler. Returns the (possibly adjusted) double result in st0.

**Called by:** __cintrindisp2 (0063b1a0), __cintrindisp1 (0063b1de)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Argument word of the original transcendental call, copied into the exception record's operand fields |
| this | 0xC | R | — | Second argument word of the original call, copied into the exception record |
| this | 0x10 | R | — | Third argument word, copied into the exception record when the further-handler flag is clear |
| this | 0x14 | R | — | Fourth argument word, copied into the exception record when the further-handler flag is clear |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731d00 | dbl_731D00 | R | Double constant from the CRT math constant pool used in the overflow/underflow rescale path (FSCALE factor / magnitude bound) |
| 00731d08 | dbl_731D08 | R | Double constant from the same pool, used in the underflow denormal-flush comparison (magnitude bound) |
| 00731d10 | dbl_731D10 | R | Double constant from the same pool used in the underflow result adjustment |
| 00731d18 | dbl_731D18 | R | Double constant from the same pool used for the overflow FSCALE rescale |
| 00731d20 | dbl_731D20 | R | Double constant from the same pool used as the overflow magnitude bound |
| 00731d28 | dbl_731D28 | R | Double constant from the same pool used as the overflow saturation value |
| 00fb8178 | dword_FB8178 | R | CRT flag: when nonzero, exception processing is suppressed and the result is returned unchanged (early-out at function top) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00641bee | __87except | CRT x87 exception dispatcher — invoked with the exception code, the built exception record and context block to invoke the registered math error handler |

**Guard conditions:**
- `dword_FB8178 != 0` → immediate return of `result` (all exception handling skipped).
- `switch` on the saved state byte at ebp-144: case `0` → go to inexact check; case `-1` → if saved-operand exponent field (`word & 0x7FF0`) is NOT 0x7FF0, go to inexact check, else set exception code 3 (overflow) and continue; case `-2` → if exponent field is 0, set code 4, rescale with `__FSCALE__(result, 1536.0)` and flush tiny results to zero, else if exponent field != 0x7FF0 go to inexact check, else code 3; any other value → store it as the exception code and continue.
- At the inexact check: if saved x87 status word has bit 0x20 (inexact/precision) set, OR the current fps byte lacks bit 0x20, return `result` unchanged; otherwise set exception code 8 and continue.
- In the error path: only if byte `[ebp-89] & 1` is clear are the caller's argument words copied into the exception record; the byte at `[v8+12] != 1` gates copying of the additional argument words 4/5.
- Function always ends by calling `_87except` and returning the stored result (post-handler value).
