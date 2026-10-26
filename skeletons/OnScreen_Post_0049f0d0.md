## OnScreen_Post_0049f0d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccf10 | aDDevF119992002_16 | R | AssertStr_SourcePath_16 [DERIVED] |
| 005ccf8c | aEnteredOnscree_3 | R | EnteredOnScreenString [DERIVED] |
| 007ce058 | dword_7CE058 | R | Unknown_UI_Singleton [DERIVED] (also: ` — UI context object) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b1c0 | StaticArrayCleanup | [LLM] |
| 0049d150 | MultiStageCleanupWithRepeatedCallCycle | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004d8720 | UtilityFunction_8720 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
