## BufferReset_004b3b40 — RingBufferFullReset

**Summary:** Drains all remaining ring buffer entries by calling sub_4B3400 on each, decrements pending counter for each entry, then resets all three buffer pointers (start, current, end) to base+4. Called at shutdown/reset from GamePostMainLoop.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), sub_4B9B80 (004b9b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | postProcessInput — pending entry counter, decremented per drained entry |
| this | 0x6C004 | RW | — | Ring buffer end pointer (reset to base+4) |
| this | 0x6C008 | RW | — | Ring buffer current/start pointer (reset to base+4) |
| this | 0x6C00C | RW | — | Ring buffer read pointer (reset to base+4) |

**Written-by note (persistence):**
- this 0x0: written each loop iteration (decremented) and final zero via pointer reset — external value overwritten
- this 0x6C004: written once at end — set to base+4 (buffer empty)
- this 0x6C008: written once at end — set to base+4 (buffer empty)
- this 0x6C00C: written once at end — set to base+4 (buffer empty)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3400 | sub_4B3400 | Process/drain a single pending ring buffer entry |

**Guard conditions:** Checks if current pointer (0x6C008) equals end pointer (0x6C004). If equal: skip drain loop (buffer already empty). If not equal: drain all entries until current == end, decrementing counter per entry.
