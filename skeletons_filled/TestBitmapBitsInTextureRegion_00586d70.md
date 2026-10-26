## TestBitmapBitsInTextureRegion_00586d70 — Test bitmap occupancy for region range

**Summary:** Identical logic to BitmapRangeOccupancyTestViaBitOps but uses field 0x38 (instead of 0x34) as the range descriptor index. Reads start+count from descriptor table at field 0x1C, then tests bitmap at field 0x14 for occupied bits within range, returning bitmask.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Pointer to bitmap data |
| this | 0x1C | R | — | Base pointer to range descriptor table (4-byte entries: start WORD + count WORD) |
| this | 0x38 | R | — | Index into range descriptor table (alternative to field 0x34) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `(_WORD)v5` (count field of range descriptor) must be non-zero. If zero, function returns 0 immediately. When non-zero, loops v5 iterations building result bitmask.
