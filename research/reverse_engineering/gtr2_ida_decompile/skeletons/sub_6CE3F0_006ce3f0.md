## sub_6CE3F0_006ce3f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6B4A10 (006b4a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C8) | 0x8 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| *(this+0xDC) | 0x24 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 47 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x1AC | RW | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1AC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006ce380 | sub_6CE380 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006cde50 | sub_6CDE50 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24 | > | 0 | [LLM] |
| this | 0x140 | < | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
