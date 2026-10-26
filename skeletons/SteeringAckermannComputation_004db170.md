## SteeringAckermannComputation_004db170 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 005acee4 | flt_5ACEE4 | R | G6B5ScaleFactor [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4aec | byte_5D4AEC | R | DefaultTextColor [DERIVED] (also: ` — frame counter value) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408490 | ShortComputation_8490 | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004b9a00 | PackedFlagRead_9a00 | [LLM] |
| 004b9a10 | sub_4B9A10 | [LLM] |
| 004d7e40 | UITextRenderWithScale | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
