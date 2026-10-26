## AISteeringCorrection_00426cf0 — AI Steering Correction and Grip-Degradation Blend

**Summary:** Computes AI steering correction blend factor by combining racing line steering with suspension-ratio-based steering, applying tire grip degradation logic post race-start, and enforcing difficulty-scaled and track-specific limits. Part of AI driver per-frame update.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIMainUpdate (00424e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x37CC | R | — | racing line target steering angle (this+14284) |
| this | 0x38C4 | R | — | actual vehicle steering angle or yaw rate (this+14532) |
| this | 0x39F9 | R | — | byte flag — steering correction mode active (this+14841) |
| this | 0x4028 | RW | — | lateral slip correction output value (this+16424) |
| this | 0x442C | R | — | lateral force or body slip angle magnitude (fabs of this+17452) |
| this | 0x4434 | RW | 0 | steering blend factor / smoothed steering target (this+17460) |
| this | 0x4438 | RW | 0 | tire grip memory / peak grip during degradation (this+17464) |
| this | 0x4440 | R | — | Speed [FACT] (also: actualSpeed) |
| this | 0x4464 | RW | — | previous frame steering target for smoothing (this+17508) |
| this | 0x446C | R | — | steering override / active flag (this+17516) |
| this | 0x4484 | R | — | lap distance counter / speed history (this+17540) |
| this | 0x44B8 | R | — | track segment maximum steering angle limit (this+17592) |
| this | 0x4538 | R | — | maxSpeed [CONFIRMED] |
| this | 0x457C | RW | — | AI difficulty-scaled steering limit (this+17788) |
| this | 0x45FC | R | — | AI steering correction enabled flag (this+17916) |

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
| 00424750 | AIDifficultyScalar | returns AI difficulty multiplier (0.0-1.0) used to scale steering limit |
| 0042a740 | TrackParameterMinimumClamp | clamps a value to track-specific minimum (steering limit floor) |
| 0042b0e0 | AISteeringRacingLineCorrection | computes racing-line-based steering correction from track data |
| 004e8780 | SuspensionRatioClamp | returns suspension-ratio-derived steering target |
| 004e87e0 | BrakeThermalModel | returns brake-temperature-biased grip factor |
| 004e88b0 | TireGripCoefficient | returns current tire grip coefficient |

**Guard conditions:** 
- `*(this+17916) != 0`: AI steering active → sets difficulty-scaled limit = AIDifficultyScalar() * 0.75. BLOCKED if zero: skip limit calculation.
- `|lateral_force| > 0.1 AND speed > 20.0`: significant lateral force at speed → dampens steering blend toward 0 by factor (1.0 - |lateral| * 0.7). BLOCKED: keep current blend unchanged.
- `steeringBlend < 0.8999 AND (speed > 4.0 OR steeringOverride)`: steering not near limit AND (moving OR override active) → compute suspension-ratio clamp correction, blend toward it. BLOCKED: skip suspension correction.
- `byte flag at this+14841 set (x87 status flags)`: condition flags from previous fabs → apply smoothed correction delta clamped to [0,1]. BLOCKED: skip delta.
- `RacePhase < 5 AND SessionType == 7`: pre-race/race phase AND race session → call AISteeringRacingLineCorrection. BLOCKED: skip racing line correction.
- `SessionTime >= RaceTimeOffset + 2.5`: past race start grace period → enter tire grip degradation cascade:
  - `lapDist + 10.0 >= speed`: very slow → if `lapDist + 1.0 >= speed` (near stationary) AND speed > lapDist AND gripMem == 0.0 → set blend = BrakeThermalModel * 0.8. Else: not near stationary: zero blend, zero gripMem.
  - `lapDist + 3.0 >= speed`: moderate speed → blend = zero, gripMem = max(gripMem, TireGripCoefficient * 0.5).
  - else (fast): blend = zero, gripMem = TireGripCoefficient.
  BLOCKED (SessionTime < offset + 2.5): if gripMem > 0, reset to 0.
- `byte_5C3160 != 0`: track config flag → cap blend at min(blend, clamp(trackMaxSteering, 1.0)). BLOCKED: use difficulty-scaled limit as cap.
