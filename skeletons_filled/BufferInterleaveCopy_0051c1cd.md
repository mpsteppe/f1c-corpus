## BufferInterleaveCopy_0051c1cd — Interleaved pixel double-width row copy

**Summary:** Interleaved buffer blit that copies each source byte twice (double width) into every other destination row, then uses 2D array block copy to duplicate the filled row to the adjacent row. Steps by 2 in destination, effectively expanding a source row into two identical destination rows.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Row width in bytes — end-of-row boundary for inner byte-duplication loop |
| this | 0x110 | R | — | Row count — outer loop bound (v6 increments by 2) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051593f | F_2DArrayBlockCopy | Copies the just-filled destination row to the adjacent row (+1) for vertical expansion |

**Guard conditions:** Inner guard (line 21): if current dst pointer < row end boundary (v8 < v9), continue byte-doubling copy loop. When pointer reaches boundary, proceed to row duplication via F_2DArrayBlockCopy.
