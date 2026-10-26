## LinkedBufferTransfer_004b5f60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30), ModelSceneFileLoader (004b6c90), BufferPoolAllocatorInitialization (004b71e0), GameDataFileIO (004b7300), sub_4B7500 (004b7500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x718)+0x4) | 0x8 | RW | — | [LLM] |
| *(*(this+0x718)+0x8) | 0x4 | RW | — | [LLM] |
| *(this+0x718) | 0x0 | R | — | [LLM] |
| *(this+0x718) | 0x4 | R | — | [LLM] |
| *(this+0x718) | 0x8 | R | — | [LLM] |
| *(this+0x718) | 0xC | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x714 | RW | — | [LLM] |
| this | 0x718 | RW | — | [LLM] |
| this | 0x71C | RW | — | [LLM] |
| this | 0x720 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x718)+0x4) 0x8: [LLM: once/conditional? does external poke survive?]
- *(*(this+0x718)+0x8) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x714: [LLM: once/conditional? does external poke survive?]
- this 0x718: [LLM: once/conditional? does external poke survive?]
- this 0x71C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4460 | SmallStructZeroInit | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
