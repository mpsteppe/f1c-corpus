## _strtoxl_00632ff2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _strtol (006331b1), _strtoul (006331c8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x1 | R | — | [LLM] |
| this | 0x2 | R | — | [LLM] |
| this | 0x3 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091290c | off_91290C | R | [LLM] |
| 00913150 | off_913150 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006323cd | ___updatetlocinfo | [LLM] |
| 006351e0 | __errno | [LLM] |
| 00636698 | __getptd | [LLM] |
| 006380d3 | ___isctype_mt | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1 | != | 120 | [LLM] |
| this | 0x1 | != | 88 | [LLM] |
| this | 0x3 | == | 120 | [LLM] |
| this | 0x3 | == | 88 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
