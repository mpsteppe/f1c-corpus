## QuaternionToRotationMatrix_0a7e_00520a7e — [LLM: short descriptive name]

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
| 005d8c60 | xmmword_5D8C60 | R | Xmmword_SignNegation [DERIVED] |
| 005d8c70 | xmmword_5D8C70 | R | SSE_QuatConst_Xor [DERIVED] |
| 005d8c80 | xmmword_5D8C80 | R | SIMDMatrixXorMask [DERIVED] |
| 005d8c90 | xmmword_5D8C90 | R | SSEMask_XMM_5D8C90 [DERIVED] |
| 005d8ca0 | xmmword_5D8CA0 | R | SIMDVectorAndMask [DERIVED] |
| 008d4690 | xmmword_8D4690 | RW | SSE_NRConstant [DERIVED] |
| 008d46a0 | xmmword_8D46A0 | RW | VectorNormalizeConst [DERIVED] |
| 008d46b0 | byte_8D46B0 | RW | SSEMathInitFlags [DERIVED] |
| 008d6220 | dword_8D6220 | R | SIMDRSQConstants [DERIVED] |
| 008d6224 | dword_8D6224 | R | SSENRConstant2 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
