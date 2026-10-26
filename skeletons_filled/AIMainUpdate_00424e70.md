## AIMainUpdate_00424e70 — AI Per-Frame State Machine Tick

**Summary:** Per-frame AI tick for a single vehicle: computes heading from yaw, runs state-machine (driverStatus switch 0-7), dispatches racing-line/steering/gearshift logic, handles pit scheduling and session-phase transitions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | AIEnableFlag (read via base object deref: if != 1 skip pre-race init) |
| obj | 0x48A4 | R | — | CameraSetupIndex (index into SetupScenePtr table for ArrayOfStructIndexedFieldCopy) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32C8 | R | — | AIEnableFlag (>1 blocks entire tick; 0-1 allowed) |
| this | 0x34E0 | R | — | WorldPosX (position component for distance check) |
| this | 0x34E8 | R | — | WorldPosZ (position component for distance check) |
| this | 0x34F0 | R | — | RenderX [FACT] (yaw angle, used to compute heading sin/cos) |
| this | 0x357C | RW | 0 | ThrottleFactor [CONFIRMED] |
| this | 0x3580 | RW | 0 | SteeringFactor (output: set to 0 when pit-entry or terminal states) |
| this | 0x3584 | RW | 1065353216 → 1.0f | BrakeFactor [CONFIRMED] |
| this | 0x3984 | R | — | PhysicalQuantity (compared against 0.001 threshold for AI activity) |
| this | 0x399C | R | — | RPMInputHigh (used with EngineRPM in pit schedule ratio calculation) |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x3D6C | R | — | carConditions [CONFIRMED] |
| this | 0x4028 | RW | 0 | AIInternalCounter (zeroed on session phase change) |
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4064 | R | — | FinishState [FACT] |
| this | 0x4068 | RW | — | ReasonCode [FACT] |
| this | 0x409C | R | — | bestLap [CONFIRMED] |
| this | 0x413C | RW | 2139095039 | NextEventTime (session time at which next scheduled AI event fires) |
| this | 0x4144 | R | — | PitScheduleArray (base of per-driver pit timing struct array, 5 entries) |
| this | 0x4148 | R | — | PitScheduleIndex (index into array, checked <4) |
| this | 0x416C | RW | 1109393408 → 40.0f | TimeDelayClamp (max random delay for pit events) |
| this | 0x4170 | RW | 2139095039 | PitExitTimeSentinel (next pit exit trigger time, set to INT_MAX when cleared) |
| this | 0x43F8 | RW | 0 | AIStateFlag1 (zeroed on pit-entry / state transition) |
| this | 0x4404 | RW | — | NextAbilityCheckTime (session time + 4.0, triggers AIAbility recalculation) |
| this | 0x4420 | RW | 0 | SafetyCarFlag (zeroed when not in safety-car state and speed > 0.001) |
| this | 0x4424 | RW | 0 | AIStateFlag3 (zeroed on pit-entry state transition) |
| this | 0x4428 | R | — | SteeringDeviation (abs value compared against 5.0/7.0 for throttle modulation) |
| this | 0x442C | RW | 0 | SteeringOutputFactor (clamped 0.0-1.0, fed to this+13696) |
| this | 0x4434 | RW | 0 | ThrottleOutputValue (clamped 0.0-1.0, fed to this+13692) |
| this | 0x4438 | RW | 1065353216 → 1.0f | BrakeOutputValue (clamped 0.0-1.0, fed to this+13700) |
| this | 0x443C | RW | 0 | AIFlagByte (zeroed on pit entry / state clear) |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4448 | RW | — | SessionTimeAccum (decremented by 0.025 each tick in pre-race to detect phase change) |
| this | 0x444C | RW | — | CurrentRacePhase (compared with dword_7C56A8, value 4 = race, drives pit schedule) |
| this | 0x447C | RW | — | PitEntryTimestamp (set to sessionTime + 4.0 when entering pit) |
| this | 0x4480 | RW | — | CurrentTimeMirror (updated with dbl_8AFEA0 each tick) |
| this | 0x4484 | RW | 1232348144 → 999999.0f | OvertakeDistanceSentinel (reset to large value each tick, then updated by overtake scan) |
| this | 0x448C | RW | — | HeadingSin (-sin of yaw angle) |
| this | 0x4494 | RW | — | HeadingCos (-cos of yaw angle) |
| this | 0x4510 | RW | 0 | driverStatus [CONFIRMED] |
| this | 0x4524 | RW | 0 | PitStateFlag (zeroed when pit status changes) |
| this | 0x4534 | RW | — | timeOfNextExit [CONFIRMED] |
| this | 0x454C | RW | 0 | callToBox [CONFIRMED] |
| this | 0x4550 | RW | 1 | PitLapCounter (set to 1 on pit entry) |
| this | 0x4560 | RW | — | PitScheduleTime1 (randomized pit event time) |
| this | 0x4564 | RW | — | PitScheduleTime2 (next pit schedule entry, randomized) |
| this | 0x4568 | RW | — | PitScheduleFlag (toggles between 0/1 each cycle) |
| this | 0x4588 | R | — | PitStateCounter (compared with this+17888 for pit exit decision) |
| this | 0x45E0 | R | — | PitServiceProgress (compared with this+17800 for DNF decision) |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |
| this | 0x45FC | RW | 0 | AIBlockingFlag (checked for non-zero before zeroing AIStateFlag3) |
| this | 0x461C | RW | — | DistanceToSetupSq (squared distance to target, used for state transition from 3→0) |

**Written-by note (persistence):**
- this 0x357C: recalc every frame — external poke does NOT persist
- this 0x3580: recalc every frame — external poke does NOT persist
- this 0x3584: recalc every frame — external poke does NOT persist
- this 0x4028: recalc every frame — external poke does NOT persist
- this 0x4068: recalc every frame — external poke does NOT persist
- this 0x413C: recalc every frame — external poke does NOT persist
- this 0x416C: recalc every frame — external poke does NOT persist
- this 0x4170: recalc every frame — external poke does NOT persist
- this 0x43F8: recalc every frame — external poke does NOT persist
- this 0x4404: recalc every frame — external poke does NOT persist
- this 0x4420: recalc every frame — external poke does NOT persist
- this 0x4424: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4438: recalc every frame — external poke does NOT persist
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x4448: recalc every frame — external poke does NOT persist
- this 0x444C: recalc every frame — external poke does NOT persist
- this 0x447C: recalc every frame — external poke does NOT persist
- this 0x4480: recalc every frame — external poke does NOT persist
- this 0x4484: recalc every frame — external poke does NOT persist
- this 0x448C: recalc every frame — external poke does NOT persist
- this 0x4494: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4524: recalc every frame — external poke does NOT persist
- this 0x4534: recalc every frame — external poke does NOT persist
- this 0x454C: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x4560: recalc every frame — external poke does NOT persist
- this 0x4564: recalc every frame — external poke does NOT persist
- this 0x4568: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist
- this 0x45FC: recalc every frame — external poke does NOT persist
- this 0x461C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 0059e6a8 | flt_59E6A8 | R | ProximityThresholdSq [DERIVED] |
| 0059e6ec | flt_59E6EC | R | ShortIntToWorldScale [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e820 | flt_59E820 | R | OvertakingDistanceThreshold [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 0059e870 | flt_59E870 | R | AIStateDeltaThreshold [DERIVED] |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059e878 | flt_59E878 | R | AISpeedThreshold [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 005c30e0 | unk_5C30E0 | R | Unknown_String_5C30E0 [DERIVED] |
| 005c3144 | dword_5C3144 | R | VehicleField_3144 [DERIVED] |
| 005c3160 | byte_5C3160 | RW | TrackConfigByte_5C3160 [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea2cc | dword_5EA2CC | R | AiOvertakeDistanceThreshold [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce2f0 | unk_7CE2F0 | R | Unknown_AI_Struct_7CE2F0 [DERIVED] |
| 008acfb8 | flt_8ACFB8 | R | TimingsConst2 [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403f70 | ArrayOfStructIndexedFieldCopy | Copy indexed field from SetupScenePtr array to local vector (camera/target position lookup) |
| 00424c80 | AIRingBufferFieldInit | Initialize AI ring-buffer fields when session phase resets |
| 00425660 | FieldZeroSetter | Zero AI output fields during driver state 2 (standby/garage) |
| 00425670 | SteeringAngleController | Compute steering angle for driver states 0 and 6 |
| 004258c0 | sub_4258C0 | Handle driver state 1 behavior (likely formation/parade lap logic) |
| 00425920 | AIRacingLine | Compute racing-line following parameters each tick |
| 00426100 | sub_426100 | AI secondary per-tick update (situational logic after racing line) |
| 00426330 | PhysicsGearShiftLogicWithThresholds | Determine gear shifts based on RPM thresholds each tick |
| 00426430 | sub_426430 | AI preconditions check (returns false if AI should skip remaining tick) |
| 00426cf0 | AISteeringCorrection | Apply steering correction adjustments each tick |
| 004270a0 | AISteering | Main AI steering computation |
| 00429470 | AIAbility | Recalculate AI driver ability parameters (called periodically, every ~4s) |
| 00429fd0 | RandomWeightedTierSelection | Select random weighted tier for pit stop strategy |
| 0042a180 | AIPushLap | Trigger AI push-lap mode at race start |
| 0042a7d0 | OpponentProximityScanTeamRecognition | Scan opponent proximity and recognize teammate vehicles each tick |
| 0042ac70 | AIStateFlagSetter | Set global AI state flags at race start (race phase 8) |
| 0042adb0 | SessionCleanupFlagClear | Clear session cleanup flags on phase change |
| 0042ae00 | AIClearStateFlags | Clear AI internal state flags on pit entry |
| 004a4110 | sub_4A4110 | Check pit service completion (returns true if pit stop can proceed) |
| 004ef930 | RaceStartCountdownStateUpdate | Update race start countdown timer state |
| 004efa40 | VehicleClimbAdjust | Adjust vehicle climb parameters for hill detection |
| 004efac0 | ConditionalGate | Conditional gate dispatch during pit schedule initialization loop |
| 004f1a60 | LoopWithConditionalSubCall | Loop call with conditional sub-routine during pit exit transition |
| 00587bdc | CRTFtol | Convert float to long (CRT ftol) |
| 005884ed | RandLCGRandomNumberGenerator | Linear congruential random number generator |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | != | 1 | AIEnableFlag (base object) — pre-race init only if base AI enabled |
| obj | 0x32C8 | == | 1 | AIEnableFlag (base object) — pre-race init path active when base AI = 1 |
| this | 0x32C8 | > | 1 | AIEnableFlag — BLOCKED: entire tick skipped if > 1 (disabled/invalid) |
| this | 0x3D6C | != | 2 | carConditions [CONFIRMED] — BLOCKED: condition check in throttle modulation path |
| this | 0x3D6C | == | 2 | carConditions [CONFIRMED] — PASSES: special throttle modulation if car condition == 2 |
| this | 0x4064 | == | 2 | FinishState [FACT] == DNF — BLOCKED: DNF clears AI flag and exits |
| this | 0x4148 | < | 4 | PitScheduleIndex — PASSES: per-driver pit timing dispatch only for indices 0-3 |
| this | 0x444C | == | 4 | CurrentRacePhase — PASSES: race phase drives pit schedule time computation |
| this | 0x4510 | == | 5 | driverStatus [CONFIRMED] — BLOCKED: driver state 5 (pitting) enables pit completion logic |
| this | 0x45F4 | == | 1 | ActiveFlag [FACT] — PASSES: additional pit schedule logic when ActiveFlag set |

**CORRECTION (2026-07-25, live + static):** the prose name `PitLapCounter` for
`this 0x4550` above is **WRONG**. `sub_426430` passes 0x4550 as the waypoint-set
selector to `SpatialNearestNeighborQueryWithPlaneTest` (lines 78/89) and rewrites
it every frame from the acquired waypoint's `+0x12C` (line 138); it is not a lap
count. Recorded in `name_index.json` as `WaypointSetSelector` [DERIVED]. It is
also NOT a reliable "in the pit lane" indicator — live 2026-07-25 a car drove the
whole pit-lane corridor reading 0. Evidence:
`investigations/garage_exit_ignition/README.md`. Fact table left unedited.

**Guard interpretation:** Top-level guard `this+0x32C8 > 1` blocks the entire tick (AI disabled). Remaining guards form a state machine: pre-race init (ActiveFlag=0, base AI=1) runs session-phase detection and pit scheduling; pit-entry (driverStatus=4/5) handles pit stop timing and exit transitions; active driving falls through to the driverStatus switch (0=follow,1=parade,2=garage,3=approach,6=pitting,7=spin) dispatching racing-line/steering/gearshift each tick. FinishState=2 (DNF) short-circuits with flag clear.
