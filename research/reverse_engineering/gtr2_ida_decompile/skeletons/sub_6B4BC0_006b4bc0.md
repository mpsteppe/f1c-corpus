## sub_6B4BC0_006b4bc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 46 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x1A8 | R | — | [LLM] |
| this | 0x1AC | R | — | [LLM] |
| this | 0x1B0 | RW | 1 | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |
| this | 0x1CC | R | — | [LLM] |
| this | 0x1D0 | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1D0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6C | != | 0 | [LLM] |
| this | 0x1B0 | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
