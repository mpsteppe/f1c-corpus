## MemoryAllocatorWithChunking_005160ad — ChunkedElementAllocator

**Summary:** Allocates elements in bulk chunks via MemoryAllocatorWithAlignment and builds a pointer-index array via MemoryAllocator. Stores computed chunk size at this+0x50. Returns pointer to the array of element pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DirectXTextureSurfaceAllocation (0051629f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object, read for vtable dispatch on error |
| obj | 0x14 | RW | 69 | written with constant 69 on element-too-large error |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x4 | R | — | base pointer for allocator state |
| this | 0x50 | RW | — | stores computed chunk size (max elements per allocation chunk) |

**Written-by note (persistence):**
- obj 0x14: written conditionally on error with constant 69
- this 0x50: written once with computed chunk size, persists for life of allocator

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515f23 | MemoryAllocator | allocates pointer-index array (4 * count bytes) |
| 0051601f | MemoryAllocatorWithAlignment | allocates element chunks (element_size * chunk_size bytes) |

**Guard conditions:**
1. 0x3B9AC9F0 / a3 <= 0: element size exceeds maximum allocation limit — calls error handler (constant 69)
2. v5 >= a4: computed max-chunk exceeds requested count — caps chunk size to a4
3. v5 >= a4 - v7: remaining elements fewer than chunk size — caps last chunk to remaining count
