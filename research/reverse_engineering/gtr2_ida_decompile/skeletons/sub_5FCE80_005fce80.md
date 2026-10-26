## sub_5FCE80_005fce80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FDB90 (005fdb90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x6C) | 0x4C | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fc620 | sub_5FC620 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |
| 00fb27a8 | dword_FB27A8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d73c0 | sub_5D73C0 | [LLM] |
| 005d7810 | sub_5D7810 | [LLM] |
| 005d7980 | F_3DSquaredDistance [exact] | [LLM] |
| 005d8400 | sub_5D8400 | [LLM] |
| 005e4d90 | sub_5E4D90 | [LLM] |
| 005e4da0 | sub_5E4DA0 | [LLM] |
| 005fc610 | sub_5FC610 | [LLM] |
| 005fca00 | sub_5FCA00 | [LLM] |
| 00600770 | sub_600770 | [LLM] |
| 00632c60 | sub_632C60 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x30 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
