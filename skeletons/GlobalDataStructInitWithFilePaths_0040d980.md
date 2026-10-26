## GlobalDataStructInitWithFilePaths_0040d980 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Wrapper_0030 (004d0030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x84 | RW | 0 | [LLM] |
| this | 0x88 | RW | 0 | [LLM] |
| this | 0x8C | RW | 0 | [LLM] |
| this | 0x90 | RW | 0 | [LLM] |
| this | 0x94 | RW | 18446744073709551615 | [LLM] |
| this | 0x98 | RW | 0 | [LLM] |
| this | 0x9C | RW | 0 | [LLM] |
| this | 0xA0 | RW | 124 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x8C: [LLM: once/conditional? does external poke survive?]
- this 0x90: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0x98: [LLM: once/conditional? does external poke survive?]
- this 0x9C: [LLM: once/conditional? does external poke survive?]
- this 0xA0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434860 | ConstraintSolverParamInit | [LLM] |
| 00567a00 | StructZeroInit_7a00 | [LLM] |
| 00567f10 | F_9PointerArrayCleanup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
