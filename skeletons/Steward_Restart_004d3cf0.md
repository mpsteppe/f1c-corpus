## Steward_Restart_004d3cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | RW | 2147483647 | [LLM] |
| this | 0xB0 | RW | 2139095039 | [LLM] |
| this | 0xB4 | RW | 2139095039 | [LLM] |
| this | 0xB8 | RW | — | [LLM] |
| this | 0xBC | RW | 1065353216 → 1.0f | [LLM] |
| this | 0xC0 | RW | 0 | [LLM] |
| this | 0xC1 | RW | 0 | [LLM] |
| this | 0xC2 | RW | 0 | [LLM] |
| this | 0xCE | RW | 0 | [LLM] |
| this | 0xD0 | RW | 1190993920 → 32400.0f | [LLM] |
| this | 0xD4 | RW | 1102169884 → 22.2222f | [LLM] |
| this | 0xD8 | RW | 2139095039 | [LLM] |
| this | 0x104 | RW | 0 | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x118 | RW | 18446744072877927208 → -1000000000.0f | [LLM] |
| this | 0x11C | RW | 0 | [LLM] |
| this | 0x120 | RW | 0 | [LLM] |
| this | 0x190 | RW | 18446744073709551615 | [LLM] |
| this | 0x192 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0xAC: [LLM: once/conditional? does external poke survive?]
- this 0xB0: [LLM: once/conditional? does external poke survive?]
- this 0xB4: [LLM: once/conditional? does external poke survive?]
- this 0xB8: [LLM: once/conditional? does external poke survive?]
- this 0xBC: [LLM: once/conditional? does external poke survive?]
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0xC1: [LLM: once/conditional? does external poke survive?]
- this 0xC2: [LLM: once/conditional? does external poke survive?]
- this 0xCE: [LLM: once/conditional? does external poke survive?]
- this 0xD0: [LLM: once/conditional? does external poke survive?]
- this 0xD4: [LLM: once/conditional? does external poke survive?]
- this 0xD8: [LLM: once/conditional? does external poke survive?]
- this 0x104: [LLM: once/conditional? does external poke survive?]
- this 0x118: [LLM: once/conditional? does external poke survive?]
- this 0x11C: [LLM: once/conditional? does external poke survive?]
- this 0x120: [LLM: once/conditional? does external poke survive?]
- this 0x190: [LLM: once/conditional? does external poke survive?]
- this 0x192: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d453c | jpt_4D4162 | R | [LLM] |
| 004d455c | jpt_4D41E4 | R | [LLM] |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e9c8 | dbl_59E9C8 | R | Unknown_Double_59E9C8 [DERIVED] |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 0059fb48 | dbl_59FB48 | R | PhysicsConstant_59FB48 [DERIVED] |
| 005acf00 | dbl_5ACF00 | R | Double_Unknown_Render [DERIVED] |
| 005c32fc | aLaps_1 | R | LapsLabel [DERIVED] |
| 005c3300 | byte_5C3300 | R | VehicleFile_Count [DERIVED] |
| 005d2310 | aRacetime | R | aRacetime [DERIVED] |
| 005d3b6c | aDDevF119992002_3 | R | aDDevF119992002_3 [DERIVED] |
| 005d430c | aPreracepresent | R | PreRacePresentationString [DERIVED] |
| 005d4320 | dword_5D4320 | R | TrackCVarConstant [DERIVED] |
| 005d4324 | dword_5D4324 | R | UnknownDataInt [DERIVED] |
| 005d4328 | byte_5D4328 | R | Unknown_Byte_5D4328 [DERIVED] |
| 005d432c | aRacetimescaled | R | RacetimescaledString [DERIVED] |
| 005d433c | asc_5D433C | R | ASCIIString_5D433C [DERIVED] |
| 005d4340 | aDDF | R | Str_DDF [DERIVED] |
| 005d434c | aDefaultscoring | R | DefaultScoringString [DERIVED] |
| 005d435c | aWednesday | R | WednesdayString [DERIVED] |
| 005d4368 | byte_5D4368 | R | HUDVisibilityFlag [DERIVED] |
| 005d4374 | byte_5D4374 | R | CarNumberFontIndex [DERIVED] |
| 005d4384 | dword_5D4384 | R | Dword5D4384 [DERIVED] |
| 005d4388 | word_5D4388 | R | Unknown_Word_5D4388 [DERIVED] |
| 005d438c | off_5D438C | R | off_5D438C [DERIVED] |
| 005d4390 | aEnteredSteward_1 | R | String_EnteredSteward_1 [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 007cec54 | dword_7CEC54 | R | ReconPitClosed [DERIVED] |
| 007cec90 | dword_7CEC90 | R | VehicleLoadState [DERIVED] |
| 007ced8c | dword_7CED8C | R | UIRacePhaseFlag [DERIVED] |
| 007cee88 | dword_7CEE88 | R | SessionInitFlags [DERIVED] |
| 007d04a4 | dword_7D04A4 | R | RaceUint32_7D04A4 [DERIVED] |
| 007d05a0 | dword_7D05A0 | R | Race_UriCheck_05A0 [DERIVED] |
| 007d0798 | flt_7D0798 | R | RaceSetupScaling [CONFIRMED] |
| 007d0894 | dword_7D0894 | R | UnknownGameStateInt [DERIVED] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040da30 | CameraDirectorResetInit | [LLM] |
| 0040dc00 | StringPathExtensionManipulation | [LLM] |
| 0040dcd0 | StateMachineInitializer | [LLM] |
| 0042ce30 | SessionTypeNameLookup | [LLM] |
| 0042d140 | sub_42D140 | [LLM] |
| 00448300 | RandomScaledValue | [LLM] |
| 004c29f0 | sub_4C29F0 | [LLM] |
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 004d0ec0 | ArithmeticComparison_0ec0 | [LLM] |
| 004d0f00 | ShortComputation_0f00 | [LLM] |
| 004d1cd0 | SingleCallWrapper_1cd0 | [LLM] |
| 004d2dd0 | sub_4D2DD0 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00587ece | sub_587ECE | [LLM] |
| 0058850f | sub_58850F | [LLM] |
| 005887ed | StrlenFormatCallWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
