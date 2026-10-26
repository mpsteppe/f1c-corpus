## sub_4BBA90_004bba90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A5EA0 (004a5ea0), sub_4A5F20 (004a5f20), sub_4BCCC0 (004bccc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0xA4 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xA4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d30 | aSS_2 | R | Str_DriverSettingsSuffix [DERIVED] |
| 005d2548 | aPenalty | R | String_Penalty [DERIVED] |
| 005d2554 | aSDS | R | FormatPctS [DERIVED] |
| 005d255c | aFinedUs | R | FinedUs [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007d0b10 | byte_7D0B10 | R | Unknown_Byte_7D0B10 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
