## ArrayCopyWithRealloc_0054fda0 — Reallocating DWORD array copy

**Summary:** Replaces an integer array at this+0x4C by freeing the old allocation, allocating a new buffer of a3 DWORDs, copying from a source array, and updating the count at this+0x50. Used during mesh vertex buffer loading to store per-element integer data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXMeshVertexBufferParsingAndLoading (00547b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | RW | — | Pointer to allocated DWORD array; freed and reallocated each call |
| this | 0x50 | RW | — | Array element count; set to a3 each call |

**Written-by note (persistence):**
- this 0x4C: old pointer freed, new allocation stored; overwritten each call
- this 0x50: unconditionally written to a3 each call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Frees prior array allocation (if non-null) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates new buffer of 4*a3 bytes |

**Guard conditions:** If existing pointer at this+0x4C is non-null, PASSES: frees old buffer before reallocating. If null, BLOCKED: skip free, proceed to allocate.
