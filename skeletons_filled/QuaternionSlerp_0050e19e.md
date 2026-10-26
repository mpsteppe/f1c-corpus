## QuaternionSlerp_0050e19e — Spherical linear interpolation between two quaternions

**Summary:** SLERPs between quaternions `a2` and `a3` with factor `a4` (0-1). Uses standard formula with dot-product sign flip for shortest path, trig-based interpolation except near 1-dot ~ FLT_EPSILON where linear interpolation avoids instability.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x (interpolated result) |
| this | 0x4 | RW | — | Quaternion y (interpolated result) |
| this | 0x8 | RW | — | Quaternion z (interpolated result) |
| this | 0xC | RW | — | Quaternion w (interpolated result) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ac9c0 | flt_5AC9C0 | R | QuaternionSlerpEpsilon [DERIVED] (also: ` — near-unity epsilon for dot product) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `1 - |dot(q1,q2)| <= 1.1920929e-7` (~FLT_EPSILON), the quaternions are nearly parallel — skip trigonometric computation and use linear interpolation weights `1-t` and `t` to avoid division by near-zero sin(θ). Otherwise compute full SLERP with `sin((1-t)θ)/sinθ` and `sin(tθ)/sinθ` weights.
