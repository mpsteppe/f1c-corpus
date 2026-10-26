## sub_51BFD0_0051bfd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_421CA0 (00421ca0), sub_423790 (00423790), sub_4C2000 (004c2000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4514 | R | — | [LLM] |
| this | 0x4914 | R | — | [LLM] |
| this | 0x4930 | R | — | [LLM] |
| this | 0x4934 | R | — | [LLM] |
| this | 0x4989 | RW | 1 | [LLM] |
| this | 0x498A | R | — | [LLM] |
| this | 0x498C | RW | 0 | [LLM] |
| this | 0x4998 | R | — | [LLM] |
| this | 0x499C | R | — | [LLM] |
| this | 0x49A0 | RW | 0 | [LLM] |
| this | 0x49A4 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x4989: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x498C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x49A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x49A4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051bb70 | sub_51BB70 | [LLM] |
| 005261a0 | sub_5261A0 | [LLM] |
| 005262a0 | sub_5262A0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
