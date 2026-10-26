## QuaternionTransformComposition_005267a7 — QuaternionTransformCompose

**Summary:** Compose up to 3 quaternion/transform inputs based on which are non-null (a6/a7/a8), apply resulting transform to vector via F_4DVectorTransform, optionally blend output with a5 weighting. Core 3D transform composition routine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0052690f | jpt_5267E2 | R | Jump table for switch on a6/a7/a8 null-state combination |
| 005af980 | qword_5AF980 | R | SIMD_Const_5AF980 [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af990 | qword_5AF990 | R | MMX_3DNow_QuadConstant_0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00526550 | F_4DVectorTransform | Apply composed transform (matrix/quaternion) to vector(s) a4 → a3 |
| 005265db | F_8SIMDMatrixPackedFloatOperation | Compose two SIMD matrix/quaternion transforms (used for a6/a7/a8 combinations) |

**Guard conditions:** Switch selects composition path based on which of (a6, a7, a8) are non-null. Formula: `(a6!=0) | (2*((a7!=0) | (2*(a8!=0))))`. Cases 0-7. Case 0 (all null): identity. Cases 3,5,6,7: compose via F_8SIMDMatrixPackedFloatOperation. Then if a5 is non-null, apply blend/weight adjustment to a3 output; if a5 is null, skip the blend.
