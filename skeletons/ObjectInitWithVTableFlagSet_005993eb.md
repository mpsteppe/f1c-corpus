## ObjectInitWithVTableFlagSet_005993eb — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleObjectConstructorWithVtableInit (005989d7), ObjectConstructorWithVTableSetupAndSEH (00598af5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |
| this | 0x30 | RW | 32 | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a5fe | sub_59A5FE | [LLM] |
| 0059a8fa | sub_59A8FA | [LLM] |
| 0059a948 | StructFieldInitWithConditionalCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
