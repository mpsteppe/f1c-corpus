// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059491A
// Canonical corpus name: SlabBuddyAllocatorInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SlabBuddyAllocatorInitialization_0059491a.c

void UnknownObject::initializeSlabBuddyAllocator()
{
    // Initializes a slab/buddy-style allocator. If dword_5E7978 == -1 the allocator context v0 is the static pool &off_5E7968; otherwise v0 = HeapAlloc(hHeap, 0, 0x2020). On allocation failure returns 0. Reserves a 0x400000-byte region with VirtualAlloc(0, 0x400000, 0x2000, 4); on failure frees the heap context and returns 0. Commits 0x10000 bytes with VirtualAlloc(v1, 0x10000, 0x1000, 4); on failure calls VirtualFree(v2, 0, 0x8000), frees the context, and returns 0. Links the context into a free list: static-pool case self-links off_5E7968/off_5E796C, heap case inserts v0 between off_5E7968 and off_5E796C. Initializes context header fields (v0[2..5]), fills a 1024-entry x 2-word free-list table, zeroes the committed region via sub_58BB10, and walks 1024-byte slabs setting header words. Returns the context pointer v0.
    // GUARD: If dword_5E7978 == -1, use the static pool; otherwise heap-allocate the allocator context [global:0x005E7978, abi:lead, source:raw]
    // ASSIGNMENT: v0 = &off_5E7968 (static pool context) [global:0x005E7968]
    // CALL: v0 = HeapAlloc(hHeap, 0, 0x2020) — allocate 0x2020-byte allocator context from the private heap [global:0x0059E1C0, global:0x008D4904]
    // GUARD: If v0 == 0 (HeapAlloc failed), return 0 [source:raw]
    // CALL: v1 = VirtualAlloc(0, 0x400000, 0x2000, 4) — reserve 0x400000-byte virtual address region [global:0x0059E0A0]
    // GUARD: If v1 == 0, free heap context (if not static pool) and return 0 [source:raw]
    // CALL: VirtualAlloc(v1, 0x10000, 0x1000, 4) — commit initial 0x10000 bytes of the reservation [global:0x0059E0A0]
    // CALL: On commit failure: VirtualFree(v2, 0, 0x8000) — release the reservation [global:0x0059E0A4]
    // CALL: On failure cleanup: HeapFree(hHeap, 0, v0) — free heap-allocated context when not the static pool [global:0x0059E1BC, global:0x008D4904]
    // STATE_TRANSITION: Static-pool case: if off_5E7968 is 0 set it to &off_5E7968; if off_5E796C is 0 set it to &off_5E7968 (self-linked list head) [global:0x005E7968, global:0x005E796C]
    // STATE_TRANSITION: Heap case: insert v0 into the list — v0[0] = &off_5E7968, v0[1] = off_5E796C, off_5E796C = v0, *(v0[1]) = v0 [global:0x005E7968, global:0x005E796C]
    // ASSIGNMENT: v0[5] = v2 + 0x100000 (end/limit pointer of the arena) [source:raw]
    // ASSIGNMENT: v0[3] = v0 + 38 (pointer into the context's own embedded table) [source:raw]
    // ASSIGNMENT: v0[4] = v2 (base pointer of the committed arena) [source:raw]
    // ASSIGNMENT: v0[2] = v0 + 6 (start of the free-list table) [source:raw]
    // LOOP: Fill the 1024-entry x 2-word free-list table (v3 starting at v0+6): entry value is 240 while index < 16 else -1; second word always 241; advance 2 words per iteration [source:raw]
    // CALL: sub_58BB10(v2, 0, 0x10000) — zero-initialize the committed 0x10000-byte region [callee:0x0058BB10]
    // LOOP: Walk 1024-byte slabs from v2 while v2 < v0[4] + 0x10000: set slab header byte at +248 to -1, word at +0 to next-slab pointer (v2 + 2), word at +4 to 240; advance by 1024 bytes [source:raw]
    // RETURN: Return v0 (allocator context pointer) [function:0x0059491A, source:raw]

    // Conservative worker pseudocode:
    //   int* initializeSlabBuddyAllocator() {
    //       int* ctx;
    //       if (dword_5E7978 == -1) ctx = &off_5E7968;
    //       else {
    //           ctx = HeapAlloc(hHeap, 0, 0x2020);
    //           if (!ctx) return 0;
    //       }
    //       int* arena = VirtualAlloc(0, 0x400000, 0x2000, 4);
    //       if (!arena) { if (ctx != &off_5E7968) HeapFree(hHeap, 0, ctx); return 0; }
    //       if (!VirtualAlloc(arena, 0x10000, 0x1000, 4)) {
    //           VirtualFree(arena, 0, 0x8000);
    //           if (ctx != &off_5E7968) HeapFree(hHeap, 0, ctx);
    //           return 0;
    //       }
    //       if (ctx == &off_5E7968) {
    //           if (!off_5E7968) off_5E7968 = &off_5E7968;
    //           if (!off_5E796C) off_5E796C = &off_5E7968;
    //       } else {
    //           ctx[0] = &off_5E7968; ctx[1] = off_5E796C; off_5E796C = ctx; *(int*)ctx[1] = ctx;
    //       }
    //       ctx[5] = arena + 0x100000; ctx[3] = ctx + 38; ctx[4] = arena; ctx[2] = ctx + 6;
    //       int* e = ctx + 6;
    //       for (int i = 0; i < 1024; i++) { e[0] = (i < 16) ? 240 : -1; e[1] = 241; e += 2; }
    //       sub_58BB10(arena, 0, 0x10000);
    //       for (char* p = arena; p < (char*)ctx[4] + 0x10000; p += 1024) {
    //           *(p + 248) = -1; *(int*)p = p + 8; *(int*)(p + 4) = 240;
    //       }
    //       return ctx;
    //   }
    // UNRESOLVED: Exact semantics of dword_5E7978 marker and the static pool off_5E7968/off_5E796C list role are DERIVED-level; not independently verified.
    // UNRESOLVED: sub_58BB10 is treated as a zero-fill routine here per the raw source call signature; its implementation is not analyzed in this packet.
    // UNRESOLVED: Allocator owner class unknown; the free-list table layout (which entry maps to which block size) is not established.
}
