## CubicSplineInterpolation_00457d00 — CatmullRomSplineInterpolate

**Summary:** Evaluates Catmull-Rom cubic spline at parameter `a2` over a keyframe array (28-byte stride: 3 position components + 4 tangent/control fields + time). Finds segment containing `a2`, normalizes position, computes 4 basis functions, and writes interpolated X/Y/Z plus time into output slots at offsets 0xC-0x18.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | keyframe[1].valueX (second keyframe X component) |
| obj | 0x20 | R | — | keyframe[1].valueY (second keyframe Y component) |
| obj | 0x24 | R | — | keyframe[1].valueZ (second keyframe Z component) |
| obj | 0x34 | R | — | keyframe[1].time (second keyframe time value) |
| this | 0x0 | R | — | pointer to keyframe array (28-byte stride per keyframe) |
| this | 0x4 | R | — | keyframe count minus 3 (number of spline segments) |
| this | 0x8 | R | — | total time span / maximum time boundary |
| this | 0xC | RW | — | output: current spline position (t) |
| this | 0x10 | RW | — | output: interpolated X component |
| this | 0x14 | RW | — | output: interpolated Y component |
| this | 0x18 | RW | — | output: interpolated Z component |

**Written-by note (persistence):**
- this 0xC: written every call (t = a2, or clamped at 0.0 or this[2]). No external poke survives.
- this 0x10: written every call (interpolated X). No external poke survives.
- this 0x14: written every call (interpolated Y). No external poke survives.
- this 0x18: written every call (interpolated Z). No external poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 < 0.0 → clamp output to first segment keyframe (index 1 values), set t=0.0. If a2 >= this[2] → clamp to last segment keyframe, set t=this[2]. Otherwise, binary search across (this[1]-3) segments: find segment where keyframe[v6].time <= a2 < keyframe[v6+1].time, then compute normalized position and evaluate 4-point Catmull-Rom basis.
