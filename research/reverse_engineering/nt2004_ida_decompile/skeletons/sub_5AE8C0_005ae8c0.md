## sub_5AE8C0_005ae8c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_598430 (00598430)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x168)+0x4) | 0x28 | RW | — | [LLM] |
| *(*(this+0xFC)+0x278) | 0x278 | R | — | [LLM] |
| *(this+0x168) | 0x4 | R | — | [LLM] |
| *(this+0x168) | 0x8 | R | — | [LLM] |
| this | 0xF0 | RW | — | [LLM] |
| this | 0xF4 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x158 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x168 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x168)+0x4) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007e6b48 | dword_7E6B48 | R | [LLM] |
| 007e8d04 | dword_7E8D04 | R | [LLM] |
| 007feea8 | dword_7FEEA8 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cf510 | nullsub_6 | [LLM] |
| 00597b20 | sub_597B20 | [LLM] |
| 0059aba0 | sub_59ABA0 | [LLM] |
| 005a26b0 | sub_5A26B0 | [LLM] |
| 005a2740 | sub_5A2740 | [LLM] |
| 005ab360 | sub_5AB360 | [LLM] |
| 005ab3a0 | sub_5AB3A0 | [LLM] |
| 005aca90 | sub_5ACA90 | [LLM] |
| 005ae610 | sub_5AE610 | [LLM] |
| 005ae860 | sub_5AE860 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x158 | > | 0 | [LLM] |
| this | 0x178 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
