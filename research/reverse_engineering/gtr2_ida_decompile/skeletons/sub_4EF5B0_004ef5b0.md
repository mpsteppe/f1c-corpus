## sub_4EF5B0_004ef5b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_540C90 (00540c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x174 | RW | — | [LLM] |
| this | 0x178 | RW | — | [LLM] |
| this | 0x17C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x174: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x178: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x17C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16ec | flt_6F16EC | R | [LLM] |
| 006f39c0 | flt_6F39C0 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 0091e084 | dword_91E084 | R | [LLM] |
| 00b640c8 | dword_B640C8 | R | [LLM] |
| 00b66040 | dbl_B66040 | R | [LLM] |
| 00b6b7d0 | dword_B6B7D0 | R | [LLM] |
| 00b6b7fc | dword_B6B7FC | R | [LLM] |
| 00b6b828 | dword_B6B828 | R | [LLM] |
| 00b6f118 | byte_B6F118 | R | [LLM] |
| 00b6f1c8 | dword_B6F1C8 | R | [LLM] |
| 00b6f1f0 | dword_B6F1F0 | R | [LLM] |
| 00b6f1f8 | dword_B6F1F8 | R | [LLM] |
| 00b6f218 | dword_B6F218 | R | [LLM] |
| 00b6f21c | dword_B6F21C | R | [LLM] |
| 00b6f220 | dword_B6F220 | R | [LLM] |
| 00b6f25c | dword_B6F25C | R | [LLM] |
| 00b6f2e8 | dword_B6F2E8 | R | [LLM] |
| 00b6f370 | flt_B6F370 | R | [LLM] |
| 00b70a44 | flt_B70A44 | R | [LLM] |
| 00b72314 | dword_B72314 | R | [LLM] |
| 00be08a0 | dword_BE08A0 | RW | [LLM] |
| 00be08a4 | flt_BE08A4 | R | [LLM] |
| 00fb1d18 | dbl_FB1D18 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00421a90 | sub_421A90 | [LLM] |
| 00421b30 | sub_421B30 | [LLM] |
| 00439ab0 | sub_439AB0 | [LLM] |
| 00439ad0 | sub_439AD0 | [LLM] |
| 004ee320 | sub_4EE320 | [LLM] |
| 004eebd0 | sub_4EEBD0 | [LLM] |
| 004ff740 | sub_4FF740 | [LLM] |
| 00631ba8 | _rand | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x174 | != | 2139095039 | [LLM] |
| this | 0x178 | == | 2139095039 | [LLM] |
| this | 0x17C | != | 2139095039 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
