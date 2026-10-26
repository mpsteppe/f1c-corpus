## MemoryAllocationWithBufferRead_004080f0 — StreamReadToAllocatedBuffer

**Summary:** Reads element count from a stream at offset 0x0C, allocates a 4-byte-per-element buffer, then reads each element into the buffer. Zero-initializes allocated buffer before fill. Returns 0 on full success, non-zero on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListNodeInsert (00407520)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | stream/file handle for reading data |
| this | 0x14 | R | — | element count; read from stream as first 4 bytes, then used as allocation size |
| this | 0x18 | RW | 0 | buffer pointer; allocated and filled by this function |

**Written-by note (persistence):**
- this 0x18: allocated inside function; set to zero on entry check, then to new buffer, then to zero again if read fails and cleanup runs. External non-zero poke would cause early return (guard at line 13).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041a160 | pfnAPC | cancels/closes the stream handle on read failure |
| 00587bcf | FreeWrapper_7bcf | frees allocated buffer on read failure |
| 00587c03 | OperatorNewNhMallocWrapper | allocates buffer: 4 bytes × element count |
| 00587f64 | sub_587F64 | seeks stream to beginning (offset 0) |
| 0058803f | ThreadSafeReadWrapper_803f | thread-safe read of 4 bytes from stream; returns non-zero on success |

**Guard conditions:** If stream handle at this+0x0C is null, returns 1 immediately (no stream). If buffer pointer at this+0x18 is already non-zero, returns 1 (already allocated). If initial ThreadSafeReadWrapper_803f of element count fails, returns 1. If any element read fails during the loop, the stream is cancelled, buffer freed, pointer cleared, and returns non-zero. Returns 0 only when all elements are read successfully.
