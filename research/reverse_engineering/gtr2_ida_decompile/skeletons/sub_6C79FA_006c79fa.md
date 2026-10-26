## sub_6C79FA_006c79fa — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6A14B5 (006a14b5), sub_6ADF60 (006adf60), sub_6B1163 (006b1163)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x4 | R | — | [LLM] |
| *(this+0x18) | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x160 | RW | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x170 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x160: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x170: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f37a0 | dbl_6F37A0 | R | [LLM] |
| 006fd194 | aC_8 | R | [LLM] |
| 00745770 | dword_745770 | R | [LLM] |
| 0074577c | dword_74577C | R | [LLM] |
| 00745788 | dword_745788 | R | [LLM] |
| 007457d0 | dword_7457D0 | R | [LLM] |
| 007457dc | dword_7457DC | R | [LLM] |
| 007457e8 | dword_7457E8 | R | [LLM] |
| 00745830 | dword_745830 | R | [LLM] |
| 00745890 | dword_745890 | R | [LLM] |
| 007458f0 | dword_7458F0 | R | [LLM] |
| 00745950 | dword_745950 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | [LLM] |
| 00680cec | ZeroInit16ElementArray [structural] | [LLM] |
| 00680d22 | sub_680D22 | [LLM] |
| 00681186 | sub_681186 | [LLM] |
| 006811d1 | sub_6811D1 | [LLM] |
| 00681430 | sub_681430 | [LLM] |
| 00681a51 | sub_681A51 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |
| 006bb1aa | sub_6BB1AA | [LLM] |
| 006bb35b | sub_6BB35B | [LLM] |
| 006c29d6 | sub_6C29D6 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | != | 18446744073709551615 | [LLM] |
| this | 0x164 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
