## ListSearchWithGlobalMatch_004c81a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x14)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x14)+0x0) | 0x18 | RW | 0 | [LLM] |
| *(this+0x14) | 0x0 | R | — | [LLM] |
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x14)+0x0) 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008acfcc | dword_8ACFCC | R | ComparisonValue (sentinel) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
