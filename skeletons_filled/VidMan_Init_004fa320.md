## VidMan_Init_004fa320 — VidManInitialize

**Summary:** Initializes the video/visual manager subsystem: sets rendering flags, loads the track scene file, initializes the audio engine with collision geometry, and configures force feedback. Returns 0 on success, 1 if audio engine initialization fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004f9480 | sub_4F9480 | R | Callback function pointer passed to sub_546230 for rendering/initialization step |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005cc220 | aCubeErrorLoadi_1 | R | String_CubeError [DERIVED] |
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix [DERIVED] |
| 005d6e9c | aEnteredVidmanI | R | EnteredVidManStr [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |
| 007cf65c | dword_7CF65C | R | ShadowMapConfigValue [DERIVED] |
| 007cfb90 | dword_7CFB90 | R | Unknown_Render_7CFB90 — rendering mode selector (1–3 or default) |
| 007cfbfc | dword_7CFBFC | R | UnknownDword_7CFBFC — rendering config flag |
| 007cfc20 | dword_7CFC20 | R | ParticleSystemPtr [DERIVED] |
| 007d032c | dword_7D032C | R | Unknown_Race_TimerFlag [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe70 | byte_8AFE70 | W | RaceByteFlag [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c55b0 | TrackSceneLoader | Load the scene file for the current track context |
| 004d15f0 | sub_4D15F0 | Initialize force feedback subsystem with base pointer |
| 004d7a50 | StringSplitLoop | Split/tokenize a string on delimiter; used for debug log parsing |
| 004d7aa0 | DebugLogWrite | Write a formatted debug log message to the debug buffer |
| 004f9480 | sub_4F9480 | Rendering initialization/step function called with float parameter |
| 0053c5b0 | StringRelocationCopy | Copy/relocate a string — called on failure path (scene load error) |
| 0053c800 | StringRegistry | Register a constructed path string in the global string registry |
| 0053d400 | SingleGlobalSetter | Set a single global value (3 - shadow map config) |
| 0053d410 | GlobalFlagSetter_d410 | Set a global flag from the particle system pointer |
| 0053d430 | ShortComputation_d430 | Perform a short computation on a rendering config value |
| 005458d0 | FlagBitSetter | Set a flag bit (bit 2) on success path |
| 00546010 | AudioEngineInitialization | Initialize the audio engine with collision geometry handle and track path |
| 00546230 | sub_546230 | Call a function pointer with a float argument; also used to reset with (0,0) |
| 0054a1c0 | sub_54A1C0 | Set rendering subsystem flags with (flag_id, value) pairs |
| 00551fb0 | SetAudioGlobalFlagFromBool | Set an audio global flag from a boolean config value |
| 0058815f | StringFormatWithBufferOverflowCheck | sprintf with buffer overflow protection for path construction |

**Guard conditions:** No early-return guards based on field values. The function always executes its main path. Switch on `dword_7CFB90` (rendering mode) selects different sub_54A1C0 flag configurations. AudioEngineInitialization return value gates success (0) vs failure (1) path — on failure, logs error with scene file path and returns 1.
