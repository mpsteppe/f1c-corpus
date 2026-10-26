## __setlocale_lk_006328b2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _setlocale (00632a8b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x1 | R | — | [LLM] |
| this | 0x2 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00721098 | Source | R | [LLM] |
| 0073047c | asc_73047C | R | [LLM] |
| 00912a4c | dword_912A4C | RW | [LLM] |
| 00912a54 | off_912A54 | R | [LLM] |
| 00912a84 | off_912A84 | R | [LLM] |
| 00912a88 | off_912A88 | R | [LLM] |
| 00912b08 | dword_912B08 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630fe0 | sub_630FE0 | [LLM] |
| 00631d10 | _strncmp | [LLM] |
| 00632408 | __setlocale_get_all | [LLM] |
| 006324c7 | __expandlocale | [LLM] |
| 00632623 | sub_632623 | [LLM] |
| 00634919 | _free | [LLM] |
| 006349bb | sub_6349BB | [LLM] |
| 006354d0 | sub_6354D0 | [LLM] |
| 00636cf0 | _strcmp | [LLM] |
| 0063a5a0 | _strcspn | [LLM] |
| 0063b160 | InPlaceStringShift [structural] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 76 | [LLM] |
| this | 0x1 | == | 67 | [LLM] |
| this | 0x2 | == | 95 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
