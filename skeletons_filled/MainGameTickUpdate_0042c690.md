## MainGameTickUpdate_0042c690 — Main Game Tick Update Loop

**Summary:** Drives the per-frame game update loop: converts session time to tick counter, dispatches AI updates, vehicle physics, particle effects, fuel consumption, tire force computation, and player controls at fixed sub-intervals. Coordinates all per-vehicle per-frame subsystems.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9b0 | dbl_59E9B0 | R | Rad2DegOrTimerMult [DERIVED] (also: ` — conversion multiplier) |
| 0059e9d8 | dbl_59E9D8 | R | GameTickMultiplier [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c5694 | dword_7C5694 | RW | TimerOutputInt [DERIVED] (also: ` — timer/angle output global) |
| 007c5698 | dword_7C5698 | RW | SessionTickCounter [DERIVED] |
| 007c932c | dword_7C932C | W | RaceScoring_ClearFlags_0 [DERIVED] |
| 007c9330 | dword_7C9330 | W | UpdateLoopZeroState [DERIVED] |
| 007c9334 | dword_7C9334 | W | SessionClearStateArray [DERIVED] |
| 007c9338 | dword_7C9338 | W | StewardCounterBlock8 [DERIVED] |
| 007c933c | dword_7C933C | W | CollisionAccumulator [DERIVED] |
| 007c9340 | dword_7C9340 | W | ScoringAudioAccum0 [DERIVED] |
| 007c9344 | dword_7C9344 | W | PhysicsWorkspace_Zeroed_Block [DERIVED] |
| 007c9348 | dword_7C9348 | W | PhysicsAccum_07 [DERIVED] |
| 007c934c | dword_7C934C | W | ZeroedBlock7C934C [DERIVED] |
| 007c9350 | dword_7C9350 | W | Unknown_FlagBlock_Clear [DERIVED] |
| 007c9354 | dword_7C9354 | W | LapScoringFlagsBatch [DERIVED] |
| 007c9358 | dword_7C9358 | W | SimulationAccumBlock [DERIVED] |
| 007cbb10 | unk_7CBB10 | R | Collision_ContactBuffer [DERIVED] |
| 007cbf24 | dword_7CBF24 | R | Unknown_Int_7CBF24 [DERIVED] |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad238 | dword_8AD238 | R | ScoringGateOpen [DERIVED] |
| 008ad23c | dword_8AD23C | R | TimerTickAccumulator [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00410980 | LoopWithConditionalSkipFunction | dispatches global per-frame update with conditional skip logic |
| 004109d0 | PerVehicleCameraUpdateIterator | iterates vehicles for per-vehicle camera update |
| 00424e70 | AIMainUpdate | updates AI logic for a single vehicle |
| 0042c440 | sub_42C440 | early tick preparation/setup routine |
| 0042caa0 | AILateralForceComputation | computes AI lateral force adjustments |
| 00451720 | DriverInputController | processes driver input from collision contact buffer |
| 004bccc0 | sub_4BCCC0 | per-frame subsystem update (called every 10th tick for player vehicle) |
| 004d5960 | DebugLogInit | initializes debug logging |
| 004d59b0 | sub_4D59B0 | writes debug log entry |
| 004e4930 | VehiclePhysicsModeDispatcher | dispatches vehicle physics mode update (called on non-10th ticks for specific conditions) |
| 004eb430 | ParticleEffectUpdateDispatch | updates particle effects for a vehicle |
| 004ed810 | WheelTireForceUpdate | computes wheel tire forces |
| 004ed960 | FuelConsumptionAndWear | updates fuel consumption and component wear |
| 004ee2d0 | sub_4EE2D0 | additional per-vehicle subsystem update |
| 004f1c40 | VehicleYawRotationRecoveryController | controls vehicle yaw rotation recovery |
| 00587bdc | CRTFtol | converts floating-point to integer (truncation) |
| 005895a2 | sub_5895A2 | time-based subsystem call with scaled session time |

**Guard conditions:** Top-level gate: `dword_8AB6E4 != 2` — if scoring gate equals 2, the entire tick update is BLOCKED (skips to camera update only). Inner tick scheduling: every 10th tick (`dword_7C5698 % 10 == 0`) runs full AI + physics pass for all vehicles; on non-10th ticks, vehicle physics dispatches only for player car under specific conditions (no replay mode, tire model conditions met, engine flag set). Every 400th tick: fuel consumption update. Every 50th tick: AI lateral force + tire force updates. Every `dword_8AD23C` ticks: debug logging. Tick counter wraps at 400. Driver input processed only when `dword_7CBF24` is non-zero (collision contact data available).