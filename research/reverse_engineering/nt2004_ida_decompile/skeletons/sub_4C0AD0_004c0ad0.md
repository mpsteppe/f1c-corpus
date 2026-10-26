## sub_4C0AD0_004c0ad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C0190 (004c0190), sub_4DC900 (004dc900), sub_4DCA20 (004dca20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | 1 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1C | != | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
