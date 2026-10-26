## ImageResampleFilter_0051c2db — Vertical resampling pixel blend

**Summary:** Resamples image rows by blending adjacent source row pairs with weighted convolution (weights 3:1, shifts by 4). Processes two source rows per output row, applying a vertical filter kernel with per-pixel channel blending.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Source pixel first channel byte (from center and neighbor rows) |
| obj | 0x1 | R | — | Source pixel second channel byte |
| obj | 0x2 | R | — | Source pixel third channel byte |
| this | 0x0 | R | — | First DWORD of main struct (read as byte; vtable or struct header) |
| this | 0x4 | R | — | Byte at offset 4 within main struct |
| this | 0x5 | R | — | Byte at offset 5 within main struct |
| this | 0x6 | R | — | Byte at offset 6 within main struct |
| this | 0x110 | R | — | Row count — outer loop bound (number of output rows to produce) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x110 | > | 0 | Row count — outer loop guard. Must be >0 to enter resampling. |

**Guard interpretation:** Outer guard (line 26): if row count > 0, process row pairs. If <= 0, skip entirely. Inner guard (line 51): if channel count at a2+40 != 2, process interior pixels with the weighted blend loop. If channel count == 2, handle as edge/simple case (only first/last pixel pair processed per row).
