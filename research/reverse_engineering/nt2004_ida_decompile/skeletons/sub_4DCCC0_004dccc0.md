## sub_4DCCC0_004dccc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C19D0 (004c19d0), sub_4DD490 (004dd490), sub_4DDB70 (004ddb70), sub_4DEBE0 (004debe0), sub_4DF490 (004df490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ffc88 | aSS_3 | R | [LLM] |
| 00610144 | aDisqualified | R | [LLM] |
| 00629328 | flt_629328 | R | [LLM] |
| 0062a170 | dword_62A170 | R | [LLM] |
| 0062a17c | Destination | R | [LLM] |
| 0062a37b | byte_62A37B | W | [LLM] |
| 00764d68 | byte_764D68 | R | [LLM] |
| 0079fc40 | dword_79FC40 | RW | [LLM] |
| 007d3c44 | dword_7D3C44 | RW | [LLM] |
| 007d758c | byte_7D758C | R | [LLM] |
| 007da9d0 | dbl_7DA9D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b5b0 | sub_41B5B0 | [LLM] |
| 0041f230 | BinarySearchInStringTable [structural] | [LLM] |
| 0045d100 | sub_45D100 | [LLM] |
| 004d0d00 | sub_4D0D00 | [LLM] |
| 004f81a0 | sub_4F81A0 | [LLM] |
| 005beab0 | _strncpy | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x38 | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%s %s`
- `Disqualified:`
- `Disqualified:`
