// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515F23
// Canonical corpus name: MemoryAllocator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocator_00515f23.c

void UnknownObject::AllocFromFreeList()
{
    // Per-category free-list allocator for a custom heap. Aligns the request up to an 8-byte boundary, walks the per-category free list (head at this+0x4 + 4*cat + 48) for a first-fit block, and when none fits allocates a fresh block through MallocWrapper (chunk budget from dword_5AF8B8/dword_5AF8C0, halving on OOM, erroring through ShortComputation_5f0e). New blocks are chained into the list and the running total at this+0x4C is incremented. The found block is then carved: its free size shrinks by the request and a pointer 16 bytes past the block header (which carries size fields at +8 and +4) is returned.
    // GUARD: Reject oversized requests: when a3 exceeds 0x3B9AC9F0, call ShortComputation_5f0e(a1, 1) as the error handler for an oversized allocation [callee:0x00515F0E, source:raw]
    // CALCULATION: Align the request up to the next 8-byte boundary: v3 = a3 + (8 - (a3 & 7)) when a3 is not already a multiple of 8 [source:raw]
    // ASSIGNMENT: Category initialization for a2 >= 2: write constant 12 to the sub-object at obj+0x14 and the category index to obj+0x18, where obj is the object whose pointer lives at this+0x0 (the vtable pointer used by the virtual dispatch) [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALL: Invoke the category-initialization callback through the vtable stored at *a1 (obj+0x0), passing the allocator itself [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALCULATION: Compute the free-list head for category a2 as this+4 + 4*a2 + 48 (v11 = this+0x4 is the head-array base) [field:this:0x00000004, source:raw]
    // LOOP: Walk the category free list tracking the previous block v13, stopping at the first block whose size field (v5+8) is at least the aligned request v3; when the list is exhausted (v5 null) a new block must be allocated [source:raw]
    // CALCULATION: Budget a new block: total v6 = request + 16 for the block header, with the chunk size taken from dword_5AF8C0[a2] when a list block exists or dword_5AF8B8[a2] otherwise, capped at 1000000000 - v6 [global:0x005AF8C0, global:0x005AF8B8, source:raw]
    // CALL: Allocate the new block with MallocWrapper(a1, v7 + v6), retrying with v7 halved on failure and invoking ShortComputation_5f0e(a1, 2) once v7 drops below 0x32 (out-of-memory) [callee:0x00519346, callee:0x00515F0E, source:raw]
    // ASSIGNMENT: Account and link the new block: add v7 + v6 to the running byte counter at this+0x4C (v11+72), zero the block's forward/backward links, set its size to v3 + v7, and insert it at the head of the category list [field:this:0x0000004C, source:raw]
    // CALCULATION: Carve the request out of the found block: reduce the block size field (v5+8) by v3 and advance the data offset field (v5+4) by v3 [source:raw]
    // RETURN: Return the payload pointer: block base + prior data offset + 16 (skipping the block header). Consumed by MemoryAllocatorWithChunking, ChunkedBufferAlloc, LinkedListNodeAllocAndInsert and sub_51623E [function:0x00515F23, caller:0x005160AD, caller:0x0051613F, caller:0x005161DD, caller:0x0051623E, source:raw]

    // Conservative worker pseudocode:
    //   align request v3 up to 8 bytes;
    //   if (a3 > 0x3B9AC9F0) ShortComputation_5f0e(a1, 1);
    //   if (a2 >= 2) { obj->[0x14] = 12; obj->[0x18] = a2; vtable_call(a1); }
    //   head = (v11 + 4*a2 + 48); block = *head; prev = 0;
    //   while (block && block->size < v3) { prev = block; block = block->next; }
    //   if (!block) {
    //     chunk = prev ? dword_5AF8C0[a2] : dword_5AF8B8[a2];
    //     chunk = min(chunk, 1000000000 - (v3+16));
    //     do { block = MallocWrapper(a1, chunk + v3 + 16); chunk >>= 1; }
    //     while (!block && chunk >= 0x32);
    //     if (!block) ShortComputation_5f0e(a1, 2);
    //     *(v11+72) += chunk + v3 + 16;
    //     init block links, size = v3 + chunk; link into list;
    //   }
    //   block->size -= v3;
    //   return block + block->data_offset + 16;
    // UNRESOLVED: The class behind this+0x0 is not resolvable from this packet; the vtable dispatch in the a2 >= 2 branch and the sub-object layout (obj+0x14/+0x18) belong to an unknown heap-manager hierarchy
}
