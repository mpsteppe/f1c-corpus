## F_3DNowQuaternionFromAngle_0052278b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00527578 | F_3DVectorNormalize_7578 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
