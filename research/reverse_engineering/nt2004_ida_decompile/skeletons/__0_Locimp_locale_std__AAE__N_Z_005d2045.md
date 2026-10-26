## ??0_Locimp@locale@std@@AAE@_N@Z_005d2045 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ?_Init@locale@std@@CAPAV_Locimp@12@XZ (005d1f31)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 1 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d46f0 | loc_5D46F0 | R | [LLM] |
| 005f76d8 | off_5F76D8 | R | [LLM] |
| 005f76e0 | ??_7facet@locale@std@@6B@ | R | [LLM] |
| 005fe194 | asc_5FE194 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005d07e1 | ReferenceCountDecrementWithConditionalFree [structural] | [LLM] |
| 005d0a47 | BufferWriteWithNullTerminate [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
