## MemcpyLikeWithRealloc_00587510 — Reallocate buffer and copy data

**Summary:** Manages a growable buffer (ptr at 0x0, capacity at 0x4, stored size at 0x8). If `a3` exceeds capacity, frees old buffer and allocates new one of size `a3`. Copies `a3` bytes from `a2` into buffer. Returns 1 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BufferUnpackWithSizeCheckByteWordCopy (0057d660), NegatedPredicate (00587100), BinaryPacketFieldParserWithOffsetMath (00587310), StructInitParse (00587490), BufferWriteWithParams (00587620), BufferCopyViaVirtualTypeDispatch (00587930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Pointer to allocated buffer; read for memcpy source and free check |
| this | 0x4 | RW | — | Buffer capacity in bytes; compared against a3 for realloc decision |
| this | 0x8 | RW | 0 | Stored size after copy; set to a3 on success, 0 on skip |

**Written-by note (persistence):**
- this 0x4: updated to a3 if reallocation occurred; external poke overwrites it
- this 0x8: updated to a3 on success, 0 on skip; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005874d0 | OperatorNewWithResultCheck | Allocate buffer of size a3; stores result into this+0 |
| 00587bcf | FreeWrapper_7bcf | Free old buffer when reallocating |

**Guard conditions:** First check: `a3 > capacity` triggers reallocation. Second check: `*this != NULL && a3 > 0` triggers memcpy; else sets stored size to 0 and returns 1 (skip, not error).
