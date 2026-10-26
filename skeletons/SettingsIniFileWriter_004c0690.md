## SettingsIniFileWriter_004c0690 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerOpponentStateWriter (004c0cc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005d2720 | aActiveD | R | String_Active [DERIVED] |
| 005d272c | aControltypeD | R | ControlTypeDString [DERIVED] |
| 005d273c | aCurrentgridpos_0 | R | CurrentGridposString [DERIVED] |
| 005d2754 | aOriginalgridpo_0 | R | OriginalGridPositionString [DERIVED] |
| 005d2770 | aPolestakenD | R | String_PolesTakenD [DERIVED] |
| 005d2780 | aPointsposition_0 | R | PointsPositionFormat [DERIVED] |
| 005d2794 | aSeasonpointsD | R | SeasonPointsD [DERIVED] |
| 005d27a8 | aFinishpoints22 | R | FinishPointsFormatString [DERIVED] |
| 005d27c0 | aFinishposition_0 | R | FinishPositionFormat [DERIVED] |
| 005d27d8 | aRcdfileS | R | RCDFileString [DERIVED] |
| 005d27e8 | aVehfileS | R | VehfileSString [DERIVED] |
| 005d27f8 | aNameS | R | Str_NameS [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566c30 | BufferWriteWithStringLengthCheck | [LLM] |
| 00566cf0 | ResourceLookupWithDualPath | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x18 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
