## sub_64BEF8_0064bef8 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_64E329 (0064e329)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x10 | RW | 0 | [LLM] |
| obj | 0x68 | R | — | [LLM] |
| obj | 0x6C | R | — | [LLM] |
| obj | 0x70 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00681563 | sub_681563 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d1b0 | sub_41D1B0 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
