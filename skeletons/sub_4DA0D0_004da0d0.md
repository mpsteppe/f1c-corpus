## sub_4DA0D0_004da0d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D9F80 (004d9f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x4060 | R | — | [LLM] |
| *(this+0x1C) | 0x46F8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf60 | flt_5ACF60 | R | TextColorDefault [DERIVED] |
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae8 | byte_5D4AE8 | R | PositionNameSuffix [DERIVED] |
| 005d4af0 | byte_5D4AF0 | R | [LLM] |
| 005d4af1 | byte_5D4AF1 | R | [LLM] |
| 005d4af4 | dword_5D4AF4 | R | [LLM] |
| 005d4b40 | a63f | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7e40 | UITextRenderWithScale | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
