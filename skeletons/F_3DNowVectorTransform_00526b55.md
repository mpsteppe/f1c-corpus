## F_3DNowVectorTransform_00526b55 — [LLM: short descriptive name]

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
| 00526c88 | jpt_526B8B | R | [LLM] |
| 005af980 | qword_5AF980 | R | SIMD_Const_5AF980 [DERIVED] |
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af998 | qword_5AF998 | R | MMMX_PolyCoeffAF998 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00522b22 | sub_522B22 | [LLM] |
| 005257c0 | F_4x4MatrixInversion | [LLM] |
| 00526550 | F_4DVectorTransform | [LLM] |
| 005265db | F_8SIMDMatrixPackedFloatOperation | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
