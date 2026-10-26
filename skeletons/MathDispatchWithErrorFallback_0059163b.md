## MathDispatchWithErrorFallback_0059163b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 0058afcf | TLSOffsetGetter | [LLM] |
| 00591bf1 | FloatParsingWithErrorHandling | [LLM] |
| 00591e66 | ReturnFPUControlWord | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
