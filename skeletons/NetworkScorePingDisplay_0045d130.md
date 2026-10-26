## NetworkScorePingDisplay_0045d130 — [LLM: short descriptive name]

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
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c5c4c | aPingD | R | s_FormatPingD [DERIVED] |
| 005c5c54 | aScoreD | R | ScoreD [DERIVED] |
| 005c5c60 | aPlayerD | R | PlayerDFormatString [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ce30 | ShortComputation_ce30 | [LLM] |
| 00461470 | ThunkToFUN00461480 | [LLM] |
| 00462370 | StructFieldReadAt0x3e14 | [LLM] |
| 00462410 | DataTableRowAccessor | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
