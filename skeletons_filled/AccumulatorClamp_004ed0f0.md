## AccumulatorClamp_004ed0f0 — accumulator with hysteresis threshold clamping

**Summary:** Accumulates input scaled by 0.225, applies upper bound clamp, checks hysteresis thresholds to update output value and flag. Part of accumulator/clamping system for physics.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FloatParameterForwarder (004ed1c0), ForceApplicationRouter (004ed1f0), PhysicsTimeStep (004ed220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3A6C | RW | — | accumulator value (integrated input * 0.225) |
| this | 0x3A70 | RW | — | output/clamped value (may be reduced by hysteresis) |
| this | 0x3A78 | R | — | threshold base for upper bound and hysteresis checks |
| this | 0x3A80 | R | — | reference value for output reduction when threshold exceeded |
| this | 0x3D60 | RW | 1 | hysteresis flag (set to 1 when lower threshold crossed) |

**Written-by note (persistence):**
- this 0x3A6C: recalc every frame — external poke does NOT persist
- this 0x3A70: recalc every frame — external poke does NOT persist
- this 0x3D60: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059e8fc | flt_59E8FC | R | AccelAccumLimit [DERIVED] |
| 005acee8 | flt_5ACEE8 | R | FrontRearDistributionWeight [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No early-return guards. Threshold comparisons at +0.15 and +0.3 relative to this[0x3A78] control output reduction and flag setting, but always fall through to full execution.
