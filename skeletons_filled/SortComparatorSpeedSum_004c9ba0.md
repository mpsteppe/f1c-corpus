## SortComparatorSpeedSum_004c9ba0 — SortComparatorSpeedSum

**Summary:** qsort/qsort-style comparator function. Sums two float speed fields (offsets 0x738 and 0x740) from each object and returns -1/0/1 for sorting by total speed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x738 | R | — | First speed component of the driver/vehicle object |
| obj | 0x740 | R | — | Second speed component of the driver/vehicle object |
| this | 0x0 | R | — | Pointer-to-owner indirection (object ptr stored at arg offset 0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always compares both sums; returns 1/0/-1.
