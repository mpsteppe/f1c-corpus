## sub_6ACF7B_006acf7b — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD2DE (006ad2de)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x104 | RW | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x104: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007428a0 | aCannotMapExpre | R | [LLM] |
| 0074451c | aRelativeAddres_4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |
| 006aa95c | sub_6AA95C | [LLM] |
| 006aaaa9 | sub_6AAAA9 | [LLM] |
| 006aabee | sub_6AABEE | [LLM] |
| 006aacc9 | sub_6AACC9 | [LLM] |
| 006aad9b | sub_6AAD9B | [LLM] |
| 006aaeec | sub_6AAEEC | [LLM] |
| 006cbc69 | sub_6CBC69 | [LLM] |
| 006cc45d | sub_6CC45D | [LLM] |
| 006cc5dc | sub_6CC5DC | [LLM] |
| 006cc79d | sub_6CC79D | [LLM] |
| 006cce53 | sub_6CCE53 | [LLM] |
| 006cd04a | sub_6CD04A | [LLM] |
| 006cd054 | sub_6CD054 | [LLM] |
| 006cd068 | sub_6CD068 | [LLM] |
| 006cd125 | sub_6CD125 | [LLM] |
| 006cd12f | sub_6CD12F | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC8 | != | 257 | [LLM] |
| this | 0xC8 | == | 260 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `cannot map expression to pixel shader instruction set`
- `relative addressing not allowed for pixel shaders`
