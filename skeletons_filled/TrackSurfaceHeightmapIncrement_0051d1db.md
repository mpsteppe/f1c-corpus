## TrackSurfaceHeightmapIncrement_0051d1db — Track surface heightmap counter increment

**Summary:** Increments uint16 counters in a track surface heightmap grid based on 3-byte-per-pixel source data. Each pixel's bytes encode a grid position (x, y, z via shift operations), and the function increments the counter at that position, clamping overflow to 65535 (-1).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1A4) | 0x18 | R | — | Heightmap data array pointer — base address for indexed heightmap access |
| this | 0x0 | RW | 18446744073709551615 (0xFFFFFFFF) | Read as initial return value (a1 pointer cast to WORD*) — not actually modified |
| this | 0x5C | R | — | Pixel count per row — inner loop bound for heightmap increment |
| this | 0x1A4 | R | — | Pointer to heightmap sub-struct holding the data array reference |

**Written-by note (persistence):**
- this 0x0: Not actually written by this function; initial return value register assignment only.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard at `v5 > 0` (line 17): if pixel count > 0, enter the per-pixel heightmap increment loop for the current row. If v5 == 0, skip to next row.
