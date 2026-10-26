## sub_4CDB30_004cdb30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D02E0 (004d02e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x24 | R | — | [LLM] |
| obj | 0xA4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd740 | sub_4CD740 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x84 | == | 1 | [LLM] |
| this | 0x84 | == | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
