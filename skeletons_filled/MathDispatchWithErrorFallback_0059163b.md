## MathDispatchWithErrorFallback_0059163b — FloatParseDispatchWithFPEGuard

**Summary:** Gate for floating-point parsing — if FPE exception flag (dword_5E9AD0) is set, writes error code 33 to TLS slot, resets FPU control word with mask 0xFFFF, and returns input double unchanged; otherwise delegates to FloatParsingWithErrorHandling.

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
| 0058afcf | TLSOffsetGetter | retrieve TLS slot base address for writing error code |
| 00591bf1 | FloatParsingWithErrorHandling | parse floating-point string into double with error handling |
| 00591e66 | ReturnFPUControlWord | set FPU control word to a given mask value |

**Guard conditions:** Single check: if `dword_5E9AD0` (FPE exception flag) is non-zero → BLOCKED (short-circuit error path: set TLS error 33, reset FPU, return a2). If zero → PASSES to FloatParsingWithErrorHandling for actual parsing.
