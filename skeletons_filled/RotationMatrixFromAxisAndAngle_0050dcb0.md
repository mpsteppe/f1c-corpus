## RotationMatrixFromAxisAndAngle_0050dcb0 — Axis-angle to quaternion conversion

**Summary:** Builds a quaternion (x,y,z,w) from a rotation axis (derived from `a2` via a thunk call) and an angle `a3` (in degrees). Computes half-angle trig and scales the axis by `sin(halfAngle)` for the vector part.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x = axis.x * sin(angle/2) |
| this | 0x4 | RW | — | Quaternion y = axis.y * sin(angle/2) |
| this | 0x8 | RW | — | Quaternion z = axis.z * sin(angle/2) |
| this | 0xC | RW | — | Quaternion w = cos(angle/2) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c2b3 | ThunkTo | Resolves axis components from `a2` into local variables v5/v6/v7 (axis x/y/z) |

**Guard conditions:** No guard — all four quaternion components are unconditionally written.
