## sub_4D4EB0_004d4eb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D8DD0 (004d8dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x1B0 | R | — | [LLM] |
| *(*(this+0x20)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x20)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x20)+0x4) | 0x8 | R | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x20) | 0x4 | RW | — | [LLM] |
| *(this+0x28) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x4 | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x20) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea6b0 | dbl_5EA6B0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cf510 | nullsub_6 | [LLM] |
| 004db610 | ShortComputation_ac20 [exact] | [LLM] |
| 0052e830 | sub_52E830 | [LLM] |
| 0052e850 | FloatComparisonCheck [exact] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
