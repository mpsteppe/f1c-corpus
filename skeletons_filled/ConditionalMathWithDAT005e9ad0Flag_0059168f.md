## ConditionalMathWithDAT005e9ad0Flag_0059168f — MathDispatchWithFpeGuardAndExceptionDecode

**Summary:** Dispatches floating-point operation based on decoded exception code bit flags. If sub_5919DA returns false, calls sub_591727 for exception context setup. Then if FPE flag (dword_5E9AD0) is set or decoded mode is zero, sets error code, resets FPU, returns fallback (a4); otherwise forwards to FloatParsingWithErrorHandling.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_5895A2 (005895a2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e9ad0 | dword_5E9AD0 | R | CrtFPEExceptionFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00591727 | sub_591727 | setup exception-handling context (arguments array) before parsing |
| 005919da | sub_5919DA | check exception code and parameters; returns success flag |
| 00591bf1 | FloatParsingWithErrorHandling | parse floating-point string with error handling |
| 00591c79 | SetErrorCodeBasedOnInputRange | write error code to TLS based on decoded mode value |
| 00591cc6 | BitFlagDecoderViaBitTests | decode exception code into operation mode bit flags |
| 00591e66 | ReturnFPUControlWord | reset FPU control word with mask |

**Guard conditions:** Two-stage guard: (1) if `sub_5919DA(dwExceptionCode, &a4, a5)` returns 0 → calls sub_591727 setup, continues (not blocked). (2) if `dword_5E9AD0` (FPE flag) is non-zero OR `v5` (decoded bit flags) is zero → BLOCKED (error path: SetErrorCodeBasedOnInputRange, ReturnFPUControlWord, return a4). PASSES when FPE flag clear and decoded mode valid.
