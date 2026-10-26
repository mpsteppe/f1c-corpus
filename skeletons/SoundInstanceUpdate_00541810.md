## SoundInstanceUpdate_00541810 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5550E0 (005550e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0xB8 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1100 | R | — | [LLM] |
| this | 0x13D8 | R | — | [LLM] |
| this | 0x155C | RW | — | [LLM] |
| this | 0x1560 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x155C: [LLM: once/conditional? does external poke survive?]
- this 0x1560: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x155C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
