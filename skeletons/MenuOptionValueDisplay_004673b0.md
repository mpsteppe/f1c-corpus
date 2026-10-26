## MenuOptionValueDisplay_004673b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IndexedCallWith1Increment (00467340)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x320 | R | — | [LLM] |
| this | 0x324 | R | — | [LLM] |
| this | 0x328 | R | — | [LLM] |
| this | 0x32C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c56c0 | byte_7C56C0 | R | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042f2f0 | SetupValueFormatDispatcher | [LLM] |
| 0042f470 | VehicleSetupValueFormatter | [LLM] |
| 00467430 | StringCompareAndConditionalReplace | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
