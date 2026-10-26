## MemoryAllocation_004046b0 — WheelContactHeightSmoothing

**Summary:** Iterates over all sub-objects (wheels) in the array at this[77] (316-byte stride). For each wheel with a valid neighbor pointer (offset +276), updates contact height (offset +76) based on the neighbor chain. If the neighbor's node type (offset +300) is below a threshold (this[4]), queries SpatialNearestNeighborQueryWithPlaneTest for terrain height and averages with parent contact height. For type==1 nodes without a parent, walks the linked list to accumulate contact heights from ancestors.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SurfaceHeightfieldCollisionCallback (00404250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | threshold for node type at +300 (compared against v7) |
| this | 0x130 | R | — | wheel count (this[76]) |
| this | 0x134 | R | — | wheel array pointer (this[77]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004038e0 | SpatialNearestNeighborQueryWithPlaneTest | queries terrain height at wheel position when node type >= threshold |

**Guard conditions:** If this[76] (count) > 0, iterates each wheel entry. Only processes entries with a valid neighbor pointer (offset +276). If neighbor's type (+300) < this[4], queries terrain height; if type == 1 and entry has no parent pointer, walks ancestor chain accumulating contact heights. PASSES: wheel contact heights updated. BLOCKED: if count == 0 or no neighbor pointer set, skips.
