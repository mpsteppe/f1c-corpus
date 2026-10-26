## sub_5FDBD0_005fdbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5FDD80 (005fdd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x4 | RW | 0 | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x40) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f2f60 | j_nullsub_7 | R | [LLM] |
| 00fb27f8 | dword_FB27F8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005ea540 | sub_5EA540 | [LLM] |
| 005f2f60 | j_nullsub_7 | [LLM] |
| 005fdb10 | sub_5FDB10 | [LLM] |
| 006308d3 | j__free | [LLM] |
| 0063093b | ??_M@YGXPAXIHP6EX0@Z@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
