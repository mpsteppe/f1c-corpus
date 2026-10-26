## LocaleEnumProc_0058ffec — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d3f98 | Locale | RW | CurrentLocaleID [DERIVED] |
| 008d3f9c | dword_8D3F9C | R | LocaleMatchFlag [DERIVED] |
| 008d3fa0 | dword_8D3FA0 | R | Locale_CharsetMode [DERIVED] |
| 008d3fa4 | dword_8D3FA4 | R | LocaleIsThreeLetterFlag [DERIVED] |
| 008d3fa8 | dword_8D3FA8 | R | LocaleLanguageStr [DERIVED] |
| 008d3fac | dword_8D3FAC | R | LocaleLanguageRegionPtr [DERIVED] |
| 008d3fb0 | dword_8D3FB0 | RW | LocaleValidationFlags [DERIVED] |
| 008d3fb1 | byte_8D3FB1 | W | Unknown_Byte_Config [DERIVED] |
| 008d3fb4 | dword_8D3FB4 | W | LocaleLanguageID [DERIVED] |
| 008d3fb8 | dword_8D3FB8 | R | LocaleInfoFunc [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | [LLM] |
| 0058e1b0 | Strlen | [LLM] |
| 00590440 | ShortInRangeCheckAgainstStaticTable | [LLM] |
| 0059045f | sub_59045F | [LLM] |
| 005905dd | HexStringToIntParser | [LLM] |
| 00596c80 | sub_596C80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
