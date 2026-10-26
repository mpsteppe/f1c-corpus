// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00502EE5
// Canonical corpus name: ConditionalFree_2ee5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFree_2ee5_00502ee5.c

void UnknownObject::ConditionalFreeWithFlag()
{
    // Conditionally frees memory based on flag bits in a2. When bit 2 of a2 is set, the container is treated as an element array: NTimeCallbackLoopWithSEH is invoked with the FreeWrapper callback (0x00502C1F) to free each element held by the container header at this - 1, and when bit 1 is also set the header block this - 1 is itself freed, returning this - 1. When bit 2 is clear, the first data element stored at this[0] is freed directly via FreeWrapper_7bcf, and when bit 1 is set the container block this is also freed, returning this.
    // GUARD: Branch on flag bit 2 of a2: when (a2 & 2) != 0 take the element-array path (loop-free via callback), otherwise take the direct-free path on the first data element. [source:raw]
    // CALL: NTimeCallbackLoopWithSEH(this, 12, *(this - 1), FreeWrapper): iterate the elements owned by the container whose header precedes this and invoke the FreeWrapper callback (global 0x00502C1F) on each with SEH protection; the element count and array base come from the header at this - 1. [callee:0x0058A5F7, global:0x00502C1F, source:raw]
    // GUARD: On the element-array path, test flag bit 1: when (a2 & 1) != 0 the container header block at this - 1 is freed after its elements. [source:raw]
    // CALL: FreeWrapper_7bcf(this - 1): free the container header block when flag bit 1 is set on the element-array path. [callee:0x00587BCF, source:raw]
    // RETURN: Return this - 1 (the container header pointer) from the element-array path. [source:raw]
    // CALL: FreeWrapper_7bcf(*this): on the bit-2-clear path, free the first data element whose pointer is stored at this[0] (field this + 0x0). [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // GUARD: On the bit-2-clear path, test flag bit 1: when (a2 & 1) != 0 the container block this itself is freed. [source:raw]
    // CALL: FreeWrapper_7bcf(this): free the container block when flag bit 1 is set on the direct-free path. [callee:0x00587BCF, source:raw]
    // RETURN: Return this (unchanged) from the bit-2-clear path. [source:raw]

    // Conservative worker pseudocode:
    //   if ((a2 & 2) != 0) {
    //     NTimeCallbackLoopWithSEH(this, 12, *(this - 1), FreeWrapper);
    //     if ((a2 & 1) != 0) FreeWrapper_7bcf(this - 1);
    //     return this - 1;
    //   } else {
    //     FreeWrapper_7bcf(*this);
    //     if ((a2 & 1) != 0) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The literal 12 passed to NTimeCallbackLoopWithSEH (element size, stride or count encoding) is not explained by the packet.
    // UNRESOLVED: The exact layout of the container header at this - 1 (where the element count and array base are read) is not established by the packet.
    // UNRESOLVED: The callers 0x00502F31 and 0x00506003 are not resolved to semantic context, so the two container shapes handled by bit 2 remain unconfirmed.
    // UNRESOLVED: The legacy ABI label (abi:lead) is not adopted; the proposed name follows the existing analysis fill (ConditionalFreeWithFlag).
}
