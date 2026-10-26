## sub_6AF40D_006af40d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B01E5 (006b01e5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x100)+0x10)+0x0) | 0x3E | R | — | [LLM] |
| *(*(this+0x100)+0x10) | 0x0 | R | — | [LLM] |
| *(*(this+0x100)+0x8) | 0x0 | R | — | [LLM] |
| *(*(this+0x14)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x14)+0x0) | 0xC | R | — | [LLM] |
| *(this+0x100) | 0x0 | RW | 0 | [LLM] |
| *(this+0x100) | 0x4 | R | — | [LLM] |
| *(this+0x100) | 0x8 | R | — | [LLM] |
| *(this+0x100) | 0xC | R | — | [LLM] |
| *(this+0x100) | 0x10 | R | — | [LLM] |
| *(this+0x100) | 0x3C | R | — | [LLM] |
| *(this+0x14) | 0x0 | R | — | [LLM] |
| obj | 0x54 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x100) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00744740 | aInternalErrorW | R | [LLM] |
| 0091a658 | unk_91A658 | R | [LLM] |
| 0091a698 | unk_91A698 | R | [LLM] |
| 016c9914 | off_16C9914 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | [LLM] |
| 00680cec | ZeroInit16ElementArray [structural] | [LLM] |
| 00680d22 | sub_680D22 | [LLM] |
| 00681186 | sub_681186 | [LLM] |
| 006811d1 | sub_6811D1 | [LLM] |
| 00681997 | sub_681997 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |
| 00681c03 | sub_681C03 | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006a323b | sub_6A323B | [LLM] |
| 006af0f0 | sub_6AF0F0 | [LLM] |
| 006af146 | sub_6AF146 | [LLM] |
| 006af2ee | sub_6AF2EE | [LLM] |
| 006c5456 | sub_6C5456 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `internal error: write to output with instruction other than mov`
