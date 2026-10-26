## TableWeightedMix_0051e5d7 — MultiTableWeightedSumMix

**Summary:** Mixes pixel data by summing byte values from multiple lookup tables across channels. For each pixel, adds channel contributions from table-per-index to produce output byte.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | pixel width (stride) |
| this | 0x64 | R | — | channel count |
| this | 0x1A4 | R | — | context pointer |
| this | 0x1BC | R | — | context field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a4 (pixel count) <= 0, skip outer loop. if v4 (width) == 0, skip inner mix loop per pixel (line 31). if result (channel count) > 0, process each channel (line 38). PASSES when all counts positive; BLOCKED when zero.
