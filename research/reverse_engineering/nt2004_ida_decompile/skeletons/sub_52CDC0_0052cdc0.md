## sub_52CDC0_0052cdc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_52AE20 (0052ae20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x50)+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x50)+0x4) | 0x4 | RW | 0 | [LLM] |
| *(this+0x38) | 0x8 | R | — | [LLM] |
| *(this+0x50) | 0x4 | R | — | [LLM] |
| *(this+0x54) | 0x4 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x50)+0x4) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x54) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |
| 005d54f4 | flt_5D54F4 | R | [LLM] |
| 005d54f8 | flt_5D54F8 | R | [LLM] |
| 005d5504 | flt_5D5504 | R | [LLM] |
| 005d5510 | flt_5D5510 | R | [LLM] |
| 005d56a8 | flt_5D56A8 | R | [LLM] |
| 005d5ae0 | flt_5D5AE0 | R | [LLM] |
| 005d5b60 | flt_5D5B60 | R | [LLM] |
| 005d5b90 | flt_5D5B90 | R | [LLM] |
| 005d5ba4 | flt_5D5BA4 | R | [LLM] |
| 005d5bfc | flt_5D5BFC | R | [LLM] |
| 005d6334 | flt_5D6334 | R | [LLM] |
| 005ea410 | flt_5EA410 | R | [LLM] |
| 005ea848 | flt_5EA848 | R | [LLM] |
| 005ea86c | flt_5EA86C | R | [LLM] |
| 005eaa2c | flt_5EAA2C | R | [LLM] |
| 005eac4c | flt_5EAC4C | R | [LLM] |
| 005fd340 | NumOfElements | R | [LLM] |
| 00767cc4 | flt_767CC4 | R | [LLM] |
| 00767ce8 | flt_767CE8 | R | [LLM] |
| 007d3c50 | dword_7D3C50 | RW | [LLM] |
| 007d3c54 | flt_7D3C54 | R | [LLM] |
| 007d4054 | flt_7D4054 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052c0c0 | sub_52C0C0 | [LLM] |
| 0052c170 | sub_52C170 | [LLM] |
| 0052d460 | sub_52D460 | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
