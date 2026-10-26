## BitmapRangeOccupancyTestViaBitOps_00586d00 — Test bitmap occupancy for a range descriptor

**Summary:** Reads a range descriptor (start + count) from an array indexed by field 0x34, then tests which positions within that range have bits set in a bitmap at field 0x14. Returns a bitmask of occupied positions.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VTableDispatchWithConditionalBranch (00585400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Pointer to bitmap data tested for occupied bits |
| this | 0x1C | R | — | Base pointer to range descriptor table (4-byte entries: start WORD + count WORD) |
| this | 0x34 | R | — | Index into range descriptor table |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `(_WORD)v5` (the count field of the range descriptor) must be non-zero. If zero, function returns 0 immediately (no bits tested). When non-zero, loops v5 iterations building the result bitmask.
