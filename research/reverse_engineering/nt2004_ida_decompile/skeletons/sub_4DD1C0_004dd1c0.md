## sub_4DD1C0_004dd1c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4FBC40 (004fbc40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0xD4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xD4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d5d18 | dbl_5D5D18 | R | [LLM] |
| 00628f80 | flt_628F80 | RW | [LLM] |
| 0079fc40 | dword_79FC40 | RW | [LLM] |
| 007d3c44 | dword_7D3C44 | RW | [LLM] |
| 007d78fc | dword_7D78FC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0d00 | sub_4D0D00 | [LLM] |
| 004dd160 | sub_4DD160 | [LLM] |
| 004dd350 | sub_4DD350 | [LLM] |
| 004dd490 | sub_4DD490 | [LLM] |
| 004fe730 | EncodedDataWriterWithXOR [structural] | [LLM] |
| 0051c290 | sub_51C290 | [LLM] |
| 0059ef10 | sub_59EF10 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | [LLM] |
| this | 0x10 | == | 1 | [LLM] |
| this | 0x74 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
