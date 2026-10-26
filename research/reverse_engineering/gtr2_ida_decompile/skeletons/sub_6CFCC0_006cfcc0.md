## sub_6CFCC0_006cfcc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x150) | 0x14 | R | — | [LLM] |
| *(this+0x150) | 0x18 | R | — | [LLM] |
| obj | 0x4 | R | — | [LLM] |
| obj | 0x14 | RW | 122 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x118 | R | — | [LLM] |
| this | 0x14C | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x16C | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1C8 | RW | 0 | [LLM] |
| this | 0x1CC | RW | 0 | [LLM] |
| this | 0x1D0 | RW | 0 | [LLM] |
| this | 0x1E4 | RW | — | [LLM] |
| this | 0x280 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1D0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1E4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x280: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006cf3e0 | sub_6CF3E0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14C | > | 0 | [LLM] |
| this | 0x168 | > | 0 | [LLM] |
| this | 0x198 | != | 63 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
