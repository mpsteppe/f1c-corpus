## AISteeringCorrection_00426cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x37CC | R | — | [LLM] |
| this | 0x38C4 | R | — | [LLM] |
| this | 0x39F9 | R | — | [LLM] |
| this | 0x4028 | RW | — | [LLM] |
| this | 0x442C | R | — | [LLM] |
| this | 0x4434 | RW | 0 | [LLM] |
| this | 0x4438 | RW | 0 | [LLM] |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4464 | RW | — | [LLM] |
| this | 0x446C | R | — | [LLM] |
| this | 0x4484 | R | — | [LLM] |
| this | 0x44B8 | R | — | [LLM] |
| this | 0x4538 | R | — | maxSpeed [CONFIRMED] |
| this | 0x457C | RW | — | [LLM] |
| this | 0x45FC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4028: recalc every frame — external poke does NOT persist
- this 0x4434: recalc every frame — external poke does NOT persist
- this 0x4438: recalc every frame — external poke does NOT persist
- this 0x4464: recalc every frame — external poke does NOT persist
- this 0x457C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e8e8 | flt_59E8E8 | R | LateralSpeedThreshold [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 005c3160 | byte_5C3160 | R | TrackConfigByte_5C3160 [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424750 | AIDifficultyScalar | [LLM] |
| 0042a740 | TrackParameterMinimumClamp | [LLM] |
| 0042b0e0 | AISteeringRacingLineCorrection | [LLM] |
| 004e8780 | SuspensionRatioClamp | [LLM] |
| 004e87e0 | BrakeThermalModel | [LLM] |
| 004e88b0 | TireGripCoefficient | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
