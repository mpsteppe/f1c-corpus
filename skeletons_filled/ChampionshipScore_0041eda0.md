## ChampionshipScore_0041eda0 — CategoryLeaderCheck

**Summary:** Checks if a given standings entry leads or ties for the lead in any scoring category by comparing cumulative category totals against all other entries; returns 1 if the entry is not behind any other entry in a category, 0 otherwise.

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
| 0041ed20 | IndexedFieldGetter | Get scoring value for entry at a given category index |
| 004c11d0 | FlagsGetter | Get number of scoring categories from standings node |
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Get first/base standings entry pointer |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- Standings node must exist; `this` must be non-null; otherwise returns 0.
- `FlagsGetter` must return >= 2 (at least 2 categories); otherwise returns 0.
