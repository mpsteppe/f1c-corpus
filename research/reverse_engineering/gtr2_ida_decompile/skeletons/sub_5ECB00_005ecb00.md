## sub_5ECB00_005ecb00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5ED820 (005ed820)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C4)+0xC) | 0x0 | R | — | [LLM] |
| *(this+0x1C4) | 0x8 | R | — | [LLM] |
| *(this+0x1C4) | 0xC | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a8 | dword_FB27A8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7810 | sub_5D7810 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0x1C4)+0xC) | 0x0 | == | 32 | [LLM] |
| *(this+0x1C4) | 0x8 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
