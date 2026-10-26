## TrigTableLookup_00447ab0 — TrigTableLinearInterpolator

**Summary:** Performs a linear interpolated lookup into a 256-entry trig table using a scaled input value (x4.0 offset by -0.5). Uses integer truncation for table index and fractional part for interpolation between adjacent entries. Part of vehicle physics trig calculations.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RandomPhysicsParameterGenerator (00447b10), TireFrictionCurveEval (00447bb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | R | — | input value for trig lookup (scaled by 4.0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** no branches — always returns interpolated table value
