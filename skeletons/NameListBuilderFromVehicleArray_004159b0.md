## NameListBuilderFromVehicleArray_004159b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5090 (00415090)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00415520 | SmallEntryStructInit | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac390 | dword_8AC390 | R | VehicleFileCount [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401000 | sub_401000 | [LLM] |
| 00414a90 | sub_414A90 | [LLM] |
| 00414d70 | TextFormatStructInitializer_4d70 | [LLM] |
| 00415c30 | NullSafePointerDereference | [LLM] |
| 00418c10 | MemoryAllocation_8c10 | [LLM] |
| 00418d60 | DestructorWithDoubleFreePattern | [LLM] |
| 00434030 | DoublyLinkedListAppend | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
