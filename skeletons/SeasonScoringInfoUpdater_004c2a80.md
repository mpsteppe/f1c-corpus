## SeasonScoringInfoUpdater_004c2a80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0760 (004a0760), Steward_Post (004d4600)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 005d2804 | aSeasonscoringi | R | sSeasonScoringInfo [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | [LLM] |
| 004c28d0 | TrackSceneNodeAdd | [LLM] |
| 004c2be0 | Accumulator | [LLM] |
| 004c2c00 | ArithmeticComparison_2c00 | [LLM] |
| 004c2c20 | SimpleCounterIncrement | [LLM] |
| 004c2cb0 | MovingAverageFilterWithClamp | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679a0 | NullCheckWrapper | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587ece | sub_587ECE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
