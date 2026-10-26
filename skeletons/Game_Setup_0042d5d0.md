## Game_Setup_0042d5d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 2 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3628 | aEnteredGameSet | R | EnteredGameSetString [DERIVED] |
| 005ec488 | dword_5EC488 | R | PlayerFile [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042c170 | DynMan_Setup | [LLM] |
| 00455c60 | HWInput_Setup | [LLM] |
| 00463ef0 | sub_463EF0 | [LLM] |
| 0049ef70 | OnScreen_Setup | [LLM] |
| 004a0eb0 | Options_Setup | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004b1870 | PlayerFile_Setup | [LLM] |
| 004ba1e0 | SimpleZeroInit | [LLM] |
| 004c8ab0 | Sound_Setup | [LLM] |
| 004ceec0 | SpecialFX_Setup | [LLM] |
| 004d36d0 | Steward_Setup | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9160 | UtilityFunction_9160 | [LLM] |
| 004fa2f0 | VidMan_Setup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
