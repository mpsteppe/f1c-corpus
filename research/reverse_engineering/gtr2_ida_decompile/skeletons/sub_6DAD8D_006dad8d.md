## sub_6DAD8D_006dad8d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B9A1A (006b9a1a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 9 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | 7 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006db4b1 | jpt_6DAE08 | R | [LLM] |
| 0072fd8c | aInvalidBitLeng | R | [LLM] |
| 0072fda8 | aTooManyLengthO | R | [LLM] |
| 0072fdcc | aInvalidStoredB | R | [LLM] |
| 0072fdec | aInvalidBlockTy | R | [LLM] |
| 00748a00 | dword_748A00 | R | [LLM] |
| 0091bbc0 | dword_91BBC0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006ded6b | sub_6DED6B | [LLM] |
| 006ded9e | sub_6DED9E | [LLM] |
| 006df2f5 | sub_6DF2F5 | [LLM] |
| 006df685 | PathStringModifier [structural] | [LLM] |
| 006df6fe | sub_6DF6FE | [LLM] |
| 006df7f8 | ArithmeticComparison_a5a8 [structural] | [LLM] |
| 006df829 | sub_6DF829 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 9 | [LLM] |
| this | 0x4 | == | 0 | [LLM] |
| this | 0x8 | < | 19 | [LLM] |
| this | 0x18 | != | 0 | [LLM] |
| this | 0x18 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `invalid bit length repeat`
- `too many length or distance symbols`
- `invalid stored block lengths`
- `invalid block type`
