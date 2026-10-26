## sub_46CEE0_0046cee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_460CD0 (00460cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x6C)+0x4) | 0x4 | R | — | [LLM] |
| *(*(obj+0x7C)+0x4) | 0x4 | R | — | [LLM] |
| *(obj+0x6C) | 0x0 | R | — | [LLM] |
| *(obj+0x6C) | 0x8 | R | — | [LLM] |
| *(obj+0x7C) | 0x0 | R | — | [LLM] |
| *(obj+0x7C) | 0x8 | R | — | [LLM] |
| obj | 0x60 | RW | — | [LLM] |
| obj | 0x6C | RW | 0 | [LLM] |
| obj | 0x70 | RW | 0 | [LLM] |
| obj | 0x74 | RW | 0 | [LLM] |
| obj | 0x78 | RW | 0 | [LLM] |
| obj | 0x7C | RW | 0 | [LLM] |
| obj | 0x80 | RW | 0 | [LLM] |
| obj | 0x84 | RW | 0 | [LLM] |
| obj | 0x88 | RW | 0 | [LLM] |
| obj | 0x36E8 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x7C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x80: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x84: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x88: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0x36E8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d56ac | flt_5D56AC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0046cc10 | sub_46CC10 | [LLM] |
| 0057b720 | HighResolutionTimerDelta [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(obj+0x6C) | 0x8 | == | 0 | [LLM] |
| *(obj+0x7C) | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
