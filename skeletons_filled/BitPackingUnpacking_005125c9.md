## BitPackingUnpacking_005125c9 — Unpack bit-packed data into byte fields

**Summary:** Reads bit-packed elements from a buffer and unpacks them into separate byte fields based on bit depth (1, 2, or 4 bits per element); writes result size metadata back to the tracking struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_51389E (0051389e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | element count (number of packed values) |
| this | 0x4 | RW | — | output data size in bytes (computed and stored) |
| this | 0x9 | RW | 8 | bits per element (input packing depth); reset to 8 after processing |
| this | 0xA | R | — | multiplier factor for computing totals |
| this | 0xB | RW | — | computed byte value = 8 * this+0xA |

**Written-by note (persistence):**
- this 0x4: overwritten each call with computed output size
- this 0x9: reset to 8 each call; external poke survives only until next call
- this 0xB: overwritten each call with 8 * this+0xA

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If bits-per-element (this+0x9) >= 8, skips unpacking entirely and jumps to metadata update. For v3 == 1 (bits), extracts 1 bit per element. For v3 == 2, extracts 2 bits per element. For v3 == 4, extracts 4 bits (nibble) per element. All other values skip unpack.
