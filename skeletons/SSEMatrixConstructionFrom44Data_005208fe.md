## SSEMatrixConstructionFrom44Data_005208fe — [LLM: short descriptive name]

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
| 008d61e0 | xmmword_8D61E0 | R | XMMConst_8D61E0 [DERIVED] |
| 008d61f0 | xmmword_8D61F0 | R | SIMD_MatrixInitConst [DERIVED] |
| 008d6200 | xmmword_8D6200 | R | SSEConstXMM2 [DERIVED] |
| 008d6210 | xmmword_8D6210 | R | SIMD_XMMConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528bd0 | EmptyStub_8bd0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
