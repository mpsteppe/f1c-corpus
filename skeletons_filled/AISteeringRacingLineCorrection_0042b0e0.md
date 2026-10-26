## AISteeringRacingLineCorrection_0042b0e0 — AI Steering Racing Line Correction

**Summary:** Computes steering angle corrections for AI vehicles based on distance to the racing line and position relative to other vehicles. Handles both race-phase (proximity to opponent) and qualifying-phase (waypoint-based) correction modes.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3AA8) | 0x12C | R | — | opponent vehicle active/valid flag (nonzero = opponent exists and is active) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | vehicle speed (integer, scaled by 8.5 for interrupt timing calculation) |
| this | 0x34BC | R | — | vehicle right-axis X component (rotation matrix column 0) |
| this | 0x34C4 | R | — | vehicle forward-axis X component (rotation matrix column 2) |
| this | 0x34C8 | R | — | vehicle right-axis Y component (rotation matrix column 0) |
| this | 0x34D0 | R | — | vehicle forward-axis Y component (rotation matrix column 2) |
| this | 0x34D4 | R | — | vehicle right-axis Z component (rotation matrix column 0) |
| this | 0x34DC | R | — | vehicle forward-axis Z component (rotation matrix column 2) |
| this | 0x3984 | R | — | speed lower threshold for AI maneuver computation |
| this | 0x3988 | R | — | speed upper threshold (cap for maneuver speed target) |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x39A8 | R | — | target/requested RPM value (compared against EngineRPM) |
| this | 0x3AA8 | R | — | pointer to opponent vehicle data struct (used to check validity and read position) |
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x4354 | RW | — | steering correction primary accumulator (zeroed on reset) |
| this | 0x4358 | RW | — | steering correction secondary accumulator (zeroed on reset) |
| this | 0x442C | RW | — | computed steering angle offset (atan2 projection, clamped [-1.0, 1.0]) |
| this | 0x4434 | RW | — | steering correction strength/clamping factor (range 0.0 to 0.9) |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4448 | R | — | time multiplier / lap-based offset for steering reset timing |
| this | 0x4460 | RW | — | timestamp of last steering reset (session time, compared to detect >10s gap) |
| this | 0x44B4 | R | — | steering angle normalization divisor (divides atan2 result) |
| this | 0x4510 | RW | 5 | driverStatus [CONFIRMED] |
| this | 0x4538 | RW | — | maxSpeed [CONFIRMED] |
| this | 0x4550 | RW | 1 | active maneuver state flag (1 = steering reset sequence engaged) |
| this | 0x45E8 | R | — | base speed multiplier for AI speed target computation |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x4354: recalc every frame — external poke does NOT persist
- this 0x4358: recalc every frame — external poke does NOT persist
- this 0x442C: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4460: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4538: recalc every frame — external poke does NOT persist
- this 0x4550: recalc every frame — external poke does NOT persist
- this 0x45F4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e6a4 | flt_59E6A4 | R | MIN_VELOCITY_THRESHOLD [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e86c | flt_59E86C | R | FloatToInt64Scale [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e990 | flt_59E990 | R | PhysicsConstant_59E990 [DERIVED] |
| 0059e994 | flt_59E994 | R | AIPerfThreshold [DERIVED] |
| 0059e998 | flt_59E998 | R | AI_SteeringAngleThreshold [DERIVED] |
| 0059e99c | flt_59E99C | R | PhysicsConversionFactor [DERIVED] (also: ` — conversion factor) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` â€” waypoint accumulation weight) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cec18 | byte_7CEC18 | R | ByteFlag7CEC18 [DERIVED] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008acf94 | flt_8ACF94 | R | RaceTimeThreshold [CONFIRMED] |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403cd0 | sub_403CD0 | retrieves track waypoint/spline position by index from setup scene data |
| 00429fd0 | RandomWeightedTierSelection | selects random AI behavior tier with weighted probability |
| 0042a740 | TrackParameterMinimumClamp | clamps a parameter to track-based minimum threshold |
| 004d10e0 | SingleFunctionDispatch_10e0 | retrieves vehicle world-space position and orientation transform |
| 004ef7c0 | AIVehiclePathPositionTracking | resets AI vehicle path tracking state on the racing line |
| 004efa40 | VehicleClimbAdjust | adjusts vehicle behavior for track elevation changes |
| 004efac0 | ConditionalGate | evaluates conditional state gate for AI logic branching |
| 004efb20 | F_3DTransformWithMatrixMultiplication | applies 3D transformation using matrix multiply (world-to-local or similar) |
| 004effd0 | DistanceComparison | checks whether vehicle position is within valid racing line distance |
| 004f0050 | DistanceProjectionCalc | computes scalar distance projection along the racing line |
| 004f1890 | SpeedValueSetterWithGlobalMirror | sets speed target value with global mirror/sync |
| 004f1a60 | LoopWithConditionalSubCall | executes iteration loop with conditional sub-function calls |
| 004f2320 | VehicleDynamicsStateReset | resets vehicle dynamics/physics state to initial values |
| 00566e40 | EulerToRotationMatrix | converts Euler angles to 3x3 rotation matrix |
| 0058957a | InterruptDispatch | dispatches an interrupt/trigger event with computed timing value |

**Guard conditions:** RacePhase (dword_7C56A8) gates all behavior: must be 1 (qualifying/practice) or 3 (racing). In phase 3, searches VehiclePtrArray for nearest opponent with matching position rank; requires projected distance difference > -200; applies TrackParameterMinimumClamp with distance-based value; if speed < 1.0 and opponent is stationary (< 0.2 velocity) and near race start, zeroes steering correction. In phase 1 or late phase 3 (session time >= RaceTimeThreshold + 30s): requires valid opponent pointer (*(this+0x3AA8) non-null and opponent+0x12C non-zero); checks DistanceComparison, EngineRPM comparison (target RPM > actual), and time-since-last-reset > 10s before triggering reset sequence (sets driverStatus=5, activeFlag=1, maxSpeed to idle). Without valid opponent, falls back to waypoint-based correction: must have byte_7CEC18 set; finds nearest track waypoint using sub_403CD0; if nearest distance < 80.0, computes atan2 steering angle from projected displacement onto vehicle axes; if v36 >= 40.0, skips correction; if v22 < 0 (behind racing line), resets vehicle dynamics instead.
