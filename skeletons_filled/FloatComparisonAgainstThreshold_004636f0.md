## FloatComparisonAgainstThreshold_004636f0 — Positive Float Check

**Summary:** Returns whether float value at this+0x380 is greater than 0.0. Simple positive-threshold check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_f070 (0049f070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x380 | R | — | float value checked against zero |
| this | 0x0 | R | — | vtable/primary pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditionally returns the comparison result.
