## CustomMemoryPoolAllocatorInit_004906e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Accessor (00490920), GlobalDataRead (00490930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00490850 | ResourceLinkedListTeardown | R | [LLM] |
| 007cd9c8 | byte_7CD9C8 | RW | CodecModuleInitFlag [DERIVED] (also: ` — init flag) |
| 007cd9cc | dword_7CD9CC | RW | PoolDescriptorPtr [DERIVED] (also: ` — pool descriptor pointer) |
| 007cd9d0 | dword_7CD9D0 | W | AllocatorHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004912f0 | ThunkToFUN00491330 | [LLM] |
| 00491710 | ObjectConstructor_1710 | [LLM] |
| 00587b3e | BooleanToIntConversion | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
