## OnScreen_Setup_0049ef70 — OnScreen_Setup

**Summary:** OnScreen debug-log entry point called during Game_Setup. Runs StringSplitLoop assertion check, logs "entered onscreen" message if assertion passes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccf10 | aDDevF119992002_16 | R | AssertStr_SourcePath_16 [DERIVED] |
| 005ccf38 | aEnteredOnscree_0 | R | EnteredOnscreeString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Assertion check parsing source path string (arg 2610) |
| 004d7aa0 | DebugLogWrite | Writes debug log message when assertion passes |

**Guard conditions:** Checks StringSplitLoop return != 0 — non-zero PASSES (log enter message), zero BLOCKS (skip log)
