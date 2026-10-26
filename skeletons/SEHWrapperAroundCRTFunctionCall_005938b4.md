## SEHWrapperAroundCRTFunctionCall_005938b4 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiArgRenderingDispatchWithLayout (00593839)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | [LLM] |
| 005b9950 | stru_5B9950 | R | ExceptionHandler_State [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | [LLM] |
| ff00000000001695 | byte_FF00000000001695 | W | [LLM] |
| ff00000000001699 | byte_FF00000000001699 | RW | [LLM] |
| ff0000000000169a | byte_FF0000000000169A | R | [LLM] |
| ff0000000000169b | byte_FF0000000000169B | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005888a6 | MSVCRTSEHFrameUnwinder | [LLM] |
| 0058890e | CRTAbnormalTermination | [LLM] |
| 0058a3b6 | SEHExceptionFrameWrapper | [LLM] |
| 0058e0c7 | TLSValueRetrievalWithInit | [LLM] |
| 005939cf | FileMagicNumberValidator | [LLM] |
| 00593bbd | SEHWrappedRenderDispatchCall | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 18446744073179853667 | [LLM] |
| this | 0x10 | == | 3 | [LLM] |
| this | 0x14 | == | 429065504 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
