## F_2DImageWeightedAverage_0051d6d2 — WeightedCentroidCompute

**Summary:** Computes weighted centroid (center of mass) of non-zero pixel values within a 2D grid region. Accumulates weighted sums of X/Y/Z coordinates using pixel values as weights, normalizes by total weight, and writes 3 byte results to output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderBufferSetup (0051d80a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | bounding box min X |
| this | 0x4 | R | — | bounding box max X |
| this | 0x8 | R | — | bounding box min Y |
| this | 0xC | R | — | bounding box max Y |
| this | 0x10 | R | — | bounding box min Z |
| this | 0x14 | R | — | bounding box max Z |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if minX > maxX, skip entire X loop (line 36). if minY > maxY, skip inner Y loop body (line 41). if minZ > maxZ, skip inner Z loop body (line 50). PASSES when min <= max; BLOCKED when range empty.
