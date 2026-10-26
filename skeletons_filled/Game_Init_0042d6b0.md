## Game_Init_0042d6b0 — Game Subsystem Initialization Orchestrator

**Summary:** Top-level game initialization function that sequentially starts all major subsystems (video, scene, AI, sound, rendering, input, physics, camera, special effects, UI, session manager). Sets game state to 3 (init phase) and returns 1 if video init fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 3 | game state / initialization phase (3 = subsystem init in progress) |

**Written-by note (persistence):**
- this 0x0: written once at game startup — external poke persists until next call of this function (game restart)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3640 | aEnteredGameIni | R | EnteredGameIniString [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | pointer passed to sub_4FCAA0 (physics/setup system init) |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab710 | dword_8AB710 | R | UIWidgetList [DERIVED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004040a0 | AIDatabase_Init | initializes AI driver database and behavior tables |
| 0040c920 | CamMan_Init | initializes camera manager subsystem |
| 0042c1a0 | DynMan_Init | initializes dynamic object manager (physics world objects) |
| 00455d50 | HWInput_Init | initializes hardware input system (keyboard, wheel, gamepad) |
| 00463f70 | SessionTypeSetter | configures session type based on loaded game module data |
| 0049efa0 | OnScreen_Init | initializes on-screen display / HUD subsystem |
| 004a1830 | sub_4A1830 | initializes unknown session-related struct at 0x7CE2A4 |
| 004a40e0 | LargeBufferZeroInit | zeroes a large buffer/struct at 0x7CE2F0 (AI-related data) |
| 004b0170 | EmptyStub_0170 | no-op / placeholder stub (called with session transition flag) |
| 004b4030 | Render_Init | initializes rendering subsystem |
| 004ba1f0 | sub_4BA1F0 | initializes scoring/grid system (called with ScoringGate) |
| 004bdc10 | SceneExtentComputation | computes scene extents/bounds for UI widget layout |
| 004c8ae0 | Sound_Init | initializes audio/sound subsystem |
| 004cf070 | SpecialFX_Init | initializes special effects / particle system |
| 004d38f0 | Steward_Init | initializes race steward / force feedback system |
| 004d7a50 | StringSplitLoop | parses device path string (game install path validation) |
| 004d7aa0 | DebugLogWrite | writes debug log message ("Entered game ini") |
| 004fa320 | VidMan_Init | initializes video manager (returns 0 on success, non-zero on failure) |
| 004fcaa0 | sub_4FCAA0 | initializes additional physics/setup subsystem |

**Guard conditions:** 
- `StringSplitLoop(2, aDDevF119992002_11, 467)`: If string parsing succeeds (non-zero), write "Entered game ini" to debug log.
- `VidMan_Init(&unk_8AFE18)`: If video initialization returns non-zero (failure), abort and return 1 immediately. No further subsystems are initialized.
- All other init calls are unconditional once VidMan_Init succeeds.
