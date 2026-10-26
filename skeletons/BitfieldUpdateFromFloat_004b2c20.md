## BitfieldUpdateFromFloat_004b2c20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VectorToShort3Conversion (004b2c80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xF: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acce0 | flt_5ACCE0 | R | Unknown_Float_Skidding [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
