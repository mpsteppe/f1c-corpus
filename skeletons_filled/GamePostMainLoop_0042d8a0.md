## GamePostMainLoop_0042d8a0 — GamePostMainLoop

**Summary:** Main per-frame game processing loop: dispatches session state checks, runs the multi-phase physics/scoring/collision pipeline, updates camera, weather, rendering, HUD, and force feedback subsystems, then checks for loop exit conditions. Core game loop / main tick orchestrator.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 5 | loop state/phase counter — initialized to 5, may be read by external subsystems |

**Written-by note (persistence):**
- this 0x0: written once on entry (set to 5) — external poke after entry does NOT persist since it's the initial overwrite

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3590 | aDDevF119992002_11 | R | DevicePath_99_02 [DERIVED] — format string for debug logging |
| 005c3670 | aNextStateDWasN | R | NextStateDWasN [DERIVED] — debug log message format string |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] — scene setup data for multi-phase state machine |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] — session manager for camera director |
| 005ec6d0 | unk_5EC6D0 | R | data pointer passed to MainGameTickUpdate — main game state data |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] — array of module output pointers for collision broadcast |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] — main game module manager (session state, scoring, collision) |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] — restart gate input; value 5 continues loop, 4/6 exit |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] — if set, skips camera/render updates (HUD-only mode) |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] — passed to sub_4A1830 |
| 007d2e50 | dword_7D2E50 | R | SessionMsgCount [DERIVED] (also: ` — session message counter) — buffer reset target |
| 0083ee60 | dword_83EE60 | R | RingBufferCount [DERIVED] (also: ` -- ring buffer counter) — vehicle iteration and buffer reset target |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] — passed to RenderScreenSave |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] — scoring gate for conditional dispatch and state update |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] — passed to RenderTickUpdate |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] — passed to WeatherParticleUpdate |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] — force feedback subsystem |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] — debug log output buffer |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] — race phase timing context (init/reset each iteration) |
| 008afec0 | unk_8AFEC0 | R | Unknown_Setup_FEC0 [DERIVED] — passed to sub_4FCEE0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404460 | MultiPhaseProcessingStateMachine | runs multi-phase physics/state processing on scene setup data |
| 0040ca30 | MainCameraDirectorUpdate | updates main camera director using session manager |
| 0042c690 | MainGameTickUpdate | main game tick update processing |
| 00455e50 | CollisionGlobalUpdateBroadcast | broadcasts collision updates across all modules |
| 00461cd0 | SessionStateCheck | checks session state — returns 1 when session is in a specific active state |
| 00463ca0 | sub_463CA0 | processes game module manager state |
| 00463cd0 | CollisionResponseStatus | updates collision response status for game module manager |
| 004643c0 | SessionScoringUpdate | updates session scoring data |
| 0049f070 | ShortComputation_f070 | short computation on race session state |
| 004a0fd0 | RestartGate | checks restart gate condition — returns 5 to continue, 4/6 to exit loop |
| 004a1830 | sub_4A1830 | processes unknown session data |
| 004b3b40 | BufferReset | resets a buffer/counter to zero |
| 004b3ba0 | IterateVehicles | iterates over vehicle ring buffer |
| 004b40a0 | RenderScreenSave | renders screen save/capture using race session state |
| 004ba150 | ConditionalStateUpdate | updates conditional state on scoring gate |
| 004ba180 | ConditionalMultiPathDispatcher | dispatches conditional multi-path processing on scoring gate |
| 004ba6c0 | TwoPathDispatch | two-path dispatch on scoring gate |
| 004c8b70 | RenderTickUpdate | render tick update using scene array |
| 004cfcc0 | WeatherParticleUpdate | updates weather particles on scoring grid |
| 004d4580 | sub_4D4580 | processes force feedback base data |
| 004d7a50 | StringSplitLoop | string split loop utility — checks device path format |
| 004d7aa0 | DebugLogWrite | writes debug log message to buffer |
| 004f9f00 | ConditionalInit | initializes/acquires race phase timer context |
| 004f9f30 | ConditionalStateReset | releases/resets race phase timer context |
| 004fa7e0 | sub_4FA7E0 | performance HUD overlay update (calls FrameRateMonitorAndOverlayRenderer) |
| 004fcee0 | sub_4FCEE0 | processes unknown setup data |

**Guard conditions:** 
1. SessionStateCheck returns 1: PASSES into main processing with v2=1 (HUD-disabled mode, skips camera/screen save).
2. RestartGate returns != 5: BREAKS out of the main loop.
   - If returns 4: returns 0 (normal exit).
   - If returns != 6: calls StringSplitLoop for device path validation, logs debug message via DebugLogWrite if valid, returns 1.
3. v2 (HUDFlag) == 1: BLOCKS MainCameraDirectorUpdate and RenderScreenSave (only WeatherParticleUpdate runs).
4. v2 (HUDFlag) == 0: PASSES full render pipeline (camera, weather, screen save, short computation).
5. SessionStateCheck at end returns 1: exits loop cleanly (return 0).
