## sub_59A8FA_0059a8fa — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598A41 (00598a41), ObjectConstructorWithSEHVtableInit (00598b5d), ObjectInitWithVTableFlagSet (005993eb), ObjectConstructorWithVtableSetup (00599b86), CConstructorWithSEH (00599c58), StreamCreationWithFlagInit (0059a3a9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x24: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4618 | dword_8D4618 | RW | CRTTermFuncTable [DERIVED] |
| 008d463c | byte_8D463C | W | RefCountArray [DERIVED] (also: Reference count array (indexed by extraout_ECX[9]) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059a54d | sub_59A54D | [LLM] |
| 0059a5e9 | sub_59A5E9 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24 | < | 8 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
