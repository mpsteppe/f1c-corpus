## DoublyLinkedListAppend_6750_00496750 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameObjectUpdateFrame (004661b0), DirectoryChangeHandler (0048e6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C0) | 0x4 | RW | — | [LLM] |
| this | 0x24 | RW | 1 | [LLM] |
| this | 0x18BC | RW | — | [LLM] |
| this | 0x18C0 | RW | — | [LLM] |
| this | 0x18C4 | RW | — | [LLM] |
| this | 0x18C8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x18C0) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x18BC: [LLM: once/conditional? does external poke survive?]
- this 0x18C0: [LLM: once/conditional? does external poke survive?]
- this 0x18C4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
