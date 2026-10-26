## Quaternion3DMath_005219e1 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af918 | qword_5AF918 | R | MMX_PackedConstant [DERIVED] |
| 005af928 | qword_5AF928 | R | CollisionSATWorkspace [DERIVED] |
| 005af938 | qword_5AF938 | R | MMX_3DNow_QuadConstant_1 [DERIVED] |
| 005af940 | qword_5AF940 | R | ThreeDNow_AndMask_Packed [DERIVED] |
| 005af948 | qword_5AF948 | R | SIMDCompareThreshold [DERIVED] |
| 005af950 | qword_5AF950 | R | SIMDQuadMask [DERIVED] |
| 005af970 | qword_5AF970 | R | VectorLengthSquaredThreshold [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |
| 005b06e0 | qword_5B06E0 | R | AABBTreeSplitData [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00529000 | SquareRootApproximation | [LLM] |
| 005295e0 | PackedFloatingPointMath | [LLM] |
| 00529700 | sub_529700 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
