## RenderNodeListDestructor_00404ac0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x40)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x40) | 0x0 | R | — | [LLM] |
| *(obj+0x40) | 0x8 | R | — | [LLM] |
| obj | 0x28 | R | — | [LLM] |
| obj | 0x30 | R | — | [LLM] |
| obj | 0x38 | R | — | [LLM] |
| obj | 0x40 | RW | 0 | [LLM] |
| obj | 0x44 | RW | 0 | [LLM] |
| obj | 0x48 | RW | 0 | [LLM] |
| obj | 0x4C | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x40: [LLM: once/conditional? does external poke survive?]
- obj 0x44: [LLM: once/conditional? does external poke survive?]
- obj 0x48: [LLM: once/conditional? does external poke survive?]
- obj 0x4C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f70 | ConditionalFreeWithBit0Flag | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x40) | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
