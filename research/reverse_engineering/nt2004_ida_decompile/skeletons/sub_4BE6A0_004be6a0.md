## sub_4BE6A0_004be6a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BF030 (004bf030), sub_4BF120 (004bf120), sub_4C2790 (004c2790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004be880 | jpt_4BE6F5 | R | [LLM] |
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |
| 005d5ae0 | flt_5D5AE0 | R | [LLM] |
| 005d5ba0 | flt_5D5BA0 | R | [LLM] |
| 005d5ca0 | dbl_5D5CA0 | R | [LLM] |
| 00628f60 | flt_628F60 | R | [LLM] |
| 007d3c50 | dword_7D3C50 | RW | [LLM] |
| 007d4054 | flt_7D4054 | R | [LLM] |
| 007d7928 | dword_7D7928 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f90 | sub_404F90 | [LLM] |
| 005bef20 | __CIpow | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
