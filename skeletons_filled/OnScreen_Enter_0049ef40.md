## OnScreen_Enter_0049ef40 — OnScreen_Enter

**Summary:** OnScreen debug-log entry point called during Game_Enter. Runs StringSplitLoop as assertion check, logs "entered onscreen" message on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccef4 | aEnteredOnscree | R | EnteredOnScreenString [DERIVED] |
| 005ccf10 | aDDevF119992002_16 | R | AssertStr_SourcePath_16 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Assertion check parsing source path string (arg 2604) |
| 004d7aa0 | DebugLogWrite | Writes debug log message when assertion passes |

**Guard conditions:** Checks StringSplitLoop return != 0 — non-zero PASSES (log enter message), zero BLOCKS (skip log)
