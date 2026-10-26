## MonochromeBufferByteDuplicateCopy_0051c176 — Monochrome pixel double-width blit

**Summary:** Copies each source byte into two consecutive destination bytes, doubling the horizontal width. Iterates over rows by count, processing each row up to its width boundary. Used for monochrome/stencil-style bitmap expansion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Row width in bytes — end-of-row boundary for inner copy loop |
| this | 0x110 | R | — | Row count — number of rows to process; loop bound |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x110 | > | 0 | Row count — outer loop condition. Must be >0 to enter processing. |

**Guard interpretation:** Outer guard (line 17): if a1[68] (row count) > 0, enter per-row loop. If <= 0, skip entire operation. Inner guard (line 26): if current dst pointer < row end boundary, continue byte-by-byte duplication loop. When pointer reaches boundary, move to next row.
