## sub_5D10CC_005d10cc — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5D0CF0 (005d0cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d45ea | loc_5D45EA | R | [LLM] |
| 005f75d0 | ??_7?$basic_istream@GU?$char_traits@G@std@@@std@@6B@ | R | [LLM] |
| 005f75e0 | ??_7?$basic_ios@GU?$char_traits@G@std@@@std@@6B@ | R | [LLM] |
| 005f75ec | unk_5F75EC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005d1d72 | ?_Addstd@ios_base@std@@IAEXXZ | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
