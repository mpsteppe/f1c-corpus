## Render_Restart_004b4060 — RenderRestart

**Summary:** Resets render state by filling 168-byte struct `this` with 0x01 byte pattern, logs "Entered Render Restart". Called from Game_Restart during session restart.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d23c8 | aDDevF119992002_21 | R | Source file path string assertion identifier |
| 005d23f0 | aEnteredRenderR | R | "Entered Render Restart" debug string |
| 008ad25c | dword_8AD25C | R | Debug message buffer for log output |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Validate/process source path string (called with count 215) |
| 004d7aa0 | DebugLogWrite | Write restart log message |

**Guard conditions:** Checks StringSplitLoop return value (byte). If zero: skip logging. If non-zero (success): log "Entered Render Restart". Struct memset always executes regardless.
