// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051954E
// Canonical corpus name: PerIndexBufferCopyWithInterleavedOffset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerIndexBufferCopyWithInterleavedOffset_0051954e.c

void UnknownObject::PerIndexBufferCopyWithInterleavedOffset()
{
    // Copies per-element buffer data between source and destination arrays using an interleaved offset pattern. For each element in this+0x20 elements, computes a scaled copy size from element descriptors, then copies blocks backward and forward across stride positions to mirror each element across adjacent slots. Returns the final element index.
    // ASSIGNMENT: Load element count bound a1[8] (this+0x20) into v16 accumulator init. [field:this:0x00000020]
    // ASSIGNMENT: Load element descriptor base a1[49] (this+0xC4). [field:this:0x000000C4]
    // ASSIGNMENT: Load stride a1[69] (this+0x114) used to scale copy block sizes. [field:this:0x00000114]
    // ASSIGNMENT: Load element data buffer pointer a1[96] (this+0x180). [field:this:0x00000180]
    // GUARD: If element count this+0x20 > 0, iterate elements; otherwise return immediately. [guard:0, field:this:0x00000020]
    // CALCULATION: Compute per-element copy count v15 = descriptorValue * descriptorValue[6] / stride (this+0x114). [field:this:0x00000114, source:raw]
    // ASSIGNMENT: Read source offset from array at bufferBase+56 (this+0x1B8) indexed by elementIndex. [field:this:0x000001B8]
    // ASSIGNMENT: Read destination offset from array at bufferBase+60 (this+0x1BC) indexed by elementIndex. [field:this:0x000001BC]
    // LOOP: If copyCount > 0, inner copy loop advances three pointers (backward, forward, destination) copying one dword per step until copyCount reaches zero. [source:raw]
    // LOOP: Outer loop advances element descriptor pointer by 21 dwords and increments elementIndex until elementIndex >= element count this+0x20. [field:this:0x00000020, source:raw]
    // RETURN: Return final elementIndex as result. [source:raw]

    // Conservative worker pseudocode:
    //   int PerIndexBufferCopyWithInterleavedOffset(this) {
    //     elemCount = this[8];
    //     if (elemCount <= 0) return 0;
    //     stride = this[69];
    //     base = this[96];
    //     desc = this[49];
    //     for (i = 0; i < elemCount; i++) {
    //       count = desc[0] * desc[6] / stride;
    //       src = *(base + 56)[i];
    //       dst = *(base + 60)[i];
    //       if (count > 0) { copy src<->dst across stride offsets for count steps; }
    //       desc += 21;
    //     }
    //     return i;
    //   }
    // UNRESOLVED: field this+0xD0 (a1[52]) and this+0xE8 (a1[58]) are listed in evidence but never referenced in the raw source; cannot attribute to an operation.
    // UNRESOLVED: Inner loop direction (backward/forward pointers) implies interleave mirroring but the exact layout semantics are unproven.
    // UNRESOLVED: Owner object type unknown; called only from AudioStreamBufferFill (0x00519720).
}
