// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585FB0
// Canonical corpus name: LinkedListCleanupWithSubObjectDelete
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListCleanupWithSubObjectDelete_00585fb0.c

void UnknownObject::LinkedListCleanupWithSubObjectDelete()
{
    // Cleans up a linked list whose head lives at this+0x0. While the head is non-null, walks the node chain through the next pointer at node+0x4. For each node with a non-zero flag byte at node+0x8, reads the node's data pointer at node+0x0 and, when it is non-null, calls EmptyStub_0170 (no visible arguments) then frees that data via FreeWrapper_7bcf. Every node object itself is then freed via FreeWrapper_7bcf. After the walk, clears this+0x0, this+0x4, this+0x8 and this+0xC to 0 and returns 0. Called by sub_583AE0 (00583AE0).
    // GUARD: Walk proceeds only when the head field at this+0x0 is non-null; an empty list skips straight to the final field clear. [field:this:0x00000000, source:raw]
    // LOOP: Iterates the node chain from the head via the next pointer at node+0x4 until a null successor terminates the loop. [source:raw]
    // GUARD: Per-node byte flag check at node+0x8; when non-zero the node carries a data pointer that requires cleanup. [field:obj:0x00000008, source:raw]
    // ASSIGNMENT: Reads the node's data pointer at node+0x0 into the local v4. [field:obj:0x00000000, source:raw]
    // GUARD: Inner guard on the node's data pointer at node+0x0; the stub call and the data free run only when the pointer is non-null. [field:obj:0x00000000, source:raw]
    // CALL: Calls EmptyStub_0170 on flagged nodes with no visible arguments in the decompilation. [callee:0x004B0170, source:raw]
    // CALL: Frees the node's data buffer via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000000, source:raw]
    // CALL: Frees the node object itself via FreeWrapper_7bcf on every visited node, whether or not it held data. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clears the container fields this+0x0, this+0x4, this+0x8 and this+0xC to 0 after the walk. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Returns 0 as the cleanup result. [source:raw]

    // Conservative worker pseudocode:
    //   node = *this;
    //   while (node) {
    //     next = node[1];
    //     if (byte at node+0x8) {
    //       data = node[0];
    //       if (data) {
    //         EmptyStub_0170();
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     FreeWrapper_7bcf(node);
    //     node = next;
    //   }
    //   *this = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //   return 0;
    // UNRESOLVED: The full node struct is not evidenced here; only the data pointer at node+0x0, the next pointer at node+0x4 and the flag byte at node+0x8 are visible.
    // UNRESOLVED: EmptyStub_0170 is invoked with no visible argument in the decompilation, so its role as a per-node sub-object teardown (suggested by the canonical name) is not independently evidenced.
    // UNRESOLVED: The roles of the fields cleared at this+0x4, this+0x8 and this+0xC (tail/iterator/count in the structural twin 005833e0) are inferred from the cluster relationship, not evidenced in this packet.
}
