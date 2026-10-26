## ResourcePoolNodeAllocDealloc_00490940 — PoolNodePopOrAlloc

**Summary:** Pool node allocator: tries to pop a node from global pool's free list; if empty, allocates + initializes new node and appends to pool. Runs secondary dealloc-walk to remove a matching value node. Ends with ShortComputation_16e0 on inputs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionBroadphaseBuilder (00490ee0), RectangleClipping (00491350), sub_4919C0 (004919c0), CollisionProxyListBuilder (00491ad0), ShortComputation_1c70 (00491c70), ShortComputation_1cb0 (00491cb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434030 | DoublyLinkedListAppend | Append newly allocated node to pool's free list |
| 00490930 | GlobalDataRead | Read global data structure containing pool state |
| 004912f0 | ThunkToFUN00491330 | Initialize 4 DWORDs in a pool data block |
| 004916e0 | ShortComputation_16e0 | Short computation on input parameters (a1-a4) |
| 00491d30 | LinkedListNodeRemovalByValue | Remove linked list node by its value field (unlink) |
| 00491e40 | sub_491E40 | Destructor/cleanup for a pool node |
| 004bb490 | sub_4BB490 | Clear/zero memory region within a pool node |
| 00587bcf | FreeWrapper_7bcf | Free heap memory for a deallocated node |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate heap memory for a new pool node |

**Guard conditions:** Path 1 (pop from free list): if head pointer `v4[4]` (offset +0x10) is non-null → attempt reuse by calling LinkedListNodeRemovalByValue; if removal fails (returns 0) → v7=0, falls to alloc path. Path 2 (dealloc walk): if list `*v6` (head) is non-null AND `*v15` (first node value) is non-zero → walk list looking for node matching v16, unlink and free it.
