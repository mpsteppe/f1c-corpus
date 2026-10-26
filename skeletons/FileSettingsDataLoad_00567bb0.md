## FileSettingsDataLoad_00567bb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioFileLoadDecode (00567f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30ac | asc_5C30AC | R | StrDelimiter_Period [DERIVED] (also: ` — first lookup key string or identifier) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00567b10 | sub_567B10 | [LLM] |
| 00567bb0 | FileSettingsDataLoad | [LLM] |
| 00567fb0 | FileDataProcessor | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
