## Sound_Enter_004c8a20 — SoundSystemEnter

**Summary:** Sound system entry/init called from Game_Enter. Lazily initializes audio resources, dispatches global guard, queries scene graph nodes, and logs sound environment entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3380 | aEnteredSoundEn | R | EnteredSoundEnvString [DERIVED] |
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf380 | flt_7CF380 | R | RenderFadeAlpha [DERIVED] (also: ` -- unknown float global) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004116c0 | SceneGraphQuery | Queries scene graph node by type (0=background, 1=foreground?) |
| 004184f0 | LazyRendererAudioInitCheck | Lazily checks/initializes renderer audio component |
| 004c82c0 | InitWithStatusCheck | Checks if sound system is already initialized |
| 004c82f0 | sub_4C82F0 | Fallback init path when InitWithStatusCheck fails |
| 004c83b0 | sub_4C83B0 | Initializes sound context struct (this) |
| 004c8560 | LazyAudioResourceInit | Lazily initializes audio resources |
| 004c8900 | GlobalDispatchWithGuard | Dispatches global guard with fade-alpha parameter |
| 004d7a50 | StringSplitLoop | Parses/splits string by delimiter, returns success flag |
| 004d7aa0 | DebugLogWrite | Writes debug log message to buffer |

**Guard conditions:** No early-return guard. StringSplitLoop return used only for conditional logging. InitWithStatusCheck result gates fallback init call but does not block rest of function.
