## sub_6D9DD5_006d9dd5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6DAAC0 (006daac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x16B0 | RW | — | [LLM] |
| this | 0x16B1 | R | — | [LLM] |
| this | 0x16B4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x16B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x16B4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00748104 | byte_748104 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006d9938 | sub_6D9938 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
