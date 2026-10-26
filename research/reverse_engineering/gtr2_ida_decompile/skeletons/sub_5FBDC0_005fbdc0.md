## sub_5FBDC0_005fbdc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FBFF0 (005fbff0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb27ac | dword_FB27AC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | [LLM] |
| 00632c60 | sub_632C60 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
