## Game_Init_0042d6b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 3 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3640 | aEnteredGameIni | R | EnteredGameIniString [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
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
| 004040a0 | AIDatabase_Init | [LLM] |
| 0040c920 | CamMan_Init | [LLM] |
| 0042c1a0 | DynMan_Init | [LLM] |
| 00455d50 | HWInput_Init | [LLM] |
| 00463f70 | SessionTypeSetter | [LLM] |
| 0049efa0 | OnScreen_Init | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004a40e0 | LargeBufferZeroInit | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b4030 | Render_Init | [LLM] |
| 004ba1f0 | sub_4BA1F0 | [LLM] |
| 004bdc10 | SceneExtentComputation | [LLM] |
| 004c8ae0 | Sound_Init | [LLM] |
| 004cf070 | SpecialFX_Init | [LLM] |
| 004d38f0 | Steward_Init | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004fa320 | VidMan_Init | [LLM] |
| 004fcaa0 | sub_4FCAA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
