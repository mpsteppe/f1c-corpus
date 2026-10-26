## sub_4EE0B0_004ee0b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42E180 (0042e180), sub_42F350 (0042f350), sub_4612C0 (004612c0), sub_4D8B50 (004d8b50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40C8 | R | — | [LLM] |
| this | 0x62B0 | RW | — | [LLM] |
| this | 0x62B4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x62B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x62B4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006291d0 | dword_6291D0 | R | [LLM] |
| 0062bc28 | flt_62BC28 | R | [LLM] |
| 00765e90 | dword_765E90 | R | [LLM] |
| 007663e0 | byte_7663E0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00417c10 | sub_417C10 | [LLM] |
| 0041f400 | sub_41F400 | [LLM] |
| 004b4210 | sub_4B4210 | [LLM] |
| 004c00c0 | sub_4C00C0 | [LLM] |
| 004ce010 | sub_4CE010 | [LLM] |
| 004cf510 | nullsub_6 | [LLM] |
| 004dc0b0 | sub_4DC0B0 | [LLM] |
| 004eddd0 | sub_4EDDD0 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 00509b10 | sub_509B10 | [LLM] |
| 00525c50 | sub_525C50 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
