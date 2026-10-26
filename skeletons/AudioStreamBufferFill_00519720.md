## AudioStreamBufferFill_00519720 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x180 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x1B0 | RW | 0 | [LLM] |
| this | 0x1B4 | RW | 0 | [LLM] |
| this | 0x1C0 | RW | — | [LLM] |
| this | 0x1C4 | RW | 2 | [LLM] |
| this | 0x1C8 | RW | — | [LLM] |
| this | 0x1CC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1B0: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1C0: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]
- this 0x1C8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051954e | PerIndexBufferCopyWithInterleavedOffset | [LLM] |
| 00519622 | ArrayProcessingWithScaling | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1CC | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
