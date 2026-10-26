## sub_4A7EA0_004a7ea0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B7E60 (004b7e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2C | RW | 18446744073709551615 | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x34 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00506720 | ShortComputation_cb70 [exact] | [LLM] |
| 00506ba0 | sub_506BA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
