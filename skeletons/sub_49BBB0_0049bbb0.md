## sub_49BBB0_0049bbb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualTextDisplay (0049e410), MultiLayerTextStringRenderer (004dbc90), DoubleRenderPass (004dc1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ccc0c | flt_5CCC0C | R | Unknown_Float_5CCC0C [DERIVED] |
| 005cce18 | asc_5CCE18 | R | Unknown_String5CCE18 [DERIVED] |
| 005cce24 | a2d063f_1 | R | Unknown_String5CCE24 [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b630 | SpatialGridCell | [LLM] |
| 004bc2a0 | ArithmeticComparison_c2a0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
