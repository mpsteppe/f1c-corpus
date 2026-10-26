## MultiTableCoordinateSearch_004f9240 — MultiTableCoordinateSearch

**Summary:** Searches multiple coordinate tables for a matching 4-tuple (4 coordinate values). Iterates tables by index, calling UtilityFunction_9160 to track current table, then searches entries within each table via GlobalGuardedFieldReader. Returns matching entry index or -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F9420 (004f9420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe6c | dword_8AFE6C | R | ParticleArrayCurrentIndex [DERIVED] (also: ` — current index) — Used to detect index wrap/change |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9150 | ShortComputation_9150 | Returns number of available tables |
| 004f9160 | UtilityFunction_9160 | Sets current particle/index tracker to specified table index |
| 004f9190 | ConditionalDispatch_9190 | Returns number of entries in current table |
| 004f91b0 | GlobalGuardedFieldReader | Reads 4 coordinate values from a table entry at given index |

**Guard conditions:** `ShortComputation_9150() <= 0` → returns -1 immediately (no tables). Inner loop breaks on coordinate match. Outer loop returns -1 if all tables exhausted without match.
