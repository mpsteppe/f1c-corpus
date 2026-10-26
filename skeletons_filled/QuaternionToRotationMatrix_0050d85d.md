## QuaternionToRotationMatrix_0050d85d — Quaternion to Rotation Matrix

**Summary:** Converts a unit quaternion (a2) to a 4x4 rotation matrix (a1). Implements standard formula: R[i][j] = ... using products qx^2, qy^2, qz^2, qx*qy, qx*qz, qx*qw, qy*qz, qy*qw, qz*qw. Output is column-major with translation row/column zeroed and bottom-right element = 1.0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix element [0][0] (1 - 2qy^2 - 2qz^2) |
| this | 0x4 | RW | — | Output matrix element [0][1] (2qx*qy + 2qz*qw) |
| this | 0x8 | RW | — | Output matrix element [0][2] (2qx*qz - 2qy*qw) |
| this | 0xC | RW | — | Output matrix element [0][3] = 0.0 |
| this | 0x10 | RW | — | Output matrix element [1][0] (2qx*qy - 2qz*qw) |
| this | 0x14 | RW | — | Output matrix element [1][1] (1 - 2qx^2 - 2qz^2) |
| this | 0x18 | RW | — | Output matrix element [1][2] (2qy*qz + 2qx*qw) |
| this | 0x1C | RW | — | Output matrix element [1][3] = 0.0 |
| this | 0x20 | RW | — | Output matrix element [2][0] (2qx*qz + 2qy*qw) |
| this | 0x24 | RW | — | Output matrix element [2][1] (2qy*qz - 2qx*qw) |
| this | 0x28 | RW | — | Output matrix element [2][2] (1 - 2qx^2 - 2qy^2) |
| this | 0x2C | RW | — | Output matrix element [2][3] = 0.0 |
| this | 0x30 | RW | — | Output matrix element [3][0] = 0.0 |
| this | 0x34 | RW | — | Output matrix element [3][1] = 0.0 |
| this | 0x38 | RW | — | Output matrix element [3][2] = 0.0 |
| this | 0x3C | RW | — | Output matrix element [3][3] = 1.0 |

**Written-by note (persistence):**
- this 0x0-0x3C: all 16 elements written unconditionally each call; output buffer, ephemeral

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: under-relaxation upper bound) |

**Functions called:** none

**Guard conditions:** unconditional — no branches, no early return.
