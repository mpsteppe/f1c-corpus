## SpecialFX_Enter_004cee90 — SpecialFX_Enter

**Summary:** Debug trace function called when entering the special effects system. Logs "entered special" message via conditional debug write.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d38f8 | aEnteredSpecial | R | String_EnteredSpecial [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | conditional debug/log trace trigger |
| 004d7aa0 | DebugLogWrite | write debug log message to buffer |

**Guard conditions:** If StringSplitLoop(2, ...) returns non-zero → log entry message. If zero → skip logging.
