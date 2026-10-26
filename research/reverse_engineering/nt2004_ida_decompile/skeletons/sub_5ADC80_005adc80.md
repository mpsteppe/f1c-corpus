## sub_5ADC80_005adc80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BC910 (004bc910), sub_5061D0 (005061d0), sub_5B2B20 (005b2b20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x14C)+0x30)+0x30) | 0x30 | R | — | [LLM] |
| *(*(this+0x14C)+0x30) | 0x30 | RW | — | [LLM] |
| this | 0x11C | RW | — | [LLM] |
| this | 0x14C | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x14C)+0x30) 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005acc00 | StructZeroInitWithUnitVector [structural] | [LLM] |
| 005acc30 | sub_5ACC30 | [LLM] |
| 005acea0 | CallWrapperReturning0 [exact] | [LLM] |
| 005b5940 | j_nullsub_6 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
