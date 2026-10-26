## MemoryAllocator_00515f23 — AllocFromFreeList

**Summary:** Custom heap allocator using per-category free lists with 8-byte aligned allocation. Traverses free list for best-fit block, creates new blocks via MallocWrapper when necessary, tracks total allocated bytes at this+0x4C. Calls ShortComputation_5f0e error handler on oversized allocation or out-of-memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryAllocatorWithChunking (005160ad), ChunkedBufferAlloc (0051613f), LinkedListNodeAllocAndInsert (005161dd), sub_51623E (0051623e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object, read for vtable dispatch in error handler |
| obj | 0x14 | RW | 12 | written with constant 12 when a2 >= 2 (signals category-based init) |
| obj | 0x18 | RW | — | written with category index a2 when a2 >= 2 |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x4 | R | — | base pointer for free list array (heads at +48 + 4*a2) |
| this | 0x4C | RW | — | running total of allocated bytes, incremented by new block size |

**Written-by note (persistence):**
- obj 0x14: written conditionally (when a2 >= 2) with constant 12
- obj 0x18: written conditionally (when a2 >= 2) with a2 value
- this 0x4C: incremented each time a new block is allocated, persistent counter

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af8b8 | dword_5AF8B8 | R | MemPoolFreeList — allocation chunk size for reusing existing free list |
| 005af8c0 | dword_5AF8C0 | R | HeapFreeListSize — allocation chunk size when no existing free list |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515f0e | ShortComputation_5f0e | error handler: arg=1 for oversized allocation (>0x3B9AC9F0), arg=2 for out-of-memory |
| 00519346 | MallocWrapper | underlying raw memory allocation from system heap |

**Guard conditions:**
1. a3 > 0x3B9AC9F0: oversized request — calls error handler (code 1), may be fatal
2. (a3 & 7) != 0: unaligned size — rounds up to next 8-byte boundary
3. a2 >= 2: writes constant 12 and category index to obj, dispatches via vtable
4. *v12 == NULL: free list head empty — skips directly to creating new block (LABEL_11)
5. v5[2] >= v3: block has enough space — PASS (use this block); blocked otherwise (continue traversal)
6. v5 == NULL: no suitable block found — creates new block allocation
