## sub_6AED1D_006aed1d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x4 | R | — | [LLM] |
| *(this+0x14) | 0x8 | R | — | [LLM] |
| *(this+0x14) | 0xC | R | — | [LLM] |
| *(this+0x14) | 0x10 | R | — | [LLM] |
| obj | 0x54 | R | — | [LLM] |
| obj | 0x58 | R | — | [LLM] |
| obj | 0x64 | R | — | [LLM] |
| obj | 0x70 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x1F0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00742820 | aNS | R | [LLM] |
| 00742830 | aVSD | R | [LLM] |
| 0200001f | byte_200001F | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00632041 | sub_632041 | [LLM] |
| 0066078b | sub_66078B | [LLM] |
| 006c64e6 | sub_6C64E6 | [LLM] |
| 006c9357 | sub_6C9357 | [LLM] |
| 006ca49d | sub_6CA49D | [LLM] |
| 006cb0ce | sub_6CB0CE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 0 | [LLM] |
| this | 0x158 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `n_%s`
- `v_%s%d`
