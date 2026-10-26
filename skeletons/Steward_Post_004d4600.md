## Steward_Post_004d4600 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x110 | RW | 0 | [LLM] |
| this | 0x114 | RW | 0 | [LLM] |
| this | 0x1A8 | RW | 0 | [LLM] |
| this | 0x1AC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xA8: [LLM: once/conditional? does external poke survive?]
- this 0x10C: [LLM: once/conditional? does external poke survive?]
- this 0x110: [LLM: once/conditional? does external poke survive?]
- this 0x114: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1AC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d3b6c | aDDevF119992002_3 | R | aDDevF119992002_3 [DERIVED] |
| 005d43ac | aEnteredSteward_2 | R | EnteredStewardString [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040da30 | CameraDirectorResetInit | [LLM] |
| 004482d0 | D3DStateInit | [LLM] |
| 004bb950 | StructResetReinitializer | [LLM] |
| 004c2a80 | SeasonScoringInfoUpdater | [LLM] |
| 004d24d0 | sub_4D24D0 | [LLM] |
| 004d2e20 | ArithmeticComparison_2e20 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
