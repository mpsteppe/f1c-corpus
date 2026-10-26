## TireFrictionCurveEval_00447bb0 — Tire friction curve piecewise evaluation

**Summary:** Evaluates tire friction force from slip input (double at this+0x19C). Returns saturated output (58.5) when input ≥ 4.4, zero when input ≤ 0.0, and interpolated value using TrigTableLookup in the range 0.0–4.0 with inflection at 0.4. Scales final result by 58.5.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParamRangeClampedLerp (0049f530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19C | R | — | tire slip input (ratio/angle) used as friction curve independent variable |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059ec80 | dbl_59EC80 | R | InputOffsetBias [DERIVED] |
| 0059ef00 | flt_59EF00 | R | SaturatedOutputValue [DERIVED] (also: ` — output value at saturation) |
| 0059ef08 | dbl_59EF08 | R | OutputScaleFactor [DERIVED] |
| 0059ef10 | dbl_59EF10 | R | InputSaturationThreshold [DERIVED] (also: ` — upper input threshold (saturation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00447ab0 | TrigTableLookup | lookup curve shape modifier from trigonometric table for friction interpolation |

**Guard conditions:** Returns 58.5 immediately if this+0x19C ≥ 4.4 (saturation clamp). Returns 0.0 immediately if this+0x19C ≤ 0.0 (no-slip clamp). Otherwise proceeds to interpolation path.
