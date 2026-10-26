## sub_59AAB9_0059aab9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleRefcountAcquireUnderLock (00598c1c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059ab83 | loc_59AB83 | R | [LLM] |
| 0059d4ea | loc_59D4EA | R | [LLM] |
| 0059d4fc | loc_59D4FC | R | [LLM] |
| 005b9d44 | dword_5B9D44 | R | Unknown_Struct_CRT [DERIVED] |
| 008d4648 | dword_8D4648 | RW | ModuleInstancePtr [DERIVED] |
| 008d464c | dword_8D464C | RW | GlobalObjManagerPtr [DERIVED] |
| 008d4650 | dword_8D4650 | RW | EncodingSingletonPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587b3e | BooleanToIntConversion | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058a5d8 | SEHHandlerInit | [LLM] |
| 0058e1b0 | Strlen | [LLM] |
| 00598c4a | CounterIncrementThreadSafe | [LLM] |
| 00598c88 | RefcountDecrementWithLock | [LLM] |
| 00599615 | BufferWriteWithNullTerminate | [LLM] |
| 0059a54d | sub_59A54D | [LLM] |
| 0059a5e9 | sub_59A5E9 | [LLM] |
| 0059abcd | ObjectConstructorWithVTableAndStringInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
