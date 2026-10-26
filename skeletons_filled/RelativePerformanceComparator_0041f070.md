## RelativePerformanceComparator_0041f070 — PerformanceGapCheck

**Summary:** Checks if a standings entry's performance value at offset 408 exceeds the maximum value of all other active entries by at least 10, indicating a significant performance gap.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x198 | R | — | Performance sort key (best lap / points value) compared against other entries |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c1370 | ActiveEntityCounter | Count active entries in standings |
| 004c13a0 | ShortComputation_13a0 | Get standings entry pointer by index |
| 004c2850 | LinkedListDereference | Dereference linked list wrapper to get standings node |

**Guard conditions:** (none — no race-active or track-condition checks). Internal:
- `this` must be non-null → BLOCKED: return false.
- If no active entries other than `this` → gap cannot be computed; `v2` stays at -1 → `this[102] - (-1) >= 10` is trivially true if `this[102] >= 9`.
