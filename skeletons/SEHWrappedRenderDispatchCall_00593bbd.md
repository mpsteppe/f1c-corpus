## SEHWrappedRenderDispatchCall_00593bbd — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5934E1 (005934e1), SEHWrapperAroundCRTFunctionCall (005938b4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | [LLM] |
| 005b9978 | stru_5B9978 | R | CRT_ExRegFrame2 [DERIVED] |
| ff00000000001692 | byte_FF00000000001692 | R | [LLM] |
| ff00000000001695 | byte_FF00000000001695 | W | [LLM] |
| ff00000000001699 | byte_FF00000000001699 | RW | [LLM] |
| ff0000000000169b | byte_FF0000000000169B | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a323 | AtomicLOCKUNLOCKWithIndirectCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
