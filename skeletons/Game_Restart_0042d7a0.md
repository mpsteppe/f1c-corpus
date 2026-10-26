## Game_Restart_0042d7a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 4 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3658 | aEnteredGameRes | R | EnteredGameResString [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad264 | dword_8AD264 | R | PenaltyMessageQueue [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404250 | SurfaceHeightfieldCollisionCallback | [LLM] |
| 0040c9e0 | CamMan_Restart | [LLM] |
| 00418e50 | HUDDisplayDataReset | [LLM] |
| 0042c3b0 | DynMan_Restart | [LLM] |
| 00455da0 | HWInput_Restart | [LLM] |
| 00464290 | SynchronizeWithServer | [LLM] |
| 0049f000 | OnScreen_Restart | [LLM] |
| 004a0fb0 | GlobalZeroInit | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004a40f0 | ArrayZeroInit | [LLM] |
| 004b18d0 | PlayerFile_Restart | [LLM] |
| 004b4060 | Render_Restart | [LLM] |
| 004ba460 | sub_4BA460 | [LLM] |
| 004c8b20 | Sound_Restart | [LLM] |
| 004cfc90 | SpecialFX_Restart | [LLM] |
| 004d3cf0 | Steward_Restart | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004d7b00 | sub_4D7B00 | [LLM] |
| 004fa640 | VidMan_Restart | [LLM] |
| 004fcc30 | sub_4FCC30 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
