## Sound_Restart_004c8b20 — SoundRestartStateReset

**Summary:** Resets virtual dispatch state on sound context, zeros scene camera parameter global, and reinitializes sound buffer. Called from Game_Restart.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005d33f0 | aEnteredSoundRe | R | EnteredSoundReString [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 008ac4b0 | flt_8AC4B0 | R | SceneCameraParam [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c7dd0 | FieldZero4 | Zeros a 4-byte field at given address |
| 004c8630 | VirtualDispatchStateReset | Resets virtual dispatch state for sound context |
| 004d7a50 | StringSplitLoop | Parses/splits string by delimiter with expected token count |
| 004d7aa0 | DebugLogWrite | Writes debug log message to buffer |

**Guard conditions:** StringSplitLoop return. If non-zero, logs "Entered sound restart". All other calls unconditional.
