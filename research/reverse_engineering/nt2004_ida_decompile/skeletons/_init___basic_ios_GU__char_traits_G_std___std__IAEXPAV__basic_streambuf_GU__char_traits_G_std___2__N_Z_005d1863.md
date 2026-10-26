## ?init@?$basic_ios@GU?$char_traits@G@std@@@std@@IAEXPAV?$basic_streambuf@GU?$char_traits@G@std@@@2@_N@Z_005d1863 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5D0F90 (005d0f90), sub_5D1064 (005d1064)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d1a76 | ?clear@ios_base@std@@QAEXH_N@Z | [LLM] |
| 005d1d72 | ?_Addstd@ios_base@std@@IAEXXZ | [LLM] |
| 005d1dc0 | StructFieldInitWithConditionalCall [structural] | [LLM] |
| 005d2680 | _btowc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
