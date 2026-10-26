## ObjectComparisonWithTiebreak_0041ef40 — StandingsEntryComparator

**Summary:** Compares two standings entries by primary sort key at offset 412, then breaks ties by iterating positions and comparing CountMatchingSeasonEntries; returns the better-ranked entry or 0 if entries are perfectly equal.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDisplayIDResolver (0041daf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x19C | R | — | Primary sort key (score/points/total time) used for ranking comparison |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041efe0 | CountMatchingSeasonEntries | Count how many standings entries match a given position value (tiebreaker) |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- If `a1` is null → return `a2`. If `a2` is null → return `a1`.
- If entries differ at offset 412 → higher value wins immediately.
- If tied at offset 412 → iterate positions 1..VehicleCount using CountMatchingSeasonEntries count as tiebreaker.
- If all tiebreaker positions produce equal counts → return 0.
