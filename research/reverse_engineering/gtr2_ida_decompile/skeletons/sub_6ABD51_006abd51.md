## sub_6ABD51_006abd51 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x100) | 0x3C | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007443e4 | aCannotMapSwizz | R | [LLM] |
| 0091a410 | unk_91A410 | R | [LLM] |
| 0091a430 | unk_91A430 | R | [LLM] |
| 0091a440 | unk_91A440 | R | [LLM] |
| 0091a450 | unk_91A450 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |
| 006a323b | sub_6A323B | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC8 | == | 260 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `cannot map swizzle to ps_1_4`
