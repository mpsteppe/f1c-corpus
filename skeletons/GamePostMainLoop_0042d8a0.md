## GamePostMainLoop_0042d8a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 5 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3670 | aNextStateDWasN | R | NextStateDWasN [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007d2e50 | dword_7D2E50 | R | SessionMsgCount [DERIVED] (also: ` — session message counter) |
| 0083ee60 | dword_83EE60 | R | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404460 | MultiPhaseProcessingStateMachine | [LLM] |
| 0040ca30 | MainCameraDirectorUpdate | [LLM] |
| 0042c690 | MainGameTickUpdate | [LLM] |
| 00455e50 | CollisionGlobalUpdateBroadcast | [LLM] |
| 00461cd0 | SessionStateCheck | [LLM] |
| 00463ca0 | sub_463CA0 | [LLM] |
| 00463cd0 | CollisionResponseStatus | [LLM] |
| 004643c0 | SessionScoringUpdate | [LLM] |
| 0049f070 | ShortComputation_f070 | [LLM] |
| 004a0fd0 | RestartGate | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004b3b40 | BufferReset | [LLM] |
| 004b3ba0 | IterateVehicles | [LLM] |
| 004b40a0 | RenderScreenSave | [LLM] |
| 004ba150 | ConditionalStateUpdate | [LLM] |
| 004ba180 | ConditionalMultiPathDispatcher | [LLM] |
| 004ba6c0 | TwoPathDispatch | [LLM] |
| 004c8b70 | RenderTickUpdate | [LLM] |
| 004cfcc0 | WeatherParticleUpdate | [LLM] |
| 004d4580 | sub_4D4580 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9f00 | ConditionalInit | [LLM] |
| 004f9f30 | ConditionalStateReset | [LLM] |
| 004fa7e0 | sub_4FA7E0 | [LLM] |
| 004fcee0 | sub_4FCEE0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
