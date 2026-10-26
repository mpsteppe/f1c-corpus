// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004677E0
// Canonical corpus name: LinkedListNodeDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeDestructor_004677e0.c

void UnknownObject::LinkedListNodeDestructor()
{
    // Destructor for an object holding an embedded singly linked list: walks the list from the head pointer at this[62] (offset 0xF8), freeing each node's two-level data block and the node struct itself (skipping the inner free when the per-node flag byte at node offset 0x8 is zero), clears the head/tail/count/capacity fields to zero, invokes vtable cleanup via VTableSetCleanup (0x00487F30), and finally frees the this object when the scalar-deleting flag (a2 & 1) is set.
    // CALCULATION: Load the list head pointer from this[62] (offset 0xF8); it is the loop cursor for node iteration [field:this:0x000000F8, source:raw]
    // LOOP: While the current node pointer is non-null, walk the singly linked list following the next pointer at node offset 0x4 [field:this:0x000000F8, field:*(this+0xFC):0x00000004, source:raw]
    // CALCULATION: Per node: capture the data block pointer *v4 (node offset 0x0) and the flag byte at node offset 0x8, then advance the cursor to the next pointer at node offset 0x4 [field:*(this+0xF8):0x00000000, field:*(this+0xFC):0x00000004, source:raw]
    // GUARD: If the flag byte at node offset 0x8 is non-zero (inner data is present and must be freed) [source:raw]
    // GUARD: If the node data block pointer (*v4) is non-null [field:*(this+0xF8):0x00000000, source:raw]
    // GUARD: If the inner pointer **v4 inside the data block is non-null [source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees the inner pointer **v4 [callee:0x00587BCF, field:*(this+0xF8):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees the node data block *v4 [callee:0x00587BCF, field:*(this+0xF8):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees the list node struct itself, unconditionally [callee:0x00587BCF, field:*(this+0xFC):0x00000004, source:raw]
    // ASSIGNMENT: Clear this[62] (offset 0xF8) list head pointer to 0 [field:this:0x000000F8, source:raw]
    // ASSIGNMENT: Clear this[63] (offset 0xFC) list tail pointer to 0 [field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Clear this[64] (offset 0x100) element count to 0 [field:this:0x00000100, source:raw]
    // ASSIGNMENT: Clear this[65] (offset 0x104) capacity field to 0 [field:this:0x00000104, source:raw]
    // CALL: VTableSetCleanup (0x00487F30) performs vtable-based cleanup on this object [callee:0x00487F30, source:raw]
    // GUARD: If the destructor flag (a2 & 1) is set (scalar deleting destructor path) [source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) frees the this object when the flag is set [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer [source:raw]

    // Conservative worker pseudocode:
    //   cursor = this[62];
    //   while (cursor) {
    //     node = cursor;
    //     flag = *(BYTE*)(node + 8);
    //     cursor = *(DWORD*)(node + 4);
    //     if (flag) {
    //       data = *(DWORD*)node;
    //       if (data) {
    //         if (*(DWORD*)data) FreeWrapper_7bcf(*(DWORD*)data);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     FreeWrapper_7bcf(node);
    //   }
    //   this[62] = this[63] = this[64] = this[65] = 0;
    //   VTableSetCleanup(this);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Exact owning class of the linked-list container not established.
    // UNRESOLVED: Purpose of the two-level node data allocation (*v4 and **v4) not grounded beyond free order.
}
