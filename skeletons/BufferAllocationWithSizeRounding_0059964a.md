## BufferAllocationWithSizeRounding_0059964a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_599560 (00599560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005996a8 | loc_5996A8 | R | [LLM] |
| 0059d2fc | loc_59D2FC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058a5d8 | SEHHandlerInit | [LLM] |
| 0058cc00 | MemoryCopy_cc00 | [LLM] |
| 005993af | ReferenceCountDecrementWithConditionalFree | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
