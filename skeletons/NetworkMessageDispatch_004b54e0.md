## NetworkMessageDispatch_004b54e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x10)+0x0) | 0x368 | RW | 0 | [LLM] |
| *(*(this+0x10)+0x0) | 0x36C | RW | 18446744073709551615 | [LLM] |
| *(*(this+0x10)+0x0) | 0x370 | RW | 18446744073658219970 | [LLM] |
| *(*(this+0x28)+0x0) | 0x368 | R | — | [LLM] |
| *(*(this+0x28)+0x0) | 0x36C | R | — | [LLM] |
| *(this+0x10) | 0x0 | R | — | [LLM] |
| *(this+0x10) | 0x8 | RW | 0 | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x24) | 0x4 | RW | — | [LLM] |
| *(this+0x28) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x4 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x10)+0x0) 0x368: [LLM: once/conditional? does external poke survive?]
- *(*(this+0x10)+0x0) 0x36C: [LLM: once/conditional? does external poke survive?]
- *(*(this+0x10)+0x0) 0x370: [LLM: once/conditional? does external poke survive?]
- *(this+0x10) 0x8: [LLM: once/conditional? does external poke survive?]
- *(this+0x24) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd24 | dword_5ACD24 | R | D3DRenderDefaultColor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ba7a0 | DoublyLinkedListNodeRemoval | [LLM] |
| 004ba980 | sub_4BA980 | [LLM] |
| 004bad70 | CollisionNodeListInsertion | [LLM] |
| 004bae20 | LinkedListRemoveByValue | [LLM] |
| 004fffa0 | ThunkWithStructInitSubCalls | [LLM] |
| 004fffb0 | ZoneThresholdComparisonWithConditionalAction | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
