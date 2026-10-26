## sub_6CE9E0_006ce9e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B0) | 0x48 | R | — | [LLM] |
| *(this+0x1B8) | 0x0 | R | — | [LLM] |
| *(this+0xDC) | 0xC | R | — | [LLM] |
| *(this+0xDC) | 0x1C | R | — | [LLM] |
| *(this+0xDC) | 0x20 | R | — | [LLM] |
| *(this+0xDC) | 0x24 | R | — | [LLM] |
| *(this+0xDC) | 0x30 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA0 | RW | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x1B0 | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xA0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
