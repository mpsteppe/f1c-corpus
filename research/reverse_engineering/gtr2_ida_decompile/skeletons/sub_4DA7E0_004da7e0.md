## sub_4DA7E0_004da7e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10C | RW | 0 | [LLM] |
| this | 0x138 | RW | — | [LLM] |
| this | 0x13C | RW | — | [LLM] |
| this | 0x140 | RW | — | [LLM] |
| this | 0x14C | RW | — | [LLM] |
| this | 0x150 | RW | — | [LLM] |
| this | 0x154 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x10C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x138: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x13C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x140: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x150: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x154: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0071164c | aTabfontcolorro | R | [LLM] |
| 00711664 | aTabfontcolorse | R | [LLM] |
| 0071167c | aTabfontcolorno | R | [LLM] |
| 00711694 | aTabfontscale | R | [LLM] |
| 007116a4 | aTabspacevertic | R | [LLM] |
| 007116b8 | aTabspacehorizo | R | [LLM] |
| 007116cc | aTabheight | R | [LLM] |
| 007116d8 | aTabwidth | R | [LLM] |
| 007116e4 | aRolloverpulset | R | [LLM] |
| 007116f8 | aColorrolloverA | R | [LLM] |
| 0071170c | aColorselectedA | R | [LLM] |
| 00711720 | aColornotselect | R | [LLM] |
| 00711738 | aTexture | R | [LLM] |
| 00711740 | off_711740 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d38b0 | sub_4D38B0 | [LLM] |
| 004da070 | sub_4DA070 | [LLM] |
| 004da470 | sub_4DA470 | [LLM] |
| 00612eb0 | sub_612EB0 | [LLM] |
| 006131c0 | sub_6131C0 | [LLM] |
| 006133a0 | sub_6133A0 | [LLM] |
| 006134b0 | sub_6134B0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 006308d3 | j__free | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `TabFontColorRollover`
- `TabFontColorSelected`
- `TabFontColorNotSelected`
- `TabFontScale`
- `TabSpaceVertical`
- `TabSpaceHorizontal`
- `TabHeight`
- `TabWidth`
- `RolloverPulseTime`
- `ColorRollover_ARGB`
- `ColorSelected_ARGB`
- `ColorNotSelected_ARGB`
- `Texture`
- `Tab`
