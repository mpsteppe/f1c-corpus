## AISteeringRacingLineCorrection_0042b0e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringCorrection (00426cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3AA8) | 0x12C | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x4 | R | — | [LLM] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |
| this | 0x3984 | R | — | [LLM] |
| this | 0x3988 | R | — | [LLM] |
| this | 0x39A0 | R | — | EngineRPM [CONFIRMED] |
| this | 0x39A8 | R | — | [LLM] |
| this | 0x3AA8 | R | — | [LLM] |
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x4354 | RW | — | [LLM] |
| this | 0x4358 | RW | — | [LLM] |
| this | 0x442C | RW | — | [LLM] |
| this | 0x4434 | RW | — | [LLM] |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4448 | R | — | [LLM] |
| this | 0x4460 | RW | — | [LLM] |
| this | 0x44B4 | R | — | [LLM] |
| this | 0x4510 | RW | 5 | driverStatus [CONFIRMED] |
| this | 0x4538 | RW | — | maxSpeed [CONFIRMED] |
| this | 0x4550 | RW | 1 | [LLM] |
| this | 0x45E8 | R | — | [LLM] |
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
| 00403cd0 | sub_403CD0 | [LLM] |
| 00429fd0 | RandomWeightedTierSelection | [LLM] |
| 0042a740 | TrackParameterMinimumClamp | [LLM] |
| 004d10e0 | SingleFunctionDispatch_10e0 | [LLM] |
| 004ef7c0 | AIVehiclePathPositionTracking | [LLM] |
| 004efa40 | VehicleClimbAdjust | [LLM] |
| 004efac0 | ConditionalGate | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |
| 004effd0 | DistanceComparison | [LLM] |
| 004f0050 | DistanceProjectionCalc | [LLM] |
| 004f1890 | SpeedValueSetterWithGlobalMirror | [LLM] |
| 004f1a60 | LoopWithConditionalSubCall | [LLM] |
| 004f2320 | VehicleDynamicsStateReset | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
