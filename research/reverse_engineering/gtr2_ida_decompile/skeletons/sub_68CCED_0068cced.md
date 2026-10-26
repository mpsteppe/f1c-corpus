## sub_68CCED_0068cced — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6925FA (006925fa), sub_692CC1 (00692cc1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0x14) | 0x8 | R | — | [LLM] |
| *(this+0x14) | 0x20 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16a0 | dbl_6F16A0 | R | [LLM] |
| 006f16a8 | dbl_6F16A8 | R | [LLM] |
| 006f16b0 | dbl_6F16B0 | R | [LLM] |
| 0073d2a0 | aInternalErrorC_1 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00680d22 | sub_680D22 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |
| 00681b0a | sub_681B0A | [LLM] |
| 00685446 | sub_685446 | [LLM] |
| 006854b0 | sub_6854B0 | [LLM] |
| 00685503 | sub_685503 | [LLM] |
| 00686791 | sub_686791 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x14) | 0x8 | == | 18446744073709551615 | [LLM] |
| this | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `internal error: component out of range`
- `internal error: component out of range`
