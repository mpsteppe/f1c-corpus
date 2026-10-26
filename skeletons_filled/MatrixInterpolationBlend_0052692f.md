## MatrixInterpolationBlend_0052692f — MatrixInterpolationBlendSkeletal

**Summary:** Compose up to 3 transform inputs (a6/a7/a8) based on null-state switch, normalize composed result via sub_525E9A, interpolate between input vector a4 and blend weight a5, then apply transform. Used for skeletal animation blending.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00526b35 | jpt_526969 | R | Jump table for switch on a6/a7/a8 null-state combination |
| 005af980 | qword_5AF980 | R | SIMD_Const_5AF980 [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af998 | qword_5AF998 | R | MMMX_PolyCoeffAF998 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00525e9a | sub_525E9A | SIMD matrix/quaternion normalization (applied after composition) |
| 00526550 | F_4DVectorTransform | Transform vector by composed matrix |
| 005265db | F_8SIMDMatrixPackedFloatOperation | Compose two SIMD matrix/quaternion transforms |

**Guard conditions:** Switch on `(a6!=0) | (2*((a7!=0) | (2*(a8!=0))))` → 8 cases select which optional inputs compose the transform. Case 0 (all null): identity. If a5 is non-null: interpolate blend path between a4 and a5 before transform. If a5 is null: direct transform of a4 via composed matrix.
