## OnScreen_Exit_0049f120 — OnScreen_Exit

**Summary:** OnScreen exit logging called from GameExit. Runs StringSplitLoop assertion check, logs "entered onscreen" message on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccf10 | aDDevF119992002_16 | R | AssertStr_SourcePath_16 [DERIVED] |
| 005ccfa8 | aEnteredOnscree_4 | R | EnteredOnscreenStr [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Assertion check parsing source path string (arg 2705) |
| 004d7aa0 | DebugLogWrite | Writes debug log message when assertion passes |

**Guard conditions:** Checks StringSplitLoop return != 0 — non-zero PASSES (log exit message), zero BLOCKS (skip log)
