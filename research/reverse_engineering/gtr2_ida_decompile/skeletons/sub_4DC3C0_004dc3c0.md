## sub_4DC3C0_004dc3c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DC3C0 (004dc3c0), sub_4DCE40 (004dce40), sub_4DD1F0 (004dd1f0), sub_4DD510 (004dd510)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | R | — | [LLM] |
| this | 0x2FE | R | — | [LLM] |
| this | 0x300 | R | — | [LLM] |
| this | 0x308 | R | — | [LLM] |
| this | 0x30C | R | — | [LLM] |
| this | 0x310 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | [LLM] |
| 006f5d1c | aPosition | R | [LLM] |
| 00711868 | aCustomdata | R | [LLM] |
| 00712824 | asc_712824 | R | [LLM] |
| 007128cc | aPosWH | R | [LLM] |
| 00712b64 | aFriendgizmo | R | [LLM] |
| 00712b70 | aAttributeset | R | [LLM] |
| 00712b80 | aActions | R | [LLM] |
| 00712b88 | aChild | R | [LLM] |
| 00712b90 | aCaption3 | R | [LLM] |
| 00712b9c | aCaption2 | R | [LLM] |
| 00712ba8 | aTooltipfontcol | R | [LLM] |
| 00712bc0 | aTooltipfontsca | R | [LLM] |
| 00712bd4 | aTooltipfont | R | [LLM] |
| 00712be0 | aTooltiptextjus | R | [LLM] |
| 00712bfc | aNone | R | [LLM] |
| 00712c04 | aTooltipbgmap | R | [LLM] |
| 00712c14 | aTooltipbgcolor | R | [LLM] |
| 00712c28 | aTooltip3 | R | [LLM] |
| 00712c34 | aTooltip2 | R | [LLM] |
| 00712c40 | aTooltip | R | [LLM] |
| 00712c48 | aCaption1 | R | [LLM] |
| 00712c54 | aOffset | R | [LLM] |
| 00712c5c | aPos2Offset | R | [LLM] |
| 00712c68 | aWidthHeight | R | [LLM] |
| 00712c78 | aName | R | [LLM] |
| 00712c80 | aUndefinedGizmo | R | [LLM] |
| 00712c98 | aNullGizmonameP | R | [LLM] |
| 0075ad58 | unk_75AD58 | R | [LLM] |
| 0075af70 | byte_75AF70 | R | [LLM] |
| 00b6e1a0 | String1 | R | [LLM] |
| 016c96b0 | off_16C96B0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd2a0 | sub_4CD2A0 | [LLM] |
| 004cd360 | sub_4CD360 | [LLM] |
| 004d3c70 | sub_4D3C70 | [LLM] |
| 004dac90 | sub_4DAC90 | [LLM] |
| 004dad10 | sub_4DAD10 | [LLM] |
| 004dada0 | sub_4DADA0 | [LLM] |
| 004dbb40 | sub_4DBB40 | [LLM] |
| 004dbcd0 | sub_4DBCD0 | [LLM] |
| 004dbe00 | sub_4DBE00 | [LLM] |
| 004dc3c0 | sub_4DC3C0 | [LLM] |
| 004e2a80 | ShortComputation_a9c0 [exact] | [LLM] |
| 004e2af0 | OffsetAccumulator [exact] | [LLM] |
| 004e2b30 | PositionUpdate [exact] | [LLM] |
| 004e2b70 | sub_4E2B70 | [LLM] |
| 004e3af0 | sub_4E3AF0 | [LLM] |
| 004e3ee0 | sub_4E3EE0 | [LLM] |
| 006131c0 | sub_6131C0 | [LLM] |
| 006133a0 | sub_6133A0 | [LLM] |
| 006134b0 | sub_6134B0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00616480 | sub_616480 | [LLM] |
| 0063099c | __ftol2 | [LLM] |
| 00630a80 | _strstr | [LLM] |
| 00631761 | _sprintf | [LLM] |
| 00631c0d | __stricmp | [LLM] |
| 00633686 | __strupr | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x300 | < | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `POSITION`
- `CUSTOMDATA`
- `POS-W-H`
- `FRIENDGIZMO`
- `ATTRIBUTESET`
- `ACTIONS`
- `CHILD`
- `CAPTION3`
- `CAPTION2`
- `ToolTipFontColorARGB`
- `ToolTipFontScale`
- `ToolTipFont`
- `ToolTipTextJustification`
- `none`
- `ToolTipBGMap`
- `ToolTipBGColorARGB`
- `TOOLTIP3`
- `TOOLTIP2`
- `TOOLTIP`
- `CAPTION1`
- … +6 more
