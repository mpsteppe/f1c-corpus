## sub_52ACD0_0052acd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x54) | 0x4 | R | — | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |
| this | 0x58 | RW | 0 | [LLM] |
| this | 0x5C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x58 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
