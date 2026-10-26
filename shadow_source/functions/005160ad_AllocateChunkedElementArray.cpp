// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005160AD
// Canonical corpus name: MemoryAllocatorWithChunking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocatorWithChunking_005160ad.c

void UnknownObject::AllocateChunkedElementArray()
{
    // Chunked element allocator: allocates a pointer-index array of a4 elements via MemoryAllocator, then fills it by allocating a4 elements in bulk chunks through MemoryAllocatorWithAlignment (chunk of at most v5 elements each). The max chunk size v5 = min(0x3B9AC9F0 / a3, a4) is stored at this+0x50, and the final chunk is capped to the remaining element count. An element size larger than 0x3B9AC9F0 triggers the error path: constant 69 written at obj+0x14 and a vtable dispatch through *a1. Returns the pointer-index array.
    // ASSIGNMENT: Cache the base pointer from this+0x4 (a1[1]) into v4 [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the max possible chunk as v5 = 0x3B9AC9F0 / a3 (elements per chunk bounded by the allocator's 1,000,000,000-byte ceiling) [source:raw]
    // GUARD: When 0x3B9AC9F0 / a3 <= 0 (element size exceeds the allocation ceiling): write constant 69 at obj+0x14 and dispatch the error handler through the object vtable at obj+0x0 (read as *a1), passing a1 [field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // GUARD: Cap the chunk size: when v5 >= a4, set v5 = a4 so a single chunk covers the whole request [source:raw]
    // ASSIGNMENT: Store the computed chunk size v5 at v4 + 76 (this+0x4 + 76 = this+0x50) [field:this:0x00000050, field:this:0x00000004, source:raw]
    // CALL: Allocate the pointer-index array v11 = MemoryAllocator(a1, a2, 4 * a4) [callee:0x00515F23, source:raw]
    // LOOP: Fill loop over v7 < a4; when v5 >= a4 - v7 the last chunk is capped to the remaining element count [source:raw]
    // CALL: Allocate a chunk of v5 elements: v8 = MemoryAllocatorWithAlignment(a1, a2, a3 * v5) [callee:0x0051601F, source:raw]
    // LOOP: Inner fill loop: store the current element pointer into the index array (v11 + 4*v7), advance v8 by a3, increment v7, repeat v9 times (v9 = v5) [source:raw]
    // RETURN: Return the pointer-index array v11; consumed by DirectXTextureSurfaceAllocation (0051629f) [caller:0x0051629F, source:raw]

    // Conservative worker pseudocode:
    //   base = this+0x4;
    //   chunk = 0x3B9AC9F0 / a3;
    //   if (chunk <= 0) { obj+0x14 = 69; vtable_call(a1); }
    //   if (chunk >= a4) chunk = a4;
    //   base+76 (this+0x50) = chunk;
    //   index = MemoryAllocator(a1, a2, 4 * a4);
    //   i = 0;
    //   while (i < a4) {
    //     if (chunk >= a4 - i) chunk = a4 - i;
    //     p = MemoryAllocatorWithAlignment(a1, a2, a3 * chunk);
    //     for (n = chunk; n; n--) { index[i] = p; p += a3; i++; }
    //   }
    //   return index;
    // UNRESOLVED: The class behind this+0x0 is not resolvable from this packet; the vtable dispatch on error and the obj+0x14 constant-69 convention belong to an unknown heap-manager hierarchy
    // UNRESOLVED: Whether the per-chunk element stride a3 and the index array (4 bytes per element) are meant to be consumed by callers as separate allocations is inferred from the sibling fill logic, not proven by a caller contract
}
