## Render_Post_004b4170 — RenderPost

**Summary:** Post-render lifecycle marker — validates source path via StringSplitLoop, logs "Entered Render Post". Called from Game_Post during shutdown/cleanup sequence.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d23c8 | aDDevF119992002_21 | R | Source file path string assertion identifier |
| 005d241c | aEnteredRenderP | R | "Entered Render Post" debug string |
| 008ad25c | dword_8AD25C | R | Debug message buffer for log output |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Validate/process source path string (called with count 438) |
| 004d7aa0 | DebugLogWrite | Write post-render log message |

**Guard conditions:** Checks StringSplitLoop return value (byte). If zero: skip logging, return early. If non-zero (success): log "Entered Render Post".
