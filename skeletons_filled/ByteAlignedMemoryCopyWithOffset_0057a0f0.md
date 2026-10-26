## ByteAlignedMemoryCopyWithOffset_0057a0f0 — SelfOffsetMemoryCopy48

**Summary:** Copies 48 bytes from a source address (computed as dest + offset) to a destination buffer using an offset-based self-copy pattern. Copies first 16 bytes byte-by-byte, then the remaining 32 bytes using a second loop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AllocationWrapper (00585030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | first 16 bytes of destination buffer (written by copy) |
| this | 0x10 | RW | — | bytes 16-47 of destination buffer (written by second loop) |

**Written-by note (persistence):**
- this 0x0: written unconditionally with source bytes; survives as copied content in destination buffer
- this 0x10: written unconditionally with source bytes; survives as copied content in destination buffer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none (no early return or conditional check).
