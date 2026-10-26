## SteeringAlignmentToleranceCheck_004b67d0 — Steering Angle Tolerance Check

**Summary:** Checks if an angular difference (a2) is within tolerance, scaled by difficulty level (this[0x9AC]) and an additional factor (a3). Returns true if the angle difference is small enough for alignment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B6360 (004b6360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9AC | R | — | Difficulty/assist level index (0-3, threshold selector) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b689c | jpt_4B67DD | R | Jump table for first switch (base tolerance selection) |
| 004b68ac | jpt_4B6832 | R | Jump table for second switch (multiplier tolerance selection) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: display message threshold) |
| 005acd44 | flt_5ACD44 | R | TireLateralForceCoeff1 [DERIVED] |
| 005acd58 | flt_5ACD58 | R | SteeringProgressiveScale [DERIVED] |
| 005acd5c | flt_5ACD5C | R | Flt_SteeringDeadzone [DERIVED] |
| 005acd60 | flt_5ACD60 | R | SteeringWheelAngleCoeff [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns true immediately if |a2| <= base tolerance (varies by index: 0.0491/0.0245/0.01636/0.01227/0.09817 rad). Otherwise, computes dynamic tolerance = max(base_tol*2, mult_tol * |a3|). Returns true if |a2| <= dynamic tolerance.
