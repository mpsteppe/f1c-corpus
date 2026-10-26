## sub_4B1CF0_004b1cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B2660 (004b2660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0xC | RW | 17 | [LLM] |
| this | 0x24 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b1eec | jpt_4B1D06 | R | [LLM] |
| 004b1f04 | jpt_4B1D98 | R | [LLM] |
| 004b1f18 | byte_4B1F18 | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5708 | flt_5D5708 | R | [LLM] |
| 0075aac4 | dword_75AAC4 | R | [LLM] |
| 0075cbb4 | dword_75CBB4 | R | [LLM] |
| 00766074 | unk_766074 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b25b0 | sub_4B25B0 | [LLM] |
| 004b25d0 | sub_4B25D0 | [LLM] |
| 004b2610 | sub_4B2610 | [LLM] |
| 004b3000 | sub_4B3000 | [LLM] |
| 004de9d0 | sub_4DE9D0 | [LLM] |
| 004deb10 | sub_4DEB10 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
