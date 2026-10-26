## PhaseBasedAudioParticleEnvelope_004d7ff0 — Audio particle envelope tick

**Summary:** Advances a phase accumulator (this+0xC) by a fixed delta (dbl_8AFE98), then computes a multi-segment amplitude envelope (attack-sustain-release) across a 4.0-unit cycle, gated at a 0.2 threshold. Calls TimerClockFormat to apply the resulting amplitude.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableDispatchChain_7e00 (004d7e00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | Phase accumulator (elapsed time / cycle position), incremented by dbl_8AFE98 each call |

**Written-by note (persistence):**
- this 0xC: Incremented by dbl_8AFE98 every call; accumulator persists across calls (external writes could also modify it)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e9c0 | flt_59E9C0 | R | TimeConversionFactor [DERIVED] |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 005acce8 | flt_5ACCE8 | R | BrakeReleaseHigh [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8130 | TimerClockFormat | Applies computed envelope amplitude to audio particle given float phase value and int channel/selector flag |
| 00587bdc | CRTFtol | Float-to-integer truncation (floor-like) for phase reduction by 60-unit multiples |

**Guard conditions:** Phase value `v2 < 0.2` → BLOCKED (early return, no envelope applied). `v2 >= 0.2` → PASSES into multi-segment envelope: 0.2–0.5 fade-in (flag=1), 0.5–1.5 sustain (flag=1), 1.5–2.0 fade-out (flag=1), 2.0–2.5 fade-in (flag=0), 2.5–3.5 sustain (flag=0), 3.5–4.0 fade-out (flag=0); `v2 >= 4.0` → noop (beyond cycle).
