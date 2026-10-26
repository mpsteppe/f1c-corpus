## RandomRotationMatrixFromEulerAngles_00541db0 — Build rotation matrix from Euler angles

**Summary:** Computes a 3×3 rotation matrix from Euler angle inputs (a2,a3,a4) using sin/cos, writes it to offsets 0x15C-0x188 (zeros in column 4, 1.0f at 0x198), then transforms the orientation vector at 0x24-0x2C by the new matrix into 0x18C-0x194.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_1cd0 (00541cd0), SceneRenderTransform (00548c20), sub_560C10 (00560c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | orientation X — multiplied by new rotation matrix |
| this | 0x28 | R | — | orientation Y — multiplied by new rotation matrix |
| this | 0x2C | R | — | orientation Z — multiplied by new rotation matrix |
| this | 0x30 | RW | — | stores a2 (Euler angle X after InterruptDispatch) |
| this | 0x34 | RW | — | stores a3 (Euler angle Y after InterruptDispatch) |
| this | 0x38 | RW | — | stores a4 (Euler angle Z after InterruptDispatch) |
| this | 0x15C | RW | — | rotation matrix m00 |
| this | 0x160 | RW | — | rotation matrix m10 |
| this | 0x164 | RW | — | rotation matrix m20 |
| this | 0x168 | RW | 0 | rotation matrix column 0, row 3 — always zero |
| this | 0x16C | RW | — | rotation matrix m01 |
| this | 0x170 | RW | — | rotation matrix m11 |
| this | 0x174 | RW | — | rotation matrix m21 |
| this | 0x178 | RW | 0 | rotation matrix column 1, row 3 — always zero |
| this | 0x17C | RW | — | rotation matrix m02 |
| this | 0x180 | RW | — | rotation matrix m12 |
| this | 0x184 | RW | — | rotation matrix m22 |
| this | 0x188 | RW | 0 | rotation matrix column 2, row 3 — always zero |
| this | 0x18C | RW | — | result orientation X (matrix * input) |
| this | 0x190 | RW | — | result orientation Y (matrix * input) |
| this | 0x194 | RW | — | result orientation Z (matrix * input) |
| this | 0x198 | RW | 1065353216 → 1.0f | 4×4 matrix homogeneous element — always set to 1.0 |

**Written-by note (persistence):**
- this 0x30-0x38: overwritten with Euler angles each call.
- this 0x15C-0x188: recomputed rotation matrix each call.
- this 0x18C-0x194: recomputed each call.
- this 0x198: set to 1.0f each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8960 | dbl_5B8960 | R | PhysicsDouble_5B8960 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058957a | InterruptDispatch | clamp/normalize Euler angle inputs |

**Guard conditions:** None — always executes fully.
