## sub_4EEA00_004eea00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** UDPSocketBind [structural] (004d19a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40C8 | R | — | [LLM] |
| this | 0x62A0 | R | — | [LLM] |
| this | 0x62CC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x62CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5c4c | flt_5D5C4C | R | [LLM] |
| 00764d70 | dword_764D70 | R | [LLM] |
| 0079fc40 | dword_79FC40 | RW | [LLM] |
| 007d3c44 | dword_7D3C44 | RW | [LLM] |
| 007da9c0 | dbl_7DA9C0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00463490 | sub_463490 | [LLM] |
| 00464a00 | sub_464A00 | [LLM] |
| 004ee360 | sub_4EE360 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40C8 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
