## CamMan_Init_0040c920 — CameraManagerInit

**Summary:** Initializes the camera manager: resolves main view string, clears game state flags, loads scene file, module assets, camera config, links loaders, and sets a global init flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | camera manager handle resolved from TwoLevelWideStringSearch("mainview") |
| this | 0x8 | RW | — | copied from this+0x18 when sub_40C140 succeeds; stores config loader result |
| this | 0x18 | R | — | config loader object pointer (set by sub_40C140) |
| this | 0x2D | RW | 0 | byte flag, initialized to 0 |

**Written-by note (persistence):**
- this 0x0: set once during init from string lookup; persists for lifetime
- this 0x8: set once from this+0x18 after config load; persists
- this 0x2D: set to 0 once during init; may be modified externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be8e0 | aMainview | R | StrMainView [DERIVED] — "mainview" string for camera manager lookup |
| 005be940 | aEnteredCammanI | R | EnteredCamManIString [DERIVED] — debug log string |
| 005be958 | aDDevF119992002_15 | R | AssertStr_SourcePath_15 [DERIVED] |
| 005ea500 | dword_5EA500 | W | GameStateFlag_5EA500 [DERIVED] — cleared to 0 |
| 005ea504 | dword_5EA504 | W | UIMenuState [DERIVED] — cleared to 0 |
| 005ea508 | dword_5EA508 | W | UIDispatchTable [DERIVED] — cleared to 0 |
| 005ea550 | dword_5EA550 | W | Unknown_GameState_5EA550 [DERIVED] — cleared to 0 |
| 005ea554 | dword_5EA554 | W | Unknown_Flag_5EA554 [DERIVED] — cleared to 0 |
| 005ea558 | dword_5EA558 | W | Unknown_SetupFlag [DERIVED] — cleared to 0 |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c140 | CameraConfigLoader | loads camera config from cams.cfg/default.cfg |
| 0040c240 | CameraSceneFileLoader | loads camera scene file based on current scene index |
| 0040c3b0 | CameraModuleAssetPathLoader | loads second camera module asset file |
| 0040c520 | CrossLinkSceneAndModuleObjects | cross-links scene and module loader objects |
| 004d7a50 | StringSplitLoop | debug log gating — returns non-zero to enable logging |
| 004d7aa0 | DebugLogWrite | writes "entered CamMan_Init" debug message |
| 00544f50 | TwoLevelWideStringSearch | resolves "mainview" string to camera manager handle |
| 0054a200 | GlobalFlagSetClear | sets global flag 32 (init complete) |

**Guard conditions:** if StringSplitLoop returns non-zero, writes debug log entry. If sub_40C140 fails (returns non-zero), this+0x8 is NOT updated from this+0x18.
