## MemoryAllocator_00515f23 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryAllocatorWithChunking (005160ad), ChunkedBufferAlloc (0051613f), LinkedListNodeAllocAndInsert (005161dd), sub_51623E (0051623e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 12 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x4C | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af8b8 | dword_5AF8B8 | R | MemPoolFreeList [DERIVED] |
| 005af8c0 | dword_5AF8C0 | R | HeapFreeListSize [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515f0e | ShortComputation_5f0e | [LLM] |
| 00519346 | MallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
