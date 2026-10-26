## RingBufferPopWithWrapCheck_0057b5c0 — PopBytesFromRingBuffer

**Summary:** Reads a3 bytes from ring buffer into output buffer a2. Advances head position by a3 (mod 4096) and decrements tail count by a3. Returns 0 if insufficient data available.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1000 | RW | — | head read-position index, advanced by 1 per byte (mod 4096) |
| this | 0x1002 | RW | — | tail available-byte count, decremented by a3 on success |

**Written-by note (persistence):**
- this 0x1000: unconditionally incremented per byte on success; external poke does not survive
- this 0x1002: unconditionally decremented by a3 on success; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a3 > tail (more bytes requested than available) → return 0 (blocked). If a3 <= tail → copy proceeds.
