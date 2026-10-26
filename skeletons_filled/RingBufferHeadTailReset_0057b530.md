## RingBufferHeadTailReset_0057b530 — ResetRingBufferHeadTail

**Summary:** Resets ring buffer head and tail indices to 0, marking buffer as empty.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57DE30 (0057de30), sub_57E570 (0057e570), SocketAddressInit (00582110)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1000 | RW | 0 | ring buffer head index/offset (WORD) |
| this | 0x1002 | RW | 0 | ring buffer tail index/offset (WORD) |

**Written-by note (persistence):**
- this 0x1000: unconditionally set to 0 each call; external poke does not survive
- this 0x1002: unconditionally set to 0 each call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
