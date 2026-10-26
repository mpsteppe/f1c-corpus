## sub_4EE4E0_004ee4e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_556440 (00556440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x180 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x18C | R | — | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x19C | R | — | [LLM] |
| this | 0x1A0 | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1A8 | R | — | [LLM] |
| this | 0x1AC | RW | — | [LLM] |
| this | 0x1B0 | RW | — | [LLM] |
| this | 0x1B4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1AC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1B4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16e8 | flt_6F16E8 | R | [LLM] |
| 006f39c0 | flt_6F39C0 | R | [LLM] |
| 006f61d8 | flt_6F61D8 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 0091e084 | dword_91E084 | R | [LLM] |
| 00b66040 | dbl_B66040 | R | [LLM] |
| 00b6f118 | byte_B6F118 | R | [LLM] |
| 00b6f1c8 | dword_B6F1C8 | R | [LLM] |
| 00b6f264 | dword_B6F264 | R | [LLM] |
| 00b6f268 | dword_B6F268 | R | [LLM] |
| 00b6f26c | dword_B6F26C | R | [LLM] |
| 00b6f370 | flt_B6F370 | R | [LLM] |
| 00b70a44 | flt_B70A44 | R | [LLM] |
| 00b72314 | dword_B72314 | R | [LLM] |
| 00fade9c | dword_FADE9C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041fe50 | sub_41FE50 | [LLM] |
| 004ee100 | sub_4EE100 | [LLM] |
| 00631ba8 | _rand | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x180 | == | 2139095039 | [LLM] |
| this | 0x184 | == | 2139095039 | [LLM] |
| this | 0x188 | == | 2139095039 | [LLM] |
| this | 0x18C | == | 2139095039 | [LLM] |
| this | 0x190 | == | 2139095039 | [LLM] |
| this | 0x194 | == | 2139095039 | [LLM] |
| this | 0x198 | == | 2139095039 | [LLM] |
| this | 0x19C | == | 2139095039 | [LLM] |
| this | 0x1A0 | == | 2139095039 | [LLM] |
| this | 0x1A4 | == | 2139095039 | [LLM] |
| this | 0x1A8 | == | 2139095039 | [LLM] |
| this | 0x1AC | != | 2 | [LLM] |
| this | 0x1B0 | != | 2 | [LLM] |
| this | 0x1B4 | != | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
