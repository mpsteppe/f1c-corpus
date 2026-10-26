## RotationVectorToQuaternion_0050e055 — Rotation vector to quaternion (w=0 output)

**Summary:** Converts a rotation-axis/angle vector `a2` (axis x,y,z + angle in a2[3]) to a quaternion with scalar part w always set to 0. Vector part is scaled by `angle/sin(angle)` for non-degenerate angles; copied verbatim when angle >= 1 or sin(angle) ≈ 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x (vector part, scaled from input) |
| this | 0x4 | RW | — | Quaternion y (vector part, scaled from input) |
| this | 0x8 | RW | — | Quaternion z (vector part, scaled from input) |
| this | 0xC | W | — | Quaternion w (always set to 0.0) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write (0.0) every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c042 | FloatRangeCheck | Checks if `sin(angle)` is approximately 0.0 to avoid division-by-near-zero |
| 005894a0 | FloatFunctionPassThrough | Called before `sin(angle)` computation; actual effect unclear |

**Guard conditions:** If `a2[3] >= 1.0` (large angle), skip the sin-based branch entirely and copy vector part verbatim. If `FloatRangeCheck(sin(angle), 0.0)` returns true (angle near 0 or π), sin is effectively zero so vector is copied verbatim to avoid division by near-zero. In all paths, w is unconditionally set to 0.0.
