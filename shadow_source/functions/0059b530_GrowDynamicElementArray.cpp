// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B530
// Canonical corpus name: GrowDynamicElementArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GrowDynamicElementArray_0059b530.c

void UnknownObject::GrowDynamicElementArray()
{
    // Grows the dynamic element array when the used count (this[0x14]) plus one exceeds capacity (this[0xC]). New capacity is computed by adding growth stride this[0x1C] until it covers count + 1; a new 4 * i-byte buffer (2 WORDs per element) is allocated and zero-initialized, the first this[0x14] elements are copied from the old array this[0x8], the old buffer is freed, and this[0x8]/this[0xC] are updated. Returns 1 on success and on the no-growth path; 0 only when the allocation fails.
    // GUARD: If used count + 1 (this[0x14] + 1) is not greater than capacity this[0xC], return 1 without growing. [field:this:0x00000014, field:this:0x0000000C, source:raw]
    // CALCULATION: Compute new capacity i, starting at stride this[0x1C] + capacity this[0xC] and adding this[0x1C] until i >= used count + 1. [field:this:0x0000001C, field:this:0x0000000C, field:this:0x00000014, source:raw]
    // CALL: Allocate 4 * i bytes via OperatorNewNhMallocWrapper; return 0 if the allocation is null. [callee:0x00587C03, source:raw]
    // LOOP: Zero-initialize all i elements of the new array, each element being 2 WORDs. [source:raw]
    // LOOP: Copy the first this[0x14] used elements (4 bytes each, 2 WORDs) from the old array this[0x8] into the new array. [field:this:0x00000014, field:this:0x00000008, source:raw]
    // CALL: Free the old array buffer (this[0x8]) via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Store the new array pointer in this[0x8] and the new capacity in this[0xC]. [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return 1 on success (both the no-growth and grown paths); 0 only when the allocation failed. [source:raw]

    // Conservative worker pseudocode:
    //   char GrowDynamicElementArray(int this) {
    //     unsigned int cap = *(this + 12);
    //     unsigned int need = *(this + 20) + 1;
    //     if (need <= cap) return 1;
    //     unsigned int stride = *(this + 28);
    //     unsigned int i = stride + cap;
    //     while (i < need) i += stride;
    //     _WORD *p = OperatorNewNhMallocWrapper(4 * i);
    //     if (!p) return 0;
    //     for (unsigned int n = 0; n < i; ++n) { p[2*n] = 0; p[2*n + 1] = 0; }
    //     for (unsigned int j = 0; j < *(this + 20); ++j)
    //       *(_DWORD *)&p[2*j] = *(_DWORD *)(*(this + 8) + 4*j);
    //     FreeWrapper_7bcf(*(void **)(this + 8));
    //     *(void **)(this + 8) = p;
    //     *(this + 12) = i;
    //     return 1;
    //   }
    // UNRESOLVED: Element semantic (2-WORD clip-rect entries) is DERIVED from existing analysis, not confirmed.
    // UNRESOLVED: Owner object type is UNKNOWN; only the caller BitmapAllocationTracker (0x0059B5C0) is known.
}
