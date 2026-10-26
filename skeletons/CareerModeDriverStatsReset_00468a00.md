## CareerModeDriverStatsReset_00468a00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| obj | 0x3C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
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
| 005c6860 | aWorldChampions | R | StrWorldChampions [DERIVED] |
| 005c6878 | aWins | R | StrWins [DERIVED] |
| 005c6880 | aPoints | R | StatKey_Points [DERIVED] |
| 005c6888 | aPolePositions | R | Key_PolePositions [DERIVED] |
| 005c6898 | aAvgOpponentStr | R | aAvgOpponentStr [DERIVED] |
| 005c68b4 | aAvgRaceLength | R | DriverStatKeyAvgRaceLength [DERIVED] |
| 005c68c8 | aAvgFinishPosit | R | StrAvgFinishPosit [DERIVED] |
| 005c68e0 | aAvgStartingPos | R | aAvgStartingPos [DERIVED] |
| 005c68f8 | aStarts | R | Str_Starts [DERIVED] |
| 005c6900 | aExperienceLaps | R | String_ExperienceLaps [DERIVED] |
| 005c6914 | aBestLap | R | sBestLap [DERIVED] |
| 005c6920 | aCircuit | R | StatKey_Circuit [DERIVED] |
| 007cff30 | byte_7CFF30 | W | ExperienceLapsResetFlag [DERIVED] |
| 007cff32 | byte_7CFF32 | R | UI_TriggerFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00468910 | HTMLResultsStatsPageWorldChampionships | [LLM] |
| 00468bf0 | sub_468BF0 | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
