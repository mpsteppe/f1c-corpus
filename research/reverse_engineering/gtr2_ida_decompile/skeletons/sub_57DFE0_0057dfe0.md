## sub_57DFE0_0057dfe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_57E220 (0057e220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4000)+0x54) | 0x30 | R | — | [LLM] |
| *(this+0x4000) | 0x54 | R | — | [LLM] |
| this | 0x3F64 | R | — | [LLM] |
| this | 0x4000 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | [LLM] |
| 006f16c8 | flt_6F16C8 | R | [LLM] |
| 006f1a30 | flt_6F1A30 | R | [LLM] |
| 006f3530 | flt_6F3530 | R | [LLM] |
| 006f3910 | flt_6F3910 | R | [LLM] |
| 00714b8c | flt_714B8C | R | [LLM] |
| 00721ec0 | flt_721EC0 | R | [LLM] |
| 00721ec4 | flt_721EC4 | R | [LLM] |
| 00721ec8 | flt_721EC8 | R | [LLM] |
| 00721ecc | flt_721ECC | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00b70c84 | dword_B70C84 | R | [LLM] |
| 00b70ca8 | dword_B70CA8 | R | [LLM] |
| 00b70ccc | dword_B70CCC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004012d0 | Vector3ScalarMultiply [exact] | [LLM] |
| 0058c6c0 | sub_58C6C0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0x4000)+0x54) | 0x30 | == | 35 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
