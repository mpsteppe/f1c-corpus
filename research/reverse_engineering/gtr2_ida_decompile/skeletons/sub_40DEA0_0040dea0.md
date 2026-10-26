## sub_40DEA0_0040dea0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_40E040 (0040e040), sub_4E8030 (004e8030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x15 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x15: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 0075770c | flt_75770C | R | [LLM] |
| 00b7117c | byte_B7117C | R | [LLM] |
| 00fae988 | dword_FAE988 | R | [LLM] |
| 00fae990 | dword_FAE990 | R | [LLM] |
| 00fb1d08 | dbl_FB1D08 | R | [LLM] |
| 00fb2790 | dword_FB2790 | R | [LLM] |
| 00fb27a4 | dword_FB27A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00562dd0 | sub_562DD0 | [LLM] |
| 0063099c | __ftol2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
