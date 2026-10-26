## ResultsPageBuilder_00469fb0 — [LLM: short descriptive name]

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
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005c6930 | aI063f | R | FormatString_I063f [DERIVED] |
| 005c694c | word_5C694C | R | FormatWord [DERIVED] |
| 005c6984 | aTrackname | R | StrTrackName [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007d2dc0 | dword_7D2DC0 | R | RaceResultListHead [DERIVED] |
| 007d2dc8 | dword_7D2DC8 | RW | RaceResultLinkedList [DERIVED] (also: ` � linked list of race results (stride 4+ per entry) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | [LLM] |
| 004894d0 | StrlenOverwrite | [LLM] |
| 00489600 | UIMenuItemCreator | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
