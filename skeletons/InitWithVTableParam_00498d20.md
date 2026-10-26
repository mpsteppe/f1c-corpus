## InitWithVTableParam_00498d20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstructorWithVTableAndSubInit_9140 (00499140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac9e8 | off_5AC9E8 | R | VTable_5AC9E8 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498df0 | MultiFieldStructInit | [LLM] |
| 0049a930 | ConstructorWith1Sentinels | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
