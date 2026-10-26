## ChecksumComputeType03Stream_0051e65f — ThreeChannelLookupSumBlend

**Summary:** Blends 3-channel pixel data by summing values from three lookup tables. For each source pixel (R, G, B), looks up table values and accumulates them into a single output byte per pixel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1A4)+0x18) | 0x0 | R | — | table array index 0 (first component table base) |
| *(*(this+0x1A4)+0x18) | 0x4 | R | — | table array index 1 (second component table base) |
| *(*(this+0x1A4)+0x18) | 0x8 | R | — | table array index 2 (third component table base) |
| *(this+0x1A4) | 0x18 | R | — | table array pointer (array of 3 table base pointers) |
| this | 0x5C | R | — | pixel width (stride) |
| this | 0x1A4 | R | — | context pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a4 (pixel count) <= 0, skip outer loop. if v7 (width) == 0, skip inner blend loop per pixel (line 36). PASSES when count > 0 and width > 0; BLOCKED otherwise.
