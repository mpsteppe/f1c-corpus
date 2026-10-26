## _localtime_00633f96 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_553180 (00553180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00913380 | dword_913380 | R | [LLM] |
| 00913384 | dword_913384 | R | [LLM] |
| 00913388 | dword_913388 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0063e0e4 | ___tzset | [LLM] |
| 0063e130 | __isindst | [LLM] |
| 0063e16e | _gmtime | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | < | 0 | [LLM] |
| this | 0x0 | > | 259200 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
