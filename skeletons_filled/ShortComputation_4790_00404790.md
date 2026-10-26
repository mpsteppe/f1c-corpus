## ShortComputation_4790_00404790 — WheelArrayIteratorUnregisteredCall

**Summary:** Iterates over all wheel entries in the array at this[77] (316-byte stride, this[76] count), calling FAILNODOCENTRY for each. Serves as an unregistered/bulk dispatch helper within the wheel collision pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SurfaceHeightfieldCollisionCallback (00404250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | wheel count (this[76]) |
| this | 0x134 | R | — | wheel array pointer (this[77]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fb5d0 | FAILNODOCENTRY | unregistered helper — called per wheel entry (no documentation available) |

**Guard conditions:** If this[76] (count) > 0, iterates calling FAILNODOCENTRY on each entry. PASSES: all entries processed. Returns count.
