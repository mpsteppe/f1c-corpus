## sub_4EED90_004eed90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_478330 (00478330), sub_4EE360 (004ee360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40C8 | R | — | [LLM] |
| this | 0x4984 | R | — | [LLM] |
| this | 0x5EB4 | R | — | [LLM] |
| this | 0x62A0 | R | — | [LLM] |
| this | 0x62B8 | R | — | [LLM] |
| this | 0x62D0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54d0 | dbl_5D54D0 | R | [LLM] |
| 005ea780 | flt_5EA780 | R | [LLM] |
| 00764d70 | dword_764D70 | R | [LLM] |
| 0076612c | unk_76612C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00463dc0 | sub_463DC0 | [LLM] |
| 004baa00 | TLSAllocationThreadIDInit [structural] | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40C8 | == | 2 | [LLM] |
| this | 0x5EB4 | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
