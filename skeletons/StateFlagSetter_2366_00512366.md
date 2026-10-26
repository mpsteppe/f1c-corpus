## StateFlagSetter_2366_00512366 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50210E (0050210e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | [LLM] |
| this | 0x61 | RW | — | [LLM] |
| this | 0x116 | R | — | [LLM] |
| this | 0x117 | R | — | [LLM] |
| this | 0x11B | RW | 2 | [LLM] |
| this | 0x11E | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x61: [LLM: once/conditional? does external poke survive?]
- this 0x11B: [LLM: once/conditional? does external poke survive?]
- this 0x11E: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x117 | >= | 8 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
