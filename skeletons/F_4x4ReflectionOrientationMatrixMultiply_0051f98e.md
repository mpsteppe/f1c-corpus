## F_4x4ReflectionOrientationMatrixMultiply_0051f98e — [LLM: short descriptive name]

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
| 005d8b00 | xmmword_5D8B00 | R | SIMD_XorMask [DERIVED] |
| 005d8b10 | xmmword_5D8B10 | R | SSEConstXMM [DERIVED] |
| 005d8b20 | xmmword_5D8B20 | R | XMMMask_5D8B20 [DERIVED] |
| 005d8b30 | xmmword_5D8B30 | R | SSE_NormalizeMask [DERIVED] |
| 005d8b40 | xmmword_5D8B40 | R | Xmm_SSE_AndMask [DERIVED] |
| 008d4690 | xmmword_8D4690 | RW | SSE_NRConstant [DERIVED] |
| 008d46a0 | xmmword_8D46A0 | RW | VectorNormalizeConst [DERIVED] |
| 008d46b0 | byte_8D46B0 | RW | SSEMathInitFlags [DERIVED] |
| 008d60c0 | dword_8D60C0 | R | NewtonRaphsonConstant [DERIVED] |
| 008d60c4 | dword_8D60C4 | R | SIMD_RSqrtConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
