## BestLapEntrantFinder_0041e920 — BestLapEntrantFinder

**Summary:** Finds the standings entrant with the highest best-lap value at offset 408, optionally filtered by name; in strict mode (a2=0), rejects ties and returns 0 if the best value is not unique across entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDisplayIDResolver (0041daf0), sub_4203F0 (004203f0)

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
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c1390 | FixedOffsetReturn | Get first/base standings entry pointer |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |
| 00588410 | sub_588410 | Compare name string against entry name at offset 0 |

**Guard conditions:** (none — no race-active or track-condition checks). Internal logic:
- If standings node is null → returns 0.
- Initial check: first entry's value at offset 408 must be > -1 to be considered.
- If `a1` (name filter) is non-zero, first entry must match name; otherwise skip first entry.
- If `a2` (strict mode) is 0 and best entry value matches another entry's value at offset 408 → returns 0 (non-unique best).
