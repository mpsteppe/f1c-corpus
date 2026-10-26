## OnScreen_Post_0049f0d0 — OnScreen_Post

**Summary:** OnScreen post-frame cleanup called from Game_Post. Runs assertion log, calls session utility function, triggers multi-stage cleanup on UI singleton, then cleans up static array.

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
| 0049b1c0 | StaticArrayCleanup | Cleans up static array data |
| 0049d150 | MultiStageCleanupWithRepeatedCallCycle | Multi-stage cleanup on UI singleton |
| 004d7a50 | StringSplitLoop | Assertion check parsing source path string (arg 2688) |
| 004d7aa0 | DebugLogWrite | Writes debug log message when assertion passes |
| 004d8720 | UtilityFunction_8720 | Session-mode utility function |

**Guard conditions:** Checks StringSplitLoop return != 0 (assertion log gate)
