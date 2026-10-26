## PlayerFile_Restart_004b18d0 — Player file restart handler

**Summary:** Called from Game_Restart. Logs "entered playerf" debug message after successful debug path parse. No struct fields accessed — pure logging stub.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d22e0 | aDDevF119992002_20 | R | SourcePath_F1_1999_2002_20 [DERIVED] |
| 005d236c | aEnteredPlayerf_1 | R | EnteredPlayerFileStr [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parse debug path string, return success flag |
| 004d7aa0 | DebugLogWrite | Write debug log message to debug buffer |

**Guard conditions:** StringSplitLoop return value (non-zero = parse success) gates DebugLogWrite. On success, logs "entered playerf" and returns 1. On failure, returns 0 without logging.
