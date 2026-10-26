## ScoringClassificationDisplay_0041e320 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A08E0 (004a08e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00415550 | LinkedListIndexScannerWithValidation | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 0041f220 | ChampionshipPointsAccumulator | [LLM] |
| 0041f340 | sub_41F340 | [LLM] |
| 0041f5d0 | sub_41F5D0 | [LLM] |
| 0041f8a0 | ConstructorChampionshipClinchDetection | [LLM] |
| 00420820 | ConstructorStandingsParser | [LLM] |
| 00420cf0 | GdbSeasonSelector | [LLM] |
| 004c11d0 | FlagsGetter | [LLM] |
| 004c2850 | LinkedListDereference | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
