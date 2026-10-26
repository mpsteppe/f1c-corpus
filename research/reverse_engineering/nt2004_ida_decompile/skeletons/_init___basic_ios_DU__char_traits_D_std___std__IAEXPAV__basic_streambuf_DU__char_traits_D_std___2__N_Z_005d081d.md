## ?init@?$basic_ios@DU?$char_traits@D@std@@@std@@IAEXPAV?$basic_streambuf@DU?$char_traits@D@std@@@2@_N@Z_005d081d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5CFE4F (005cfe4f), sub_5CFF6D (005cff6d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |
| this | 0x30 | RW | 32 | [LLM] |

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

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
