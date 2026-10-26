# SessionStandingsRuntime

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED grouping of 18 validated IR functions that share two runtime objects. (1) The session-event emitters guard on dword_7D0308 (race active) and flt_7CF3C8 (track condition), build a driver-data record (message id, driver indices, position, timing parameters, sentinel -1 / -2.0 defaults) and commit it to the driver-data table at flt_5EA618. This family covers fixed event 337, standings/championship status, position-based status, the full race-commentary dispatcher, season-result messages 478-503, and scoring classification 427/483-487. (2) The standings/scoring helpers query the race standings sort list at dword_7D2DB0: best-lap/offset-408 key scans, composite and championship score computations, name-keyed point accumulation, constructor-team selection, and a family of null-guarded predicates over entry fields. Owner identity is almost entirely UNKNOWN in the packet; only RaceCommentarySystem is a named owner, and only offset 0x198 carries a dedicated field evidence reference. Contradiction kept explicit: equal offsets +408/+412 appear on standings entries under different bases, and flt_59E440 / flt_59E670 are listed as referenced globals but never appear in raw source.

## Function roles

- `0x0041C3E0` **SessionEventDispatcher** — Emits fixed session-event message 337 into the driver-data table when the race-active guard (dword_7D0308 non-zero, flt_7CF3C8 non-zero) passes; record populated via DriverDataTableLookupAndTimeConversion and committed via InsertDriverTableEntry.
- `0x0041C440` **SessionEventDispatcher** — Dispatches a standings/championship-status event: computes a driver index only in championship mode 4 (sub_4C2990 result plus one over dword_7D2DB0, else -1), derives a message id via sub_420000, populates and commits the record.
- `0x0041C4C0` **SessionEventDispatcher** — Dispatches a position-based race-status event: computes standings position plus two via sub_4C2990, selects live (-1.0/0.0) vs sentinel (-2.0/-2.0) timing parameters from boolean a1, derives a message id via 0x004203D0, populates and commits the record.
- `0x0041D630` **RaceCommentarySystem** — Race commentary dispatcher: matches the active track-configuration name (dword_8AC490 + 396*dword_8AC48C, name at +260) against 17 track literals to pick a track-intro commentary id, scans vehicle-slot pointers dword_7C54F0 for retirements and the best-lap car, emits player-relative position-change commentary (459/460/461/397) and a wrap-up commentary (454/455/456/476), each record committed to the driver-data table.
- `0x0041DAF0` **StandingsDisplayDispatcher** — Resolves and emits season/championship result display messages (478-503) and leader/best-lap messages (479/480/481/397): selects season vs race-session mode from node flags and the offset-45380 season selector, picks the message by which track-database version files exist (sub_588410 against aF11999Gdb..aF12002Gdb), resolves entrant display ids through NamedEntryLookupInFormatList against dword_5EA5E8 (byte_5EA438 null fallback), and finalizes with InsertDriverTableEntry plus PositionChangeDetector.
- `0x0041E320` **StandingsDisplayDispatcher** — Computes and dispatches scoring-classification display messages (427, 483-487): resolves driver and constructor classification entries via sub_41F340 / sub_41F5D0, selects the message by session flags, the offset-45380 season selector, driver/constructor name equality, and championship-point deltas (485/486/487) or constructor clinch (484), then inserts the record and parses constructor standings; allocated entries freed via 0x00587BCF.
- `0x0041E840` **RaceStandingsNode** — Null-guarded accessor that dereferences the standings list at dword_7D2DB0 and reads the dword at +408 of a standings-derived object (via FixedOffsetReturn); returns 0 at either null guard.
- `0x0041E920` **RaceStandingsNode** — Scans standings entries and returns the entry with the highest value at offset 408, optionally name-filtered via sub_588410; strict mode (a2==0) returns 0 if the best value is duplicated, including by the first entry.
- `0x0041ED30` **ChampionshipScoring** — Computes a composite score by summing a named entrant's scoring values across all but the first category from the standings node; returns -1 when the node is absent, fewer than two categories exist, or no matching entry is found.
- `0x0041EDA0` **ChampionshipScoring** — Determines whether the given standings entry leads or ties the cumulative championship total at any scoring-category prefix, accumulating per-slot running totals via IndexedFieldGetter; returns 1 on any lead/tic, else 0. Used by SeasonDisplayIDResolver as the championship-score gate.
- `0x0041EFE0` **RaceStandingsNode** — Counts dword entries in a caller-provided array at a1+24 that equal the value a2, bounded by the standings node count read via FlagsGetter; returns 0 when the node is absent or the count is not greater than 0.
- `0x0041F070` **RaceStandingsNode** — Performance-gap predicate: returns whether this standings entry's offset-0x198 key exceeds the maximum key of every other active entry by at least 10.
- `0x0041F100` **RaceStandingsNode** — Predicate returning true only when this is non-null, the standings node count v3 >= 3, and the three consecutive indexed dword fields this[v3+52..54] all equal the literal 10.
- `0x0041F150` **RaceStandingsNode** — Predicate returning true only when this is non-null, the standings node count v3 > 0, and the indexed field this[v3+5] is at most 4.
- `0x0041F190` **RaceStandingsNode** — Validates a standings entry: returns the AND of the base validity flag ShortComputation_f1e0(this) and a category-dependent condition (entry valid when category count is exactly 2, or greater than 2 and this[v3+51] != sentinel 10).
- `0x0041F1E0` **RaceStandingsNode** — Predicate returning true only when this is non-null, the standings node count v3 >= 2, and the two consecutive indexed dword fields this[v3+4] and this[v3+5] both equal the literal 1.
- `0x0041F220` **ChampionshipScoring** — Accumulates championship points for a named entrant across a category count by summing IndexedFieldGetter(entry, i) over every active standings entry whose resolved scene name matches the input name; null name returns -1, category count -1 delegates to the total-points lookup sub_4C13C0.
- `0x0041F5D0` **ChampionshipScoring** — Iterates the 14 constructor team names over the standings node and returns the team with the highest championship-points total (ChampionshipPointsAccumulator at categories-1), optionally excluding a named team; allocates an 8-byte [name, score] pair and optionally re-scans to confirm the winner by name.

## Proposed classes

### DriverDataRecord

Local driver-table-entry record buffer: initialized by StructInitWithSentinelValues and populated by DriverDataTableLookupAndTimeConversion with a message id, driver indices, position, and timing parameters (defaults -1 / -2.0), then committed to the DriverDataTable. Field offsets are not observable in this packet; the record is treated as an opaque stack buffer.

Methods: 


### DriverDataTable

Shared session event / driver-data table anchored at flt_5EA618; records are appended via InsertDriverTableEntry. No member offsets are observable in this packet.

Methods: 


### SessionEventDispatcher

Guarded session-event message emitters that build a DriverDataRecord and commit it to the DriverDataTable: fixed event 337, standings/championship-status, and position-based race-status. All gate on dword_7D0308 and flt_7CF3C8. Packet owner is UnknownObject; this class is a semantic grouping (GUESS).

Methods: `0x0041C3E0`, `0x0041C440`, `0x0041C4C0`


### RaceCommentarySystem

Race commentary dispatch: emits track-intro, player-relative position-change, and wrap-up commentary records into the DriverDataTable, driven by the active track-configuration name and vehicle-slot states. The only function in the packet with a named owner.

Methods: `0x0041D630`


### StandingsDisplayDispatcher

Standings-derived display dispatch: resolves and emits season-result messages (478-503), scoring-classification messages (427, 483-487), and leader/best-lap messages by resolving entrant display ids from the format list dword_5EA5E8 and committing records to the DriverDataTable. Packet owner is UnknownObject; semantic grouping (GUESS).

Methods: `0x0041DAF0`, `0x0041E320`


### RaceStandingsNode

Shared race standings / sort list rooted at dword_7D2DB0: exposes a dereference-able node (LinkedListDereference), a base entry (FixedOffsetReturn) and indexed entries (ShortComputation_13a0), plus per-entry sort keys at +0x198, an active flag at +0x19C, and a season-mode selector at +0xB144 on the node. Owns the query/accessor/predicate helpers whose packet owner is UnknownObject; the accessor-callee identities (0x004C2850/0x004C11D0/0x004C1370/0x004C1390/0x004C13A0) are DERIVED from usage.

Methods: `0x0041E840`, `0x0041E920`, `0x0041EFE0`, `0x0041F070`, `0x0041F100`, `0x0041F150`, `0x0041F190`, `0x0041F1E0`

- `this+0x00000198` `int sort_key` (read, DERIVED)

### ChampionshipScoring

Championship scoring computations over the standings entries: per-entrant composite totals (0x0041ED30), championship lead tests (0x0041EDA0), name-keyed point accumulation (0x0041F220), and top-constructor-team selection (0x0041F5D0). Packet owner is UnknownObject; semantic grouping (GUESS).

Methods: `0x0041ED30`, `0x0041EDA0`, `0x0041F220`, `0x0041F5D0`


## Compatibility contracts

- **DriverDataTableCommit** — Session event messages are committed as records into the table anchored at 0x005EA618 via InsertDriverTableEntry (0x00418560). A replacement executable must preserve the record-building convention: StructInitWithSentinelValues (0x004144D0) then DriverDataTableLookupAndTimeConversion (0x004144F0) with message id, driver/position indices (default -1) and timing parameters (default -2.0).
- **RaceActiveEventGuard** — Every emitter in this scope runs only when dword_7D0308 (race active) is non-zero AND flt_7CF3C8 (track condition) is non-zero; otherwise the dispatch is skipped. A replacement must honor the same gating or reproduce equivalent event-suppression behavior.
- **StandingsListLayout** — The standings object at dword_7D2DB0 dereferences to a node exposing a base entry and indexed entries. Entry offset 0x198 is an int sort key used for best/performance comparisons; entry offset 0x19C non-zero marks an active entry; node offset 0xB144 equal to 3 selects season mode (vs race-session mode selected by node session flags equal to 1). Offsets GUESS/DERIVED from usage, not struct-confirmed.
- **SessionEventMessageIdSpace** — Distinct message-id families are used: 337 (fixed event), 397 (generic position change), 427 (classification fallback), 447-476 (race commentary, including track-intro 447-473 by track name and wrap-up 454/455/456/476), 478-503 (season results), 479/480/481 (leader/best-lap), 483-487 (scoring classification). Their mapping to actual audio/text resources is DERIVED-only and not runtime-confirmed.

## Unresolved

- flt_59E440 (0x0059E440) is listed as a referenced global across many functions but never appears in the raw source text; its role (claimed ZeroThreshold in existing analysis) is not grounded in this packet.
- flt_59E670 (0x0059E670) is listed as a referenced global by RaceCommentary but is not referenced by the raw source; no operation uses it.
- The -1 / -1 / -1 / -2.0 / -2.0 placeholder arguments passed to DriverDataTableLookupAndTimeConversion are sentinel defaults; their meaning depends on that callee's own semantics, which are not in this packet.
- Message ids 337, 397, 427, 447-476, 478-503 map to DERIVED dispatch positions only; the correspondence to audio/text resources is not established.
- The comparison semantics of sub_588410 (0x00588410) and sub_566810 (0x00566810) - exact match versus substring - are not defined by this packet; both are treated as name comparisons.
- Standings entry/node fields +408 (sort key), +412 (active flag), +45380 (season mode), and the index-relative fields this[v3+4..5], this[v3+51], this[v3+52..54] are inferred from usage, not confirmed against a struct definition. Equal offsets +408/+412 recur on different bases and are not proven to share ownership.
- Vehicle-slot offsets +16472 (position), +16480 (index), +16484 (status, 2=retired), +16540 (best lap float) and +18588 (driver id), plus track-config offset +260 (name), are inferred from RaceCommentary usage only.
- The semantics of championship mode value 4, the +1/+2 position adjustments on sub_4C2990 results, and the -1 default driver index are caller- and data-dependent and unverified.
- sub_420000 (0x00420000) and 0x004203D0 message-id computations, and the CRTMathHelper timing comparison in SeasonDisplayIDResolver (units unknown), require their own function analysis.
- Standings node session-flag value 1 and season-selector value 3 at offset 45380 are derived from surrounding logic; the enum meaning is unproven.
- The 14 constructor team names (jump tables jpt_41F635 at 0x0041F82C and jpt_41F715 at 0x0041F864) map to teams in a fixed switch order that is not correlated with the category range FlagsGetter-1.
- Most function owners are UnknownObject/UNKNOWN in the packet; only RaceCommentarySystem is a named owner. Class groupings (SessionEventDispatcher, StandingsDisplayDispatcher, ChampionshipScoring) are semantic GUESS groupings, not proven object boundaries.
- In ScoringClassificationDisplay, v31 = ChampionshipPointsAccumulator() is called with no visible arguments (decompiler artifact); its contribution to the delta computation is unproven.
- In AccumulateChampionshipPointsByName, discarded LinkedListDereference/FixedOffsetReturn/ShortComputation_13a0 returns suggest shared side-effect state consumed by SceneNameLookupBySeason (0x004C0A20); the mechanism is not visible in this function, and the first/base entry may be counted twice per category.
- The caller relationships 0x0040DE60 (to the three SessionEventDispatcher emitters) and 0x0046BF10 (to RaceCommentary) are known but their frame paths and call frequency are not established; NestedDataSectionFieldAccessor's caller 0x00418EE0 is known only by prose, with no caller evidence ref in the packet.
- CountMatchingSeasonEntries operates on an array at a1+24; the owning class of a1 and the 24-byte prefix skipped before the counted array are unknown.
- The meaning of the value at entry offset 408 (a best-lap time, index, or counter) is not established beyond its comparison behavior.
- byte_5EA438 acts as a fallback default name/path when an entry name is null; its concrete content is unknown.
