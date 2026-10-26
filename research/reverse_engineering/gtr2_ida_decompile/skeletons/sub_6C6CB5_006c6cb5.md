## sub_6C6CB5_006c6cb5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B01E5 (006b01e5), sub_6B1675 (006b1675)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0x14) | 0x8 | R | — | [LLM] |
| *(this+0x14) | 0xC | R | — | [LLM] |
| *(this+0x14) | 0x10 | R | — | [LLM] |
| *(this+0x14) | 0x38 | R | — | [LLM] |
| *(this+0x14) | 0x58 | R | — | [LLM] |
| obj | 0x20 | R | — | [LLM] |
| obj | 0x9C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00747900 | aInternalErrorN | R | [LLM] |
| 00747940 | aInternalErrorR_0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00680d22 | sub_680D22 | [LLM] |
| 00681692 | sub_681692 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |
| 00681b0a | sub_681B0A | [LLM] |
| 00681c03 | sub_681C03 | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006bc1a9 | sub_6BC1A9 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x14) | 0x38 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `internal error: non-vectorized pool violated port constraints`
- `internal error: result violated port constraints`
