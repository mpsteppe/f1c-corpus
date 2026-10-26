## sub_4E4ED0_004e4ed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B9790 (004b9790), sub_4B99F0 (004b99f0), sub_4B9C10 (004b9c10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x78FC | RW | 7 | [LLM] |
| this | 0x7900 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x78FC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x7900: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004e4f38 | jpt_4E4EDF | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e4f60 | sub_4E4F60 | [LLM] |
| 004e4f70 | sub_4E4F70 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
