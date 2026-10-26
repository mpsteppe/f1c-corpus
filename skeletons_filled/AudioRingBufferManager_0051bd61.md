## AudioRingBufferManager_0051bd61 — AudioRingBufferWrite

**Summary:** Writes audio data to a ring buffer. On first call, allocates the buffer via vtable. Copies input samples, zero-fills newly written region if fill level advanced, and wraps cursor when buffer is full. Returns buffer capacity.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Vtable pointer for buffer allocation interface (a1[1], index 7) |
| this | 0x20 | R | — | Unknown (not directly accessed in this function body) |
| this | 0x188 | R | — | Pointer to ring buffer state struct (a1[98]) |
| this | 0x190 | R | — | Allocation size hint parameter (v7[2]) passed to allocator |
| this | 0x194 | RW | — | Buffer data pointer (v7[3]); written by allocator, read for zero-fill and write |
| this | 0x198 | R | — | Buffer capacity in elements (v7[4]); used for wrap check |
| this | 0x19C | RW | — | Write cursor / total elements written (v7[5]); incremented on wrap |
| this | 0x1A0 | RW | 0 | Buffer allocated flag / current fill level (v7[6]); init 0 triggers alloc on first call |
| this | 0x1A4 | R | — | Vtable pointer for zero-fill/clear interface (a1[105], index 1) |
| this | 0x1A8 | R | — | Unknown (not directly accessed in this function body) |

**Written-by note (persistence):**
- this 0x194: written once on first call (buffer allocation); pointer persists
- this 0x19C: incremented by capacity when buffer wraps; persists as ring buffer write cursor
- this 0x1A0: incremented on each write (fill level), reset to 0 on wrap; persists between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If v7[6] (this+0x1A0) is 0 on entry, allocates buffer first by calling vtable (a1[1]+28). No early return — always processes the write.

