## sub_6CE4D0_006ce4d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6CE520 (006ce520)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x98 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x1B0 | R | — | [LLM] |
| this | 0x1C4 | RW | 0 | [LLM] |
| this | 0x1C8 | RW | 0 | [LLM] |
| this | 0x1CC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14C | <= | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
