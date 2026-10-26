## sub_4BEE40_004bee40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C2790 (004c2790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x0 | R | — | [LLM] |
| *(this+0xB8) | 0x2 | R | — | [LLM] |
| *(this+0xB8) | 0x48 | R | — | [LLM] |
| *(this+0xB8) | 0x64 | R | — | [LLM] |
| *(this+0xC4) | 0x0 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004beef0 | jpt_4BEE5C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004beca0 | sub_4BECA0 | [LLM] |
| 0059ef60 | Bit12FlagSet [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
