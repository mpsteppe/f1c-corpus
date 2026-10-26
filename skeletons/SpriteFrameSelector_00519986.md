## SpriteFrameSelector_00519986 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompositingPass (005199d5), CompositingCopy (00519bb2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x198 | RW | 0 | [LLM] |
| this | 0x19C | RW | 0 | [LLM] |
| this | 0x1A0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x198: [LLM: once/conditional? does external poke survive?]
- this 0x19C: [LLM: once/conditional? does external poke survive?]
- this 0x1A0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | <= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
