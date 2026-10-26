## sub_4F2AE0_004f2ae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4F2BC0 (004f2bc0), sub_4F3200 (004f3200), sub_4F3F90 (004f3f90), sub_4F44B0 (004f44b0), sub_4F4D30 (004f4d30), sub_4F4FA0 (004f4fa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | RW | 0 | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005b0910 | sub_5B0910 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
