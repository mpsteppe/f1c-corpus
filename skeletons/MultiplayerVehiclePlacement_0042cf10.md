## MultiplayerVehiclePlacement_0042cf10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), SessionSynchronizer (0045f950), sub_4A0590 (004a0590), SessionSceneInitChain (004a0630), SessionInit (004a06e0), LoadVehicleEntries (004b70b0), Steward_Init (004d38f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c355c | aMultiplayerMod | R | MultiplayerModeString [DERIVED] |
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cebc4 | byte_7CEBC4 | R | FormationLap [DERIVED] |
| 007d00ec | dword_7D00EC | W | GameState (1-7) [DERIVED] |
| 007d00f4 | dword_7D00F4 | R | GameStateMin [DERIVED] |
| 007d00f8 | dword_7D00F8 | R | GameStateUpperBound [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461db0 | SessionStateCheckWrapper | [LLM] |
| 00461dc0 | StateCheckWrapper | [LLM] |
| 00462a10 | ChampionshipStandingsReOrdering | [LLM] |
| 00462e20 | sub_462E20 | [LLM] |
| 004bc320 | FieldCopy | [LLM] |
| 004bc330 | FieldCopy_c330 | [LLM] |
| 004c01a0 | sub_4C01A0 | [LLM] |
| 004c2830 | ConditionalSeasonDataFree | [LLM] |
| 004c6f10 | sub_4C6F10 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 5 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
