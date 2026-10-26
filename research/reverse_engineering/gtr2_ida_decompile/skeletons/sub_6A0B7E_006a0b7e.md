## sub_6A0B7E_006a0b7e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6A0B7E (006a0b7e), sub_6A1459 (006a1459)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x60 | R | — | [LLM] |
| obj | 0x64 | R | — | [LLM] |
| obj | 0x68 | R | — | [LLM] |
| obj | 0x74 | R | — | [LLM] |
| obj | 0x78 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x13C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x138: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00742838 | aRelativeAddres_2 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |
| 006a0b7e | sub_6A0B7E | [LLM] |
| 006c64e6 | sub_6C64E6 | [LLM] |
| 006cb0ce | sub_6CB0CE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC8 | > | 256 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `relative addressing not supported in vs_1_0 instruction set`
