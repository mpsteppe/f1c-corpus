## ObjectConstructorWithSEHVtableInit_00598b5d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59870C (0059870c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d2aa | loc_59D2AA | R | [LLM] |
| 005b9ba4 | ??_7?$basic_istream@DU?$char_traits@D@std@@@std@@6B@ | R | IStreamVtablePtr [DERIVED] |
| 005b9bb4 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | IosVtable [DERIVED] |
| 005b9bc0 | unk_5B9BC0 | R | PrimaryVTablePtr [DERIVED] (also: primary vtable pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | [LLM] |
| 0059a8fa | sub_59A8FA | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
