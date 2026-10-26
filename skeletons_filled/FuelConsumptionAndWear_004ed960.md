## FuelConsumptionAndWear_004ed960 — Fuel Consumption and Component Wear Update

**Summary:** Per-frame update of fuel consumption, tire wear, and random mechanical failures (engine, gearbox, puncture). Decrements fuel based on throttle and engine power, applies tire wear using track grip interpolation, and triggers random failure events at cooldown intervals.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4068 | RW | 4 | error/event code register (9=out of fuel, 1=engine fail, 5=gearbox, 2=puncture, 4=random wear) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3510 | R | — | base vehicle mass (float, this[3396]) |
| this | 0x3514 | RW | — | total mass = fuel*0.75 + baseMass (this[3397], recomputed every frame) |
| this | 0x3518 | RW | — | inverse total mass = 1.0 / totalMass (this[3398]) |
| this | 0x3570 | R | — | throttle input (float, this[3420], multiplies fuel consumption) |
| this | 0x3578 | R | — | gearbox health threshold (float, this[3422], checked for gearbox failure) |
| this | 0x35D0 | R | — | per-tire wear accumulator (float, this[3444], summed across 4 wheels) |
| this | 0x3624 | R | — | tire friction base (float, this[3464], per-wheel friction input) |
| this | 0x3630 | RW | — | tire wear level (float, this[3468], per-wheel, decremented each frame, clamped >= 0.75) |
| this | 0x3634 | R | — | tire wear rate factor (float, this[3469], per-wheel wear multiplier) |
| this | 0x3978 | RW | — | fuel level (float, this[3678], decremented by consumption rate * throttle * massFactor * dt) |
| this | 0x3984 | R | — | engine power factor (float, this[3681], multiplies fuel consumption) |
| this | 0x3994 | R | — | engine RPM (float, this[3685], used in fuel calc and failure gating) |
| this | 0x3998 | R | — | engine RPM limit / max (float, this[3686], gating condition for engine failure) |
| this | 0x39A4 | R | — | EngineMaxRPM [CONFIRMED] |
| this | 0x39B0 | R | — | engine power table entry count (int, this[3692], loop count for engine power reset) |
| this | 0x39EE | RW | 1 | puncture flag (byte at this+14830, set to 1 on tire puncture event) |
| this | 0x3A30 | RW | — | gearbox wear factor (float, this[3724], scaled down by 0.03125 on gearbox failure) |
| this | 0x3A44 | RW | — | gearbox wear factor 2 (float, this[3729], scaled down by 0.03125 on gearbox failure) |
| this | 0x3BF4 | R | — | tire friction multiplier (float, this[3837], applied to per-tire friction calc) |
| this | 0x3BF8 | RW | — | last weather-noise update timestamp (float, this[3838], compared to session time for ~5.5s gate) |
| this | 0x3D48 | RW | — | engine power factor 1 (float, this[3922], -789.0 sentinel = needs regeneration, else 0.7-1.0) |
| this | 0x3D4C | RW | — | engine power factor 2 (float, this[3923], -789.0 sentinel = needs regeneration, else 0.7-1.0) |
| this | 0x3D50 | RW | — | engine power factor 3 (float, this[3924], -789.0 sentinel = needs regeneration, else 0.7-1.0) |
| this | 0x3D60 | RW | 2 | failure mode state (this[3928], DWORD: 0=idle, 1=puncture active, 2=failure processing) |

**Written-by note (persistence):**
- obj 0x4068: recalc every frame — external poke does NOT persist
- this 0x3514: recalc every frame — external poke does NOT persist
- this 0x3518: recalc every frame — external poke does NOT persist
- this 0x3630: recalc every frame — external poke does NOT persist
- this 0x3978: recalc every frame — external poke does NOT persist
- this 0x39EE: recalc every frame — external poke does NOT persist
- this 0x3A30: recalc every frame — external poke does NOT persist
- this 0x3A44: recalc every frame — external poke does NOT persist
- this 0x3BF8: recalc every frame — external poke does NOT persist
- this 0x3D48: recalc every frame — external poke does NOT persist
- this 0x3D4C: recalc every frame — external poke does NOT persist
- this 0x3D50: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ee134 | jpt_4EDBA3 | R | switch jump table for failure type dispatch (i = 0/1/2/3) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e4e8 | flt_59E4E8 | R | PhysicsScale_E4E8 [DERIVED] (also: ` — physics/math scaling constant) |
| 0059e6f8 | flt_59E6F8 | R | SignedShortScale [DERIVED] (also: ` — scale factors) |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e874 | flt_59E874 | R | AITurnInSpeedThreshold [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e8f8 | flt_59E8F8 | R | PhysicsConst_59E8F8 [DERIVED] |
| 0059e918 | flt_59E918 | R | ProximityDistThreshold [DERIVED] |
| 0059e93c | flt_59E93C | R | EngineSpeedThreshold [DERIVED] |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059ed18 | flt_59ED18 | R | ForceReductionFactor [DERIVED] |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 005ad1f8 | dbl_5AD1F8 | R | UninitFloatMarker [DERIVED] (also: ` — Sentinel value (likely 0.0 or -1.0, indicating "use dynamic") |
| 005ad200 | flt_5AD200 | R | TireGripCalcFloat [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007cea5c | dword_7CEA5C | R | EngineWearMode (0/2/3) [DERIVED] |
| 007d0c60 | dword_7D0C60 | R | TireWearMultiplier [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008aced0 | flt_8ACED0 | R | TireFrictionRangeLow [DERIVED] |
| 008aced4 | flt_8ACED4 | R | TireWearInterpMax [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041ac50 | sub_41AC50 | posts a failure/event notification (arg2 = failure type: 0=engine, 1=gearbox, 2=puncture, 3=random wear) |
| 004d21d0 | sub_4D21D0 | returns true if race is in progress (gates failure event processing) |
| 004e8010 | TireBrushModelForceSolver | recomputes tire forces using brush model (called every ~5.5s with weather noise) |
| 005884ed | RandLCGRandomNumberGenerator | linear congruential random number generator (used for random tire wear target) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D60 | == | 0 | failure mode state: 0 = idle (no active failure), allows new failure events to start |

**Guard interpretation:** 
- `this[3678] > 0.0`: Fuel level must be above zero to decrement. When fuel drops to <= 0 after decrement, fuel is clamped to 0 and error code 9 (out of fuel) is posted if not already set.
- `fabs(dbl_8AFEA0 - this[3838]) > 5.5`: Weather-noise gate — TireBrushModelForceSolver is called only if ~5.5 seconds have elapsed since last call. Resets with random noise offset.
- `sub_4D21D0()`: Must return true (race in progress) for any failure events (engine, gearbox, puncture, random wear) to be processed.
- `this[i + 3929] >= 0.0`: Per-wheel failure countdown timer. When a failure timer expires (drops below 0), the switch dispatches the failure type. Case 0 = engine, 1 = gearbox, 2 = puncture, 3 = random tire wear.
- `this[3686] * 0.5 <= this[3685]`: Engine RPM at 50% or more of max → failure can proceed. Otherwise countdown resets to 0 (failure suppressed at low RPM).
- `this[3422] == 0.0`: If gearbox health is zero, gearbox failure is skipped (timer reset to 0).
- Engine wear mode `dword_7CEA5C == 3`: If wear mode 3, cap engine failure countdown to 60.0 max.
- Engine power factors (`this[3922/3923/3924]`): -789.0 sentinel means "needs regeneration". Random noise table (flt_8AAE74) selects which factor to regenerate with values 0.7-1.0.
