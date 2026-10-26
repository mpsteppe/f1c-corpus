## TriangleClosestPointOrNormal_00520ce0 — [LLM: short descriptive name]

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
| 008d6270 | dword_8D6270 | R | SSE_Triangle_IndexLUT [DERIVED] |
| 008d627c | flt_8D627C | R | NormalizationThreshold2 [DERIVED] |
| 008d6280 | flt_8D6280 | R | SIMDCrossProductFloat [DERIVED] |
| 008d6284 | flt_8D6284 | R | CrossProductScale4 [DERIVED] |
| 008d6288 | flt_8D6288 | R | EigenDecompConst [DERIVED] |
| 008d6290 | flt_8D6290 | R | SVDScaleFactorB [DERIVED] |
| 008d6294 | flt_8D6294 | R | SvdNormalizeCoeff2 [DERIVED] |
| 008d6298 | flt_8D6298 | R | SIMD_EigenvalueConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
