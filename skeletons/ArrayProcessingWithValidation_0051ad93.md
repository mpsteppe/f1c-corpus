## ArrayProcessingWithValidation_0051ad93 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x124) | 0x14 | R | — | [LLM] |
| *(this+0x124) | 0x18 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 49 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |
| this | 0x170 | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x19C | RW | 0 | [LLM] |
| this | 0x1A0 | RW | 0 | [LLM] |
| this | 0x1A4 | RW | 0 | [LLM] |
| this | 0x1A8 | RW | 0 | [LLM] |
| this | 0x1AC | RW | 0 | [LLM] |
| this | 0x1B4 | RW | 0 | [LLM] |
| this | 0x1C4 | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x19C: [LLM: once/conditional? does external poke survive?]
- this 0x1A0: [LLM: once/conditional? does external poke survive?]
- this 0x1A4: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1AC: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a5ea | sub_51A5EA | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x120 | > | 0 | [LLM] |
| this | 0x16C | != | 63 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
