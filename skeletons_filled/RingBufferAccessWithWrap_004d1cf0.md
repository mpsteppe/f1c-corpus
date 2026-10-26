## RingBufferAccessWithWrap_004d1cf0 — FloatIndexedRingBufferAccessor

**Summary:** Converts a float index to an integer ring-buffer index by truncating `a2 * this[264] - 1`, wraps using modulo this[268] (buffer size), clamps to [0, size-1], and reads a 8-byte element from the buffer at this[272].

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIAbility (00429470), ShortComputation_bad0 (0049bad0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x108 | R | — | scaling factor multiplied by float a2 to produce raw index |
| this | 0x10C | R | — | ring buffer size (modulus for wrap-around) |
| this | 0x110 | R | — | pointer to ring buffer data (8-byte stride elements) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bdc | CRTFtol | converts float to integer (truncation) |

**Guard conditions:** If raw index < 0, wraps by adding this[268] (buffer size). Clamps to [0, this[268]-1] (valid index range). No early return; always returns a valid buffered element.
