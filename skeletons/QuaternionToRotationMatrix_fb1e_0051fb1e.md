## QuaternionToRotationMatrix_fb1e_0051fb1e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8b50 | xmmword_5D8B50 | R | SSE_QuatConst_Add [DERIVED] |
| 005d8b60 | xmmword_5D8B60 | R | Xmmword_NormalizeCoeffC [DERIVED] |
| 005d8b70 | xmmword_5D8B70 | R | SIMDMatrixRowConst [DERIVED] |
| 005d8b80 | xmmword_5D8B80 | R | SSEConstantBias [DERIVED] |
| 005d8b90 | xmmword_5D8B90 | R | QuaternionTransformCoeff [DERIVED] |
| 005d8ba0 | dword_5D8BA0 | R | QuatMatrixCoeff [DERIVED] |
| 005d8bb0 | dword_5D8BB0 | R | SIMDQuaternionConst [DERIVED] |
| 005d8bc0 | xmmword_5D8BC0 | R | SSE_Bitmask_5D8BC0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
