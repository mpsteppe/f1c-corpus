## sub_4AFB80_004afb80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AC690 (004ac690), sub_4AD520 (004ad520), StringCopyWithFormatQuery [structural] (004afb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xC)+0x4)+0x0) | 0x40 | R | — | [LLM] |
| *(*(this+0x10)+0x3C) | 0x34 | R | — | [LLM] |
| *(*(this+0xC)+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x10) | 0x3C | R | — | [LLM] |
| *(this+0x10) | 0x40 | R | — | [LLM] |
| *(this+0x14) | 0x34 | R | — | [LLM] |
| *(this+0x8) | 0x8C | R | — | [LLM] |
| *(this+0xC) | 0x4 | R | — | [LLM] |
| *(this+0xC) | 0xC | RW | — | [LLM] |
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x4 | RW | 1 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0xC) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004afae0 | LinkedListIteratorAdvance [structural] | [LLM] |
| 004afb30 | sub_4AFB30 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0x4 | == | 0 | [LLM] |
| this | 0x0 | == | 1 | [LLM] |
| this | 0x0 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
