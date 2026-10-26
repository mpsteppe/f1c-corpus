## sub_57BDB0_0057bdb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_51B2F0 (0051b2f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x57C4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10F0 | R | — | [LLM] |
| this | 0x1130 | R | — | [LLM] |
| this | 0x1134 | R | — | [LLM] |
| this | 0x1174 | R | — | [LLM] |
| this | 0x4418 | RW | — | [LLM] |
| this | 0x4424 | R | — | [LLM] |
| this | 0x4428 | R | — | [LLM] |
| this | 0x47EC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4418: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x47EC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091e084 | dword_91E084 | R | [LLM] |
| 00b66040 | dbl_B66040 | R | [LLM] |
| 00b6cba8 | dword_B6CBA8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004735e0 | sub_4735E0 | [LLM] |
| 00473630 | sub_473630 | [LLM] |
| 004fb7e0 | sub_4FB7E0 | [LLM] |
| 0056df50 | sub_56DF50 | [LLM] |
| 00579710 | sub_579710 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x47EC | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
