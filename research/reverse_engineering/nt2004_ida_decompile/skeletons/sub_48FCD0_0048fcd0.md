## sub_48FCD0_0048fcd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fcc0c | aS_0 | R | [LLM] |
| 00600de8 | a3f | R | [LLM] |
| 0075cbbc | dword_75CBBC | R | [LLM] |
| 007689cc | dword_7689CC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049d690 | sub_49D690 | [LLM] |
| 0049ec60 | sub_49EC60 | [LLM] |
| 004af0a0 | sub_4AF0A0 | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x114 | == | 600 | [LLM] |
| this | 0x114 | == | 599 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%.3f`
