## sub_4EFD80_004efd80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D8670 (004d8670), sub_526D90 (00526d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | 2 | [LLM] |
| this | 0x1C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 00767898 | flt_767898 | R | [LLM] |
| 007d6bb4 | dword_7D6BB4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
