## VidMan_Setup_004fa2f0 — VidmanSetupLogInit

**Summary:** Initializes a debug message buffer with a path prefix and logs an "entered VidMan" message on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix [DERIVED] |
| 005d6e84 | aEnteredVidmanS | R | EnteredVidManString [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | split/format message string with path prefix into buffer |
| 004d7aa0 | DebugLogWrite | write debug log message to output |

**Guard conditions:** StringSplitLoop returns non-zero → write debug log entry; returns zero → skip log write.
