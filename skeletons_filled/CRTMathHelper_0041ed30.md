## CRTMathHelper_0041ed30 — CompositeScoreComputer

**Summary:** Computes a composite sum of all scoring category values for the best-matching standings entry of a named entrant, minus one; returns -1 if no entry found or insufficient categories.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDisplayIDResolver (0041daf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041eb30 | ScoringSessionStatsAggregator | Find best-scoring entry matching the given name |
| 0041ed20 | IndexedFieldGetter | Get scoring value for entry at a given category index |
| 004c11d0 | FlagsGetter | Get number of scoring categories from standings node |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- Standings node must exist; `FlagsGetter` must return >= 2; otherwise returns -1.
- `ScoringSessionStatsAggregator` result must be non-zero; otherwise returns -1.
