## ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV12@ID@Z_005d0721 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ?overflow@?$basic_filebuf@DU?$char_traits@D@std@@@std@@MAEHH@Z (005d02d0), ?uflow@?$basic_filebuf@DU?$char_traits@D@std@@@std@@MAEHXZ (005d04e0), ?overflow@?$basic_filebuf@GU?$char_traits@G@std@@@std@@MAEGG@Z (005d1390), ?uflow@?$basic_filebuf@GU?$char_traits@G@std@@@std@@MAEGXZ (005d15bd)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f75c8 | dword_5F75C8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c2450 | _memset | [LLM] |
| 005d0992 | ?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAE_NI_N@Z | [LLM] |
| 005d21c1 | ?_Xlen@std@@YAXXZ | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
