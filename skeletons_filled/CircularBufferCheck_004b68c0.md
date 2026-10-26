## CircularBufferCheck_004b68c0 — Circular Buffer Active Count

**Summary:** Computes the number of active entries in a circular buffer of pit stall data (176-byte entries). Returns count based on read/write index positions; returns 0 if buffer is in invalid state or the single entry is empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStallProximityCheck (004b5da0), sub_4B6190 (004b6190), sub_4B7860 (004b7860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | R | — | Pointer to circular buffer data array (176-byte entries) |
| this | 0x9B4 | R | — | Circular buffer modulus (max entries before wrap) |
| this | 0x9B8 | R | — | Current write index into circular buffer |
| this | 0x9BC | R | — | Read index (oldest active entry) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b69f0 | CoordinateBoundCheck | Check if buffer indices are negative (invalid/uninitialized) |

**Guard conditions:** If CoordinateBoundCheck returns true (indices are invalid/negative), return 0. If computed count == 1 AND first byte of the entry at (176 * read_index) is zero, return 0 (slot is empty). Normal case: returns count = write_index - read_index + 1 (if not wrapped) or modulus - read_index + write_index + 1 (if wrapped).
