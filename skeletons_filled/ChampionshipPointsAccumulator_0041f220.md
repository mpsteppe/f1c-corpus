## ChampionshipPointsAccumulator_0041f220 — PointsAccumulatorByName

**Summary:** Accumulates championship scoring values (IndexedFieldGetter) across a specified number of categories for a named entrant by iterating standings entries and summing values where the entry's scene name matches the input name.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ScoringClassificationDisplay (0041e320), sub_41F340 (0041f340), sub_41F5D0 (0041f5d0), ConstructorChampionshipClinchDetection (0041f8a0), TimingDifferenceChecker (0041fdb0), ConstructorStandingsParser (00420820), GdbSeasonSelector (00420cf0)

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
| 004c0a20 | SceneNameLookupBySeason | Fill buffer with scene/track name associated with current standings entry |
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Get first/base standings entry pointer |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c13c0 | sub_4C13C0 | Return total points for an entrant from alternate storage (used when a2 == -1) |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00566810 | sub_566810 | Compare scene/entry name against input name |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- `a1` (name) must be non-null → PASSES: proceed with accumulation. BLOCKED: return -1.
- `a2 == -1` → special case: return result of sub_4C13C0(a1) directly (bypasses iteration).
- `a2 >= 0` → accumulate category values 0 through a2-1 for entries matching the name.
