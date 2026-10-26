## OrientationRotationMatrixUpdate_00541d10 — Update orientation rotation matrix

**Summary:** Stores orientation input vector (a2,a3,a4) at 0x24-0x2C, multiplies a 3×3 rotation matrix at 0x15C-0x184 by the vector to compute transformed orientation at 0x18C-0x194, and writes 1.0f to 0x198 (4×4 matrix homogeneous element).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_1cd0 (00541cd0), SceneRenderTransform (00548c20), sub_55A060 (0055a060), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | orientation X — written with a2 |
| this | 0x28 | RW | — | orientation Y — written with a3 |
| this | 0x2C | RW | — | orientation Z — written with a4 |
| this | 0x15C | R | — | rotation matrix column 0, row 0 (m00) |
| this | 0x160 | R | — | rotation matrix column 0, row 1 (m10) |
| this | 0x164 | R | — | rotation matrix column 0, row 2 (m20) |
| this | 0x16C | R | — | rotation matrix column 1, row 0 (m01) |
| this | 0x170 | R | — | rotation matrix column 1, row 1 (m11) |
| this | 0x174 | R | — | rotation matrix column 1, row 2 (m21) |
| this | 0x17C | R | — | rotation matrix column 2, row 0 (m02) |
| this | 0x180 | R | — | rotation matrix column 2, row 1 (m12) |
| this | 0x184 | R | — | rotation matrix column 2, row 2 (m22) |
| this | 0x18C | RW | — | result orientation X (matrix * input) |
| this | 0x190 | RW | — | result orientation Y (matrix * input) |
| this | 0x194 | RW | — | result orientation Z (matrix * input) |
| this | 0x198 | RW | 1065353216 → 1.0f | 4×4 matrix homogeneous element (always set to 1.0) |

**Written-by note (persistence):**
- this 0x24-0x2C: overwritten with input vector each call.
- this 0x18C-0x194: recomputed each call.
- this 0x198: set to 1.0f each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes fully.
