## PixelBlendFilterHorizontal_0051c237 — Horizontal 3-tap pixel blend filter

**Summary:** Applies a horizontal weighted blend filter across pixel rows using a 3-tap kernel (weights 3-1-3). Processes each row of pixels, blending adjacent values with shift-divide for each output pixel.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x110 | R | — | Row count — number of rows to filter; outer loop bound |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x110 | > | 0 | Row count — must be >0 to enter the per-row filter loop |

**Guard interpretation:** Outer guard (line 21): if row count > 0, enter per-row filter loop. If <= 0, skip entirely. Inner guard (line 33): if channel count at a2+40 != 2, process interior pixels with the weighted blend loop. If channel count == 2, skip interior processing (only first/last pixel handled).
