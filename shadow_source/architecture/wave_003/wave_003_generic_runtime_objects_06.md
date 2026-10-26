# StandingsAndScoring

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for wave_003_generic_runtime_objects_06: five defensible class families across the standings/scoring/display layer. ConstructorChampionshipScoring (DERIVED) groups constructor-championship evaluation (0x0041F8A0 clinch detection, 0x00420820 podium parse, 0x00420CF0 season GDB selection) on shared 14-constructor name-table, ChampionshipPointsAccumulator and driver-table emission evidence. RaceStandings (DERIVED, anchored by the packet's own DERIVED owner for DualStatusValidator) groups scene-name-keyed list scans over dword_7D2DB0. GameDictionary (DERIVED) owns the sorted string-table loader 0x00423890 with two DERIVED fields at this+4 (entry_count) and this+8 (entries_ptr). SeasonScoringController (GUESS) and DynamicManager (GUESS) carry the scoring gate/reset and restart handler. Interfaces capture the standings-list accessor set, display-entry builder, scene-name resolution and string-buffer utilities. Trust stays at DERIVED/GUESS; no CONFIRMED claims. Contradictions and unresolved semantics (status value 10/6 meanings, offset 408/412/416 record layout, season indices, display ids, aRb/aSS globals, field:this:0x00000000) are recorded, not resolved.

## Function roles

- `0x0041F8A0` **ConstructorChampionshipScoring** — Constructor championship clinch predicate: resolves the input team against the 14-constructor name table, then verifies it leads all 13 rivals in cumulative points at every scoring-category prefix; returns 1 only when mathematically clinched.
- `0x0041FB10` **RaceStandings** — Standings entrant validation: locates a named entrant by season-resolved scene name and requires both status values 10 and 6 at the rank-derived status offset; returns true only when both were observed.
- `0x0041FC60` **RaceStandings** — Session-state search: scans the current-session list and then each active entity for a scene whose state table at byte offset 216 contains value 10; returns 1 when found.
- `0x0041FE00` **RaceStandings** — Config-section search: walks the section table backwards looking for the first section whose type tag equals 10 and whose season/season name matches the target; returns the matching section index or 0.
- `0x0041FF10` **RaceStandings** — Scene-element scan: finds an element whose season-resolved scene name matches and whose per-index dword field at offset 212 + 4*v2 equals 10; head element fast-path then active-element loop.
- `0x004203F0` **RaceStandings** — Session timing anomaly check: fetches two entrant records via BestLapEntrantFinder, derives a value from record fields and list flags/scene order, and returns a sentinel-initialized structure when the value lands in a small threshold window.
- `0x00420490` **RaceStandings** — Standings position-change dispatch: locates the entries holding positions 1 and 2 by the offset-412 field, suppresses dispatch on ties via the offset-408 shared-value test, and emits driver-table message 397 when the dispatch flag is set.
- `0x00420820` **ConstructorChampionshipScoring** — Constructor standings podium parse: accumulates championship points for the 14 teams, selects the top three with tie detection, emits the podium team names, and builds driver-table display entries (ids 423/424/488) when enabled.
- `0x00420CF0` **ConstructorChampionshipScoring** — Season GDB selector: chooses the constructor with the most active drivers (tie-broken), probes the season path against four season GDB filenames, and fills/publishes a driver-table record for the selected season.
- `0x004212E0` **RaceStandings** — Summed-field helper: sums the dword field at entity offset 416 for every active entity whose season-resolved scene name matches the receiver.
- `0x00421380` **RaceStandings** — Entity-state counter: counts active entities whose scene matches the receiver and whose state dword at offset 216 equals 10, via a nested active-entity/flag-array walk.
- `0x00423890` **GameDictionary** — Game dictionary loader: builds the dictionary path, parses quoted key/value lines, inserts pairs into the sorted string table owned by this, sorts it, and reports a missing locale string; returns the inserted-pair count.
- `0x0042BC10` **SeasonScoringController** — Session scoring gate: returns true only while global dword_7D2E44 is zero and SessionStateCheck on the session object at dword_7CD25C does not return 1; reused as a shared scoring predicate across 11 callers.
- `0x0042BD60` **SeasonScoringController** — Season scoring reset: clears the global init flag, then loops the vehicle array setting team IDs and calling SessionStateTransition(-1, 0) per slot; returns the last transition result.
- `0x0042C3B0` **DynamicManager** — Dynamic-management restart: processes a build path, writes a debug entry, resets timer/session counters, reloads AI settings, forces per-vehicle render updates, runs a batch entity process, and resyncs the current player vehicle index and pointer.

## Proposed classes

### ConstructorChampionshipScoring

Evaluate constructor championship standings: detect a mathematically clinched constructor championship, parse the constructor podium from accumulated points with tie detection, and select the season GDB for the leading constructor; emits driver-table display entries when enabled.

Methods: `0x0041F8A0`, `0x00420820`, `0x00420CF0`


### RaceStandings

Standings/scene-element list access over the mutable list at dword_7D2DB0: scene-name-keyed scans for entrant status validation, session-state search, config-section and scene-element lookup, position-change dispatch, summed-field accumulation and entity-state counting.

Methods: `0x0041FB10`, `0x0041FC60`, `0x0041FE00`, `0x0041FF10`, `0x004203F0`, `0x00420490`, `0x004212E0`, `0x00421380`


### GameDictionary

Sorted string-table dictionary loader: parse quoted key/value pairs from a dictionary file line by line, insert accepted pairs, sort the table, and verify presence of the locale string.

Methods: `0x00423890`

- `this+0x00000004` `int32 entry_count` (read, DERIVED)
- `this+0x00000008` `pointer entries_ptr` (read, DERIVED)

### SeasonScoringController

Gate and reset session scoring state: shared predicate that decides whether scoring may proceed, and the per-slot season scoring reset over the vehicle array.

Methods: `0x0042BC10`, `0x0042BD60`


### DynamicManager

Dynamic-management layer restart handler: reset session counters, reload AI settings, force render updates, run batch entity processing, and resync the current vehicle pointer.

Methods: `0x0042C3B0`


## Compatibility contracts

- **StandingsListContract** — dword_7D2DB0 is a mutable linked-list wrapper that every consumer re-dereferences on each use; the active-entity count and list pointer can change between iterations. A replacement must treat the list head as non-cacheable across scans and must keep the head/index accessor split (FixedOffsetReturn vs ShortComputation_13a0) observed here.
- **DriverTableDisplayEntryContract** — Display entries are sentinel-initialized (StructInitWithSentinelValues with -1/-1/-2.0/-2.0 sentinels), resolved against the format list dword_5EA5E8, filled via DriverDataTableLookupAndTimeConversion with message ids 397/423/424/488 (and season ids 492/496/500/504), then published through InsertDriverTableEntry into the table anchored at flt_5EA618.
- **ConstructorNameTableContract** — Fourteen constructor names (Arrows..Stewart) live in string globals 0x005C25B4..0x005C2620 and are selected by per-index jump tables (0x0041FAA0/0x0041FAD8, 0x00420C44/0x00420C7C/0x00420CB4, 0x00421200/0x00421238/0x00421270/0x004212A8). Index 0..13 is the team identity used by ChampionshipPointsAccumulator and by the season GDB selection.
- **SeasonGdbSelectionContract** — Season GDB selection probes the season path global dword_7D0434 against four season filename literals (0x005BF970..0x005BF994) in order via sub_588410 and maps a hit to a driver-table season index (492/496/500/504); byte_5EA438 is the empty/fallback string across name lookups.

## Unresolved

- Status values 10 and 6 at entrant status offsets 212/216 and the session-state-table meaning are not recoverable from this packet; the counted value 10 is an enum-like literal with unknown semantics.
- RaceStandings membership of 0x004203F0 (SessionTimingAnomalyDetect) is GUESS; its entrant-record layout (threshold at element index 102, base at byte offset 408) and the result formula v5 + 10 * (sceneOrder - flags) are unresolved.
- The offset-408 shared-value discriminator (tie detection) and offset-412 position field in PositionChangeDetector are DERIVED from comparison logic only; the standings entry structure is not identified.
- The 8-byte working object (obj[0]=0, obj[1]=-1) allocated by GdbSeasonSelector and the season indices 492/496/500/504 and display ids 397/423/424/488 are passed verbatim without derived semantics.
- callee:0x00587BCF (FreeWrapper_7bcf) is listed as a callee by static facts but does not appear in the raw decompiled bodies of 0x0041F8A0 and 0x00420820; its cleanup role is inferred, not verified.
- Globals aRb (0x005BE828) and aSS (0x005BE860) are not named in the raw decompilation; they are likely file-open mode and path format constants consumed inside the callee chain.
- dword_7D2DB0 is described as standings list, scene-element list and config-section list across functions; whether these are one shared mutable list or several distinct lists is unresolved.
- field:this:0x00000000 (referenced by GdbSeasonSelector with LinkedListIndexScannerWithValidation) has no named meaning and is not assigned to a class field.
- The fixed count 16 passed to the table sort (sub_5890AA) and the byte_5EA438 seed semantics in LoadGameDictionaryFile are unresolved.
- ABI module classification Memory_Allocation (LEGACY) for 0x0041FB10 does not match the standings-oriented behavior and is treated as an unverified label.
- sub_4C2990's contract (count vs rank-derived index) and the exact comparison semantics of sub_566810 and sub_588410 are not proven by this packet.
