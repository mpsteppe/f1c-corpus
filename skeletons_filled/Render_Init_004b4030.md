## Render_Init_004b4030 — RenderInit

**Summary:** Initializes render subsystem by calling StringSplitLoop for path validation, then logs "Entered Render Init" on success. Called from Game_Init during startup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d23b0 | aEnteredRenderI | R | "Entered Render Init" debug string |
| 005d23c8 | aDDevF119992002_21 | R | Source file path string assertion identifier |
| 008ad25c | dword_8AD25C | R | Debug message buffer for log output |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Validate/process source path string (called with count 199) |
| 004d7aa0 | DebugLogWrite | Write initialization log message |

**Guard conditions:** Checks StringSplitLoop return value (byte). If zero: skip logging, return early. If non-zero (success): log "Entered Render Init".
