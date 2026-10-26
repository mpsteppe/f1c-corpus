## DriverStandingComparator_004d0c20 — Driver standing comparator

**Summary:** qsort-style comparator for two drivers by race standing. Status=3 (retired) drivers sort after active drivers; then compares integer rank at vehicle offset 44, float time/gap at offset 104, then pointer address as tiebreaker.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStopOrderRank (004d1bc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Driver index (byte), used to calculate offset into VEH array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005f070c | unk_5F070C | R | Base of vehicle array (stride 18624 per driver), indexed by driver ID |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — comparator always processes both inputs and returns -1/0/1.
