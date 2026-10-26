## sub_5DAE90_005dae90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FBCC0 (005fbcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x214)+0x0) | 0x0 | RW | — | [LLM] |
| *(this+0x214) | 0x0 | R | — | [LLM] |
| *(this+0x21C) | 0x4 | R | — | [LLM] |
| *(this+0x26C) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x214 | R | — | [LLM] |
| this | 0x21C | RW | — | [LLM] |
| this | 0x26C | R | — | [LLM] |
| this | 0x270 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x214)+0x0) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x21C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a8 | dword_FB27A8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7280 | sub_5D7280 | [LLM] |
| 005d8c20 | sub_5D8C20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
