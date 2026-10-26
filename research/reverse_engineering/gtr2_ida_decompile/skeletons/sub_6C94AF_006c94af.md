## sub_6C94AF_006c94af — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B3A58 (006b3a58), sub_6CA50D (006ca50d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x14)+0x60)+0x14) | 0x18 | R | — | [LLM] |
| *(*(this+0x14)+0x0) | 0x4 | R | — | [LLM] |
| *(*(this+0x14)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x14)+0x60) | 0x14 | R | — | [LLM] |
| *(this+0x14) | 0x0 | R | — | [LLM] |
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0x14) | 0x60 | R | — | [LLM] |
| obj | 0x8C | R | — | [LLM] |
| obj | 0x90 | R | — | [LLM] |
| obj | 0x94 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | RW | — | [LLM] |
| this | 0x11C | RW | — | [LLM] |
| this | 0x120 | RW | — | [LLM] |
| this | 0x158 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x110: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x120: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b0 | dbl_6F16B0 | R | [LLM] |
| 006f1f44 | flt_6F1F44 | R | [LLM] |
| 00747a04 | aConstantTableI | R | [LLM] |
| 00747a38 | aMicrosoftRD3dx_0 | R | [LLM] |
| 00747a6c | aSS_8 | R | [LLM] |
| 00747a74 | aIS | R | [LLM] |
| 00747a7c | aBS | R | [LLM] |
| 00747a84 | aCS | R | [LLM] |
| 00e00000 | unk_E00000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00631200 | _memcpy | [LLM] |
| 00632041 | sub_632041 | [LLM] |
| 00634c30 | __ftol | [LLM] |
| 00646152 | sub_646152 | [LLM] |
| 006801f7 | FloatArrayInitializer [structural] | [LLM] |
| 00680214 | sub_680214 | [LLM] |
| 0068024c | sub_68024C | [LLM] |
| 00680385 | sub_680385 | [LLM] |
| 00680391 | sub_680391 | [LLM] |
| 00686791 | sub_686791 | [LLM] |
| 006c5628 | sub_6C5628 | [LLM] |
| 006c5921 | sub_6C5921 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 0 | [LLM] |
| this | 0x158 | != | 0 | [LLM] |
| this | 0x158 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `constant table info exceeds maximum comment size`
- `Microsoft (R) D3DX9 Shader Compiler 5.04.00.2904`
- `s_%s`
- `i_%s`
- `b_%s`
- `c_%s`
