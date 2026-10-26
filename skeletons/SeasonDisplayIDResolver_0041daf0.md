## SeasonDisplayIDResolver_0041daf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0760 (004a0760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005bf970 | aF12002Gdb | R | TrackDbFileName [DERIVED] |
| 005bf97c | aF12001Gdb | R | aF12001Gdb [DERIVED] |
| 005bf988 | aF12000Gdb | R | TrackDatabaseFilename [DERIVED] |
| 005bf994 | aF11999Gdb | R | aF11999Gdb [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | [LLM] |
| 004144f0 | DriverDataTableLookupAndTimeConversion | [LLM] |
| 00415230 | NamedEntryLookupInFormatList | [LLM] |
| 00418560 | InsertDriverTableEntry | [LLM] |
| 0041e920 | BestLapEntrantFinder | [LLM] |
| 0041eb30 | ScoringSessionStatsAggregator | [LLM] |
| 0041ed30 | CRTMathHelper | [LLM] |
| 0041eda0 | ChampionshipScore | [LLM] |
| 0041ef40 | ObjectComparisonWithTiebreak | [LLM] |
| 00420490 | PositionChangeDetector | [LLM] |
| 004c11d0 | FlagsGetter | [LLM] |
| 004c1370 | ActiveEntityCounter | [LLM] |
| 004c1390 | FixedOffsetReturn | [LLM] |
| 004c13a0 | ShortComputation_13a0 | [LLM] |
| 004c2850 | LinkedListDereference | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
