## F_3DNowVectorTransform_00526b55 — F_3DNowVectorTransformAndInvert

**Summary:** Compose up to 3 transform inputs (a6/a7/a8), invert composed result via F_4x4MatrixInversion, optionally blend input vector with weight a5, then apply inverse transform. Differs from MatrixInterpolationBlend by inverting the composed matrix.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00526c88 | jpt_526B8B | R | Jump table for switch on a6/a7/a8 null-state combination |
| 005af980 | qword_5AF980 | R | SIMD_Const_5AF980 [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af998 | qword_5AF998 | R | MMMX_PolyCoeffAF998 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00522b22 | sub_522B22 | Build identity/default matrix |
| 005257c0 | F_4x4MatrixInversion | Invert 4x4 matrix |
| 00526550 | F_4DVectorTransform | Transform vector by composed matrix |
| 005265db | F_8SIMDMatrixPackedFloatOperation | Compose two SIMD matrix/quaternion transforms |

**Guard conditions:** Switch on `(a6!=0) | (2*((a7!=0) | (2*(a8!=0))))` → 8 cases. Cases 0: identity via sub_522B22. Cases 1/2/4: single-input inversion. Cases 3/5/6/7: compose then invert. If a5 non-null: blend between a4 and a5 then transform. If a5 null: direct transform of a4.
