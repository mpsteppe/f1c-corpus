## F_2DBlitTextureCopy_0051c653 — 2D texture column-wise blit copy

**Summary:** Copies texture pixel data with column-to-row transposition. For each output row, iterates columns, copying source row segments into destination with vertical stride equal to column count. Used for texture orientation/transpose during 2D blit operations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | Column count — inner loop bound; also used as destination stride between copies |
| this | 0x5C | R | — | Row length in bytes — number of bytes copied per source-to-destination segment |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard at (a5-1) >= 0 (line 17): if output row count >= 0, enter processing loop. If < 0 (no rows), skip entirely.
