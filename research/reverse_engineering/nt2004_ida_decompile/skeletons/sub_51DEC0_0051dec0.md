## sub_51DEC0_0051dec0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_51CDC0 (0051cdc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4604)+0x54) | 0x2C | R | — | [LLM] |
| *(*(this+0x4604)+0x54) | 0x30 | R | — | [LLM] |
| *(this+0x4604) | 0x54 | R | — | [LLM] |
| this | 0xE4 | RW | 1 | [LLM] |
| this | 0x648 | RW | 0 | [LLM] |
| this | 0x7D8 | R | — | [LLM] |
| this | 0x4074 | R | — | [LLM] |
| this | 0x4488 | R | — | [LLM] |
| this | 0x448C | R | — | [LLM] |
| this | 0x4490 | R | — | [LLM] |
| this | 0x4604 | R | — | [LLM] |
| this | 0x4954 | R | — | [LLM] |
| this | 0x4960 | R | — | [LLM] |
| this | 0x49F4 | R | — | [LLM] |
| this | 0x49F8 | R | — | [LLM] |
| this | 0x49FC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x648: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54d0 | dbl_5D54D0 | R | [LLM] |
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5b90 | flt_5D5B90 | R | [LLM] |
| 005d5bf8 | flt_5D5BF8 | R | [LLM] |
| 005ea604 | flt_5EA604 | R | [LLM] |
| 005eab50 | flt_5EAB50 | R | [LLM] |
| 007608e4 | dbl_7608E4 | R | [LLM] |
| 007608fc | dbl_7608FC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051dae0 | sub_51DAE0 | [LLM] |
| 0051dd00 | sub_51DD00 | [LLM] |
| 00526050 | sub_526050 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
