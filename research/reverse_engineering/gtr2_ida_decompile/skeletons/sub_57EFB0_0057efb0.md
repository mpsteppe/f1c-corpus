## sub_57EFB0_0057efb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_428C90 (00428c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FB0 | RW | — | [LLM] |
| this | 0x40AC | RW | — | [LLM] |
| this | 0x41A8 | RW | — | [LLM] |
| this | 0x42A4 | RW | — | [LLM] |
| this | 0x4328 | RW | — | [LLM] |
| this | 0x434C | R | — | [LLM] |
| this | 0x4358 | R | — | [LLM] |
| this | 0x43A0 | R | — | [LLM] |
| this | 0x467C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x3FB0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40AC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x41A8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x42A4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4328: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x467C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | [LLM] |
| 006f2358 | dbl_6F2358 | R | [LLM] |
| 00721ed8 | dbl_721ED8 | R | [LLM] |
| 00721ee0 | dbl_721EE0 | R | [LLM] |
| 00b71ffc | byte_B71FFC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00579710 | sub_579710 | [LLM] |
| 00633410 | BitfieldManager [structural] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x43A0 | >= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
