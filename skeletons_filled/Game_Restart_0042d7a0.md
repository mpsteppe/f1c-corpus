## Game_Restart_0042d7a0 — Game Subsystem Restart Orchestrator

**Summary:** Executes a full game restart sequence: sets game state to 4 (restarting), then calls restart/reset functions for all engine subsystems in dependency order — sound, special effects, input, dynamics, camera, rendering, HUD, video, player file, AI, and scoring. Part of the game state machine and session management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 4 | game state flag (4 = restart/loading phase) |

**Written-by note (persistence):**
- this 0x0: written once per restart call — external poke persists until next restart or state transition

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] |
| 005c3658 | aEnteredGameRes | R | EnteredGameResString [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | global config/data block passed to VidMan_Restart |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008ad264 | dword_8AD264 | R | PenaltyMessageQueue [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404250 | SurfaceHeightfieldCollisionCallback | reinitializes surface/heightfield collision data from setup scene |
| 0040c9e0 | CamMan_Restart | restarts camera manager subsystem (passes session manager pointer) |
| 00418e50 | HUDDisplayDataReset | resets HUD display data structures from game state array |
| 0042c3b0 | DynMan_Restart | restarts dynamics/physics manager subsystem |
| 00455da0 | HWInput_Restart | restarts hardware input manager (passes module pointer array) |
| 00464290 | SynchronizeWithServer | synchronizes game module state with server/multiplayer backend |
| 0049f000 | OnScreen_Restart | restarts on-screen display / overlay manager (passes race session state) |
| 004a0fb0 | GlobalZeroInit | zero-initializes global session transition flag block |
| 004a1830 | sub_4A1830 | restarts/resets session-related structure at unk_7CE2A4 |
| 004a40f0 | ArrayZeroInit | zero-initializes AI struct array at unk_7CE2F0 |
| 004b18d0 | PlayerFile_Restart | restarts player file/config autoload (passes AutoLoadConfigFile flag) |
| 004b4060 | Render_Restart | restarts rendering subsystem (passes race session state byte) |
| 004ba460 | sub_4BA460 | restarts/resets scoring gate subsystem (passes dword_8AB6E4) |
| 004c8b20 | Sound_Restart | restarts sound/audio subsystem (passes first scene name) |
| 004cfc90 | SpecialFX_Restart | restarts special effects subsystem (passes scoring grid base) |
| 004d3cf0 | Steward_Restart | restarts steward/marshal subsystem (passes force feedback base) |
| 004d7a50 | StringSplitLoop | string parsing utility (checks device path string with delimiter, max 509) |
| 004d7aa0 | DebugLogWrite | writes debug log message to message buffer ("Entered GameRestart") |
| 004d7b00 | sub_4D7B00 | restarts penalty message queue subsystem |
| 004fa640 | VidMan_Restart | restarts video/display manager (passes game race phase timer) |
| 004fcc30 | sub_4FCC30 | restarts unknown setup/configuration block at unk_8AFEC0 |

**Guard conditions:** No branching guards — function unconditionally sets game state to 4 and executes all subsystem restarts in fixed sequence. The StringSplitLoop call at line 4 only gates the debug log write (line 5), not the restart flow. Function always returns 0.
