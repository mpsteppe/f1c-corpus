## AutoJoinRetryLoop_004637a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC6 | R | — | [LLM] |
| obj | 0x3FB8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c329c | dword_5C329C | W | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6508 | aCouldNotAutojo | R | CouldNotAutojoString [DERIVED] |
| 005c6530 | aCouldNotSwitch | R | Str_CouldNotSwitch [DERIVED] |
| 005c6578 | aAutojoinFailur | R | StringAutoJoinFailure [DERIVED] |
| 005c6590 | aClientTeamSele | R | StrClientTeamSelect [DERIVED] |
| 005c65a4 | aAutojoinAttemp | R | AutojoinAttemptString [DERIVED] |
| 005c65c4 | asc_5C65C4 | R | ASC_Separator [DERIVED] |
| 005c65c8 | aJoiningSession | R | JoiningSessionString [DERIVED] |
| 005c65d8 | aAutojoinWaitPa | R | AutojoinWaitStr [DERIVED] |
| 005cc9e8 | dword_5CC9E8 | R | SessionInitState [CONFIRMED] (also: ` — multiplayer active flag) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC [LLM: field purpose] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007d0410 | dword_7D0410 | W | ChampionshipMode [FACT] (also: RaceMode) |
| 007d0418 | dword_7D0418 | R | SessionTimeoutOverride [DERIVED] |
| 007d041c | dword_7D041C | R | RaceModeTimeoutAlt [DERIVED] (also: ` — alternate timeout sources) |
| 007d0f28 | flt_7D0F28 | R | AutoJoinTimeout [DERIVED] (also: ` — join timeout threshold) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 004537b0 | sub_4537B0 | [LLM] |
| 00461550 | FAILWRONGDESCRIPTION | [LLM] |
| 00461900 | SessionConfigWriteback | [LLM] |
| 00461cd0 | SessionStateCheck | [LLM] |
| 00462ce0 | CollisionSpatialQuery | [LLM] |
| 00462d30 | EnumToEnumTranslator | [LLM] |
| 00462da0 | sub_462DA0 | [LLM] |
| 004630d0 | UniqueID | [LLM] |
| 00463750 | ConstantOffsetAccessor | [LLM] |
| 00466080 | CallWrapper | [LLM] |
| 00485b90 | sub_485B90 | [LLM] |
| 00497250 | ShortComputation_7250 | [LLM] |
| 00497940 | LookupDispatch | [LLM] |
| 004a0af0 | sub_4A0AF0 | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b1600 | PathPathRegistryWriter | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 004f9ad0 | ArithmeticComparison_9ad0 | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568ba0 | StructZeroInit_8ba0 | [LLM] |
| 00568be0 | QPCTimerInitialization | [LLM] |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | [LLM] |
| 00568cf0 | HighResolutionTimerDelta | [LLM] |
| 00568d90 | PerformanceCounterDiffWithScaling | [LLM] |
| 0057a920 | SingleFunctionCallWrapper_a920 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
