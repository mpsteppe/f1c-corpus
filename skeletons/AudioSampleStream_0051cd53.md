## AudioSampleStream_0051cd53 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0xC | R | — | [LLM] |
| *(this+0x19C) | 0x20 | R | — | [LLM] |
| *(this+0x19C) | 0x24 | RW | 1 | [LLM] |
| *(this+0x19C) | 0x28 | R | — | [LLM] |
| *(this+0x19C) | 0x2C | RW | — | [LLM] |
| this | 0x19C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x19C) 0x24: [LLM: once/conditional? does external poke survive?]
- *(this+0x19C) 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051593f | F_2DArrayBlockCopy | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x19C) | 0x2C | < | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
