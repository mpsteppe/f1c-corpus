## Sound_Setup_004c8ab0 — SoundSetupLog

**Summary:** Calls string split parser on default scene path with token count 683; conditionally logs "Entered sound setup" message. Called from Game_Setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005d33c0 | aEnteredSoundSe | R | StringEnteredSoundSet [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parses/splits string by delimiter with expected token count |
| 004d7aa0 | DebugLogWrite | Writes debug log message to buffer |

**Guard conditions:** StringSplitLoop return value. If non-zero, logs "Entered sound setup" and returns that result. If zero, returns 0 silently (no log).
