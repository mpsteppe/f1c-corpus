## TrackSplineExtrapolation_004349a0 — TrackSplineExtrapolation

**Summary:** Computes track spline extrapolation data. Samples track spline points from SetupScenePtr, interpolates midpoints, performs extrapolation calculations with Catmull-Rom-like spline math, then calls sub_457F90 with result array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4348B0 (004348b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians — conversion factor |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor — physics constant |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant — physics constant |
| 0059e8f8 | flt_59E8F8 | R | PhysicsConst_59E8F8 — physics constant |
| 0059ead0 | flt_59EAD0 | R | TrackDirScalingFactor — track direction scaling |
| 005c329c | dword_5C329C | R | VehicleCount — used as offset for output computation |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr — scene pointer for track spline data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403cd0 | sub_403CD0 | get track spline point data from scene at index |
| 00457f90 | sub_457F90 | process/finalize spline extrapolation result with count |

**Guard conditions:** No guard conditions — function executes fully on every call. Loop runs 103 iterations (hardcoded). Second loop runs 109 iterations for negate/adjust phase.
