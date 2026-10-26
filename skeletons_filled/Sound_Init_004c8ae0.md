## Sound_Init_004c8ae0 — SoundInitLog

**Summary:** Logs "Entered sound init" conditionally after string parsing; unconditionally dispatches network message with scene camera parameter. Called from Game_Init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005d33d8 | aEnteredSoundIn | R | Str_EnteredSoundIn [DERIVED] |
| 008ac4b0 | flt_8AC4B0 | R | SceneCameraParam [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parses/splits string by delimiter with expected token count |
| 004d7aa0 | DebugLogWrite | Writes debug log message to buffer |

**Guard conditions:** StringSplitLoop return. If non-zero, logs "Entered sound init". Network message dispatch is unconditional.
