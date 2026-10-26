## sub_45BAC0_0045bac0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_45BAC0 (0045bac0), sub_45D190 (0045d190), sub_45D250 (0045d250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x4 | R | — | [LLM] |
| *(this+0xC) | 0x10 | R | — | [LLM] |
| *(this+0xC) | 0x14 | R | — | [LLM] |
| *(this+0xC) | 0x18 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xA | R | — | [LLM] |
| this | 0xB | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b685d0 | flt_B685D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b1f0 | QuadraticSurfaceCollisionTest [structural] | [LLM] |
| 0045bac0 | sub_45BAC0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0x18 | < | 0 | [LLM] |
| this | 0x8 | < | 0 | [LLM] |
| this | 0x8 | == | 18446744073709551614 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
