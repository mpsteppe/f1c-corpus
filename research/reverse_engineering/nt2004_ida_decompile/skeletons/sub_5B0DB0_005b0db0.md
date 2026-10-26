## sub_5B0DB0_005b0db0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4F4D30 (004f4d30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x20 | RW | — | [LLM] |
| *(this+0x50) | 0x24 | RW | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x50) 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005b0c50 | TextureAllocationWithFormatSizeFlags [structural] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
