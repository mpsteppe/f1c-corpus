// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545A40
// Canonical corpus name: sub_545A40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_545A40_00545a40.c

void UnknownObject::RebuildFilteredNodeArray()
{
    // Rebuilds a filtered array of 24-byte entries reachable from two linked node lists. Frees the previous array (24-byte stride elements with a 4-byte count header), allocates a new array sized to this+0x13C via the allocation wrapper, then walks a first node list from this+0x100 (forward link at +0x104) and a second list from this+0x108. For each node it descends a sub-chain at +0xEC and skips the node unless the sub-chain yields a node whose flags at +0x14 include 0x4000; matching outer nodes are appended at array+16 with a 24-byte stride. The second list appends entries after the first-list run without updating the entry counter. Always returns 0. Called by VertexBufferResourceAllocation (0x00543FA0).
    // ASSIGNMENT: Initialize the entry counter v2 to 0 before any rebuild work. [source:raw]
    // GUARD: Skip the entire rebuild when the entry count this+0x13C is not positive. [guard:0, field:this:0x0000013C]
    // LOOP: When an old array exists at this+0x140, walk it backward in 24-byte steps, invoking EmptyStub_0170 for each of the recorded elements (count read from the 4-byte header at array-4). [callee:0x004B0170, field:this:0x00000140, source:raw]
    // CALL: Free the old array allocation through its 4-byte header pointer (array-4) via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000140]
    // CALL: Allocate new storage of 24 * this+0x13C + 4 bytes via OperatorNewNhMallocWrapper. [callee:0x00587C03, field:this:0x0000013C]
    // ASSIGNMENT: Write the element count into the 4-byte allocation header; the array payload begins at header+4. [source:raw]
    // LOOP: Initialize each 24-byte element of the new array with ShortComputation_8e00, advancing 6 dwords (24 bytes) per element until the count is exhausted. [callee:0x00548E00]
    // ASSIGNMENT: Store the new array payload pointer at this+0x140 (this[80] = v12). [field:this:0x00000140]
    // LOOP: Walk the first node list from head this+0x100, following the forward link at +0x104 (v14 = *(v14 + 260)) until null. [field:this:0x00000100, field:*(this+0x204):0x00000104]
    // GUARD: Skip a first-list node when its byte flag at +0x4 has bit 0x40 set. [field:*(this+0x204):0x00000004]
    // ASSIGNMENT: Read the sub-list head v15 from the node at +0xEC (v15 = *(v14 + 236)). [field:*(this+0x204):0x000000EC]
    // LOOP: Iterate the sub-list v15 via its next pointer at +0x4C (v15 = *(v15 + 76)) until null. [field:*(*(*(this+0x204)+0xEC)+0x4C):0x0000004C]
    // ASSIGNMENT: Read the chain start v17 from the sub-list node at +0x204 (v17 = *(v15 + 516)). [field:*(*(this+0x204)+0xEC):0x00000204]
    // LOOP: Follow the chain forward link at +0x10 (v17 = *(v17 + 16)) until a node whose flags at +0x14 include 0x4000, or the chain ends. [field:*(*(*(*(this+0x204)+0xEC)+0x204)+0x10):0x00000010, field:*(*(*(*(this+0x204)+0xEC)+0x204)+0x10):0x00000014]
    // ASSIGNMENT: Append a matched first-list sub-node pointer into slot array+16+24*v2, advance the entry counter v2 and the 24-byte slot stride. [field:this:0x00000140]
    // LOOP: Walk the second node list from head this+0x108, iterating nodes by their next pointer at +0x4C; per node, descend the same node layout (+0x204 sub-chain, +0x10/+0x14 chain links/flags). [field:this:0x00000108, source:raw]
    // ASSIGNMENT: Append matched second-list nodes into slots after the first-list run with a 24-byte stride, without updating the entry counter v2. [field:this:0x00000140, source:raw]
    // RETURN: Always return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_545A40(DWORD* this) {
    //     int count = 0;
    //     if ((int)this[79] > 0) {
    //       if (this[80]) {
    //         // teardown: one EmptyStub_0170() per old element, then free header this[80]-4
    //         FreeWrapper_7bcf(this[80] - 4);
    //       }
    //       DWORD* p = OperatorNewNhMallocWrapper(24 * this[79] + 4);
    //       if (p) { p[0] = this[79]; this[80] = p + 1; for (i = 0; i < this[79]; i++) ShortComputation_8e00(p + 1 + 6 * i); }
    //       else this[80] = 0;
    //       for (node = this[64]; node; node = *(DWORD*)(node + 0x104)) {
    //         if ((*(BYTE*)(node + 0x4) & 0x40) == 0)
    //           for (s = *(DWORD*)(node + 0xEC); s; s = *(DWORD*)(s + 0x4C)) {
    //             for (n = *(DWORD*)(s + 0x204); n && (*(DWORD*)(n + 0x14) & 0x4000) == 0; n = *(DWORD*)(n + 0x10));
    //             if (n) { this[80][count + 4] = s; count++; }
    //           }
    //       }
    //       for (s = this[66]; s; s = *(DWORD*)(s + 0x4C)) {
    //         for (n = *(DWORD*)(s + 0x204); n && (*(DWORD*)(n + 0x14) & 0x4000) == 0; n = *(DWORD*)(n + 0x10));
    //         if (n) { this[80][count + 4] = s; }
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The packet lists second-list field bases *(this+0x30C) (+0x10/+0x14) and *(this+0x154) (+0x4C) that do not appear in the raw source text; the raw second loop instead reads this+0x108 and the same node offsets (+0x204, +0x4C, +0x10, +0x14) as the first loop. Those field refs are parked as unresolved rather than forced onto the raw code.
    // UNRESOLVED: EmptyStub_0170 is a stub call during old-array teardown; its intended per-element action is unknown.
    // UNRESOLVED: The second list appends entries without incrementing the entry counter, so the final count reflects first-list matches only; whether this is intentional is unknown.
    // UNRESOLVED: Identity and semantics of the 24-byte array entries (stored at slot+16) and of the 0x4000 chain flag are unconfirmed.
}
