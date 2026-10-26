## MemoryAllocatorWithAlignment_0051601f — AlignedAllocFromMalloc

**Summary:** Allocates 8-byte aligned memory via MallocWrapper, links each new block into a per-category singly-linked free list at this+0x3C+4*a2. Always allocates fresh from system heap (no block splitting). Tracks total allocation size at this+0x4C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MemoryAllocatorWithChunking (005160ad), ChunkedBufferAlloc (0051613f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | first field of sub-object, read for vtable dispatch in init path |
| obj | 0x14 | RW | 12 | written with constant 12 when a2 >= 2 |
| obj | 0x18 | RW | — | written with category index a2 when a2 >= 2 |
| this | 0x0 | R | — | vtable pointer for virtual dispatch |
| this | 0x4 | R | — | base pointer for per-category free list array |
| this | 0x4C | RW | — | running total of allocated bytes, incremented by each allocation |

**Written-by note (persistence):**
- obj 0x14: written conditionally (when a2 >= 2) with constant 12
- obj 0x18: written conditionally (when a2 >= 2) with a2 value
- this 0x4C: incremented each allocation, persistent counter

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515f0e | ShortComputation_5f0e | error handler: arg=3 for oversized allocation, arg=4 for MallocWrapper failure |
| 00519346 | MallocWrapper | underlying raw memory allocation from system heap |

**Guard conditions:**
1. a3 > 0x3B9AC9F0: oversized request — calls error handler (code 3)
2. (a3 & 7) != 0: unaligned size — rounds up to next 8-byte boundary
3. a2 >= 2: writes constant 12 and category index to obj, dispatches via vtable
4. !v5 (MallocWrapper returned NULL): allocation failure — calls error handler (code 4)
