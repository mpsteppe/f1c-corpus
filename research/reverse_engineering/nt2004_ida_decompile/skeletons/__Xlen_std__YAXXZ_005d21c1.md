## ?_Xlen@std@@YAXXZ_005d21c1 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAEAAV12@ID@Z (005d0721), ?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AAE_NI_N@Z (005d0992)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d472c | loc_5D472C | R | [LLM] |
| 005f76e8 | ??_7length_error@std@@6B@ | R | [LLM] |
| 005f76f4 | aStringTooLong | R | [LLM] |
| 005f9260 | __TI3?AVlength_error@std@@ | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005c5210 | _strlen | [LLM] |
| 005d07e1 | ReferenceCountDecrementWithConditionalFree [structural] | [LLM] |
| 005d0a47 | BufferWriteWithNullTerminate [structural] | [LLM] |
| 005d221b | sub_5D221B | [LLM] |
| 005d3159 | CxxThrowException8 [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `string too long`
