## sub_49CCA0_0049cca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_49D450 (0049d450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x4 | R | — | [LLM] |
| *(this+0x54) | 0x14 | R | — | [LLM] |
| *(this+0x58) | 0x4 | R | — | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |
| this | 0x58 | RW | 0 | [LLM] |
| this | 0x5C | RW | 0 | [LLM] |
| this | 0x60 | RW | 0 | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049cd60 | sub_49CD60 | [LLM] |
| 004afee0 | sub_4AFEE0 | [LLM] |
| 004b1160 | sub_4B1160 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x100 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
