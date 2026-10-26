## sub_4DCA90_004dca90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D0D50 (004d0d50), sub_4DCC00 (004dcc00), sub_4E17F0 (004e17f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1298 | R | — | [LLM] |
| obj | 0x12A1 | RW | 1 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x38 | RW | 0 | [LLM] |
| this | 0x3C | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x12A1: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d550c | flt_5D550C | R | [LLM] |
| 0075cbac | dword_75CBAC | R | [LLM] |
| 007d7428 | byte_7D7428 | R | [LLM] |
| 007d758c | byte_7D758C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00428150 | sub_428150 | [LLM] |
| 004c1940 | sub_4C1940 | [LLM] |
| 004eec20 | sub_4EEC20 | [LLM] |
| 004eec50 | sub_4EEC50 | [LLM] |
| 004eece0 | sub_4EECE0 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 004f81a0 | sub_4F81A0 | [LLM] |
| 004f8f50 | sub_4F8F50 | [LLM] |
| 0050b4e0 | sub_50B4E0 | [LLM] |
| 0050e010 | sub_50E010 | [LLM] |
| 0051c1e0 | F_3DTransformWithMatrixMultiplication [structural] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x12A1 | != | 1 | [LLM] |
| this | 0x38 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
