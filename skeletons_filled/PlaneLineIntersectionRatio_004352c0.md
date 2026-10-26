## PlaneLineIntersectionRatio_004352c0 — RayPlaneIntersectionRatio

**Summary:** Computes intersection ratio t along ray from a1 to a3 where it intersects plane defined by parameters a2 and a4 (x and z components). Returns FLT_MAX (3.4028235e38) for degenerate cases where denominator is zero.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | planeParamA (float x) |
| this | 0x8 | R | — | planeParamB (float z) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059eae0 | flt_59EAE0 | R | FLT_MAX_Infinity [DERIVED] (also: ` — infinity/FLT_MAX return value) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Returns FLT_MAX if a4.x == 0.0 AND a4.z == 0.0 (degenerate plane). Returns FLT_MAX if the computed denominator equals 0.0 (parallel/no intersection). Otherwise returns ratio v9/v10.
