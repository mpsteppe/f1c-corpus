## sub_4FFF90_004fff90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xC | R | — | [LLM] |
| obj | 0x39E4 | R | — | [LLM] |
| obj | 0x3E78 | R | — | [LLM] |
| obj | 0x3E8C | R | — | [LLM] |
| obj | 0x3E90 | R | — | [LLM] |
| obj | 0x3E94 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x2FD | RW | 0 | [LLM] |
| this | 0x30C | R | — | [LLM] |
| this | 0x328 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x2FD: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1e9c | flt_6F1E9C | R | [LLM] |
| 006f344c | flt_6F344C | R | [LLM] |
| 006f3780 | flt_6F3780 | R | [LLM] |
| 00714c64 | flt_714C64 | R | [LLM] |
| 00714c68 | flt_714C68 | R | [LLM] |
| 00757c1c | dword_757C1C | R | [LLM] |
| 0091e084 | dword_91E084 | R | [LLM] |
| 00b6e4d0 | dword_B6E4D0 | R | [LLM] |
| 00b6f1c8 | dword_B6F1C8 | R | [LLM] |
| 00b71278 | dword_B71278 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004278d0 | sub_4278D0 | [LLM] |
| 004ee320 | sub_4EE320 | [LLM] |
| 004f0cb0 | sub_4F0CB0 | [LLM] |
| 004f0d10 | sub_4F0D10 | [LLM] |
| 004f14a0 | sub_4F14A0 | [LLM] |
| 004f1bf0 | sub_4F1BF0 | [LLM] |
| 004fcb90 | sub_4FCB90 | [LLM] |
| 004fff30 | sub_4FFF30 | [LLM] |
| 00573480 | sub_573480 | [LLM] |
| 00578670 | sub_578670 | [LLM] |
| 0057de20 | sub_57DE20 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x39E4 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
