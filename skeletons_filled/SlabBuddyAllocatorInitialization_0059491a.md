## SlabBuddyAllocatorInitialization_0059491a — SlabBuddyAllocatorInit

**Summary:** Initializes the slab buddy allocator. Selects context (static pool or HeapAlloc), reserves 4MB virtual address space, commits initial 64KB, initializes per-block free lists and block headers in committed region. Returns allocator context pointer or 0 on allocation failure.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_59325D (0059325d), sub_594C12 (00594c12)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0a0 | VirtualAlloc | R | kernel32!VirtualAlloc — reserve 4MB / commit 64KB for allocator arena |
| 0059e0a4 | VirtualFree | R | kernel32!VirtualFree — release virtual reservation on failure cleanup |
| 0059e1bc | HeapFree | R | kernel32!HeapFree — free allocator context on failure |
| 0059e1c0 | HeapAlloc | R | kernel32!HeapAlloc — allocate allocator context (8224 bytes) |
| 005e7968 | off_5E7968 | RW | HeapListHead [DERIVED] — static pool linked list head |
| 005e796c | off_5E796C | RW | MemMgr_HeapFreeListHead [DERIVED] — free list head pointer |
| 005e7978 | dword_5E7978 | R | HeapMarker [DERIVED] — if -1, use static pool; otherwise heap-allocate context |
| 008d4904 | hHeap | R | PrivateHeapHandle [DERIVED] — OS heap for backing allocations |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058bb10 | sub_58BB10 | zero-initialize committed 64KB region (memset) |

**Guard conditions:** Three allocation guards return 0: (1) `HeapAlloc(hHeap, 0, 0x2020)` returns 0 (when not static pool) → return 0; (2) first `VirtualAlloc(0, 0x400000, 0x2000, 4)` returns 0 → cleanup context, return 0; (3) second `VirtualAlloc(v1, 0x10000, 0x1000, 4)` returns 0 → VirtualFree the first alloc, cleanup, return 0.
