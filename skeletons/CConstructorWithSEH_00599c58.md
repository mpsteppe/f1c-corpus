## CConstructorWithSEH_00599c58 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LocaleFunctionCallWrapper_987c (0059987c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d40a | loc_59D40A | R | [LLM] |
| 005b9c40 | ??_7?$basic_istream@GU?$char_traits@G@std@@@std@@6B@ | R | IStreamWVTable [DERIVED] |
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |
| 005b9c5c | unk_5B9C5C | R | LocaleVTablePtr [DERIVED] (also: ` — locale vtable pointer) |

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
