## CompositingCopy_00519bb2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x4 | R | — | [LLM] |
| *(this+0x124) | 0xC | R | — | [LLM] |
| *(this+0x124) | 0x34 | R | — | [LLM] |
| *(this+0x124) | 0x38 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x80 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x198 | RW | 0 | [LLM] |
| this | 0x19C | RW | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x198: [LLM: once/conditional? does external poke survive?]
- this 0x19C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519986 | SpriteFrameSelector | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x124) | 0x38 | > | 0 | [LLM] |
| this | 0x120 | <= | 0 | [LLM] |
| this | 0x120 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
