// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593E46
// Canonical corpus name: sub_593E46
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_593E46_00593e46.c

void UnknownObject::SlabHeapFreeCoalesceBlock()
{
    // Frees a block in a custom slab buddy allocator: coalesces with adjacent free blocks, updates the two-level 64-size-class occupancy bitmaps (allocator-level at this+0x0 and this+0x4, per-slab at result[v4+17] and result[v4+49]) and the doubly-linked per-class free lists, and when the slab and then its descriptor become fully empty, releases the slab virtual memory and frees the descriptor backing block.
    // CALCULATION: Compute slab index v4 = (a2 - slab base at this+0xC) >> 15; slabs are 0x8000 bytes. [field:this:0x0000000C, source:raw]
    // GUARD: Read block header at a2-4; if (header - 1) has bit 0 set the block is in use and the free/coalesce path is skipped. [source:raw]
    // CALCULATION: Clamp the freed block size class v7 = (v20 >> 4) - 1 into the range 0..63. [source:raw]
    // GUARD: If the next block header fields v6[1] and v6[2] are equal the next block is free, so coalesce it into the block being freed. [source:raw]
    // STATE_TRANSITION: For coalesced blocks whose size class is below 32: clear the class bit in the per-slab lower bitmap result[v4+17]; when class occupancy drops to zero, clear the matching bit in the allocator-level lower bitmap at this+0x0. [field:this:0x00000010, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: For coalesced blocks whose size class is 32 or above: clear the class bit in the per-slab upper bitmap result[v4+49]; when class occupancy drops to zero, clear the matching bit in the allocator-level upper bitmap at this+0x4. [field:this:0x00000010, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Unlink the free next block from its size class: write v6[2] + 4 = v6[1] and v6[1] + 8 = v6[2], then merge sizes v5 += v20. [source:raw]
    // GUARD: If the previous block header v21 at a2-8 is free, merge left: v24 = v3 - v21 and merged size v22 = v21 + v5. [source:raw]
    // CALCULATION: Clamp the merged block size class v13 = (v22 >> 4) - 1 into the range 0..63. [source:raw]
    // STATE_TRANSITION: When the previous block was free and its class v14 differs from the merged class v13, clear the old class bit in the per-slab bitmap (result[v4+17] for classes below 32, result[v4+49] otherwise), clear the allocator-level bit at this+0x0 or this+0x4 when occupancy hits zero, and unlink the previous block (v24[2] + 4 = v24[1], v24[1] + 8 = v24[2]). [field:this:0x00000010, field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Link the merged block into the size class v13 free list: v3[1] = v17[1], v3[2] = v17, v17[1] = v3, v3[1] + 8 = v3, and write the merged size into both block headers (*v3 = v22 and *(v3 + v22 - 4) = v22). [source:raw]
    // STATE_TRANSITION: Increment the class occupancy byte at result + v13 + 4; when it was zero, set the class bit in the per-slab bitmap (result[v4+17] below class 32, result[v4+49] otherwise) and the allocator-level bit at this+0x0 or this+0x4. [field:this:0x00000010, field:this:0x00000000, field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Decrement the per-slab live-block counter (*v19 at result[129 * v4 + 81]); when it reaches zero the whole 0x8000-byte slab is empty. [field:this:0x00000010, source:raw]
    // STATE_TRANSITION: When the slab is empty and a descriptor exists at dword_8D48F4, release the slab's virtual memory via VirtualFree (address from dword_8D48EC shifted by 15, size 0x8000), mark the descriptor flags at desc+8, zero the slab slot at desc[16] + 4 * dword_8D48EC + 196, and decrement the descriptor's live-slab count at desc[16] + 67. [global:0x008D48F4, global:0x008D48EC, global:0x0059E0A4, source:raw]
    // STATE_TRANSITION: When the descriptor's live-slab count reaches zero, clear the descriptor in-use flag at desc + 4 (desc + 4 AND NOT 1). [global:0x008D48F4, source:raw]
    // STATE_TRANSITION: When the descriptor is fully freed (desc + 8 == -1): VirtualFree the descriptor backing memory at desc + 12, HeapFree(hHeap, 0, desc + 16), call sub_58B130 to compact free-list entries (desc, desc + 20, lpMem + 20 * dword_8D48F8 - desc - 20), decrement dword_8D48F8, step a1 back by 5 words when it lies above the descriptor, and reset the allocation cursor dword_8D48F0 to lpMem. [callee:0x0058B130, global:0x0059E1BC, global:0x0059E0A4, global:0x008D4904, global:0x008D48FC, global:0x008D48F8, global:0x008D48F0, source:raw]
    // ASSIGNMENT: Commit allocator metadata: set dword_8D48EC = v4 (current slab index) and dword_8D48F4 = a1 (current descriptor). [global:0x008D48EC, global:0x008D48F4, source:raw]
    // RETURN: Return the allocator descriptor pointer (a1). [source:raw]

    // Conservative worker pseudocode:
    //   slabIndex = (ptr - this.slabBase(0xC)) >> 15
    //   if block header at ptr-4 has bit 0 set: return (block in use)
    //   merge right neighbor if free; merge left neighbor if free
    //   update per-slab class bitmaps result[slabIndex+17] and result[slabIndex+49] and allocator bitmaps this+0x0 / this+0x4
    //   relink merged block into its size class free list
    //   if slab live counter reaches zero: VirtualFree slab, update descriptor flags and counts
    //   if descriptor fully free: VirtualFree backing memory, HeapFree descriptor block, sub_58B130 compact, update globals
    // UNRESOLVED: Exact descriptor sub-structure layout (flags at desc+4, desc+8, backing pointer at desc+12, arrays at desc+16 and desc+20) is inferred from pointer arithmetic only, not an authoritative struct definition.
    // UNRESOLVED: The allocator-level bitmap is split between this+0x0 (classes 0-31) and this+0x4 (classes 32-63); per-slab equivalents sit in the descriptor array returned by this+0x10 at word indices v4+17 and v4+49.
    // UNRESOLVED: sub_58B130 is interpreted as free-list compaction per prior analysis; its exact contract is not independently verified here.
}
