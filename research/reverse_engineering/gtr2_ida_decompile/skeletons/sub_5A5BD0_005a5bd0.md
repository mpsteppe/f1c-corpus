## sub_5A5BD0_005a5bd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5A01D0 (005a01d0), sub_5A03A0 (005a03a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x58C)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x58C)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x58C)+0x4) | 0x8 | R | — | [LLM] |
| *(this+0x570) | 0x0 | R | — | [LLM] |
| *(this+0x570) | 0x8 | RW | 0 | [LLM] |
| *(this+0x58C) | 0x0 | R | — | [LLM] |
| *(this+0x58C) | 0x4 | RW | — | [LLM] |
| obj | 0x5C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x570 | R | — | [LLM] |
| this | 0x580 | R | — | [LLM] |
| this | 0x584 | R | — | [LLM] |
| this | 0x58C | RW | — | [LLM] |
| this | 0x590 | RW | — | [LLM] |
| this | 0x594 | RW | — | [LLM] |
| this | 0x598 | R | — | [LLM] |
| this | 0x59C | R | — | [LLM] |
| this | 0x5A0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x570) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x58C) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x590: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x594: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1184 | ReleaseMutex | R | [LLM] |
| 006f1188 | WaitForSingleObject | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059f9f0 | sub_59F9F0 | [LLM] |
| 005a6920 | sub_5A6920 | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x598 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
