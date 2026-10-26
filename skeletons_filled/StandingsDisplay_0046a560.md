## StandingsDisplay_0046a560 — Season standings/career statistics UI menu builder

**Summary:** Builds a UI menu displaying career/season standings statistics (experience, starts, avg positions, poles, points, wins, lap records, championships) by reading scoring globals and creating formatted menu items. Part of the career/season statistics UI system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_0ad0 (004a0ad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x48) | 0x4 | R | — | linked list node next pointer (traversed during list cleanup from this+0x44) |
| this | 0x44 | RW | 0 | linked list head pointer (freed then zeroed) |
| this | 0x48 | RW | 0 | secondary list pointer / linked list head B (zeroed) |
| this | 0x4C | RW | 0 | tertiary list pointer (zeroed) |
| this | 0x50 | RW | 0 | quaternary list pointer (zeroed) |

**Written-by note (persistence):**
- this 0x44: once (list rebuild); external poke survives (new list rebuilt on next call)
- this 0x48: once (list rebuild); external poke survives
- this 0x4C: once (list rebuild); external poke survives
- this 0x50: once (list rebuild); external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c684c | aSS1f | R | FormatString_Ss1f [DERIVED] |
| 005c6858 | aSSI | R | Str_SSI [DERIVED] |
| 005c6878 | aWins | R | StrWins [DERIVED] |
| 005c6880 | aPoints | R | StatKey_Points [DERIVED] |
| 005c6888 | aPolePositions | R | Key_PolePositions [DERIVED] |
| 005c68c8 | aAvgFinishPosit | R | StrAvgFinishPosit [DERIVED] |
| 005c68e0 | aAvgStartingPos | R | aAvgStartingPos [DERIVED] |
| 005c68f8 | aStarts | R | Str_Starts [DERIVED] |
| 005c6900 | aExperienceLaps | R | String_ExperienceLaps [DERIVED] |
| 005c6990 | aDriversChampii | R | DriversChampionshipString [DERIVED] |
| 005c69a8 | aLapRecords | R | LapRecordsString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007d2dd4 | dword_7D2DD4 | R | Dword_SeasonScoring [DERIVED] |
| 007d2dd8 | dword_7D2DD8 | R | NetSessionFlag [DERIVED] |
| 007d2de0 | dword_7D2DE0 | R | UIStateVar [DERIVED] |
| 007d2de4 | dword_7D2DE4 | R | ScoringStandingsValue [DERIVED] |
| 007d2de8 | dword_7D2DE8 | R | Career_StatValue_2DE8 [DERIVED] |
| 007d2dec | dword_7D2DEC | R | Dword_7D2DEC_Season [DERIVED] |
| 007d2df0 | dword_7D2DF0 | R | SeasonDB_Int [DERIVED] |
| 007d2df4 | flt_7D2DF4 | R | UnknownScoringFloat [DERIVED] |
| 007d2df8 | flt_7D2DF8 | R | Unknown_Float_7D2DF8 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434420 | DoublePointerFree | frees a pointer and its pointed-to data (double-indirect free) |
| 00486f30 | LinkedListInsertWithNodeAllocation | allocates a new linked list node with string key and value (-1 = empty/default) |
| 00487010 | UIListIndexedAccessor | retrieves UI list item string by index from a list control |
| 004894d0 | StrlenOverwrite | writes string length / null-terminates after string manipulation |
| 00489600 | UIMenuItemCreator | creates a UI menu item entry with formatted text and flags |
| 00489cb0 | StateCleanupNotification | sends state cleanup notification (resets UI state) |
| 004b0b20 | sub_4B0B20 | unknown initialization (called with buffer and size 256) |
| 00566650 | StringCopyWithBufferRealloc | copies string into buffer with possible reallocation |
| 00587bcf | FreeWrapper_7bcf | memory free wrapper |
| 0058815f | StringFormatWithBufferOverflowCheck | formatted sprintf with buffer overflow protection |

**Guard conditions:** No guard conditions — function executes unconditionally. The `while (v2)` loop at line 37 traverses and frees a linked list; the loop terminates when list is exhausted (v2 == NULL).
