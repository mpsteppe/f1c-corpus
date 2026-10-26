## D3DAnimationTimeUpdate_00550310 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x134) | 0x15C | R | — | [LLM] |
| *(this+0x134) | 0x164 | R | — | [LLM] |
| *(this+0x134) | 0x168 | R | — | [LLM] |
| *(this+0x134) | 0x180 | R | — | [LLM] |
| *(this+0x134) | 0x1A8 | RW | — | [LLM] |
| *(this+0x134) | 0x1B0 | R | — | [LLM] |
| *(this+0x134) | 0x1C0 | R | — | [LLM] |
| *(this+0x134) | 0x1C4 | RW | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x134) 0x1A8: [LLM: once/conditional? does external poke survive?]
- *(this+0x134) 0x1C4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x134) | 0x164 | > | 0 | [LLM] |
| *(this+0x134) | 0x1B0 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
