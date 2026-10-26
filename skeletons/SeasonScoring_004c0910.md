## SeasonScoring_004c0910 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceStandingsRankingsComputation (004c0f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x198 | RW | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1A8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x198: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 005d2804 | aSeasonscoringi | R | sSeasonScoringInfo [DERIVED] |
| 007d00ec | dword_7D00EC | R | GameState (1-7) [DERIVED] |
| 007d2e48 | dword_7D2E48 | R | SeasonScoringDB (stride 0x48c0) [DERIVED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567970 | DataEntryAccessor | [LLM] |
| 005679a0 | NullCheckWrapper | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587ece | sub_587ECE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
