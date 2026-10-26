## PlayerOpponentStateWriter_004c0cc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CareerStatsWriter (004c2420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005d284c | aPlayer | R | Str_UI_Player [DERIVED] |
| 005d2858 | aOpponent | R | String_Opponent [DERIVED] |
| 005d2864 | aS22d_0 | R | Str_S22D [DERIVED] |
| 005d2870 | aCurrentraceD | R | StringCurrentRaceD [DERIVED] |
| 005d2880 | aRaceoverD | R | RaceoverDFormat [DERIVED] |
| 005d2890 | aRacesessionD | R | RaceSessionString [DERIVED] |
| 005d28a0 | aSeasonstatusD | R | SeasonStatusString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0690 | SettingsIniFileWriter | [LLM] |
| 00566c30 | BufferWriteWithStringLengthCheck | [LLM] |
| 00566cf0 | ResourceLookupWithDualPath | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
