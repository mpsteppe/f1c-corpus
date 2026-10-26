## sub_6D8BD0_006d8bd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6D93E0 (006d93e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 45 | [LLM] |
| obj | 0x18 | RW | 0 | [LLM] |
| obj | 0x1C | RW | 4 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xC0 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xEC | RW | 1 | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xEC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00ffffff | byte_FFFFFF | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xA8 | <= | 0 | [LLM] |
| this | 0xC0 | == | 0 | [LLM] |
| this | 0xC4 | == | 63 | [LLM] |
| this | 0xEC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
