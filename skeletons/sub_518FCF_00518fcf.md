## sub_518FCF_00518fcf — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5119E9 (005119e9)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | [LLM] |
| this | 0x10C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aff58 | aUnknownCritica | R | UnknownCriticaString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051189c | DoubleBufferInit | [LLM] |
| 00517fd0 | sub_517FD0 | [LLM] |
| 00518828 | sub_518828 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
