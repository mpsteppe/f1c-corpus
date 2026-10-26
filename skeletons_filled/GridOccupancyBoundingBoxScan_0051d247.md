## GridOccupancyBoundingBoxScan_0051d247 — GridOccupancyBoundaryShrink

**Summary:** Scans 3D occupancy grid of 16-bit cells to find tight axis-aligned bounding box of populated (non-zero) entries. Shrinks min/max bounds per axis by scanning inward from each direction and returns count of occupied cells.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51D57F (0051d57f), RenderBufferSetup (0051d80a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x18 | R | — | row-pointer array base (array of grid row addresses indexed by X coordinate) |
| this | 0x1A4 | R | — | context pointer to grid data structure |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Outer if-blocks check each axis range validity: if minX >= maxX, skip X-direction scan (lines 58-122); if minY >= maxY, skip Y-direction scan (lines 126-204); if minZ >= maxZ, skip Z-direction scan (lines 207-270). PASSES when range is valid (min < max) and proceeds to scan for occupied cells; BLOCKED when range is empty/inverted.
