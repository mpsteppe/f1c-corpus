## GdbSeasonSelector_00420cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringClassificationDisplay (0041e320)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00421200 | jpt_420DA8 | R | [LLM] |
| 00421238 | jpt_420EB7 | R | [LLM] |
| 00421270 | jpt_420FAE | R | [LLM] |
| 004212a8 | jpt_421015 | R | [LLM] |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] |
| 005bf97c | aF12001Gdb | R | aF12001Gdb [DERIVED] |
| 005bf988 | aF12000Gdb | R | TrackDatabaseFilename [DERIVED] |
| 005bf994 | aF11999Gdb | R | aF11999Gdb [DERIVED] |
| 005c25b4 | aToyota | R | Str_Team_Toyota [DERIVED] |
| 005c25bc | aStewart | R | String_Stewart [DERIVED] |
| 005c25c4 | aRenault | R | sTeamName_Renault [DERIVED] |
| 005c25cc | aBenetton | R | TeamName_Benetton [DERIVED] |
| 005c25d8 | aJaguar | R | StrJaguar [DERIVED] |
| 005c25e0 | off_5C25E0 | R | Unknown_Setup_25E0 [DERIVED] |
| 005c25e4 | aMinardi | R | TeamNameMinardi [DERIVED] |
| 005c25ec | aProst | R | aProst [DERIVED] |
| 005c25f4 | aArrows | R | TrackArrows [DERIVED] |
| 005c25fc | aSauber | R | TeamName_Sauber [DERIVED] |
| 005c2604 | aJordan | R | TrackNameJordan [DERIVED] |
| 005c260c | aWilliams | R | Str_Team_Williams [DERIVED] |
| 005c2618 | aFerrari | R | sTeamFerrari [DERIVED] |
| 005c2620 | aMclaren | R | TeamName_McLaren [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00415550 | LinkedListIndexScannerWithValidation | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 0041f220 | ChampionshipPointsAccumulator | [LLM] |
| 0041f340 | sub_41F340 | [LLM] |
| 004212e0 | ShortComputation_12e0 | [LLM] |
| 00421380 | CountActiveEntitiesByState | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
