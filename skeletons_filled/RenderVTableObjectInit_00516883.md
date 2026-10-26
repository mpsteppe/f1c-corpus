## RenderVTableObjectInit_00516883 — AllocatorVTableInit

**Summary:** Allocates a 80-byte function dispatch table via MallocWrapper, populates it with 11 function pointers composing the allocator interface (MemoryAllocator, MemoryAllocatorWithAlignment, etc.), zeroes internal state fields, and stores the table at this+0x4. On allocation failure writes constant 53 to obj and dispatches error via vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50F632 (0050f632)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object, vtable dispatch for error path |
| obj | 0x14 | RW | 53 | written with constant 53 on MallocWrapper failure |
| obj | 0x18 | RW | 0 | written with 0 on MallocWrapper failure |
| this | 0x0 | R | — | vtable pointer for error dispatch |
| this | 0x4 | RW | 0 | stores pointer to allocated 80-byte function dispatch table, cleared to 0 before allocation |

**Written-by note (persistence):**
- obj 0x14: written only on allocation failure with constant 53
- obj 0x18: written only on allocation failure with 0
- this 0x4: set to 0 initially, then to allocated table on success; persists until freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00515f23 | MemoryAllocator | R | function pointer stored at table[0] — pool-based allocator |
| 0051601f | MemoryAllocatorWithAlignment | R | function pointer stored at table[1] — aligned allocator |
| 005160ad | MemoryAllocatorWithChunking | R | function pointer stored at table[2] — chunked allocator |
| 0051613f | ChunkedBufferAlloc | R | function pointer stored at table[3] — buffer allocator |
| 005161dd | LinkedListNodeAllocAndInsert | R | function pointer stored at table[4] — linked-list node allocator |
| 0051623e | sub_51623E | R | function pointer stored at table[5] — second linked-list node allocator |
| 0051629f | DirectXTextureSurfaceAllocation | R | function pointer stored at table[6] — texture surface allocator |
| 00516531 | RingBufferWriteWithBoundsCheck | R | function pointer stored at table[7] — ring buffer write |
| 0051664f | OffsetValidationWithBufferUpdate | R | function pointer stored at table[8] — buffer offset validation |
| 00516772 | sub_516772 | R | function pointer stored at table[9] — free list cleanup |
| 00516853 | TwoIterationCleanup | R | function pointer stored at table[10] — two-pass cleanup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00519346 | MallocWrapper | allocates 80-byte block for function dispatch table |
| 00587b96 | EmptyStub_7b96 | called on allocation failure before error dispatch |
| 0058fb7e | StubReturning0 | returns initial value stored at table[11] |

**Guard conditions:**
1. MallocWrapper return == NULL: allocation failure — writes constants 53 and 0 to obj, dispatches error via vtable (no return to caller)
2. MallocWrapper return != NULL: normal init — fills table, stores at this+0x4
