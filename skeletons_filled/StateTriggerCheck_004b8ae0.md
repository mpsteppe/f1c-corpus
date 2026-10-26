## StateTriggerCheck_004b8ae0 — StateTriggerCheck

**Summary:** Tests whether a game state/loading transition trigger condition is met — first checks that the target threshold exceeds the current value, then ticks all major game subsystems (physics, rendering, camera, weather, collision, session state), and returns 1 only if the loading progress has reached or exceeded the target threshold; returns 0 if blocked by any early-exit guard.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadingPhase1 (004b87c0), LoadingPhase2 (004b8940), sub_4B9890 (004b9890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF30 | R | — | Current loading progress value (this[972]) — compared against target to check if threshold not yet reached |
| this | 0xF34 | R | — | Target loading threshold value (this[973]) — the goal value that progress must reach or exceed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | MainGameTick object — passed to MainGameTickUpdate as main game update target |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] |
| 007cc4c8 | dword_7CC4C8 | R | CheckFlag [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 008ab678 | byte_8AB678 | R | RaceSessionState [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404460 | MultiPhaseProcessingStateMachine | Advances the multi-phase processing state machine (main game flow controller) |
| 0040ca30 | MainCameraDirectorUpdate | Updates the main camera director system (camera positioning, transitions) |
| 0042c690 | MainGameTickUpdate | Executes the main game tick update (core game logic per-frame) |
| 0044f460 | PackedFlagRead | Reads a packed bit flag from byte_7CA594 at bit position 1 (wheel brake bias check) |
| 00455e50 | CollisionGlobalUpdateBroadcast | Broadcasts collision detection results across all game modules |
| 0049f070 | ShortComputation_f070 | Processes race session state transition based on dword_7CE048 |
| 004a1830 | sub_4A1830 | Unknown subsystem update — called with no arguments |
| 004b40a0 | RenderScreenSave | Renders/captures screen state for save/transition (receives session phase byte) |
| 004b8790 | FloatGetter | Reads the current loading progress float from this object — compared against threshold |
| 004b8c40 | sub_4B8C40 | Initializes/clears a state value to 0 (called with *a2 and literal 0) |
| 004ba180 | ConditionalMultiPathDispatcher | Dispatches conditional multi-path logic on the scoring gate object |
| 004c8b70 | RenderTickUpdate | Updates the rendering system for the current frame |
| 004cfcc0 | WeatherParticleUpdate | Updates weather and particle effects system |
| 004d4580 | sub_4D4580 | Updates force feedback system (force feedback base object) |
| 004fa7e0 | sub_4FA7E0 | Updates the game race phase timer |

**Guard conditions:** First check: `this[973] - this[972] <= 0.0` → target threshold not exceeding current progress (no work to do), return 0 immediately. After subsystem ticks: `dword_7CC4C8` (CheckFlag) non-zero → blocked by external flag, return 0. `PackedFlagRead(byte_7CA594, 1)` non-zero → wheel-brake bias threshold flag set, return 0. `FloatGetter(this) >= this[973]` → current progress has reached or passed the target threshold, return 0 (trigger not fired because target already met). Otherwise all guards pass, return 1 (trigger condition satisfied).
