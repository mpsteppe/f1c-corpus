// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051629F
// Canonical corpus name: DirectXTextureSurfaceAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXTextureSurfaceAllocation_0051629f.c

void UnknownObject::DirectXTextureSurfaceAllocation()
{
    // Allocates texture surfaces for a Direct3D texture manager. Walks two linked lists of surface descriptors (a first list and a second list), accumulating weighted pixel-area totals v3 and v4 over the unallocated nodes. When the first total v3 is positive, asks ShortComputation_935c for a budget-based scale factor v14 (clamped to a minimum of 1 when the returned budget is smaller than v4; else unlimited 1000000000), then walks both lists again and for each unallocated node either keeps the original width or clamps the allocated width to v14 times the node divisor, marks the node downscaled, allocates the backing memory (MemoryAllocatorWithChunking for the first list, ChunkedBufferAlloc for the second), zeroes per-node state fields and records the format read from the manager. Returns the last value computed by the budget calculation.
    // LOOP: Walk the first surface-descriptor list (head a1[1]+16) following next-pointers at node+36, and for each node whose allocation pointer (node+0) is zero accumulate v3 += node+8 * node+12 and v4 += node+8 * node+4 (weighted pixel-area totals). [field:*(this+0x68):0x00000000, field:*(this+0x68):0x00000004, field:*(this+0x68):0x00000008, field:*(this+0x68):0x0000000C, field:*(this+0x68):0x00000024, field:this:0x00000004, source:raw]
    // LOOP: Walk the second surface-descriptor list (head a1[1]+17) following next-pointers at node+36, and for each node whose allocation pointer (node+0) is zero accumulate v3 += (node+8 * node+12) << 7 and v4 += (node+8 * node+4) << 7 (same area totals, scaled by 1<<7). [field:*(this+0x6C):0x00000000, field:*(this+0x6C):0x00000004, field:*(this+0x6C):0x00000008, field:*(this+0x6C):0x0000000C, field:*(this+0x6C):0x00000024, field:this:0x00000044, source:raw]
    // GUARD: Only run the allocation pass when the first accumulated area term v3 is greater than zero. [source:raw]
    // CALL: ShortComputation_935c(a1, v3, v4): derive a budget (return value) from the two accumulated area terms; the result is used as a memory-budget ceiling. [callee:0x0051935C, source:raw]
    // GUARD: When the budget returned by ShortComputation_935c is smaller than v4, compute the per-surface scale factor v14 = budget / v3 and clamp it to a minimum of 1; otherwise treat the budget as unlimited (v14 = 1000000000). [source:raw]
    // GUARD: Per-node scale decision for first-list nodes: for each unallocated node compute the effective mip count (width - 1) / divisor + 1; when it exceeds v14, clamp the allocated width (node+16) to v14 * divisor and mark the node as downscaled (byte node+34 = 1), otherwise keep the original width (node+16 = width). [field:*(this+0x68):0x00000004, field:*(this+0x68):0x00000008, field:*(this+0x68):0x0000000C, field:*(this+0x68):0x00000010, field:*(this+0x68):0x00000022, source:raw]
    // CALL: SurfaceMemoryAllocate(a1): invoked after a first-list node's width is clamped, to reallocate the surface memory for the reduced size. [callee:0x00519361, source:raw]
    // ASSIGNMENT: Allocate and initialize a first-list node: node+0 = MemoryAllocatorWithChunking(a1, 1, node+8, node+16), zero node+24 and node+28, clear byte node+33, and copy the manager format value (a1[1]+19) into node+20. [callee:0x005160AD, field:*(this+0x68):0x00000000, field:*(this+0x68):0x00000014, field:*(this+0x68):0x00000018, field:*(this+0x68):0x0000001C, field:*(this+0x68):0x00000021, field:this:0x0000004C, source:raw]
    // GUARD: Per-node scale decision for second-list nodes: identical to the first list — clamp node+16 to v14 * divisor and mark byte node+34 = 1 when the effective mip count exceeds v14, else keep the original width. [field:*(this+0x6C):0x00000004, field:*(this+0x6C):0x00000008, field:*(this+0x6C):0x0000000C, field:*(this+0x6C):0x00000010, field:*(this+0x6C):0x00000022, source:raw]
    // CALL: SurfaceMemoryAllocate(a1): invoked after a second-list node's width is clamped, to reallocate the surface memory for the reduced size. [callee:0x00519361, source:raw]
    // ASSIGNMENT: Allocate and initialize a second-list node: node+0 = ChunkedBufferAlloc(a1, 1, node+8, node+16), zero node+24 and node+28, clear byte node+33, and copy the manager format value (a1[1]+19) into node+20. [callee:0x0051613F, field:*(this+0x6C):0x00000000, field:*(this+0x6C):0x00000014, field:*(this+0x6C):0x00000018, field:*(this+0x6C):0x0000001C, field:*(this+0x6C):0x00000021, field:this:0x0000004C, source:raw]
    // RETURN: Return the last value held by the result register (the budget from ShortComputation_935c, or the second-list head pointer when the guard v3 > 0 failed). [source:raw]

    // Conservative worker pseudocode:
    //   v1 = a1[1];
    //   v3 = v4 = 0;
    //   for (n = v1[16]; n; n = n[9]) if (!n[0]) { v3 += n[2]*n[3]; v4 += n[2]*n[1]; }
    //   for (n = v1[17]; n; n = *(n+36)) if (!*n) { v3 += (*(n+8) * *(n+12)) << 7; v4 += (*(n+8) * *(n+4)) << 7; }
    //   if (v3 > 0) {
    //       budget = ShortComputation_935c(a1, v3, v4);
    //       v14 = (budget < v4) ? max(budget / v3, 1) : 1000000000;
    //       for (n = v1[16]; n; n = *(n+36)) if (!*n) {
    //           if ((*(n+4) - 1) / *(n+12) + 1 > v14) { *(n+16) = v14 * *(n+12); SurfaceMemoryAllocate(a1); *(n+34) = 1; }
    //           else *(n+16) = *(n+4);
    //           *n = MemoryAllocatorWithChunking(a1, 1, *(n+8), *(n+16));
    //           *(n+24) = 0; *(n+28) = 0; *(n+33) = 0; *(n+20) = v1[19];
    //       }
    //       for (n = v1[17]; n; n = *(n+36)) if (!*n) {
    //           if ((*(n+4) - 1) / *(n+12) + 1 > v14) { *(n+16) = v14 * *(n+12); SurfaceMemoryAllocate(a1); *(n+34) = 1; }
    //           else *(n+16) = *(n+4);
    //           *n = ChunkedBufferAlloc(a1, 1, *(n+8), *(n+16));
    //           *(n+24) = 0; *(n+28) = 0; *(n+33) = 0; *(n+20) = v1[19];
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The exact base mapping between the raw source variables (a1, v1 = a1[1], list heads v1[16]/v1[17]) and the packet field bases *(this+0x68), *(this+0x6C) and this is not established by the packet; node offsets used here follow the extraction labels.
    // UNRESOLVED: The first-list head offset (v1[16]) has no corresponding packet field evidence reference; only the second-list head (this:0x44) and the format source (this:0x4C) are represented in the field table.
    // UNRESOLVED: The legacy ABI name 'DirectX_Texture_Surface_Allocation' (abi:lead) is retained as the proposed name via the existing analysis fill; the manager object type and the meaning of the budget return value are unknown.
    // UNRESOLVED: The destination of the two lists (texture surfaces versus some other resource class) and the interpretation of the accumulated terms as pixel areas are DERIVED from the fill, not independently evidenced.
}
