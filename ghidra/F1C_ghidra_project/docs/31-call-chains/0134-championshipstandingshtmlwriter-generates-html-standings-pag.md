# Chain: ChampionshipStandingsHTMLWriter — Generates HTML standings page for championship mode

Seed: FUN_0046c210  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 18

---

## Overview

Triggered during championship season results display. Reads season database to determine if running championship mode (season mode == 2), then generates 4-section HTML page: header, race results, standings table, track info. For non-championship mode, writes simplified "No season data" fallback. Data flows from season DB (DAT_007d2e48, stride 0x48c0) through path-based key lookups into the HTML output buffer (DAT_005ec4cc MessageBuffer).

## Call Tree

```
FUN_0046c210 — ChampionshipStandingsHTMLWriter  [trigger: season results display]
  +-- FUN_00489cb0 — StateCleanup+Notification  [resets HTML writer state]
  +-- FUN_004c2760 — SeasonModeCheck  [returns +0xb144, checks if == 2]
  +-- FUN_004c2850 — Linked List Dereference  [loads season data from DAT_007d2e48]
  +-- FUN_004c1390 — RaceCount  [returns entry count in season DB]
  +-- FUN_004c29d0 — RaceEntry  [returns specific race entry from DB]
  +-- FUN_004c0a20 — SeasonNameLookup  [reads scene name by season index]
  |     +-- FUN_004c3f80 — [undocumented]
  |     +-- FUN_004c4080 — [undocumented]
  +-- FUN_004894d0 — YearSeasonString  [formats date/year header string]
  +-- FUN_004b0b20 — PlayerNameFromPath  [extracts player name from file path]
  |     +-- FUN_00463c40 — [undocumented]
  |     +-- FUN_004b0b10 — [undocumented]
  |     +-- FUN_00566810 — validity check
  +-- FUN_00487010 — SectionHeader(0-3)  [returns section title string by index 0-3]
  +-- FUN_00489600 — HTMLWrite  [writes formatted string to HTML buffer]
  +-- FUN_004c13c0 — SeasonPointsTotal  [calculates total points for standings]
  |     +-- FUN_004c1370 — active entity counter
  |     +-- FUN_004c1390 — root entry getter
  |     +-- FUN_004c13a0 — entry by index
  |     +-- FUN_004c0a20 — scene name lookup
  |     +-- FUN_00566810 — validity check
  +-- FUN_004c1450 — PositionPointsFormatter  [formats position/points pairs]
  |     +-- FUN_004c13c0 — SeasonPointsTotal (reuses above)
  |     +-- FUN_004c1370 — active entity counter
  |     +-- FUN_004c1390 — root entry getter
  |     +-- FUN_004c13a0 — entry by index
  |     +-- FUN_004c0a20 — scene name lookup
  |     +-- FUN_00588410 — string comparison
  +-- FUN_004c55b0 — TrackSceneLoader  [reads scene data for current track]
  |     +-- FUN_00589901 — [undocumented]
  +-- FUN_004c5840 — SeasonRacesSectionFinder  [finds "SeasonRaces" section]
  +-- FUN_005679c0 — TrackNameRead  [string-keyed linked list search for track name]
  |     +-- FUN_00499e20 — section entry reader / string accessor
  |     +-- FUN_00588410 — string compare
  +-- FUN_00567970 — ValueGet  [data entry accessor]
  +-- FUN_00423a00 — StringCopy(string table binary search)  [looks up strings]
  +-- FUN_0058815f — FormatString  [safe sprintf with overflow check]
        +-- FUN_0058d04d — core format engine (vsnprintf equivalent)
        +-- FUN_0058cf35 — buffered write / overflow error handler
```

## Step-by-Step Trace

### Level 0: FUN_0046c210 — ChampionshipStandingsHTMLWriter

**Trigger:** Season results display — called when player opens championship standings during/after a championship season
**Called by:** No callers found (callers.json — 0 callers). Likely called via UI event callback or vtable dispatch.
**Purpose:** Generates a complete HTML page showing championship standings, race results, and track info.

**Key actions:**
1. Calls FUN_00489cb0 — resets HTML writer state
2. Calls FUN_004c2760 — checks season mode flag at +0xb144 (2 = championship)
3. Calls FUN_004c2850 — loads season database linked list
4. Calls FUN_004c1390 — gets race count for iteration
5. For each of 4 sections: gets header via FUN_00487010(0-3), formats content, writes via FUN_00489600
6. Section 1: race number `"%d/%d"` using FUN_004c29d0 race data
7. Section 2: position/points via FUN_004c13c0/FUN_004c1450
8. Section 3: track name via FUN_005679c0 (linked list search), copied to MessageBuffer
9. Section 4: scene data via FUN_004c55b0
10. On non-championship: writes 4 simplified sections with "No season data" fallback

**Data passed to callees:** season DB pointer, index values for sections (0-3), string buffers for HTML output

### Level 1: Key callees

**FUN_004c0a20 — SceneNameLookupBySeason**
**Called by:** FUN_0046c210 (section 2 formatting)
**Purpose:** Reads scene/race name from season database by index. Copies 0x50-byte entry name into buffer.
**Key actions:** Calls FUN_004c3f80 to locate entry, FUN_004c4080 to copy name. Used for both season name display and as input to comparison functions.

**FUN_004c13c0 — SeasonPointsTotal**
**Called by:** FUN_0046c210 (section 2), FUN_004c1450
**Purpose:** Calculates total season points by iterating all race entries via FUN_004c1370/FUN_004c1390/FUN_004c13a0 and accumulating.
**Key actions:** Iterates race entries, sums points per driver.

**FUN_004c1450 — PositionPointsFormatter**
**Called by:** FUN_0046c210 (section 2)
**Purpose:** Formats position/points pairs for the HTML standings table. Iterates through 6 callees to extract position and points per race entry.
**Key actions:** For each entry: gets path segment count via FUN_004c13c0, root path via FUN_004c1390, suffix via FUN_004c13a0, scene name via FUN_004c0a20, string compare via FUN_00588410.

**FUN_005679c0 — TrackNameRead (linked list search)**
**Called by:** FUN_0046c210 (section 3 — track info)
**Purpose:** Walks a string-keyed linked list (DAT_007d2dc0/DAT_007d2dc8) to find track name matching a key.
**Key actions:** Compares string keys via FUN_00588410, returns associated data via FUN_00499e20.

**FUN_0058815f — FormatString (safe sprintf)**
**Called by:** FUN_0046c210 (all sections)
**Purpose:** Formats strings with overflow protection. Delegates to FUN_0058d04d (vsnprintf) and FUN_0058cf35 (overflow handler).

### Level 2: Deeper callees

**FUN_00588410 — StringCompare** (called by FUN_004c1450, FUN_005679c0)
Standard string comparison utility. Returns 0 on match.

**FUN_004c1370/FUN_004c1390/FUN_004c13a0** (called by FUN_004c13c0, FUN_004c1450)
Iteration triplet: count → get root → get by index. Standard linked-list/tree traversal pattern.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004c2760 | season_mode (+0xb144) | compare == 2 | championship flag |
| FUN_004c2850 | DAT_007d2e48 | dereference | season DB pointer |
| FUN_004c1390 | season DB | count entries | num_races |
| FUN_004c0a20 | season DB + index | copy 0x50 bytes | race name string |
| FUN_004c13c0 | season DB | iterate + accumulate | points total |
| FUN_004c1450 | season DB entries | extract position/points | position:points pairs |
| FUN_005679c0 | DAT_007d2dc0 linked list | keyed search | track name |
| FUN_0058815f | format + args | vsnprintf | formatted HTML |
| FUN_00489600 | formatted string | write to buffer | HTML output |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ec4cc | MessageBuffer | FUN_0046c210 (via FUN_00489600, FUN_0058815f) | HTML page content buffer |

## Notes

- All 18 callees are either leaf functions or shallow (max depth 2). The chain is wide (18 direct callees) but shallow.
- Most callees are data accessors (season DB, linked list, string table) — this is an output-only formatting function.
- FUN_004c13c0 and FUN_004c1450 share a subtree with FUN_004c1370/FUN_004c1390/FUN_004c13a0/FUN_004c0a20 — these are common iteration/access primitives for the season database.
- FUN_004c2760 and FUN_004c2850 are documented in docs/20 and docs/01 respectively as lightweight accessors.
- The non-championship path is simpler: 4 sections with static "No season data" text, skipping all season DB access.

---
