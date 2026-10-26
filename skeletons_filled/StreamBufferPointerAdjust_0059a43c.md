## StreamBufferPointerAdjust_0059a43c — Consume next char from buffer with pointer advance

**Summary:** Consumes next wide character from buffer: decrements remaining count at this+0x30, reads current value from position pointer at this+0x20, then advances that pointer by 2 bytes. Returns the consumed character value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_599ED6 (00599ed6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | RW | — | pointer to current buffer position (advanced by 2 on each call) |
| this | 0x30 | R | — | pointer to remaining character count (decremented on each call) |

**Written-by note (persistence):**
- this 0x20: incremented by 2 each call; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
