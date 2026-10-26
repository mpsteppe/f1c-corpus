## CollisionResponseFilter_004584c0 — AngularCollisionResponseFilter

**Summary:** Filters angular collision response by comparing total angular difference against a scaled threshold. Wraps and normalizes input Euler angles, sums absolute differences, and if total exceeds threshold * a5, performs quaternion slerp between source and target orientations. Otherwise passes source through unchanged.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_458DF0 (00458df0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA4 | R | — | angular response threshold scale factor (stiffness/damping parameter) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00455f90 | AngleWrap | wrap individual Euler angle component to [-π, π] |
| 00455fd0 | AngleNormalization | normalize angular difference to standard range |
| 00567010 | sub_567010 | convert interpolated quaternion back to Euler angles in output buffer |
| 00567030 | QuaternionFromEulerAngles | convert Euler angles to quaternion representation |
| 00567580 | sub_567580 | spherical linear interpolation (slerp) between two quaternions |

**Guard conditions:** Compute `threshold = this[0xA4] * a5 * total_angular_diff`. If `total_angular_diff <= threshold` OR `total_angular_diff <= 0.0` → copy source Euler angles directly to output, skip quaternion interpolation. Threshold being at least as large as the diff (or zero diff) means no blending needed.
