## StartingGridUIDraw_004d9420 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf64 | flt_5ACF64 | R | DisplayYSpacing [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4aef | byte_5D4AEF | R | ByteGearPosDisplay [DERIVED] |
| 005d4b00 | aGrid_0 | R | GridString [DERIVED] |
| 005d4b08 | aStarting | R | String_Starting [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004d7e40 | UITextRenderWithScale | [LLM] |
| 004d95d0 | sub_4D95D0 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
