## sub_6BFAB9_006bfab9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6A14B5 (006a14b5), sub_6AD36C (006ad36c), sub_6AE33E (006ae33e), sub_6B1163 (006b1163), sub_6B2D5D (006b2d5d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x100)+0x10) | 0x0 | R | — | [LLM] |
| *(this+0x100) | 0x0 | R | — | [LLM] |
| *(this+0x100) | 0x4 | R | — | [LLM] |
| *(this+0x100) | 0xC | R | — | [LLM] |
| *(this+0x100) | 0x10 | R | — | [LLM] |
| *(this+0x110) | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007448d4 | aInternalErrorM_0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | [LLM] |
| 00680cec | ZeroInit16ElementArray [structural] | [LLM] |
| 00681186 | sub_681186 | [LLM] |
| 006811d1 | sub_6811D1 | [LLM] |
| 00686791 | sub_686791 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x100) | 0xC | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `internal error: multiple write to same output`
