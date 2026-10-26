## sub_4D3AB0_004d3ab0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D7380 (004d7380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x0) | 0x4 | R | — | [LLM] |
| *(this+0x40) | 0x0 | R | — | [LLM] |
| *(this+0x40) | 0x4 | RW | — | [LLM] |
| *(this+0x40) | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x40) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea68c | flt_5EA68C | R | [LLM] |
| 007d5dc0 | dword_7D5DC0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466750 | sub_466750 | [LLM] |
| 004a82f0 | ConditionalFreeByFlagCheck [structural] | [LLM] |
| 004d3230 | sub_4D3230 | [LLM] |
| 004d33d0 | sub_4D33D0 | [LLM] |
| 004dad90 | sub_4DAD90 | [LLM] |
| 004db110 | sub_4DB110 | [LLM] |
| 004db380 | sub_4DB380 | [LLM] |
| 004db610 | ShortComputation_ac20 [exact] | [LLM] |
| 004dbcf0 | sub_4DBCF0 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40 | == | 0 | [LLM] |
| this | 0x4C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
