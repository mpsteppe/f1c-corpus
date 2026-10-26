## ScoringClassificationDisplay_0041e320 — ClassificationStandingsDisplay

**Summary:** Dispatches scoring classification display messages (IDs 427, 483-487) by resolving driver and constructor standings entries, comparing championship points differences between them, and handling race-session, season, and constructor-clinch scenarios.

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
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID and resolved display IDs |
| 00415550 | LinkedListIndexScannerWithValidation | Resolve format-list index for a display name |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 0041f220 | ChampionshipPointsAccumulator | Compute championship points for an entrant |
| 0041f340 | sub_41F340 | Allocate/resolve driver classification entry by name |
| 0041f5d0 | sub_41F5D0 | Allocate/resolve constructor classification entry by name |
| 0041f8a0 | ConstructorChampionshipClinchDetection | Check if constructor has mathematically clinched championship |
| 00420820 | ConstructorStandingsParser | Process/resolve constructor standings |
| 00420cf0 | GdbSeasonSelector | Handle season-specific display logic (season mode) |
| 004c11d0 | FlagsGetter | Get session type flags from standings node |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory for classification entries |
| 00588410 | sub_588410 | Compare two name strings |

**Guard conditions:**
1. `dword_7D0308` (RaceActiveFlag) must be non-zero AND `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: proceed. BLOCKED: early return if race inactive OR track condition zero.
2. `FlagsGetter(node) == 1` (race session): if `v7` (driver entry) is null → BLOCKED: return. Otherwise message 483.
3. Node+45380 == 3 (season mode): delegates to GdbSeasonSelector → skips classification logic.
4. `v7` exists AND `v9` (constructor entry) is null → try to get v9; if still null → message 483.
5. Both `v7` and `v9` exist but names match (same team): checks ConstructorChampionshipClinchDetection → clinched: message 484; not clinched: message 483.
6. Both exist and names differ: with both sub-entries (drivers + constructors) → compute point differences → messages 485/486/487. Without sub-entries → message 486.
