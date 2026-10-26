## sub_4EFA90_004efa90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4057C0 (004057c0), sub_49C1D0 (0049c1d0), sub_4D8860 (004d8860), sub_526D90 (00526d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x4 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005ea788 | dword_5EA788 | R | [LLM] |
| 005ea798 | off_5EA798 | R | [LLM] |
| 00611130 | dword_611130 | R | [LLM] |
| 00611138 | byte_611138 | RW | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 00767898 | flt_767898 | R | [LLM] |
| 007d6bac | dword_7D6BAC | RW | [LLM] |
| 007d6bb4 | dword_7D6BB4 | R | [LLM] |
| 007da9c0 | dbl_7DA9C0 | R | [LLM] |
| ff000000000060b3 | byte_FF000000000060B3 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00579060 | sub_579060 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005c0d23 | __stat | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
