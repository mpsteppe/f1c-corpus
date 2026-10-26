## F_2DRectangleRender_0049ea10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49CD80 (0049cd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x54) | 0x1C | R | — | [LLM] |
| *(*(this+0x8)+0x54) | 0x20 | R | — | [LLM] |
| *(this+0x8) | 0x54 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ec40 | ShortComputation_ec40 | [LLM] |
| 00553650 | sub_553650 | [LLM] |
| 00553980 | ObjectConstructorWithAllocationAndSubInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
