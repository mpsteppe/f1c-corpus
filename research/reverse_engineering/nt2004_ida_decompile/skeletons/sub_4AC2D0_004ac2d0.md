## sub_4AC2D0_004ac2d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AD5B0 (004ad5b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C)+0x58) | 0x58 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x6C | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x6C)+0x58) 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ac270 | sub_4AC270 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
