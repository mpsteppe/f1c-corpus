// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FDA0
// Canonical corpus name: ArrayCopyWithRealloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayCopyWithRealloc_0054fda0.c

void UnknownObject::ArrayCopyWithRealloc()
{
    // Replaces a dynamically owned DWORD array on the receiver: frees the prior allocation at this+0x4C when non-null, allocates a fresh buffer of a3 DWORDs, copies a3 elements from source array a2, and records the new element count at this+0x50. Returns the element count when the copy loop completes. Used during DirectX mesh vertex buffer parsing to store per-element integer data.
    // GUARD: Guard on the existing array pointer at this+0x4C being non-null; when set, the old buffer is freed before reallocation. [field:this:0x0000004C, source:raw]
    // CALL: Free the prior allocation at this+0x4C via FreeWrapper_7bcf (0x00587BCF) when the guard passes. [callee:0x00587BCF, field:this:0x0000004C]
    // CALCULATION: Compute the new buffer size as 4 * a3 bytes (a3 DWORDs). [source:raw]
    // CALL: Allocate the new buffer via OperatorNewNhMallocWrapper (0x00587C03) for the computed 4 * a3 byte size. [callee:0x00587C03]
    // ASSIGNMENT: Store the freshly allocated buffer pointer at this+0x4C. [field:this:0x0000004C, callee:0x00587C03]
    // LOOP: Copy loop over a3 elements: for result from 0 while result < a3, copy element result from source a2 into the new buffer at this+0x4C. [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Record the new element count a3 at this+0x50. [field:this:0x00000050]
    // RETURN: Return the loop counter result, which equals the element count a3 once the copy loop finishes (0 when a3 is zero). [source:raw]
    // CALL: Called by DirectXMeshVertexBufferParsingAndLoading (0x00547B40) to populate a per-element integer array during mesh vertex buffer loading. [caller:0x00547B40, source:raw]

    // Conservative worker pseudocode:
    //   // Reallocating DWORD array copy on a receiver object.
    //   void sub_54FDA0(int this, int src, int count) {
    //     if (*(int*)(this + 76) != 0)
    //       FreeWrapper_7bcf((void*)*(int*)(this + 76));
    //     *(int*)(this + 76) = (int)OperatorNewNhMallocWrapper(4 * count);
    //     int i = 0;
    //     for (; i < count; ++i)
    //       *(int*)(*(int*)(this + 76) + 4 * i) = *(int*)(src + 4 * i);
    //     *(int*)(this + 80) = count;
    //     return i;
    //   }
    // UNRESOLVED: The class/object type owning the this pointer is unknown; fields at this+0x4C (array pointer) and this+0x50 (element count) are only typed by the raw source's access pattern.
    // UNRESOLVED: The exact meaning of the per-element integer data stored during mesh vertex buffer parsing is not established by this function alone.
}
