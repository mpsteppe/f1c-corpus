## sub_5EDC50_005edc50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5EDDD0 (005eddd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x20) | 0xC | RW | — | [LLM] |
| *(this+0x20) | 0x4C | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x2C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x20) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x18 | <= | 0 | [LLM] |
| this | 0x18 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
