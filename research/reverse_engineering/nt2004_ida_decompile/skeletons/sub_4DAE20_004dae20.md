## sub_4DAE20_004dae20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D54F0 (004d54f0), sub_4D6660 (004d6660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | RW | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| obj | 0xC | RW | 0 | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- obj 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cf510 | nullsub_6 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
