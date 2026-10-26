## ScoringSessionStatsAggregator_0041eb30 — SessionBestPerformerFinder

**Summary:** Aggregates scoring statistics across multiple categories (flags-1 iterations) for all standings entries using IndexedFieldGetter, finds the entry with the highest total, and returns its pointer; returns 0 on ties in strict mode.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDisplayIDResolver (0041daf0), CRTMathHelper (0041ed30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041ed20 | IndexedFieldGetter | Get scoring value for an entry at a given category index |
| 004c11d0 | FlagsGetter | Get number of scoring categories from standings node |
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Get first/base standings entry pointer |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00588410 | sub_588410 | Compare name string against entry name at offset 0 |

**Guard conditions:** (none — no race-active or track-condition checks). Internal logic:
- Standings node must exist; `FlagsGetter` must return >= 2; otherwise returns 0.
- If `a1` (name filter) is non-zero, only entries matching name are considered.
- If highest-scoring entry is not the first entry AND its score equals first entry's score: in strict mode (a2 != 0) returns best pointer, in non-strict (a2 == 0) returns 0.
- Same tiebreaking applied to other entries: if another entry has same score as best, strict mode returns 0.
