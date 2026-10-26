## sub_65A5CE_0065a5ce — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_65C7B1 (0065c7b1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x2A0) | 0x4 | R | — | [LLM] |
| *(this+0x2A0) | 0xC | RW | 0 | [LLM] |
| this | 0x44 | RW | 1 | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x268 | R | — | [LLM] |
| this | 0x2A0 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x2A0) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2A0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00737904 | aUnexpectedEndi | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00659cb7 | sub_659CB7 | [LLM] |
| 0065dd1f | sub_65DD1F | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `unexpected #endif`
