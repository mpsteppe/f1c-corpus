## _toupper_0_005c09a6 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _toupper (005c0937)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00625680 | off_625680 | R | [LLM] |
| 0062588c | SrcSizeInBytes | R | [LLM] |
| 007ff1e8 | dword_7FF1E8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c409a | CharacterEncodingConvertViaLookupTableFallback [structural] | [LLM] |
| 005c924d | ___crtLCMapStringA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
