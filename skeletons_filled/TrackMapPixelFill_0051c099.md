## TrackMapPixelFill_0051c099 — Track map pixel expansion fill

**Summary:** Expands track map pixel data by filling memory with repeated pixel values using memset32. Reads row data from source, expands each pixel horizontally by a repeat count, then optionally duplicates rows via 2D array block copy for vertical expansion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Row width/pitch — boundary for row iteration and copy size |
| this | 0x110 | R | — | Row count — number of source rows to process |
| this | 0x19C | R | — | Base offset added to secondary struct pointer for parameter lookup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051593f | F_2DArrayBlockCopy | Copies a rectangular block of pixel data for vertical row duplication |

**Guard conditions:** Guard at `v21 > 0` (line 38): if vertical repeat/pixel-height count > 0, expand each source pixel into v21 bytes via memset32. If v21==0, skip expansion (no pixels to fill). Guard at `v18 > 1` (line 53): if horizontal repeat count > 1, duplicate the current row downwards by calling F_2DArrayBlockCopy for (v18-1) extra copies. If v18 <= 1, skip row duplication.
