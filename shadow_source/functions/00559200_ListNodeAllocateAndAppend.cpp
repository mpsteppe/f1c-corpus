// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559200
// Canonical corpus name: sub_559200
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_559200_00559200.c

void UnknownObject::ListNodeAllocateAndAppend()
{
    // Allocates a 108-byte list node, zero-initializes it, validates it with FlagConditionalBranchDispatch, and appends it to the tail of a singly-linked list stored at this+0x148 (head) with next pointers at node+0x68 and a back-pointer at node+0x64. On validation failure the node is freed and the output pointer a2 is zeroed. On success the node count at this+0x144 is incremented, a2 receives the new node, and the return value encodes whether the per-node VertexBufferResourceAllocation succeeded.
    // CALL: OperatorNewNhMallocWrapper(108) allocates the 108-byte node; when it returns null the node pointer stays 0. [callee:0x00587C03, source:raw]
    // CALL: StructZeroInitWithDefaults zero-initializes the freshly allocated node. [callee:0x00557410, source:raw]
    // GUARD: FlagConditionalBranchDispatch(node, a3) validates the new node; a nonzero result selects the failure path. [callee:0x00557480, source:raw]
    // CALL: On failure EmptyStub_7470 is invoked and then FreeWrapper_7bcf frees the node. [callee:0x00557470, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: On failure the output pointer a2, when present, is set to 0. [source:raw]
    // RETURN: Return -1 to signal allocation/validation failure. [source:raw]
    // GUARD: If the list head this[82] (offset 0x148) is zero the new node becomes the head; otherwise walk to the tail. [field:this:0x00000148, source:raw]
    // LOOP: Walk node next pointers at node+0x68 until the last node of the list is reached. [field:*(*(this+0x1B0)+0x68):0x00000068, source:raw]
    // ASSIGNMENT: Append the new node: the tail's next pointer at node+0x68 is set to the new node and the new node's back-pointer v5[25] (0x64) points back to the tail. [field:*(*(this+0x1B0)+0x68):0x00000068, source:raw]
    // ASSIGNMENT: Increment the node count at this+0x144. [field:this:0x00000144, source:raw]
    // ASSIGNMENT: On success the output pointer a2, when present, receives the new node. [source:raw]
    // RETURN: Return 0 when VertexBufferResourceAllocation succeeds, otherwise -1 (the nonzero result is negated); called by sub_4CB120 and UIListNodeManager (0054BB40). [callee:0x00543FA0, caller:0x004CB120, caller:0x0054BB40, source:raw]

    // Conservative worker pseudocode:
    //   int ListNodeAllocateAndAppend(a2, a3) {
    //     v5 = StructZeroInitWithDefaults(OperatorNewNhMallocWrapper(108));
    //     if (FlagConditionalBranchDispatch(v5, a3)) {
    //       if (v5) { EmptyStub_7470(v5); FreeWrapper_7bcf(v5); }
    //       if (a2) *a2 = 0;
    //       return -1;
    //     }
    //     if (this[82]) {
    //       v7 = this[82];
    //       for (i = *(v7 + 104); i; i = *(i + 104)) v7 = i;
    //       *(v7 + 104) = v5;
    //       v5[25] = v7;
    //     } else {
    //       this[82] = v5;
    //     }
    //     ++this[81];
    //     if (a2) *a2 = v5;
    //     return -(VertexBufferResourceAllocation(this) != 0);
    //   }
    // UNRESOLVED: The meaning of the a3 argument passed to FlagConditionalBranchDispatch is not established from this packet.
    // UNRESOLVED: Why a nonzero VertexBufferResourceAllocation result makes the function return -1 is unexplained here.
    // UNRESOLVED: The owning class behind the count/head fields this+0x144 and this+0x148 is unknown.
    // UNRESOLVED: this+0x1B0 is listed in the packet fields but has no direct occurrence in the raw decompiled source; the field evidence for the node next pointer is expressed through it.
}
