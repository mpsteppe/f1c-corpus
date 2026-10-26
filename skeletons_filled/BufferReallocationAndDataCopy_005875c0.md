## BufferReallocationAndDataCopy_005875c0 — Reallocate buffer with size extension

**Summary:** Computes new buffer size as `a2 + capacity(offset 0x4)`, allocates via OperatorNewWithResultCheck, copies existing data (offset 0x8 bytes) from old buffer, frees old buffer, stores new pointer at offset 0x0. Always returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Buffer pointer; replaced with new allocation on success |
| this | 0x4 | R | — | Existing capacity; added to a2 for new size |
| this | 0x8 | R | — | Current stored data size; bytes to preserve during copy |

**Written-by note (persistence):**
- this 0x0: replaced with new allocation on success; external poke overwrites it

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005874d0 | OperatorNewWithResultCheck | Allocate new buffer of size a2 + this[1] |
| 00587bcf | FreeWrapper_7bcf | Free old buffer after successful allocation and copy |

**Guard conditions:** OperatorNewWithResultCheck must succeed (return non-zero). If allocation fails, old buffer is left untouched, returns 0.
