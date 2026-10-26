## sub_50ADD0_0050add0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_509B10 (00509b10), sub_51D720 (0051d720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9E0 | R | — | [LLM] |
| this | 0x9E4 | R | — | [LLM] |
| this | 0x9E8 | R | — | [LLM] |
| this | 0xA0C | R | — | [LLM] |
| this | 0xA10 | R | — | [LLM] |
| this | 0xA14 | R | — | [LLM] |
| this | 0xB38 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xB38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d5ba0 | flt_5D5BA0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059e0c0 | TripleFieldQuery [exact] | [LLM] |
| 0059e170 | sub_59E170 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
