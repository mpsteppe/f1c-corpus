## FuelConsumptionAndWear_004ed960 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4068 | RW | 4 | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x3510 | R | — | [LLM] |
| this | 0x3514 | RW | — | [LLM] |
| this | 0x3518 | RW | — | [LLM] |
| this | 0x3570 | R | — | [LLM] |
| this | 0x3578 | R | — | [LLM] |
| this | 0x35D0 | R | — | [LLM] |
| this | 0x3624 | R | — | [LLM] |
| this | 0x3630 | RW | — | [LLM] |
| this | 0x3634 | R | — | [LLM] |
| this | 0x3978 | RW | — | [LLM] |
| this | 0x3984 | R | — | [LLM] |
| this | 0x3994 | R | — | [LLM] |
| this | 0x3998 | R | — | [LLM] |
| this | 0x39A4 | R | — | EngineMaxRPM [CONFIRMED] |
| this | 0x39B0 | R | — | [LLM] |
| this | 0x39EE | RW | 1 | [LLM] |
| this | 0x3A30 | RW | — | [LLM] |
| this | 0x3A44 | RW | — | [LLM] |
| this | 0x3BF4 | R | — | [LLM] |
| this | 0x3BF8 | RW | — | [LLM] |
| this | 0x3D48 | RW | — | [LLM] |
| this | 0x3D4C | RW | — | [LLM] |
| this | 0x3D50 | RW | — | [LLM] |
| this | 0x3D60 | RW | 2 | [LLM] |

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
| 004ee134 | jpt_4EDBA3 | R | [LLM] |
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
| 0041ac50 | sub_41AC50 | [LLM] |
| 004d21d0 | sub_4D21D0 | [LLM] |
| 004e8010 | TireBrushModelForceSolver | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3D60 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
