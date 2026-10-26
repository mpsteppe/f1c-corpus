## sub_6CE7C0_006ce7c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x150) | 0x4 | R | — | [LLM] |
| *(this+0x150) | 0xC | R | — | [LLM] |
| *(this+0x150) | 0x34 | R | — | [LLM] |
| *(this+0x150) | 0x38 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x98 | RW | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x160 | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x1B0 | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C4 | RW | 0 | [LLM] |
| this | 0x1C8 | RW | 0 | [LLM] |
| this | 0x1CC | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
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
| this | 0x14C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
