## F_3DHermiteSplineInterpolation_004ff3a0 — 3D Hermite/Catmull-Rom spline interpolation

**Summary:** Performs Hermite (Catmull-Rom) spline interpolation between two 3D points `a1`/`a3` with tangents `a2`/`a4` at parameter `a5` (0..1), writing result to `a6`. Audio/sample interpolation system: normalizes tangents, computes Hermite basis functions, blends position.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AudioSampleCrossFadeInterpolation (004ff8f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output point X (component of float[3] written to a6) |
| this | 0x4 | RW | — | Output point Y (component of float[3] written to a6) |
| this | 0x8 | RW | — | Output point Z (component of float[3] written to a6) |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `sqrt(distanceSq(a3,a1)) <= 0.0` OR `a5 == 0.0`, copy `a1` to output (start point). If `a5 == 1.0`, copy `a3` to output (end point). Otherwise compute full Hermite interpolation.
