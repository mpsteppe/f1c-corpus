## sub_4DFAA0_004dfaa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DFE50 (004dfe50), sub_4E1050 (004e1050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x5C)+0x34)+0x0) | 0x14 | R | — | [LLM] |
| *(*(this+0x58)+0x0) | 0x14 | R | — | [LLM] |
| *(*(this+0x5C)+0x34) | 0x0 | R | — | [LLM] |
| *(this+0x58) | 0x0 | R | — | [LLM] |
| *(this+0x5C) | 0x34 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x5C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c956c | off_16C956C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd340 | sub_4CD340 | [LLM] |
| 004df700 | sub_4DF700 | [LLM] |
| 004df840 | sub_4DF840 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
