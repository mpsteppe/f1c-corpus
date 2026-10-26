## RotationMatrixToQuaternion_0050db5c — 3×3 rotation matrix to quaternion conversion

**Summary:** Converts a 3×3 rotation sub-matrix (from a 4×4 column-major matrix `a2`) into a unit quaternion (x,y,z,w in `a1`). Uses the standard trace-based algorithm with two branches to avoid numerical instability near 180° rotations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x (vector part, computed from off-diagonal differences) |
| this | 0x4 | RW | — | Quaternion y (vector part, computed from off-diagonal differences) |
| this | 0x8 | RW | — | Quaternion z (vector part, computed from off-diagonal differences) |
| this | 0xC | RW | — | Quaternion w (scalar part, computed from trace) |

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
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If trace (M00+M11+M22 = `a2[0]+a2[5]+a2[10]`) > 0.0, use the direct formula with qw largest. If trace <= 0.0, find the largest diagonal element and compute the quaternion from that axis to maintain numerical stability.
