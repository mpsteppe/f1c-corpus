## RenderBufferSetup_0051d80a — VehicleRenderBufferSetup

**Summary:** Sets up render buffer for vehicle texture rendering. Allocates bounding box array, initializes to full grid bounds, tightens via GridOccupancyBoundingBoxScan, subdivides via sub_51D57F, computes weighted centroid for each sub-region via F_2DImageWeightedAverage, stores count to output field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleUpdateFrameSetup (0051dfa8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | allocator vtable function (allocate memory) |
| obj | 0x4 | R | — | object vtable pointer |
| obj | 0x14 | RW | 95 | status code set after render buffer setup |
| obj | 0x18 | RW | — | region count written after subdivision |
| this | 0x0 | R | — | object vtable pointer |
| this | 0x4 | R | — | allocator pointer |
| this | 0x70 | RW | — | output count field (number of regions) |

**Written-by note (persistence):**
- obj 0x14: set once per call to 95; survives until overwritten
- obj 0x18: set once per call to region count; survives until overwritten
- this 0x70: set once per call to region count; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051d247 | GridOccupancyBoundingBoxScan | tightens bounding box to only cover occupied cells |
| 0051d57f | sub_51D57F | subdivides occupancy bounding box into multiple regions |
| 0051d6d2 | F_2DImageWeightedAverage | computes weighted centroid for each sub-region |

**Guard conditions:** if sub_51D57F returns 0 (v3 <= 0), skip weighted-average loop over regions (line 21). PASSES when region count > 0; BLOCKED when no regions found.
