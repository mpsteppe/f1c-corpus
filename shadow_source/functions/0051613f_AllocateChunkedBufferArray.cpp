// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051613F
// Canonical corpus name: ChunkedBufferAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChunkedBufferAlloc_0051613f.c

void UnknownObject::AllocateChunkedBufferArray()
{
    // Chunked buffer allocator, a structural twin of MemoryAllocatorWithChunking (005160ad) with element units scaled by 2^7 (128). Allocates a pointer-index array of a4 entries via MemoryAllocator, then fills it by allocating a4 buffers in bulk chunks through MemoryAllocatorWithAlignment, where each buffer is a3*128 bytes and each chunk holds at most v5 = min(0x3B9AC9F0 / (a3 << 7), a4) buffers. The chunk size is stored at this+0x50 and the final chunk is capped to the remaining count. A buffer size larger than the 0x3B9AC9F0 ceiling triggers the error path: constant 69 at obj+0x14 and a vtable dispatch through *a1. Returns the pointer-index array.
    // ASSIGNMENT: Cache the base pointer from this+0x4 (a1[1]) into v4 [field:this:0x00000004, source:raw]
    // CALCULATION: Compute the max possible chunk as v5 = 0x3B9AC9F0 / (a3 << 7) (buffers per chunk, each buffer a3*128 bytes, bounded by the allocator's 1,000,000,000-byte ceiling) [source:raw]
    // GUARD: When 0x3B9AC9F0 / (a3 << 7) <= 0 (buffer size exceeds the allocation ceiling): write constant 69 at obj+0x14 and dispatch the error handler through the object vtable at obj+0x0 (read as *a1), passing a1 [field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // GUARD: Cap the chunk size: when v5 >= a4, set v5 = a4 so a single chunk covers the whole request [source:raw]
    // ASSIGNMENT: Store the computed chunk size v5 at v4 + 76 (this+0x4 + 76 = this+0x50) [field:this:0x00000050, field:this:0x00000004, source:raw]
    // CALL: Allocate the pointer-index array v11 = MemoryAllocator(a1, a2, 4 * a4) [callee:0x00515F23, source:raw]
    // LOOP: Fill loop over v7 < a4; when v5 >= a4 - v7 the last chunk is capped to the remaining count [source:raw]
    // CALL: Allocate a chunk of v5 buffers: v8 = MemoryAllocatorWithAlignment(a1, a2, (a3 * v5) << 7) [callee:0x0051601F, source:raw]
    // LOOP: Inner fill loop: store the current buffer pointer into the index array (v11 + 4*v7), advance v8 by 32 * a3 (a3*128 bytes), increment v7, repeat v9 times (v9 = v5) [source:raw]
    // RETURN: Return the pointer-index array v11; consumed by DirectXTextureSurfaceAllocation (0051629f) [caller:0x0051629F, source:raw]

    // Conservative worker pseudocode:
    //   base = this+0x4;
    //   chunk = 0x3B9AC9F0 / (a3 << 7);
    //   if (chunk <= 0) { obj+0x14 = 69; vtable_call(a1); }
    //   if (chunk >= a4) chunk = a4;
    //   base+76 (this+0x50) = chunk;
    //   index = MemoryAllocator(a1, a2, 4 * a4);
    //   i = 0;
    //   while (i < a4) {
    //     if (chunk >= a4 - i) chunk = a4 - i;
    //     p = MemoryAllocatorWithAlignment(a1, a2, (a3 * chunk) << 7);
    //     for (n = chunk; n; n--) { index[i] = p; p += 32 * a3; i++; }
    //   }
    //   return index;
    // UNRESOLVED: The class behind this+0x0 is not resolvable from this packet; the vtable dispatch on error and the obj+0x14 constant-69 convention belong to an unknown heap-manager hierarchy
    // UNRESOLVED: The 128-byte unit multiplier (a3 << 7, advance of 32 * a3) is only evidence of buffer granularity; the concrete buffer type and the caller's use of the returned array are not determined by this packet
}
