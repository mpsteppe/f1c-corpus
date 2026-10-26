// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB200
// Canonical corpus name: MultiLevelAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiLevelAllocation_004bb200.c

void UnknownObject::MultiLevelAllocation()
{
    // Multi-level allocator setup on a __thiscall container (called by ModelSceneFileLoader 004b6c90). Allocates a 4-byte header holding a pointer to a 384-byte payload block; the block is split into 32 slots of 12 bytes, each initialized by WrapperPassThrough. The block is registered as a 12-byte node (in-use flag byte = 1) at the head of a block-level list (head this+0x0, tail this+0x4, back this+0x8, count this+0xC). A second pass walks the block in 12-byte strides and allocates one 12-byte node per slot (flag byte = 0), chaining them into a slot-level list (head this+0x10, tail this+0x14/this+0x18, count this+0x1C). Returns the last node allocated in the slot pass.
    // CALL: Allocate the 4-byte list header v3 via OperatorNewNhMallocWrapper(4). [callee:0x00587C03, function:0x004BB200, source:raw]
    // GUARD: Only proceed with block and node setup when the header allocation succeeded (result non-null); otherwise v12 stays null and the slot pass reads a null base. [function:0x004BB200, source:raw]
    // CALL: Allocate the 384-byte payload block via OperatorNewNhMallocWrapper(384). [callee:0x00587C03, function:0x004BB200, source:raw]
    // GUARD: If the payload block allocation succeeded, initialize its slots; otherwise store a null block pointer. [function:0x004BB200, source:raw]
    // LOOP: do-while loop over 32 iterations advancing the slot pointer by 12 bytes per iteration. [function:0x004BB200, source:raw]
    // CALL: WrapperPassThrough called on each 12-byte slot to initialize it. [callee:0x004B4450, function:0x004BB200, source:raw]
    // ASSIGNMENT: Store the payload block pointer (or 0 when the block allocation failed) into the header v3[0]. [function:0x004BB200, source:raw]
    // CALL: Allocate a 12-byte block-level node via OperatorNewNhMallocWrapper(12). [callee:0x00587C03, function:0x004BB200, source:raw]
    // GUARD: If the block node allocation succeeded, initialize its fields; otherwise the node stays null. [function:0x004BB200, source:raw]
    // ASSIGNMENT: Initialize the block node: node[0] = header pointer, node[1] = 0 (next link), node[2] = 1 (in-use flag byte). [function:0x004BB200, source:raw]
    // GUARD: Branch on whether the block list head this+0x0 is non-null: append to an existing list or seed an empty one. [field:this:0x00000000, function:0x004BB200, source:raw]
    // ASSIGNMENT: When the block list was non-empty, link the previous tail (this+0x4) to the new node by writing node into tail[1]. [field:this:0x00000004, field:this:0x00000000, function:0x004BB200, source:raw]
    // ASSIGNMENT: When the block list was empty, set the head this+0x0 = node and the back reference this+0x8 = node. [field:this:0x00000000, field:this:0x00000008, function:0x004BB200, source:raw]
    // ASSIGNMENT: Advance the block list tail: this+0x4 = node. [field:this:0x00000004, function:0x004BB200, source:raw]
    // CALCULATION: Increment the block count at this+0xC. [field:this:0x0000000C, function:0x004BB200, source:raw]
    // LOOP: for i = 0; i < 384; i += 12: walk the payload block in 12-byte strides to cover all 32 slots. [function:0x004BB200, source:raw]
    // CALCULATION: Compute the per-slot address v9 = block base (header[0]) + i. [function:0x004BB200, source:raw]
    // GUARD: Only allocate a slot node when the computed slot address v9 is non-null. [function:0x004BB200, source:raw]
    // CALL: Allocate a 12-byte slot-level node via OperatorNewNhMallocWrapper(12). [callee:0x00587C03, function:0x004BB200, source:raw]
    // GUARD: If the slot node allocation succeeded, initialize its fields; otherwise the node stays null. [function:0x004BB200, source:raw]
    // ASSIGNMENT: Initialize the slot node: node[0] = slot address v9, node[1] = 0 (next link), node[2] = 0 (free flag byte). [function:0x004BB200, source:raw]
    // GUARD: Branch on whether the slot list head this+0x10 is non-null: prepend to an existing list or seed an empty one. [field:this:0x00000010, function:0x004BB200, source:raw]
    // ASSIGNMENT: When the slot list was non-empty, prepend by writing the old head this+0x10 into the new node's next link (node[1]). [field:this:0x00000010, function:0x004BB200, source:raw]
    // ASSIGNMENT: When the slot list was empty, set this+0x14 = node and this+0x18 = node. [field:this:0x00000014, field:this:0x00000018, function:0x004BB200, source:raw]
    // ASSIGNMENT: Set the slot list head this+0x10 = node. [field:this:0x00000010, function:0x004BB200, source:raw]
    // CALCULATION: Increment the slot count at this+0x1C. [field:this:0x0000001C, function:0x004BB200, source:raw]
    // RETURN: Return the last node allocated by the slot pass; the caller ModelSceneFileLoader (004b6c90) uses this to grow the allocator. [function:0x004BB200, caller:0x004B6C90, source:raw]

    // Conservative worker pseudocode:
    //   header = OperatorNewNhMallocWrapper(4);
    //   if (header != 0) {
    //     block = OperatorNewNhMallocWrapper(384);
    //     if (block != 0) {
    //       for (p = block; p < block + 384; p += 12) WrapperPassThrough(p);
    //     }
    //     header[0] = block;
    //     node = OperatorNewNhMallocWrapper(12);
    //     if (node != 0) { node[0] = header; node[1] = 0; node[2] = 1; }
    //     if (this[0] != 0) this[1][1] = node; else { this[0] = node; this[2] = node; }
    //     this[1] = node;
    //     ++this[3];
    //   }
    //   for (i = 0; i < 384; i += 12) {
    //     slot = header[0] + i;
    //     if (slot != 0) {
    //       n = OperatorNewNhMallocWrapper(12);
    //       if (n != 0) { n[0] = slot; n[1] = 0; n[2] = 0; }
    //       if (this[4] != 0) n[1] = this[4]; else { this[5] = n; this[6] = n; }
    //       this[4] = n;
    //       ++this[7];
    //     }
    //   }
    //   return result;
    // UNRESOLVED: If the 384-byte block allocation fails, header[0] is 0 and the slot pass computes v9 = i (12, 24, ...), which still passes the non-null guard and allocates slot nodes holding small-integer data pointers; this fallback path is likely dead code or a decompiler artifact and cannot be resolved from this packet.
    // UNRESOLVED: The container object type is unidentified; the block list versus slot list distinction is inferred from the insertion order and flag bytes.
    // UNRESOLVED: The purpose of the in-use flag byte (1 for block nodes, 0 for slot nodes) and the two-list design is not documented in this packet.
}
