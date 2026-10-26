## DynMan_Setup_0042c170 — DynMan_Setup

**Summary:** Dynamic management setup handler: processes build path string via StringSplitLoop, logs "Entered DynMan Setup" message on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 005c335c | aEnteredDynmanS | R | EnteredDynmanString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Process build path string with delimiter and max length parameter |
| 004d7aa0 | DebugLogWrite | Write debug log message to debug output buffer |

**Guard conditions:** StringSplitLoop returns 0: skip DebugLogWrite, return 0. StringSplitLoop returns non-zero: write debug log, return result value.
