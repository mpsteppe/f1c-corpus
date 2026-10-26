## StateTriggerCheck_004b8ae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadingPhase1 (004b87c0), LoadingPhase2 (004b8940), sub_4B9890 (004b9890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF30 | R | — | [LLM] |
| this | 0xF34 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] |
| 007cc4c8 | dword_7CC4C8 | R | CheckFlag [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404460 | MultiPhaseProcessingStateMachine | [LLM] |
| 0040ca30 | MainCameraDirectorUpdate | [LLM] |
| 0042c690 | MainGameTickUpdate | [LLM] |
| 0044f460 | PackedFlagRead | [LLM] |
| 00455e50 | CollisionGlobalUpdateBroadcast | [LLM] |
| 0049f070 | ShortComputation_f070 | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004b40a0 | RenderScreenSave | [LLM] |
| 004b8790 | FloatGetter | [LLM] |
| 004b8c40 | sub_4B8C40 | [LLM] |
| 004ba180 | ConditionalMultiPathDispatcher | [LLM] |
| 004c8b70 | RenderTickUpdate | [LLM] |
| 004cfcc0 | WeatherParticleUpdate | [LLM] |
| 004d4580 | sub_4D4580 | [LLM] |
| 004fa7e0 | sub_4FA7E0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
