// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A8B80
// Canonical corpus name: StaticInitBulk
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StaticInitBulk_004a8b80.c

void UnknownObject::bulkDestructorCleanup()
{
    // Bulk destructor/cleanup for a large aggregate object. Cleans a double-linked-list region, frees arrays of 36-byte two-pointer structs in fixed-count descending loops, runs a short-field cleanup helper over ~200 scattered offsets, frees multi-pointer structs, then walks a singly-linked list anchored at this+0 freeing each node and its payload, and finally zeroes the four head DWORDs.
    // CALL: Double-linked list cleanup on the anchor at this+4678 (DWORD units). [callee:0x004C1700]
    // LOOP: Four descending loops, 16 iterations each, stride 36 bytes, freeing two-pointer structs starting at this+4678, this+4534, this+4390 and this+4246. [callee:0x004AA1B0]
    // CALL: Short-field cleanup helper invoked on many offsets, this+4096 down to this+71, covering most of the object body. [callee:0x00414370]
    // LOOP: Descending loop of 44 iterations, stride 7 (DWORD units), calling the short-field cleanup helper. [callee:0x00414370]
    // LOOP: Descending loop of 48 iterations, stride 36 bytes, freeing two-pointer structs from this+3479. [callee:0x004AA1B0]
    // CALL: Further short-field cleanup calls over offsets this+3041 down to this+1121. [callee:0x00414370]
    // LOOP: Descending loop of 7 iterations, stride 28 bytes, freeing multi-pointer structs from this+2653. [callee:0x004AA170]
    // LOOP: Descending loops of 7 iterations, stride 36 bytes, freeing two-pointer structs from this+2604, this+2541, this+2424, this+2361, this+2298, this+2235, this+2172 and this+2109. [callee:0x004AA1B0]
    // CALL: Scattered direct two-pointer free calls over many offsets (this+1321..this+128 and this+1123..this+865, plus this+499..this+155 and this+338..this+218). [callee:0x004AA1B0]
    // CALL: Array destructor iteration over fixed element arrays (element sizes 24 and 36 bytes, 7 or 24 elements) using the two-pointer free function as the per-element callback. [callee:0x00401030, global:0x004AA1B0]
    // CALL: Scattered multi-pointer free calls on offsets this+354, this+347, this+118, this+111, this+104, this+97, this+87, this+80 and this+73. [callee:0x004AA170]
    // LOOP: Walk of the singly-linked list anchored at *this: for each node read the in-use byte at node+8 and the next pointer at node+4, free the node payload pointers then the node, continue while next is non-null. [field:obj:0x00000000, field:*(obj+0x0):0x00000004, field:obj:0x00000008]
    // ASSIGNMENT: Zero the four head DWORDs of the list anchor (this+0, this+4, this+8, this+C) after the walk. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the value produced by the final cleanup helper call. [function:0x004A8B80]

    // Conservative worker pseudocode:
    //   DoubleListCleanup(anchor at this+4678);
    //   for (4 anchors; i<16; ++i) FreeTwoPointers(anchor_ptr -= 36);
    //   ShortComputation_4370 over ~200 offsets plus a 44-iteration stride-7 loop;
    //   FreeTwoPointers loops (stride 36) and MultiPointerFree_a170 loop (stride 28);
    //   ArrayDestructorIterator over element arrays (sizes 24/36, counts 7/24);
    //   walk list at *this freeing nodes and payloads; zero this[0..3]; return;
    // UNRESOLVED: The per-node payload free inside the list walk uses a heap-free helper visible in the raw source but not individually catalogued in this packet.
    // UNRESOLVED: Per-offset semantics of the short-field cleanup helper are not recoverable from this function alone.
}
