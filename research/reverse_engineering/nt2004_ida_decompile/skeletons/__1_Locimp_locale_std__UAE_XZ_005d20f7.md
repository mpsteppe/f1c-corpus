## ??1_Locimp@locale@std@@UAE@XZ_005d20f7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ??_G_Locimp@locale@std@@UAEPAXI@Z (005d20db)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d4717 | loc_5D4717 | R | [LLM] |
| 005f76d8 | off_5F76D8 | R | [LLM] |
| 005f76e0 | ??_7facet@locale@std@@6B@ | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1b88 | sub_5C1B88 | [LLM] |
| 005c1db0 | __EH_prolog | [LLM] |
| 005d0100 | RefcountDecrementWithLock [structural] | [LLM] |
| 005d07e1 | ReferenceCountDecrementWithConditionalFree [structural] | [LLM] |
| 005d19c5 | ??0_Lockit@std@@QAE@XZ | [LLM] |
| 005d1a61 | ??1_Lockit@std@@QAE@XZ | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
