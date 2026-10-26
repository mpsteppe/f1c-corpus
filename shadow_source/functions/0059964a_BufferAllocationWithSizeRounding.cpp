// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059964A
// Canonical corpus name: BufferAllocationWithSizeRounding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferAllocationWithSizeRounding_0059964a.c

void UnknownObject::BufferAllocationWithSizeRounding()
{
    // Reallocates a growable buffer object: rounds the requested size read from this+8 up to a 32-byte boundary, allocates capacity+2 bytes via OperatorNewNhMallocWrapper (extra bytes carry a boundary marker), copies the old contents (min of old size and new capacity), releases the old buffer via ReferenceCountDecrementWithConditionalFree, relinks the old buffer's data/size/capacity fields, and returns the new data pointer.
    // CALL: Initialize the SEH handler frame via SEHHandlerInit for exception-safe reallocation; exception landing pads are at 0x005996A8 and 0x0059D2FC. [callee:0x0058A5D8, global:0x005996A8, global:0x0059D2FC]
    // CALCULATION: v2 = *(this + 8) | 0x1F: round the requested size up to a 32-byte boundary. [field:this:0x00000008, source:raw]
    // GUARD: If the rounded size v2 exceeds 0xFFFFFFFD, fall back to the unrounded size from this+8 to avoid overflow. [field:this:0x00000008, source:raw]
    // CALCULATION: v5 = v2 + 2 (extra bytes for the boundary marker), clamped to 0 when the signed addition overflows negative. [source:raw]
    // CALL: Allocate the new buffer with OperatorNewNhMallocWrapper(v5) and store the resulting pointer at this+8. [callee:0x00587C03, field:this:0x00000008]
    // GUARD: If the old size v6 read from the old buffer object is non-zero, copy min(v6, v2) bytes from the old data pointer into the new buffer at the +1 offset via MemoryCopy_cc00. [callee:0x0058CC00, field:this:0x00000008]
    // CALL: Release the old buffer object with ReferenceCountDecrementWithConditionalFree(v4, 1). [callee:0x005993AF]
    // ASSIGNMENT: Relink the old buffer object: data pointer v8 = new_buffer + 1 stored at v4+4, marker byte at v8-1 cleared to 0, capacity v2 stored at v4+12, and final size = min(old size v7, v2) stored at v4+8. [field:this:0x00000008, source:raw]
    // RETURN: Return the new data pointer (result = *(v4 + 4)). [source:raw]

    // Conservative worker pseudocode:
    //   int BufferAllocationWithSizeRounding(int this, int a2) {
    //     unsigned v2 = *(unsigned *)(this + 8) | 0x1F;
    //     SEHHandlerInit();
    //     if (v2 > 0xFFFFFFFD) v2 = *(unsigned *)(this + 8);
    //     int v5 = ((int)(v2 + 2) < 0) ? 0 : v2 + 2;
    //     *(unsigned *)(this + 8) = OperatorNewNhMallocWrapper(v5);
    //     unsigned v6 = *(unsigned *)(a2 + 8);
    //     if (v6) MemoryCopy_cc00(*(unsigned *)(this + 8) + 1, *(unsigned *)(a2 + 4), v6 > v2 ? v2 : v6);
    //     unsigned v7 = *(unsigned *)(a2 + 8);
    //     ReferenceCountDecrementWithConditionalFree(a2, 1);
    //     int v8 = *(unsigned *)(this + 8) + 1;
    //     *(unsigned *)(a2 + 4) = v8;
    //     *(char *)(v8 - 1) = 0;
    //     *(unsigned *)(a2 + 12) = v2;
    //     if (v7 <= v2) v2 = v7;
    //     int result = *(unsigned *)(a2 + 4);
    //     *(unsigned *)(a2 + 8) = v2;
    //     *(char *)(result + v2) = 0;
    //     return result;
    //   }
    // UNRESOLVED: Whether this+8 holds the requested size, the new allocation pointer, or both across different phases is ambiguous in the raw source; the packet registers it as a single RW field.
    // UNRESOLVED: The layout of the old buffer object (a2): data pointer at +4, size at +8, capacity at +12 is visible in raw source but not covered by registered field evidence.
    // UNRESOLVED: The two SEH landing pads (0x005996A8, 0x0059D2FC) are exception-only; their recovery behavior is unproven.
}
