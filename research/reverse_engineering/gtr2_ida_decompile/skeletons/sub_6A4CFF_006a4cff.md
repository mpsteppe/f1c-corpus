## sub_6A4CFF_006a4cff — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x100 | RW | 0 | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16e0 | dbl_6F16E0 | R | [LLM] |
| 006f2358 | dbl_6F2358 | R | [LLM] |
| 006f2370 | dbl_6F2370 | R | [LLM] |
| 006f2378 | dbl_6F2378 | R | [LLM] |
| 006f2dac | flt_6F2DAC | R | [LLM] |
| 006f37a0 | dbl_6F37A0 | R | [LLM] |
| 00720770 | dbl_720770 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | [LLM] |
| 00680cec | ZeroInit16ElementArray [structural] | [LLM] |
| 00680d22 | sub_680D22 | [LLM] |
| 00681186 | sub_681186 | [LLM] |
| 006811d1 | sub_6811D1 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
