## DriverSortComparator_004d0cf0 — Driver race position comparator

**Summary:** qsort-style comparator for two drivers by race position. Status 3 (retired) sorts after active drivers; status 1 (racing) compares lap time at offset 132; other statuses compare secondary rank at offset 12 and time at offset 16. Tiebreaker at offset 44, then pointer address.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Driver index (byte), used to index into VEH array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f070c | unk_5F070C | R | Base of vehicle array (stride 18624 per driver), indexed by driver ID |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — comparator always processes both inputs and returns -1/0/1.
