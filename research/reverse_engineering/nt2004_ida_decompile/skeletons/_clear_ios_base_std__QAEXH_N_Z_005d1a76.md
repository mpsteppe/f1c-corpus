## ?clear@ios_base@std@@QAEXH_N@Z_005d1a76 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** unknown_libname_185 (005cff18), ?init@?$basic_ios@DU?$char_traits@D@std@@@std@@IAEXPAV?$basic_streambuf@DU?$char_traits@D@std@@@2@_N@Z (005d081d), ?init@?$basic_ios@GU?$char_traits@G@std@@@std@@IAEXPAV?$basic_streambuf@GU?$char_traits@G@std@@@2@_N@Z (005d1863), StructFieldInitWithConditionalCall [structural] (005d1dc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d4644 | loc_5D4644 | R | [LLM] |
| 005f7674 | ??_7failure@ios_base@std@@6B@ | R | [LLM] |
| 005f7680 | aIosEofbitSet | R | [LLM] |
| 005f7690 | aIosFailbitSet | R | [LLM] |
| 005f76a4 | Src | R | [LLM] |
| 005f9038 | __TI3?AVfailure@ios_base@std@@ | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005d07e1 | ReferenceCountDecrementWithConditionalFree [structural] | [LLM] |
| 005d0a47 | BufferWriteWithNullTerminate [structural] | [LLM] |
| 005d1b12 | sub_5D1B12 | [LLM] |
| 005d3159 | CxxThrowException8 [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `ios::eofbit set`
- `ios::failbit set`
- `ios::badbit set`
