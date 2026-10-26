## SSEReciprocalSquareRootWithNewtonRaphsonQuaterni_00520c0e — [LLM: short descriptive name]

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
| 005d8cb0 | xmmword_5D8CB0 | R | XMMWORD_5D8CB0 [DERIVED] |
| 005d8cc0 | xmmword_5D8CC0 | R | SIMD_FilterConst [DERIVED] |
| 005d8cd0 | xmmword_5D8CD0 | R | SSEConstEps [DERIVED] |
| 005d8ce0 | xmmword_5D8CE0 | R | Xmm_SSE_MatrixConst1 [DERIVED] |
| 005d8cf0 | xmmword_5D8CF0 | R | SIMDMatrixRowMul [DERIVED] |
| 005d8d00 | dword_5D8D00 | R | SIMDCRCPolyEvalCoeff [DERIVED] |
| 005d8d10 | dword_5D8D10 | R | SIMDInvSqrtConst2 [DERIVED] |
| 005d8d20 | xmmword_5D8D20 | R | SIMDAndMask5D8D20 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
