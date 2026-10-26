## VidMan_Init_004fa320 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004f9480 | sub_4F9480 | R | [LLM] |
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
| 007cfb90 | dword_7CFB90 | R | Unknown_Render_7CFB90 [DERIVED] |
| 007cfbfc | dword_7CFBFC | R | UnknownDword_7CFBFC [DERIVED] |
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
| 004c55b0 | TrackSceneLoader | [LLM] |
| 004d15f0 | sub_4D15F0 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9480 | sub_4F9480 | [LLM] |
| 0053c5b0 | StringRelocationCopy | [LLM] |
| 0053c800 | StringRegistry | [LLM] |
| 0053d400 | SingleGlobalSetter | [LLM] |
| 0053d410 | GlobalFlagSetter_d410 | [LLM] |
| 0053d430 | ShortComputation_d430 | [LLM] |
| 005458d0 | FlagBitSetter | [LLM] |
| 00546010 | AudioEngineInitialization | [LLM] |
| 00546230 | sub_546230 | [LLM] |
| 0054a1c0 | sub_54A1C0 | [LLM] |
| 00551fb0 | SetAudioGlobalFlagFromBool | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
