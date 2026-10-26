## ComplexMemoryAllocationWithFloatComputation_00502c28 — AudioResampleFilterTableBuild

**Summary:** Allocates and builds a polyphase resampling filter position table for audio sample rate conversion. For each of a1 output positions, computes fractional input sample positions and generates a list of (source_index, fractional_weight) pairs. Handles wrap/no-wrap modes via a3 flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_502F31 (00502f31), sub_506003 (00506003)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ad260 | flt_5AD260 | R | ColorGradientLerpFactor [DERIVED] |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | Convert float/double to integer (ftol/lrint wrapper) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory for filter table |
| 005895a2 | sub_5895A2 | Float processing/rounding step for sample position |

**Guard conditions:** If a1 (output size) == 0 or a2 (input size) == 0 → return null. If a3 == 0 (non-wrapping mode): fractional positions clamped to [0, a2). If wrapping mode: positions wrap modulo input range.
