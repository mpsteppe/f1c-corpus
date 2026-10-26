## sub_6B36AB_006b36ab — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | RW | 64 | [LLM] |
| this | 0x2C | RW | 64 | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |
| this | 0x38 | RW | 8192 | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x71 | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x38: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x71: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x108: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00736b0c | aTx | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006460b4 | sub_6460B4 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
