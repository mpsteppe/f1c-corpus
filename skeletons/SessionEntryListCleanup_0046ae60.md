## SessionEntryListCleanup_0046ae60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualCallWrapper_af00 (0046af00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007d1424 | dword_7D1424 | R | TeamEntryCount [DERIVED] (also: ` — number of teams/entries) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455560 | ArrayIndexedAccessor | [LLM] |
| 0046ad50 | MessageNameBufferUpdate | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
