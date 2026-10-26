## sub_5F7FF0_005f7ff0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** SystemOSAPICall [structural] (005debd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x24A0)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x24A0)+0x0) | 0x329 | RW | 0 | [LLM] |
| *(this+0x24A0) | 0x0 | R | — | [LLM] |
| this | 0x24A0 | R | — | [LLM] |
| this | 0x24A8 | RW | — | [LLM] |
| this | 0x24B0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x24A0)+0x0) 0x329: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24A8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
