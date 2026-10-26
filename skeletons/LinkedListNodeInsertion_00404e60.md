## LinkedListNodeInsertion_00404e60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), ConfigIniParser (00421cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40 | RW | — | [LLM] |
| obj | 0x44 | RW | — | [LLM] |
| obj | 0x48 | RW | — | [LLM] |
| obj | 0x4C | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x40: [LLM: once/conditional? does external poke survive?]
- obj 0x44: [LLM: once/conditional? does external poke survive?]
- obj 0x48: [LLM: once/conditional? does external poke survive?]
- obj 0x4C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
