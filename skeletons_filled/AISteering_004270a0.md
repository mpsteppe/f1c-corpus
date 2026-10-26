## AISteering_004270a0 — AI Steering Target Computation

**Summary:** Per-frame AI steering logic: evaluates lateral track positions (5 lanes) via spatial nearest-neighbor queries, scores them, selects steering targets, and manages overtaking state transitions. Core of the AI driving system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4174) | 0x32C8 | R | — | AI car object's vehicle-status flag (inPit/pit related) |
| *(this+0x4174) | 0x4354 | R | — | AI car object's track-position speed (left edge, likely 80) |
| *(this+0x4354) | 0x50 | R | — | left track-boundary speed parameter |
| *(this+0x4354) | 0x54 | R | — | right track-boundary speed parameter |
| *(this+0x4354) | 0xB8 | R | — | reference speed (yaw-related) |
| *(this+0x4354) | 0x12C | R | — | car-state flag: isInGarage (1=garage) |
| *(this+0x4358) | 0x50 | R | — | left track-boundary speed (lower lane) |
| *(this+0x4358) | 0x54 | R | — | right track-boundary speed (lower lane) |
| obj | 0x48A4 | R | — | overtaking-right allowance counter/flag |
| obj | 0x48A8 | R | — | overtaking-left allowance counter/flag |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x34E0 | R | — | lateral offset for lane evaluation (delta x) |
| this | 0x34E4 | R | — | lateral offset for lane evaluation (delta y) |
| this | 0x34E8 | R | — | lateral offset for lane evaluation (delta z) |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x34FC | R | — | forward-direction vector component (track-local) |
| this | 0x3500 | R | — | lateral-direction vector component (track-local) |
| this | 0x4140 | RW | 1 | collision-awareness enable flag |
| this | 0x4174 | R | — | pointer to AI car's own vehicle object (this car) |
| this | 0x4180 | R | — | pointer to the AI's primary track-neighbor lookup |
| this | 0x41A4 | R | — | current car's front-lateral contact flag |
| this | 0x41A8 | R | — | current car's rear-lateral contact flag |
| this | 0x41AC | RW | — | recomputed lateral contact composite (per frame) |
| this | 0x41B4 | R | — | car body angle / slip indicator |
| this | 0x4354 | R | — | pointer to current track-position data (lane 0) |
| this | 0x4358 | R | — | pointer to alternative track-position data (lane -1) |
| this | 0x4408 | RW | — | steering target floor (lower bound, recalc per frame) |
| this | 0x440C | RW | — | steering target ceiling (upper bound, recalc per frame) |
| this | 0x4414 | R | — | steering aggressiveness factor |
| this | 0x4418 | R | — | overtaking event counter (incremented per candidate) |
| this | 0x441C | R | — | current steering bias / lateral push direction |
| this | 0x4420 | R | — | braking aggression modifier |
| this | 0x4424 | R | — | acceleration aggression modifier |
| this | 0x4428 | R | — | active throttle blending factor |
| this | 0x4438 | R | — | pit-exit slip recovery flag |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4450 | R | — | trackPartFromPitExit [CONFIRMED] |
| this | 0x4468 | R | — | lane-position tracking index (current lane select) |
| this | 0x4480 | R | — | on-track directional reference angle |
| this | 0x4488 | RW | 0 | steering-target center result (main output) |
| this | 0x448C | R | — | previous steering target (last frame) |
| this | 0x4490 | R | — | steering smoothing / history value |
| this | 0x4494 | R | — | steering rate-of-change clamp reference |
| this | 0x44A4 | R | — | next waypoint speed hint |
| this | 0x44F8 | R | — | opponent-proximity left threshold |
| this | 0x44FC | R | — | opponent-proximity right threshold |
| this | 0x4508 | RW | — | final steering output value (post-processing) |
| this | 0x4544 | R | — | steering error accumulator (integral term) |
| this | 0x4548 | R | — | steering derivative term |
| this | 0x454C | R | — | callToBox [CONFIRMED] |
| this | 0x4550 | R | — | pit-lane entry trigger flag (1=enter pit decision) |
| this | 0x4554 | RW | 1065353216 → 1.0f | steering override gain factor |
| this | 0x455C | RW | 0 | pitlane steering recovery counter |
| this | 0x456C | RW | 1 | steering-state latch (prevents oscillation) |
| this | 0x4570 | RW | 0 | elapsedTime [CONFIRMED] |
| this | 0x4574 | RW | 0 | steering mode index (1=left, 2=right, 7/8=overtake modes) |
| this | 0x4579 | RW | 1 | steering duty-cycle enable flag |

**Written-by note (persistence):**
- this 0x4140: recalc every frame — external poke does NOT persist
- this 0x41AC: recalc every frame — external poke does NOT persist
- this 0x4408: recalc every frame — external poke does NOT persist
- this 0x440C: recalc every frame — external poke does NOT persist
- this 0x4488: recalc every frame — external poke does NOT persist
- this 0x4508: recalc every frame — external poke does NOT persist
- this 0x4554: recalc every frame — external poke does NOT persist
- this 0x455C: recalc every frame — external poke does NOT persist
- this 0x456C: recalc every frame — external poke does NOT persist
- this 0x4570: recalc every frame — external poke does NOT persist
- this 0x4574: recalc every frame — external poke does NOT persist
- this 0x4579: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e464 | flt_59E464 | R | PhysicsConstant_59E464 [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` — global frame-rate correction) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e6a8 | flt_59E6A8 | R | ProximityThresholdSq [DERIVED] |
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e7f0 | flt_59E7F0 | R | DefaultFromTableSentinel [DERIVED] (also: ` — sentinel value (use default from table) |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e850 | flt_59E850 | R | Flt_Physics_Vehicle_AIScale [DERIVED] |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e888 | flt_59E888 | R | TwoPi [DERIVED] (also: ` — 2π (360° in radians) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` — yaw error tolerance (radians) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` — reverse gear throttle multiplier) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8bc | flt_59E8BC | R | PhysicsConstant_59E8BC [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059e8dc | flt_59E8DC | R | MaxTargetSpeedClamp [DERIVED] |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e8f0 | flt_59E8F0 | R | AudioDopplerFactor [DERIVED] |
| 0059e8f4 | flt_59E8F4 | R | PhysicsThreshold_59E8F4 [DERIVED] |
| 0059e8f8 | flt_59E8F8 | R | PhysicsConst_59E8F8 [DERIVED] |
| 0059e8fc | flt_59E8FC | R | AccelAccumLimit [DERIVED] |
| 0059e900 | dbl_59E900 | R | Physics_Double_59E900 [DERIVED] |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059e910 | dbl_59E910 | R | Unknown_Double_59E910 [DERIVED] |
| 0059e918 | flt_59E918 | R | ProximityDistThreshold [DERIVED] |
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |
| 0059e920 | flt_59E920 | R | SuspensionAntirollFactor [DERIVED] |
| 0059e924 | flt_59E924 | R | WheelContactLerpFactor [DERIVED] |
| 0059e928 | flt_59E928 | R | FloatCompareConst [DERIVED] (also: Float comparison constant) |
| 0059e92c | flt_59E92C | R | UnknownPhysicsFloat [DERIVED] |
| 0059e930 | dbl_59E930 | R | PhysicsDoubleThreshold [DERIVED] |
| 0059e938 | flt_59E938 | R | AIParamFloat1 [DERIVED] |
| 0059e93c | flt_59E93C | R | EngineSpeedThreshold [DERIVED] |
| 0059e940 | flt_59E940 | R | Flt_PhysicsLimit_9E940 [DERIVED] |
| 0059e944 | flt_59E944 | R | Physics_Float_59E944 [DERIVED] |
| 0059e948 | flt_59E948 | R | Unknown_Float_59E948 [DERIVED] |
| 0059e94c | flt_59E94C | R | Flt_Unknown_Dynamics [DERIVED] |
| 0059e950 | dbl_59E950 | R | EngineRPMThreshold [DERIVED] |
| 0059e958 | flt_59E958 | R | WheelbaseMult [DERIVED] |
| 0059e95c | flt_59E95C | R | CameraFOVThreshold [DERIVED] |
| 0059e960 | flt_59E960 | R | BrakeBiasThreshold [DERIVED] |
| 0059e964 | flt_59E964 | R | EngineWearAccumScale [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` — waypoint accumulation weight) |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004039c0 | BVHNearestNeighborQuery | spatial query for non-pit cars on track (fallback when SpatialTree fails) |
| 00403aa0 | SpatialTreeNearestNeighborSearch | primary spatial query to find nearest opponent car on track |
| 00423b10 | VehicleDynamics | compute vehicle-to-vehicle dynamics (speed, distance, closing rate) |
| 00423ca0 | ShortComputation_3ca0 | lateral offset calculation between this car and opponent |
| 00423db0 | ShortComputation_3db0 | forward distance and angle calculation to opponent |
| 0042a740 | TrackParameterMinimumClamp | enforce minimum track-parameter (braking/accel safety floor) |
| 0042af70 | Overtaking | execute overtaking maneuver logic for a side (left/right) |
| 004fae70 | SignedIndexTableLookup | table lookup returning signed index based on track position |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x4354) | 0x12C | == | 1 | opponent car is in garage (skip scoring) |
| this | 0x454C | == | 1 | callToBox [CONFIRMED] |
| this | 0x4550 | == | 1 | pit-lane entry decision active (override steering to pit) |

**Guard interpretation:** Opponent cars in garage (0x12C==1) are excluded from nearest-neighbor scoring. When callToBox (0x454C) or pit-entry flag (0x4550) is set, normal steering is bypassed and special pit-lane steering overrides are applied. These checks BLOCK normal lane evaluation — cars that fail them are skipped or overridden.