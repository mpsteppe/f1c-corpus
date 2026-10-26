## DynMan_Exit_0042ca70 — DynManExitLog

**Summary:** Logs a debug message indicating entry into DynMan (Dynamic Manager) exit routine. Used by game shutdown path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 005c34b0 | aEnteredDynmanE_0 | R | Str_EnteredDynmanE [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parse/log build path string segment, returns status |
| 004d7aa0 | DebugLogWrite | Write formatted debug message to debug buffer |

**Guard conditions:** Guard: StringSplitLoop returns zero → BLOCKED (skip log). Returns non-zero → PASSES (calls DebugLogWrite with entry message).
