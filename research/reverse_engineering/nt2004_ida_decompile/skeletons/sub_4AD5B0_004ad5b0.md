## sub_4AD5B0_004ad5b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4A8640 (004a8640), sub_4AD720 (004ad720), sub_4AD760 (004ad760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x4 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x22C | RW | — | [LLM] |
| this | 0x230 | R | — | [LLM] |
| this | 0x24C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x22C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 007d4458 | byte_7D4458 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ac2d0 | sub_4AC2D0 | [LLM] |
| 004ad870 | FieldGetter_79d0 [exact] | [LLM] |
| 004ad880 | SimpleSetter_79e0 [exact] | [LLM] |
| 004aef80 | sub_4AEF80 | [LLM] |
| 004aef90 | ShortComputation_8f70 [exact] | [LLM] |
| 004af090 | sub_4AF090 | [LLM] |
| 004af0b0 | sub_4AF0B0 | [LLM] |
| 004af110 | sub_4AF110 | [LLM] |
| 004af120 | sub_4AF120 | [LLM] |
| 004af130 | sub_4AF130 | [LLM] |
| 004d20d0 | sub_4D20D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
