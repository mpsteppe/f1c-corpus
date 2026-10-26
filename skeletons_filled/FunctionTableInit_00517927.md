## FunctionTableInit_00517927 — FillMathFunctionTable

**Summary:** Populates an 8-entry function pointer table with math/geometry transform functions: Vec2AffineTransform, sub_517569, sub_517653, two 4x4 matrix multiply variants, Mat2x2Mul, sub_5175F4, and VectorNormalize.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50FEA7 (0050fea7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | table entry 0: Vec2AffineTransform |
| this | 0x4 | RW | — | table entry 1: sub_517569 |
| this | 0x8 | RW | — | table entry 2: sub_517653 |
| this | 0xC | RW | — | table entry 3: F_44MatrixMultiply |
| this | 0x10 | RW | — | table entry 4: F_44MatrixMultiply_7899 |
| this | 0x14 | RW | — | table entry 5: Mat2x2Mul |
| this | 0x18 | RW | — | table entry 6: sub_5175F4 |
| this | 0x1C | RW | — | table entry 7: VectorNormalize |

**Written-by note (persistence):**
- this 0x0–0x1C: each entry written once, persists as read-only dispatch table

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005174cb | Vec2AffineTransform | R | function pointer stored at table[0] — 2D affine transform |
| 00517534 | Mat2x2Mul | R | function pointer stored at table[5] — 2x2 matrix multiply |
| 00517569 | sub_517569 | R | function pointer stored at table[1] |
| 005175f4 | sub_5175F4 | R | function pointer stored at table[6] |
| 00517653 | sub_517653 | R | function pointer stored at table[2] |
| 005176ec | VectorNormalize | R | function pointer stored at table[7] — vector normalization |
| 005177b6 | F_44MatrixMultiply | R | function pointer stored at table[3] — 4x4 matrix multiply |
| 00517899 | F_44MatrixMultiply_7899 | R | function pointer stored at table[4] — 4x4 matrix multiply variant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — fills all 8 table entries unconditionally.
