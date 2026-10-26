## RotationMatrixToAxisAngleConversion_0051fd90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d6110 | dword_8D6110 | R | MemAllocIndexTable [DERIVED] |
| 008d611c | flt_8D611C | R | SqrtApproxConstants [DERIVED] |
| 008d6120 | flt_8D6120 | R | SSE_Vec3_Normalize [DERIVED] |
| 008d6124 | flt_8D6124 | R | SvdNormalizeCoeff [DERIVED] |
| 008d6128 | flt_8D6128 | R | SIMD_EigenvectorConst [DERIVED] |
| 008d6130 | flt_8D6130 | R | SIMD_VecMathConst [DERIVED] |
| 008d6134 | flt_8D6134 | R | SVDScaleFactor [DERIVED] |
| 008d6138 | flt_8D6138 | R | NormalizationReciprocal [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
