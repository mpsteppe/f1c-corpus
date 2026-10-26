## sub_4FA7E0_004fa7e0 — MainGameFrameTick

**Summary:** Main per-frame game tick: handles scene rendering setup, session-state-dependent global-float selection, one-time display initialization, weather-based rendering configuration, per-vehicle UI widget updates, audio subsystem dispatch, pause-text overlay rendering, and frame-delta-time accumulation (clamped to 0.5s) with optional audio-init retry on byte_8AFE72.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

*(none — this function accesses only globals, no struct fields via `this`)*

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) — number of vehicles to iterate for UI updates |
| 005c35c8 | aPaused | R | String_Paused [DERIVED] — "Paused" overlay text |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) — screen width minus 48, used for display initialization |
| 005d6d70 | dbl_5D6D70 | R | EngineBrakeTorqueFactor [DERIVED] (also: ` — integration enabled flag (shared timestep variable) — 1.0 = integration enabled, otherwise scaling factor for delta time |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] — scene setup pointer, passed to AIWaypointPathCheckerRenderer |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — lookup table for BinarySearchInStringTable |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) — scratch buffer for "Paused" text |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] — array of vehicle object pointers indexed by vehicle index |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) — passed to sub_42D210 for session-based audio |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — checked against 7 to gate audio when HUD disabled |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) — session enable flag: controls audio path, pause-text rendering, and timing mode |
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] — packed flag byte read by PackedFlagRead for bits 20, 29, 33, 34 |
| 007cc4f4 | dword_7CC4F4 | R | AudioMixerInt [DERIVED] — nonzero = audio subsystem enabled, gates audio dispatch |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] — render dispatch context for TextLineWrappingAndRendering |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] — passed to SessionStateCheckWrapper to guard rendering |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] — if set, skips StateFlagComputation |
| 007ce264 | dword_7CE264 | R | SessionStateFlag [DERIVED] (also: ` — sub-mode selector) — 1 = conditional init branch mode 2, otherwise mode 0 |
| 007cf860 | dword_7CF860 | R | Unknown_AiTeamCount_F860 [DERIVED] — 0 = all-vehicle UI update, 1 = skip per-vehicle, 2+ = only vehicles with slot data |
| 007cfb90 | dword_7CFB90 | R | Unknown_Render_7CFB90 [DERIVED] — <= 1 triggers additional sub_545D00 call with 256 |
| 007cfc68 | dword_7CFC68 | R | WeatherStateFlag [DERIVED] — 0 = 6144, 1 = 4096, other = no weather sub_545D00 call |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] — 2 = skip session-state-check guard (forces GlobalFloatSetter(0)) |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] — passed to RepeatedCallLoop_f040 for audio init retry |
| 008afca8 | dword_8AFCA8 | R | RenderDisplayListPtr [DERIVED] — display list pointer passed to ConditionalInitBranch and sub_4F8D70/sub_4F8F50 |
| 008afcac | dword_8AFCAC | R | Unknown_RaceDynamics_Value [DERIVED] — zero-test gates ConditionalInitBranch mode choice |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe70 | byte_8AFE70 | RW | RaceByteFlag [DERIVED] — one-shot initialization guard: 0 = run display init, set to 1 after |
| 008afe72 | byte_8AFE72 | RW | AudioInitSuccessFlag [DERIVED] — set to 0 at start of each call; if was 1 previously, triggers RepeatedCallLoop_f040 + AIWaypointPathCheckerRenderer |
| 008afe84 | dword_8AFE84 | RW | Unknown_Race_DynamicsValue [DERIVED] — incrementing frame counter |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |
| 008afe90 | dbl_8AFE90 | RW | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) — written with result of sub_556730(0) each frame |
| 008afe94 | byte_8AFE94 | R | RaceTimeAbsolute2 [DERIVED] |
| 008afe98 | dbl_8AFE98 | RW | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) — per-frame delta time (clamped to 0.5); 0.0 when byte_7C56AC is set |
| 008afe9c | byte_8AFE9C | W | TimeAccumulator_A [DERIVED] |
| 008afea0 | dbl_8AFEA0 | RW | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) — accumulated session time: += dbl_8AFE98 each frame when not paused |
| 008afea8 | dbl_8AFEA8 | RW | InputAxisDeadZone [DERIVED] (also: ` â€” axis threshold (float) — accumulated raw delta time: += dbl_8AFE90 unconditionally each frame |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) — passed to sub_4F8F50 as render device |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | lookup "Paused" string in translation table for overlay rendering |
| 0042d210 | sub_42D210 | session-based audio subsystem dispatch (passed SessionType5 and enabled flag) |
| 0044f460 | PackedFlagRead | read a specific bit from a packed flag byte |
| 0045bd10 | TextLineWrappingAndRendering | render "Paused" text overlay on screen (color 16909060 = blue) |
| 00461db0 | SessionStateCheckWrapper | check if game is in a blocking session state (menus, loading, etc.) |
| 004c8d60 | ArithmeticComparison_8d60 | audio path: arithmetic comparison when session enabled |
| 004c8d70 | ShortComputation_8d70 | audio path: short computation when session disabled |
| 004cf040 | RepeatedCallLoop_f040 | repeated call loop on scoring grid base (audio re-init retry) |
| 004f8d70 | sub_4F8D70 | display/render setup call with display-list pointer, mode 4, screen-width-minus-48 |
| 004f8f10 | ConditionalInitBranch | conditional initialization of display list branch with mode 0 or 2 |
| 004f8f50 | sub_4F8F50 | render display list processing (takes display list pointer + D3D device) |
| 004f9b30 | StateFlagComputation | compute/set state flags (skipped when HUD disabled) |
| 004f9f70 | GlobalFloatSetter | set a global float to 0, 1, or 2 based on flag-bit combinations and dbl_5D6D70 |
| 0053ac70 | EmptyStubWithFlagCheck | empty stub / flag check called with modes 1 and 2 (likely timing fence/barrier) |
| 00545d00 | sub_545D00 | configuration call with two integer parameters (weather/rendering configuration) |
| 0054c1b0 | UIWidgetRecursiveStateUpdate | recursive UI widget state update per vehicle (mode 0, 1, 0) |
| 00556730 | sub_556730 | compute delta-time / cooling rate value (takes 0, returns double) |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | reset high-resolution timer (called on `this`, the performance counter object) |

**Guard conditions:** Multiple sequential guard blocks: (1) PackedFlagRead bits 29+33 set → ConditionalInitBranch mode 2 or 0 based on dword_8AFCAC; (2) SessionStateCheckWrapper true OR dword_8AB6E4==2 → GlobalFloatSetter(0) bypass; (3) PackedFlagRead 29+34 → GlobalFloatSetter(2) if dbl_5D6D70==1.0 else 0; (4) PackedFlagRead 29+20 → GlobalFloatSetter(1) if dbl_5D6D70==1.0 else fall to (2); (5) byte_8AFE70==0 → one-shot display init block (sets to 1, calls sub_4F8D70, ConditionalInitBranch based on dword_7CE264, weather sub_545D00 based on dword_7CFC68, then per-vehicle UI updates based on dword_7CF860); (6) !byte_7CE254 → StateFlagComputation(0); (7) audio gate: dword_7CC4F4 nonzero AND !SessionStateCheckWrapper AND dword_8AB6E4!=2 AND (dword_7C56A4!=7 OR !byte_7CE254) → sub_42D210 + audio comparison; (8) byte_7C56AC → render "Paused" overlay; (9) byte_8AFE72 was 1 → audio re-init retry chain.
