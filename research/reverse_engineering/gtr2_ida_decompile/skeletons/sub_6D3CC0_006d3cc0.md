## sub_6D3CC0_006d3cc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF8 | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x160 | RW | — | [LLM] |
| this | 0x164 | RW | 0 | [LLM] |
| this | 0x168 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x160: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x164: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x168: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x164 | < | 8 | [LLM] |
| this | 0x164 | == | 8 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
