## DualLinkedListDestruction_004fd840 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0), sub_4FCC30 (004fcc30), sub_4FD8B0 (004fd8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x54)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x3C) | 0xC | R | — | [LLM] |
| *(this+0x54) | 0x0 | R | — | [LLM] |
| *(this+0x54) | 0x8 | R | — | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |
| this | 0x58 | RW | 0 | [LLM] |
| this | 0x5C | RW | 0 | [LLM] |
| this | 0x60 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]
- this 0x58: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x54) | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
