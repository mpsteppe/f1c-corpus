## F_3DNowQuaternionFromAngle_0052278b — 3DNow! construct 4x4 rotation matrix from quaternion + normalized axis

**Summary:** Normalizes input a3 via F_3DVectorNormalize_7578 into stacked v14/v15 (16 bytes), then combines with quaternion/vector a2 via dot-product-like operations (pfmul/pfadd) and negated copies (XOR 0x80000000) to fill all 8 __m64 slots of output a1, forming a 4x4 rotation matrix.

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
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00527578 | F_3DVectorNormalize_7578 | Normalizes rotation axis vector from a3 into v14/v15 for matrix construction |

**Guard conditions:** None — no conditional branches; always executes full matrix construction.
