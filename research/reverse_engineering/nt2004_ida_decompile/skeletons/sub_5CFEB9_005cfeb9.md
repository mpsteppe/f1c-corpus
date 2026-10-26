## sub_5CFEB9_005cfeb9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5CFBC8 (005cfbc8), sub_5CFC39 (005cfc39), sub_5CFC68 (005cfc68)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d4442 | loc_5D4442 | R | [LLM] |
| 005f753c | ??_7?$basic_ostream@DU?$char_traits@D@std@@@std@@6B@ | R | [LLM] |
| 005f7544 | ??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@ | R | [LLM] |
| 005f7548 | unk_5F7548 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005d1d72 | ?_Addstd@ios_base@std@@IAEXXZ | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
