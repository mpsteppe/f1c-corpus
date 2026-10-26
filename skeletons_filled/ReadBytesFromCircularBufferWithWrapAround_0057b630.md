## ReadBytesFromCircularBufferWithWrapAround_0057b630 — PeekBytesFromRingBuffer

**Summary:** Copies a3 bytes from ring buffer at current head position into output buffer without consuming them (head/tail unchanged). Wraps read position at 4096-byte boundary. Returns 0 if insufficient data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1000 | R | — | head read-position index (read-only, not advanced) |
| this | 0x1002 | R | — | tail available-byte count (checked against a3) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a3 > tail (more bytes requested than available) → return 0 (blocked). If a3 <= tail → copy proceeds.
