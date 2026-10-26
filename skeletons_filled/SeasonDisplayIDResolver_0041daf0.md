## SeasonDisplayIDResolver_0041daf0 — SeasonResultsDisplayDispatcher

**Summary:** Sends season/championship results display messages (IDs 478-503) by iterating standings to find top entries, resolving display IDs via NamedEntryLookupInFormatList keyed by track database version files, and comparing best-lap vs scoring data.

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
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID and resolved display IDs |
| 00415230 | NamedEntryLookupInFormatList | Resolve display name/ID from format list using entrant name and path |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 0041e920 | BestLapEntrantFinder | Find entrant with best lap time from standings |
| 0041eb30 | ScoringSessionStatsAggregator | Get scoring statistics aggregator for session |
| 0041ed30 | CRTMathHelper | Compute CRT math values for comparison |
| 0041eda0 | ChampionshipScore | Check if entrant has championship score (non-zero) |
| 0041ef40 | ObjectComparisonWithTiebreak | Compare two standings objects with tiebreak, returning the higher-ranked |
| 00420490 | PositionChangeDetector | Detect and dispatch position change messages |
| 004c11d0 | FlagsGetter | Get session type flags from standings node |
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Read fixed offset value (offset 412 = used/active flag) from standings entry |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00588410 | sub_588410 | Compare/check file path against track database filename |

**Guard conditions:**
1. `dword_7D0308` (RaceActiveFlag) must be non-zero → PASSES: race active. BLOCKED: race inactive.
2. `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: track condition initialized. BLOCKED: track condition zero.
3. `FlagsGetter(node) == 1` (race session) AND `v3` (BestLapEntrantFinder result) is zero → BLOCKED: return early, no season display.
4. `FlagsGetter(node) != 1` AND field at node+45380 != 3 → BLOCKED: skip season branch, enters race-mode display logic.
5. In race-mode display: `v3 == 0` → BLOCKED: skip to PositionChangeDetector.
6. In season-mode (flags != 1, field==3): checks existence of best-lap entrant (v3) to determine single vs dual display messages.
