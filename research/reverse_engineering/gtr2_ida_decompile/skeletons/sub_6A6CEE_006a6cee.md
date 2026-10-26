## sub_6A6CEE_006a6cee — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00743ce8 | aCannotPerformT_0 | R | [LLM] |
| 00743d34 | aProgramIsOrder | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |
| 006a6c77 | sub_6A6C77 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `cannot perform texture load that is in anyway dependent on COLOR registers`
- `program is order of magnitude too large to compile to ps_1_4`
