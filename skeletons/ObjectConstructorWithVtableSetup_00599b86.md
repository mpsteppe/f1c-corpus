## ObjectConstructorWithVtableSetup_00599b86 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5998C0 (005998c0), DelegationWithFixedArgs_9904 (00599904), SingleFunctionCallWrapper_9933 (00599933)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d3c2 | loc_59D3C2 | R | [LLM] |
| 005b9c48 | ??_7?$basic_ostream@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ostream_wchar [DERIVED] |
| 005b9c50 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | VTable_basic_ios [DERIVED] |
| 005b9c54 | unk_5B9C54 | R | CppStreamObject_5B9C54 [DERIVED] |

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
