## ResultsPageBuilder_00469fb0 — ResultsPageBuilder

**Summary:** Builds a results page by iterating through the race result linked list, filtering out entries matching the settings file path, formatting each remaining entry (grand prix name, race number, lap time) into UI menu items with indexed labels (1, 2). Belongs to career mode results/stats HTML page generation system.

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
| 007d2dc8 | dword_7D2DC8 | RW | RaceResultLinkedList [DERIVED] (also: ` — linked list of race results (stride 4+ per entry) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487010 | UIListIndexedAccessor | retrieves UI list label/index (called with 1 and 2 for column headers) |
| 004894d0 | StrlenOverwrite | updates local buffer length after copy |
| 00489600 | UIMenuItemCreator | creates a UI menu item from formatted string |
| 00489cb0 | StateCleanupNotification | performs state cleanup before building the page |
| 004c5840 | SeasonRacesSectionFinder | finds season race section matching the current entry |
| 00567970 | DataEntryAccessor | accesses data entry string from a linked list search result |
| 005679c0 | StringKeyedLinkedListSearch | searches a linked list for a node by key ("TrackName") |
| 00587bdc | CRTFtol | converts float to long (for lap time minutes extraction) |
| 00587dd0 | sub_587DD0 | copies string with size limit |
| 0058815f | StringFormatWithBufferOverflowCheck | safe string format (for lap time, UI labels) |
| 00588410 | sub_588410 | compares string against settings file path to filter current entry |

**Guard conditions:** Checks dword_7D2DC0 (race result list head) for null to determine if there are entries (BLOCKED if null, skips formatting). For each entry, compares string against dword_7CE5EC (settings file path) via sub_588410; if they match (equal), skips formatting for that entry (BLOCKED). If string doesn't match settings path (PASSES), calls SeasonRacesSectionFinder and checks its result for null before formatting. Checks StringKeyedLinkedListSearch result for "TrackName" key before copying track name. Loop continues via dword_7D2DC8 next pointers until null (exhausted list, BLOCKED).
