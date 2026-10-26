## Game_Post_0042da30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 6 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3690 | aEnteredGamePos | R | s_DebugEnteredGamePos [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004045f0 | ShortComputation_45f0 | [LLM] |
| 0040cce0 | CamMan_Post | [LLM] |
| 0042c9f0 | DynMan_Post | [LLM] |
| 00455e70 | HWInput_Post | [LLM] |
| 00464600 | SessionStateByte7CE25FSetter | [LLM] |
| 0049f0d0 | OnScreen_Post | [LLM] |
| 004a11b0 | GlobalFlagClear | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004b1900 | PlayerFile_Post | [LLM] |
| 004b4170 | Render_Post | [LLM] |
| 004ba740 | GuardedDispatchWithStateCheck | [LLM] |
| 004bdde0 | F_65xNestedCallLoop | [LLM] |
| 004c8ca0 | Sound_Post | [LLM] |
| 004cfed0 | SpecialFX_Post | [LLM] |
| 004d4600 | Steward_Post | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004fac00 | VidMan_Post | [LLM] |
| 004fd6d0 | TwoCallDelegation_d6d0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
