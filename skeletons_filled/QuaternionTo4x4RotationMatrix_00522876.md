## QuaternionTo4x4RotationMatrix_00522876 — 3DNow! convert quaternion to 4x4 rotation matrix

**Summary:** Normalizes quaternion from a2 via F_3DVectorNormalize_7578 into v11/v12, then constructs a 4x4 rotation matrix in a1 using the standard quaternion-to-matrix formula: computes terms -2*q² and -2*qu with pfmul(0xC0000000 = -2.0f), shuffles components via punpckldq/punpckhdq, and fills all 8 __m64 slots with pfadd/pfmul combinations including identity elements (1065353216 = 1.0f).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 columns 0-1 |
| this | 0x8 | R | — | Output matrix row 0 columns 2-3 |
| this | 0x10 | R | — | Output matrix row 1 columns 0-1 |
| this | 0x18 | R | — | Output matrix row 1 columns 2-3 |
| this | 0x20 | R | — | Output matrix row 2 columns 0-1 |
| this | 0x28 | R | — | Output matrix row 2 columns 2-3 |
| this | 0x30 | R | — | Output matrix row 3 columns 0-1 |
| this | 0x38 | R | — | Output matrix row 3 columns 2-3 |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af9c0 | qword_5AF9C0 | R | ThreeDNowIdentityConst [DERIVED] |
| 005af9c8 | qword_5AF9C8 | R | MMatrixConstants [DERIVED] |
| 005af9d8 | qword_5AF9D8 | R | MMXMatrixCoeff [DERIVED] |
| 005af9e0 | qword_5AF9E0 | R | MMXQuatToMatrixConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00527578 | F_3DVectorNormalize_7578 | Normalizes input quaternion from a2 into v11/v12 before matrix construction |

**Guard conditions:** None — no conditional branches; always executes full conversion.
