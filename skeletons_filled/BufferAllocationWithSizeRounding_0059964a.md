## BufferAllocationWithSizeRounding_0059964a — BufferReallocWithSizeRounding

**Summary:** Reallocates growable buffer with size rounded up to 32-byte boundary. Allocates via OperatorNewNhMallocWrapper with +2 bytes for boundary marker, copies old data, frees old buffer via ReferenceCountDecrementWithConditionalFree, updates data pointer (this+0x4), size (this+0x8), capacity (this+0xC). Returns new data pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_599560 (00599560)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | buffer size — updated to min(old_size, new_capacity) after realloc |

**Written-by note (persistence):**
- this 0x8: written to min(old_size, new_capacity); external poke would corrupt buffer size tracking

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005996a8 | loc_5996A8 | R | SEH handler landing pad for buffer allocation |
| 0059d2fc | loc_59D2FC | R | SEH handler landing pad for buffer allocation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | allocate new buffer with rounded size + 2 |
| 0058a5d8 | SEHHandlerInit | initialize SEH handler for exception-safe reallocation |
| 0058cc00 | MemoryCopy_cc00 | copy old data to new buffer (min of old/new size) |
| 005993af | ReferenceCountDecrementWithConditionalFree | decrement refcount and free old buffer |

**Guard conditions:** if rounded size overflows (>0xFFFFFFFD), fall back to original size. If MemoryCopy source pointer (old data) is NULL, skip copy. Set marker byte at new_data[-1] to 0.
