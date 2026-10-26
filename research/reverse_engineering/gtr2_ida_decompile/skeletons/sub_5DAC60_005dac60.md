## sub_5DAC60_005dac60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_56DF50 (0056df50), sub_5E12E0 (005e12e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x214) | 0x1D0 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x21C | RW | — | [LLM] |
| this | 0x220 | R | — | [LLM] |
| this | 0x224 | R | — | [LLM] |
| this | 0x26C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x21C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005dab90 | sub_5DAB90 | [LLM] |
| 005e6600 | sub_5E6600 | [LLM] |
| 005fdfb0 | sub_5FDFB0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
