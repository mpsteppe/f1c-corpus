## sub_59AFE0_0059afe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x35C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16c8 | flt_6F16C8 | R | [LLM] |
| 006f1a30 | flt_6F1A30 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051bfa0 | sub_51BFA0 | [LLM] |
| 00599c10 | sub_599C10 | [LLM] |
| 00599d10 | sub_599D10 | [LLM] |
| 0059a1a0 | sub_59A1A0 | [LLM] |
| 00615460 | FPUControlWordMaskExtract [exact] | [LLM] |
| 006154a0 | sub_6154A0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | != | 2123789977 | [LLM] |
| this | 0x35C | == | 18446744073685857945 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
