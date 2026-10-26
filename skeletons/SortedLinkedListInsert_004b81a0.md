## SortedLinkedListInsert_004b81a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuActionDispatch (004b9da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x6C0)+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(*(*(this+0x6C0)+0x4)+0x4) | 0x8 | RW | — | [LLM] |
| *(*(this+0x6C0)+0x4) | 0x4 | RW | 0 | [LLM] |
| *(this+0x6C0) | 0x4 | R | — | [LLM] |
| *(this+0x6C0) | 0x8 | RW | — | [LLM] |
| this | 0x6C0 | RW | — | [LLM] |
| this | 0x6C4 | RW | — | [LLM] |
| this | 0x6C8 | RW | — | [LLM] |
| this | 0x6CC | R | — | [LLM] |
| this | 0x6D0 | RW | 1 | [LLM] |
| this | 0xF38 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(*(this+0x6C0)+0x4)+0x4) 0x8: [LLM: once/conditional? does external poke survive?]
- *(*(this+0x6C0)+0x4) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x6C0) 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x6C0: [LLM: once/conditional? does external poke survive?]
- this 0x6C4: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x6D0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b8360 | SpriteOverlayDisplayListCleanup | [LLM] |
| 004bb2e0 | MergeSort_b2e0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
