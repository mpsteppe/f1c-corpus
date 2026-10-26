## sub_64FD9A_0064fd9a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_64E329 (0064e329)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | RW | 1 | [LLM] |
| this | 0x54 | RW | — | [LLM] |
| this | 0x58 | RW | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00681563 | sub_681563 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d1b0 | sub_41D1B0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
