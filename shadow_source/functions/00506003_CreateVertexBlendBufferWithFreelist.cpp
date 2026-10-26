// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00506003
// Canonical corpus name: sub_506003
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_506003_00506003.c

void UnknownObject::CreateVertexBlendBufferWithFreelist()
{
    // Builds a weighted-blend vertex staging pipeline. Guards on matching depth (offset 4192) on the source and destination objects, allocates coordinate remap tables for both dimensions via ComplexMemoryAllocationWithFloatComputation, allocates a vertex buffer whose elements are zero-initialised and freed through registered callbacks, builds a source contribution table, accumulates weighted source floats into destination vertices through an indirect vtable method, and recycles released vertex slots through a free list. Frees every allocated staging structure before returning the status code.
    // CALL: Initialise the structured exception handler for the function body. [callee:0x0058A5D8, source:raw]
    // GUARD: Guard on both depth fields at offset 4192 of the source object (v1[1]) and destination object (*v1) equalling 1; if either is not 1, return -2147467259. [source:raw]
    // CALL: Call ComplexMemoryAllocationWithFloatComputation with the offset 4184 dimension sizes of both objects to build the first coordinate remap table. [callee:0x00502C28, source:raw]
    // CALL: Call ComplexMemoryAllocationWithFloatComputation with the offset 4188 dimension sizes of both objects to build the second coordinate remap table. [callee:0x00502C28, source:raw]
    // GUARD: Guard that both remap table allocations succeeded; otherwise fall through to the error return -2147467259. [source:raw]
    // CALL: Allocate the staging buffer header with OperatorNewNhMallocWrapper(12 * elementCount + 4); the first dword stores the element count and the element array starts one dword later. [callee:0x00587C03, source:raw]
    // CALL: Construct the vertex buffer element array via NTimeCallbackLoopWithSEH_a6eb using TripleDwordZeroInit as the per-element initialiser and FreeWrapper as the per-element free callback. [callee:0x0058A6EB, global:0x00502C12, global:0x00502C1F, source:raw]
    // CALL: Allocate the source contribution table with OperatorNewNhMallocWrapper(16 * sourceCount) and construct its elements with sub_5008C2 using sub_5007EC as the element constructor. [callee:0x00587C03, callee:0x005008C2, global:0x005007EC, source:raw]
    // GUARD: Guard that the staging buffer pointer and the source table are both non-null; otherwise jump to LABEL_47 and return error -2147024882. [source:raw]
    // LOOP: Iterate the first remap table entries and increment the reference count stored at offset 8 of each addressed vertex buffer slot (12-byte stride). [source:raw]
    // LOOP: Iterate the second remap table entries; for each slot with a null element either reuse a freed slot from the free list or allocate and construct a new one via OperatorNewNhMallocWrapper and sub_5008C2/sub_5007EC, zeroing it with memset. [callee:0x00587C03, callee:0x005008C2, global:0x005007EC, source:raw]
    // CALL: Invoke the indirect vtable method at *(*(*v2) + 4) on the destination object to emit the accumulated vertices. [source:raw]
    // CALCULATION: Weighted blend accumulation loop: for each source/destination pair multiply source floats by a weight and accumulate them into the destination vertex components (stride 16 bytes per vertex). [source:raw]
    // STATE_TRANSITION: Decrement the per-slot reference count; when it reaches zero invoke the release vtable method at *(*(*v2[1]) + 8) and push the slot onto the free list. [source:raw]
    // CALL: Conditionally free the vertex buffer via ConditionalFree_2ee5 when the element array is present. [callee:0x00502EE5, source:raw]
    // CALL: Free the two coordinate remap tables and the source contribution table via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return the status code v38 (0 on success, -2147467259 on allocation/guard failure, -2147024882 when the staging buffer is absent). [source:raw]
    // CALL: Called by D3DContextInit (0x005063A5) to create the vertex buffer during D3D context initialisation. [caller:0x005063A5, source:raw]

    // Conservative worker pseudocode:
    //   int CreateVertexBlendBufferWithFreelist() {
    //     SEHHandlerInit();
    //     if (src->depth(4192) != 1 || dst->depth(4192) != 1) return E_FAIL;
    //     remapX = ComplexMemoryAllocationWithFloatComputation(src->dim(4184), dst->dim(4184), flags);
    //     remapY = ComplexMemoryAllocationWithFloatComputation(src->dim(4188), dst->dim(4188), flags);
    //     if (!remapX || !remapY) return E_FAIL;
    //     staging = OperatorNewNhMallocWrapper(12 * remapYCount + 4);
    //     NTimeCallbackLoopWithSEH_a6eb(staging + 1, 12, remapYCount, TripleDwordZeroInit, FreeWrapper);
    //     srcTable = OperatorNewNhMallocWrapper(16 * remapXCount);
    //     sub_5008C2(srcTable, 16, remapXCount, sub_5007EC);
    //     if (!staging || !srcTable) { v38 = E_OUTOFMEMORY; goto cleanup; }
    //     /* refcount increment pass, free-list recycling, weighted blend accumulation * /
    //     v38 = 0;
    //   cleanup:
    //     ConditionalFree_2ee5(staging, 3);
    //     FreeWrapper_7bcf(remapY); FreeWrapper_7bcf(remapX); FreeWrapper_7bcf(srcTable);
    //     return v38;
    //   }
    // UNRESOLVED: Identity of the two objects at v1[0] and v1[1] and the meaning of the depth fields at offset 4192.
    // UNRESOLVED: The indirect vtable methods at *(*(*v2) + 4) and *(*(*v2[1]) + 8) are caller-defined and not statically resolvable here.
    // UNRESOLVED: The exact layout of the remap-table entries (dword count header plus paired dword records) is inferred from the iteration code, not named in the evidence.
}
