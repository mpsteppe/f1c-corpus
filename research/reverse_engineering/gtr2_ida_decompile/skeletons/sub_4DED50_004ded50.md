## sub_4DED50_004ded50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x70 | RW | 0 | [LLM] |
| this | 0x74 | RW | 0 | [LLM] |
| this | 0xCC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x70: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xCC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
