## sub_5AB3E0_005ab3e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** SceneRenderTransform [structural] (0059a9f0), sub_5AE610 (005ae610)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1160)+0x0) | 0x94 | R | — | [LLM] |
| *(*(this+0x1160)+0x0) | 0xC8 | R | — | [LLM] |
| *(*(this+0x1160)+0x0) | 0xFC | R | — | [LLM] |
| *(*(this+0x1160)+0x0) | 0x118 | R | — | [LLM] |
| *(*(this+0x1160)+0x0) | 0x11C | R | — | [LLM] |
| *(*(this+0x1160)+0x0) | 0x154 | R | — | [LLM] |
| *(this+0x1160) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1160 | R | — | [LLM] |
| this | 0x1408 | R | — | [LLM] |
| this | 0x1410 | R | — | [LLM] |
| this | 0x1428 | RW | 1 | [LLM] |
| this | 0x142C | RW | — | [LLM] |
| this | 0x1430 | RW | 0 | [LLM] |
| this | 0x1434 | R | — | [LLM] |
| this | 0x215C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1428: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x142C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1430: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac028 | jpt_5AB57D | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |
| 005d5ed0 | flt_5D5ED0 | R | [LLM] |
| 005d6498 | flt_5D6498 | R | [LLM] |
| 005f6548 | flt_5F6548 | R | [LLM] |
| 0061bbc8 | unk_61BBC8 | R | [LLM] |
| 0061bbf8 | flt_61BBF8 | W | [LLM] |
| 0061bbfc | flt_61BBFC | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054992b | sub_54992B | [LLM] |
| 005932c0 | sub_5932C0 | [LLM] |
| 00593d20 | sub_593D20 | [LLM] |
| 00593e40 | TwoFieldGetter [exact] | [LLM] |
| 00593ef0 | DoubleFieldGetter [exact] | [LLM] |
| 0059e670 | sub_59E670 | [LLM] |
| 005a2870 | sub_5A2870 | [LLM] |
| 005a9f40 | StructInitWithDefaultValues [exact] | [LLM] |
| 005aa130 | sub_5AA130 | [LLM] |
| 005aa830 | sub_5AA830 | [LLM] |
| 005aa8a0 | sub_5AA8A0 | [LLM] |
| 005aa930 | sub_5AA930 | [LLM] |
| 005aacc0 | sub_5AACC0 | [LLM] |
| 005aad80 | sub_5AAD80 | [LLM] |
| 005ab250 | sub_5AB250 | [LLM] |
| 005ac380 | sub_5AC380 | [LLM] |
| 005b4be0 | sub_5B4BE0 | [LLM] |
| 005b5dc0 | sub_5B5DC0 | [LLM] |
| 005b8990 | sub_5B8990 | [LLM] |
| 005b8c10 | sub_5B8C10 | [LLM] |
| 005be8bc | __ftol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1428 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
