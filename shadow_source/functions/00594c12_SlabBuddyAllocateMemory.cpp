// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00594C12
// Canonical corpus name: sub_594C12
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_594C12_00594c12.c

void UnknownObject::SlabBuddyAllocateMemory()
{
    // Slab/buddy allocator public memory allocation. Round-robins through the linked list of allocator contexts starting at off_5E9988, scanning each context's 8-byte free descriptors and carving a block with sub_594E1A; the descriptor start is shrunk and the cursor global updated on success. When no existing context fits, falls back to the static pool list headed by off_5E7968, and if a pool has spare descriptors commits pages with VirtualAlloc, zeroes them via sub_58BB10, and splits them into chained 4KB blocks recorded in the pool's descriptor table; if every pool is exhausted it creates a new allocator via SlabBuddyAllocatorInitialization and returns its first 256-byte block. Returns the allocated pointer (page base + 256) or 0 on failure.
    // ASSIGNMENT: v1 = off_5E9988 seeds the round-robin cursor from the allocator-context list [global:0x005E9988, source:raw]
    // LOOP: Walk the singly linked list of allocator contexts (v1 = *(char**)v1) until the cursor returns to off_5E9988 [global:0x005E9988, source:raw]
    // GUARD: A context whose page-base word v2 == -1 marks an exhausted context; the request size v5 is carried unchanged into the pool fallback [global:0x005E9988, source:raw]
    // ASSIGNMENT: v3 = *(v1 + 2) loads the context's descriptor cursor; v4 = v2 + 4096 * ((v3 - v1 - 24) >> 3) derives the 4KB page address from the descriptor's offset within the context's descriptor table [source:raw]
    // LOOP: Scan 8-byte free descriptors (start/size pairs) from v3 while v3 < v1 + 8216; a usable block needs *(v3) >= a1 and *(v3 + 1) > a1 so its span covers the request [source:raw]
    // CALL: sub_594E1A(v4, *(v3), a1) carves a block of size a1 from the page; on success the cursor global off_5E9988 is updated to v1, the descriptor start *(v3) is shrunk by v5, the new cursor *(v1 + 2) = v3 is stored, and the carved pointer is returned [callee:0x00594E1A, global:0x005E9988, source:raw]
    // ASSIGNMENT: When sub_594E1A fails, the descriptor's high bound *(v3 + 1) is lowered to a1 and the scan advances (v3 += 8, page v4 += 4096) [source:raw]
    // LOOP: A second scan from the descriptor-table base (v1 + 24) up to the recorded cursor v17 re-tries the tail of the table with the same carve-or-shrink logic [source:raw]
    // LOOP: When no existing context fits, walk the static pool list headed by off_5E7968 looking for a pool whose page base is valid and whose descriptor table is non-empty (*(v7 + 3) non-zero) [global:0x005E7968, source:raw]
    // CALL: When the pool list is exhausted, SlabBuddyAllocatorInitialization() creates a new allocator context; on success its first 256-byte block is set up (header size 240, next-free pointer, pool free-space decrement) and v16 + 256 is returned [callee:0x0059491A, source:raw]
    // RETURN: Return 0 when neither an existing context nor a fresh allocator can satisfy the request [source:raw]
    // ASSIGNMENT: v8 = *(v7 + 3) reads the pool's free-descriptor cursor; locate the first descriptor whose word is -1 (v20 counts the page index) [global:0x005E7968, source:raw]
    // CALL: VirtualAlloc(i, v20 << 12, 0x1000, 4) commits the selected pages; a return different from i fails the allocation (return 0) [global:0x0059E0A0, source:raw]
    // CALL: sub_58BB10(i, 0, 0) zero-initializes the freshly committed pages [callee:0x0058BB10, source:raw]
    // LOOP: Split the committed region into 4KB blocks chained through size headers/footers (payload 240, footer -1 sentinel, next-block pointers) and record each block pair in the pool's descriptor table [global:0x005E7968, source:raw]
    // ASSIGNMENT: off_5E9988 is updated to the current pool, the pool's free-descriptor cursor *(v7 + 3) is advanced, the request size a1 is stored in the page header byte, and *(v7 + 2) records the descriptor start [global:0x005E9988, source:raw]
    // CALCULATION: *v8 -= a1 and i[1] -= a1 shrink the pool's free-space bookkeeping; the returned pointer result = i + 64 lies 256 bytes into the first page [source:raw]
    // RETURN: Return the allocated pointer (i + 64) or 0 when page commit or allocator creation failed [source:raw]
    // CALL: Invoked by the frame-path allocator users sub_58A973, sub_58AB58 and sub_58B5D4 [caller:0x0058A973, caller:0x0058AB58, caller:0x0058B5D4, source:raw]

    // Conservative worker pseudocode:
    //   v1 = off_5E9988;
    //   do {
    //     v2 = *(v1 + 4);
    //     if (v2 != -1) { scan 8-byte descriptors; sub_594E1A carve or shrink; }
    //     v1 = *(char**)v1;
    //   } while (v1 != off_5E9988);
    //   v7 = &off_5E7968;
    //   while (*(v7 + 4) == -1 || !*(v7 + 3)) {
    //     v7 = *(char**)v7;
    //     if (v7 == &off_5E7968) { v15 = SlabBuddyAllocatorInitialization(); if (v15) { setup header; return v16 + 256; } return 0; }
    //   }
    //   i = *(v7 + 4) + (((v8 - v7 - 24) >> 3) << 12);
    //   if (VirtualAlloc(i, v20 << 12, 0x1000, 4) != i) return 0;
    //   sub_58BB10(i, 0, 0);
    //   split region into chained 4KB blocks; record descriptor pairs;
    //   off_5E9988 = v7; *(v7 + 3) = next free descriptor;
    //   *(BYTE*)(i + 8) = a1; *v8 -= a1; i[1] -= a1;
    //   return i + 64;
    // UNRESOLVED: The -1 sentinel on the page-base word and the exact pool/context list-node layout (offsets 2, 3 and 4 of each node) are read from the decompiler and not independently confirmed
    // UNRESOLVED: Whether i + 64 is a fixed 256-byte header offset or an alignment artifact is inferred from the return expression
    // UNRESOLVED: off_5E7968 as a fallback-only static pool list (the primary path is the off_5E9988 context list) is inferred from control flow
}
