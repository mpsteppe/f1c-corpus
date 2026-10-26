## BitmaskGenerationFromBitArray_00586de0 — Generate occupancy bitmask from bitmap range

**Summary:** Same pattern as BitmapRangeOccupancyTestViaBitOps but reads range index from field 0x44. Reads start+count from descriptor table at field 0x1C, tests bitmap at field 0x14, returns bitmask of occupied positions in range.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_587730 (00587730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Pointer to bitmap data |
| this | 0x1C | R | — | Base pointer to range descriptor table (4-byte entries: start WORD + count WORD) |
| this | 0x44 | R | — | Index into range descriptor table (alternative to fields 0x34/0x38) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `(_WORD)v5` (count field of range descriptor) must be non-zero. If zero, returns 0 immediately. When non-zero, loops v5 iterations building result bitmask.
