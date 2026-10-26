## SSEQuaternionCompositionFromAxisAngleComponents_00520e0e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d62a0 | xmmword_8D62A0 | R | SIMDAddConstant [DERIVED] |
| 008d62b0 | xmmword_8D62B0 | R | Xmmword_QuaternionMultiply [DERIVED] |
| 008d62c0 | dword_8D62C0 | R | SSE_ColorUnpack [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00528cc0 | sub_528CC0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
