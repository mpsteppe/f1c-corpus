## sub_41FEC0_0041fec0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_424090 (00424090)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3E74 | R | — | [LLM] |
| obj | 0x3E7C | R | — | [LLM] |
| obj | 0x3E8C | R | — | [LLM] |
| obj | 0x3E94 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731ce8 | String2 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
