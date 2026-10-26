## DestroyUIWidgetHierarchy_004b5a30 — DestroyUIWidgetHierarchy

**Summary:** Destroys the entire UI widget hierarchy by cleaning up sprite overlays, freeing linked lists of widget nodes, releasing heap-allocated buffers, and zeroing all list-head pointers across multiple sub-hierarchy levels. Part of the UI teardown/cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B41D0 (004b41d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x6C0)+0x4) | 0x4 | R | — | next-pointer in linked-list node of widget sub-hierarchy (iterated for NodeDestructor) |
| *(*(this+0x6D4)+0x4) | 0x4 | R | — | next-pointer in linked-list node of second widget sub-hierarchy (iterated for ConditionalDestructor_46f0) |
| this | 0x6C0 | RW | 0 | linked-list head of first widget-node sub-hierarchy (zeroed after destruction) |
| this | 0x6C4 | RW | 0 | linked-list tail/sentinel of first widget-node sub-hierarchy |
| this | 0x6C8 | RW | 0 | linked-list count/size field of first widget-node sub-hierarchy |
| this | 0x6CC | RW | 0 | linked-list extra field of first widget-node sub-hierarchy |
| this | 0x6D4 | RW | 0 | linked-list head of second widget sub-hierarchy (iterated and zeroed) |
| this | 0x6D8 | RW | 0 | linked-list tail/sentinel of second widget sub-hierarchy |
| this | 0x6DC | RW | 0 | linked-list count/size field of second widget sub-hierarchy |
| this | 0x6E0 | RW | 0 | linked-list extra field of second widget sub-hierarchy |
| this | 0x704 | R | — | pointer to heap-allocated buffer (checked before FreeWrapper_7bcf call) |
| this | 0x70C | R | — | pointer to heap-allocated buffer (checked before free) |
| this | 0x724 | R | — | pointer to heap-allocated buffer (checked before free) |
| this | 0x72C | R | — | pointer to heap-allocated buffer (checked before free) |
| this | 0xF94 | R | — | pointer to sprite overlay heap data (freed if non-null, then dangling) |

**Written-by note (persistence):**
- this 0x6C0: written once during destruction (zeroed) — object is dead after this call; poke meaningless
- this 0x6C4: written once during destruction — object is dead after this call
- this 0x6C8: written once during destruction — object is dead after this call
- this 0x6CC: written once during destruction — object is dead after this call
- this 0x6D4: written once during destruction — object is dead after this call
- this 0x6D8: written once during destruction — object is dead after this call
- this 0x6DC: written once during destruction — object is dead after this call
- this 0x6E0: written once during destruction — object is dead after this call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004646f0 | ConditionalDestructor_46f0 | conditionally destroy a UI node element (virtual destructor dispatch) |
| 0049af30 | LinkedListFree | free all nodes in a linked list |
| 004b0170 | EmptyStub_0170 | no-op stub (placeholder or disabled cleanup path) |
| 004b52a0 | ListRebuildWithNodeTransfer | rebuild list by transferring surviving nodes to new structure |
| 004b5e50 | sub_4B5E50 | pre-cleanup step for widget hierarchy teardown |
| 004b5f60 | LinkedBufferTransfer | transfer linked buffer ownership before destruction |
| 004b6130 | SpriteOverlayListCleanup | cleanup sprite overlay resources |
| 004ba8c0 | NodeDestructor | destroy a single UI widget node |
| 004ba900 | LinkedListNodeDestructor_a900 | destroy a linked-list node with internal cleanup |
| 004ba9f0 | LinkedListDestruction | destroy entire linked list (walk and free each node) |
| 004baeb0 | LinkedListDestructorWithCallback | destroy linked list with per-node callback |
| 004bb400 | LinkedListDestructor_b400 | destroy linked-list variant (b400) |
| 004bb4f0 | LinkedListDestructionWithRefCountLoop | destroy linked list with reference-count walk |
| 004bb650 | ListFullDestruction | full destruction of list including internal structures |
| 005668d0 | SubCallWithConditionalFieldFree | conditional field check then free on sub-structure |
| 00587bcf | FreeWrapper_7bcf | free heap-allocated memory block |

**Guard conditions:** Heap-pointer guards: each FreeWrapper_7bcf call is gated by a null-check on the pointer field (0x704, 0x70C, 0x724, 0x72C, 0xF94) — non-null PASSES into free, null BLOCKS the free call. Linked-list iteration guards: while loops walk next-pointers until null (end of list). The outer loop (v9=104) iterates 104 times destroying four-field groups per iteration — all PASS unconditionally.