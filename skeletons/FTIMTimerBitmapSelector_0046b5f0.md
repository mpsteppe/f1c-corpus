## FTIMTimerBitmapSelector_0046b5f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_46BA20 (0046ba20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c692c | word_5C692C | R | PathDelimiterChar [DERIVED] |
| 005c6a28 | aFtim14redoutli | R | StrCrashOutline [DERIVED] |
| 005c6a40 | aFtim14greenout | R | FTim14GreenOutString [DERIVED] |
| 005c6a58 | aFtim14greyoutl | R | Str_FTImg14GreyOutL [DERIVED] |
| 005c6a70 | aDS_4 | R | DS4Field [DERIVED] |
| 005c6a78 | asc_5C6A78 | R | UI_ASCString [DERIVED] |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bdd0 | sub_42BDD0 | [LLM] |
| 0046b830 | sub_46B830 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x17C | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
