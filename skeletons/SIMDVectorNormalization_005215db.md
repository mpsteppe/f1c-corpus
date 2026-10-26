## SIMDVectorNormalization_005215db — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MMX3DNowVectorTransform (00521712), F_3DVectorBlend (0052179f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af988 | qword_5AF988 | R | PackedMathOne [DERIVED] |
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |
| 005af9e8 | qword_5AF9E8 | R | Unknown_QWord_Compare [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528f00 | F_3DVectorNormalize_8f00 | [LLM] |
| 00529700 | sub_529700 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
