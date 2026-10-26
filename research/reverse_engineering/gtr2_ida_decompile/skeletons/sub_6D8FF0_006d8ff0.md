## sub_6D8FF0_006d8ff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6D91B0 (006d91b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x100) | 0x8 | R | — | [LLM] |
| *(this+0x100) | 0xC | R | — | [LLM] |
| *(this+0x100) | 0x1C | R | — | [LLM] |
| *(this+0x100) | 0x20 | R | — | [LLM] |
| *(this+0x100) | 0x34 | RW | — | [LLM] |
| *(this+0x100) | 0x38 | RW | — | [LLM] |
| *(this+0x100) | 0x3C | RW | — | [LLM] |
| *(this+0x100) | 0x40 | RW | — | [LLM] |
| *(this+0x100) | 0x44 | RW | — | [LLM] |
| *(this+0x100) | 0x48 | RW | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 13 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| obj | 0x1C | RW | 4 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | RW | — | [LLM] |
| this | 0x114 | RW | — | [LLM] |
| this | 0x118 | RW | 0 | [LLM] |
| this | 0x11C | RW | 0 | [LLM] |
| this | 0x120 | R | — | [LLM] |
| this | 0x134 | RW | 1 | [LLM] |
| this | 0x138 | RW | 1 | [LLM] |
| this | 0x13C | RW | 1 | [LLM] |
| this | 0x140 | RW | 8 | [LLM] |
| this | 0x144 | RW | 1 | [LLM] |
| this | 0x148 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x100) 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x100) 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x100) 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x100) 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x100) 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x100) 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x110: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x114: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x118: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x134: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x138: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x13C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x140: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x144: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x148: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006b5fb0 | sub_6B5FB0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
