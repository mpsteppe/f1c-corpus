## DynMan_Enter_0042c130 — DynMan_Enter

**Summary:** Dynamic management enter handler: processes build path string via StringSplitLoop, logs "Entered DynMan Enter" message, then calls SeasonScoringReset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c331c | aEnteredDynmanE | R | EnteredDynmanEString [DERIVED] |
| 005c3334 | aDDevF119992002_12 | R | sBuildPath [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Process build path string with delimiter and maximum length |
| 004d7aa0 | DebugLogWrite | Write debug log message to debug output buffer |

**Guard conditions:** StringSplitLoop returns 0: skip DebugLogWrite (log suppressed). Passes always — SeasonScoringReset called unconditionally.
