## UIWindowTextSetup_0048f9f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIDimensionCapture (0048ebd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB8 | R | — | [LLM] |
| this | 0xE0 | RW | 2 | [LLM] |
| this | 0x150 | RW | — | [LLM] |
| this | 0x154 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xE0: [LLM: once/conditional? does external poke survive?]
- this 0x150: [LLM: once/conditional? does external poke survive?]
- this 0x154: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005cc210 | aC_0 | R | StrExtension_c [DERIVED] |
| 005cc21c | byte_5CC21C | R | Str_UI_Load [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | [LLM] |
| 00587f59 | SingleFunctionCallWrapper_7f59 | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 005897ca | sub_5897CA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
