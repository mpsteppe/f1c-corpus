## RenderStateCopyWithValidation_00519eb7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProtocolStateHandler (0051a4b7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC4)+0x4C) | 0x0 | R | — | [LLM] |
| *(*(this+0xC4)+0x4C) | 0x2 | R | — | [LLM] |
| *(*(this+0xC4)+0x4C) | 0x4 | R | — | [LLM] |
| *(*(this+0xC4)+0x4C) | 0x10 | R | — | [LLM] |
| *(*(this+0xC4)+0x4C) | 0x12 | R | — | [LLM] |
| *(*(this+0xC4)+0x4C) | 0x20 | R | — | [LLM] |
| *(this+0x184) | 0x70 | RW | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xC4) | 0x4C | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x184) 0x70: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
