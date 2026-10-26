## StructInitWithGlobalData_004b4f70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualCallWrapper_4f50 (004b4f50), DriverNameTeamCopy (004b51e0), sub_4B5E50 (004b5e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x1 | RW | 0 | [LLM] |
| this | 0x41 | RW | 0 | [LLM] |
| this | 0x61 | RW | 0 | [LLM] |
| this | 0x84 | RW | 18446744073518564782 | [LLM] |
| this | 0x88 | RW | 18446744073518564782 | [LLM] |
| this | 0x8C | RW | 18446744073518564782 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1: [LLM: once/conditional? does external poke survive?]
- this 0x41: [LLM: once/conditional? does external poke survive?]
- this 0x61: [LLM: once/conditional? does external poke survive?]
- this 0x84: [LLM: once/conditional? does external poke survive?]
- this 0x88: [LLM: once/conditional? does external poke survive?]
- this 0x8C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acd10 | flt_5ACD10 | R | EntityActiveDefault [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fffa0 | ThunkWithStructInitSubCalls | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
