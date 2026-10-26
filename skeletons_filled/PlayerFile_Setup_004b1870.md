## PlayerFile_Setup_004b1870 — Player file setup on game start

**Summary:** Called from Game_Setup to initialize player file subsystem. Logs debug "entered playerf" message on path-split success, then runs two-phase init through sub_4B0770 and PlayerFileInit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d22e0 | aDDevF119992002_20 | R | SourcePath_F1_1999_2002_20 [DERIVED] |
| 005d2350 | aEnteredPlayerf_0 | R | EnteredPlayerfString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0540 | PlayerFileInit | Initialize player file data structures |
| 004b0770 | sub_4B0770 | Reset/initialize player data state |
| 004d7a50 | StringSplitLoop | Parse debug path string, return success flag |
| 004d7aa0 | DebugLogWrite | Write debug log message to debug buffer |

**Guard conditions:** StringSplitLoop return (non-zero = parse success) gates DebugLogWrite. On success, logs "entered playerf". On failure, skips log. Always proceeds to init calls.
