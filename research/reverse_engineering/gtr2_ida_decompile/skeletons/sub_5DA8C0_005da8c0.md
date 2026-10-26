## sub_5DA8C0_005da8c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4119D0 (004119d0), sub_4F7EC0 (004f7ec0), sub_56AE80 (0056ae80), sub_5DA8C0 (005da8c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x214)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x214)+0x0) | 0x1D0 | R | — | [LLM] |
| *(this+0x214) | 0x0 | R | — | [LLM] |
| *(this+0x280) | 0x0 | R | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x21C | RW | — | [LLM] |
| this | 0x224 | R | — | [LLM] |
| this | 0x274 | R | — | [LLM] |
| this | 0x27C | RW | — | [LLM] |
| this | 0x280 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x21C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x27C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005da8c0 | sub_5DA8C0 | [LLM] |
| 005ff0c0 | sub_5FF0C0 | [LLM] |
| 005ff0d0 | sub_5FF0D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
