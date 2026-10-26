## F_3DNowPackedFloatMatrixQuaternionOps_00523e7a — 3DNow! multiply quaternions and convert to 4x4 rotation matrix

**Summary:** Scales input quaternions a2 and a3 by 0.5 (0x3F0000003F000000LL), multiplies them via 3DNow! quaternion multiplication with component shuffling and sign flips, then converts the result to a 4x4 rotation matrix using the cofactor/adjugate pattern (same as sub_522B5B): 2x multiplications, cross-term products, 1.0 - trace subtraction (pfsubr 0x3F8000003F800000LL), and homogeneous row {0, 0, 0, 1.0}.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 col 0-1 (quaternion-derived rotation) |
| this | 0x8 | R | — | Output matrix row 0 col 2-3 |
| this | 0x10 | R | — | Output matrix row 1 col 0-1 |
| this | 0x18 | R | — | Output matrix row 1 col 2-3 |
| this | 0x20 | R | — | Output matrix row 2 col 0-1 |
| this | 0x28 | R | — | Output matrix row 2 col 2-3 |
| this | 0x30 | R | — | Output matrix row 3 col 0-1 (zeroed) |
| this | 0x38 | R | — | Output matrix row 3 col 2-3 ({0, 1.0} homogeneous row) |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (SIMD constant for matrix computation) |
| 005af920 | qword_5AF920 | R | MMXSignFlipConst [DERIVED] |
| 005af990 | qword_5AF990 | R | MMX_3DNow_QuadConstant_0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005295e0 | PackedFloatingPointMath | Component setup/expansion for quaternion multiplication and matrix construction |

**Guard conditions:** None — no conditional branches; always executes full quaternion multiply + matrix conversion.
