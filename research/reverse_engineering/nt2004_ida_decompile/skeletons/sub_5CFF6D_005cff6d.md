## sub_5CFF6D_005cff6d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ??0Init@ios_base@std@@QAE@XZ (005cfc8d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d4466 | loc_5D4466 | R | [LLM] |
| 005f7534 | ??_7?$basic_istream@DU?$char_traits@D@std@@@std@@6B@ | R | [LLM] |
| 005f7544 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | [LLM] |
| 005f7550 | unk_5F7550 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005d081d | ?init@?$basic_ios@DU?$char_traits@D@std@@@std@@IAEXPAV?$basic_streambuf@DU?$char_traits@D@std@@@2@_N@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
