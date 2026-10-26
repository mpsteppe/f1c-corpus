## RingBufferPushWithWrapCheck_0057b550 — PushBytesToRingBuffer

**Summary:** Pushes a3 bytes from source buffer a2 into 4096-byte ring buffer at computed write position (head+tail mod 4096). Returns 0 if insufficient space remains, 1 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1000 | R | — | head offset (signed read-position adjustment) |
| this | 0x1002 | RW | — | tail offset (unsigned write-position, incremented by a3) |

**Written-by note (persistence):**
- this 0x1002: unconditionally incremented by a3 on success; external poke overwritten by caller

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if tail + a3 > 4096 → return 0 (blocked: data won't fit in 4096-byte buffer). On success, condition passes and bytes are copied.
