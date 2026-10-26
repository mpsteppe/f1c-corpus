## ObjectConstructorWithAllocationAndSubInit_00553980 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_494690 (00494690), F_2DRectangleRender (0049ea10), FloatComputation_eb40 (0049eb40), sub_4D8CF0 (004d8cf0), sub_4DCBA0 (004dcba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005532a0 | ObjectAllocationWithZeroInit | [LLM] |
| 00553370 | sub_553370 | [LLM] |
| 00553620 | SetterWrites0x10Returns0 | [LLM] |
| 00553630 | TwoFieldSetter_3630 | [LLM] |
| 0055c2a0 | sub_55C2A0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
