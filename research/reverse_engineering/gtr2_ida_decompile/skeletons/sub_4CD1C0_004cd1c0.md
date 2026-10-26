## sub_4CD1C0_004cd1c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x27C | R | — | [LLM] |
| this | 0x4F0 | R | — | [LLM] |
| this | 0x4FC | R | — | [LLM] |
| this | 0x980 | RW | 0 | [LLM] |
| this | 0x984 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x980: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x984: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cd247 | loc_4CD247 | R | [LLM] |
| 004cd271 | loc_4CD271 | R | [LLM] |
| 00631c0d | __stricmp | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4FC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
