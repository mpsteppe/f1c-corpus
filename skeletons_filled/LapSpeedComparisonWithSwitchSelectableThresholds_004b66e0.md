## LapSpeedComparisonWithSwitchSelectableThresholds_004b66e0 — Speed Difference Threshold Check

**Summary:** Compares two float values (a2, a3) against difficulty-scaled thresholds selected by this[0x9AC]. Used to determine if speed/velocity differences between two states are within acceptable bounds.

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
| 004b67ac | jpt_4B66EC | R | Jump table for first switch (a2 threshold selection) |
| 004b67bc | jpt_4B6755 | R | Jump table for second switch (scaled threshold selection) |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: float 0.016667 (1/60, frame delta)) |
| 0059e44c | flt_59E44C | R | Flt_CollisionTolerance [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: under-relaxation upper bound) |
| 0059e8f4 | flt_59E8F4 | R | PhysicsThreshold_59E8F4 [DERIVED] |
| 005acd3c | flt_5ACD3C | R | AeroDragCoefficient [DERIVED] (also: aero constant) |
| 005acd40 | flt_5ACD40 | R | TireGripScaleFactor [DERIVED] |
| 005acd44 | flt_5ACD44 | R | TireLateralForceCoeff1 [DERIVED] |
| 005acd48 | flt_5ACD48 | R | TireGripThreshold [DERIVED] |
| 005acd4c | flt_5ACD4C | R | WheelRateInterpMult [DERIVED] |
| 005acd50 | flt_5ACD50 | R | SuspensionBumpStopScale [DERIVED] |
| 005acd54 | flt_5ACD54 | R | WheelSlipThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns true immediately if |a2| <= base threshold (varies by index: 0.045/0.022/0.01/0.007/0.066). Otherwise, clamp |a3| to [2.0, 7.5] (if |a3| < 2.0, return false; if > 7.5, clamp to 7.5). Return true if |a2| <= scaled_threshold * clamped|a3|.
