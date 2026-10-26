## sub_4DA9E0_004da9e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c3310 | aD063f | R | StrD063F [DERIVED] |
| 005c3778 | aDS | R | aDS [DERIVED] |
| 005cce6c | aLaps_0 | R | sLaps [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae8 | byte_5D4AE8 | R | PositionNameSuffix [DERIVED] |
| 005d4b74 | a3f | R | Format3fString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0049b630 | SpatialGridCell | [LLM] |
| 004d7e40 | UITextRenderWithScale | [LLM] |
| 004dac30 | SizeOffsetTableByMode | [LLM] |
| 004dad30 | SingleFunctionCallWrapper_ad30 | [LLM] |
| 004dad50 | ArithmeticComparison_ad50 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
