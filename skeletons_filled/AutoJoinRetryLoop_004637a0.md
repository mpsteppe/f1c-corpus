## AutoJoinRetryLoop_004637a0 — Multiplayer Auto-Join Retry Loop with Session State Machine

**Summary:** Implements the multiplayer auto-join retry loop: checks if auto-join is enabled (byte at *this+0xC6), determines championship mode (5=multiplayer), runs a retry loop with timeout (flt_7D0F28) that polls session state, attempts join via SessionStateTransition, resets vehicle arrays on success, and handles failure/logging paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC6 | R | — | auto-join enabled flag (byte at *this+198, gates entire function) |
| obj | 0x3FB8 | R | — | pointer to something at *this+16312 (passed to SingleFunctionCallWrapper_a920) |
| this | 0x0 | R | — | this pointer (dereferenced for flags and pointer fields) |

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
| 005ec6d0 | unk_5EC6D0 | R | per-vehicle data table base (vehicle[0] struct start, read during join retry) |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC — vehicle state/flag field at offset 0xC in vehicle struct |
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
| 00423a00 | BinarySearchInStringTable | search for string in table (used to check if joining session message already displayed) |
| 0042bc80 | BuildActiveVehiclePointerArray | rebuild vehicle pointer array after join reset |
| 004537b0 | sub_4537B0 | per-frame update dispatch (called with module pointer array) |
| 00461550 | FAILWRONGDESCRIPTION | read/write failure description buffer |
| 00461900 | SessionConfigWriteback | write session config back (after join) |
| 00461cd0 | SessionStateCheck | check current session state (returns 3 = ready to join) |
| 00462ce0 | CollisionSpatialQuery | spatial query / collision check (used as guard for join eligibility) |
| 00462d30 | EnumToEnumTranslator | translate enum/state value (returns 0=ok, 3=special failure) |
| 00462da0 | sub_462DA0 | get failure description string for a given error code |
| 004630d0 | UniqueID | generate unique session ID |
| 00463750 | ConstantOffsetAccessor | access constant offset from this ptr |
| 00466080 | CallWrapper | call wrapper / dispatch function |
| 00485b90 | sub_485B90 | sub-step retry caller (recursive call to advance retry logic) |
| 00497250 | ShortComputation_7250 | short computation / cleanup (called on autojoin failure) |
| 00497940 | LookupDispatch | UI message lookup and dispatch (show popup text) |
| 004a0af0 | sub_4A0AF0 | session data initialization with critical section |
| 004a1830 | sub_4A1830 | session state advancement |
| 004b0170 | EmptyStub_0170 | cleanup/reset stub (passed timer struct for teardown) |
| 004b1600 | PathPathRegistryWriter | write registry/path config for auto-load |
| 004d7a50 | StringSplitLoop | parse dev config string for logging level check |
| 004d7aa0 | DebugLogWrite | write to debug log buffer |
| 004ef5a0 | SessionStateTransition | transition session state (vehicle array reset) |
| 004f9ad0 | ArithmeticComparison_9ad0 | arithmetic compare on game timer |
| 005665b0 | sub_5665B0 | string append to display buffer |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer realloc |
| 00568ba0 | StructZeroInit_8ba0 | zero-init timer struct |
| 00568be0 | QPCTimerInitialization | initialize high-resolution QPC timer |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | reset timer via QueryPerformanceCounter |
| 00568cf0 | HighResolutionTimerDelta | compute elapsed time delta from timer |
| 00568d90 | PerformanceCounterDiffWithScaling | performance counter diff with scaling (returns seconds elapsed) |
| 0057a920 | SingleFunctionCallWrapper_a920 | single call wrapper (pre-join dispatch) |
| 00587bdc | CRTFtol | C runtime float-to-long conversion |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with buffer overflow protection |

**Guard conditions:** Outer guard: `byte at (*this+0xC6)` must be non-zero (auto-join enabled). Inner loop guards: (1) SessionStateCheck returns 3 → attempt join (UniqueID + SessionStateTransition + vehicle array rebuild); (2) timeout: PerformanceCounterDiffWithScaling > flt_7D0F28 → failure path, check EnumToEnumTranslator result — if ==3, special failure (continue retry), else exit; (3) SessionInitState (dword_5CC9E8) == -1 → early exit failure. CollisionSpatialQuery must pass to enter retry loop, else block exit with "could not autojoin" message. When v14 exceeds 10.0 during retry, CollisionSpatialQuery is re-run as a refresh check. Dev logging only active when dword_7C569C != 5 (not server mode).
