## StandingsDisplay_0046a560 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_0ad0 (004a0ad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x48) | 0x4 | R | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

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
| 00434420 | DoublePointerFree | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00487010 | UIListIndexedAccessor | [LLM] |
| 004894d0 | StrlenOverwrite | [LLM] |
| 00489600 | UIMenuItemCreator | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 004b0b20 | sub_4B0B20 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
