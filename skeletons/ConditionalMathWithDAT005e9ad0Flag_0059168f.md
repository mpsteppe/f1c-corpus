## ConditionalMathWithDAT005e9ad0Flag_0059168f — [LLM: short descriptive name]

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
| 00591727 | sub_591727 | [LLM] |
| 005919da | sub_5919DA | [LLM] |
| 00591bf1 | FloatParsingWithErrorHandling | [LLM] |
| 00591c79 | SetErrorCodeBasedOnInputRange | [LLM] |
| 00591cc6 | BitFlagDecoderViaBitTests | [LLM] |
| 00591e66 | ReturnFPUControlWord | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
