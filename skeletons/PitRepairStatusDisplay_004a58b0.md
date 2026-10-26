## PitRepairStatusDisplay_004a58b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F1C0 (0049f1c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4074 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x17C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea40 | dbl_59EA40 | R | SuspensionSpringK [DERIVED] |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c3810 | off_5C3810 | R | OffsetTable_5C3810 [DERIVED] |
| 005c6e14 | off_5C6E14 | R | VtablePtr_5C6E14 [DERIVED] |
| 005c6e18 | unk_5C6E18 | R | Unk_StringConstant [DERIVED] |
| 005ccea4 | off_5CCEA4 | R | GameWidgetVTable_5CCEA4 [DERIVED] |
| 005cd62c | aSD_0 | R | Str_SD [DERIVED] |
| 005cd634 | aDoNotRepair | R | DoNotRepairString [DERIVED] |
| 005cd644 | aRepair | R | RepairString [DERIVED] |
| 005cd64c | aDD_3 | R | DDStr [DERIVED] |
| 005cd658 | aDD_2 | R | DDString [DERIVED] |
| 005cd664 | aNoChange | R | NoChangeField [DERIVED] |
| 005cd670 | aDS_6 | R | FormatDS_6 [DERIVED] |
| 005cd678 | a41fS | R | String_41fS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007d0450 | dword_7D0450 | R | CostDisplayMode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004a5820 | NthValidPartLookup | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | == | 1 | [LLM] |
| this | 0x128 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
