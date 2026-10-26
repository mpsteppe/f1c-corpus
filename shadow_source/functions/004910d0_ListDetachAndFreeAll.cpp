// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004910D0
// Canonical corpus name: ListIteratorFullDestruction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListIteratorFullDestruction_004910d0.c

void UnknownObject::ListDetachAndFreeAll()
{
    // Full destruction of a doubly-linked-list sentinel struct (4 DWORDs at this+0/4/8/C). Two phases: (1) if the list is non-empty, walk each node from the head and reparent its value elsewhere via LinkedListNodePrepend, advancing a cursor stored at this+8 along each node's next pointer (+4); (2) walk the remaining nodes and free them, calling EmptyStub_0170 on a node's value when the node's flags byte at +8 is non-zero and the value is non-null, then FreeWrapper_7bcf on the value and on the node. Finally zeroes all four DWORD fields of the sentinel and returns 1.
    // ASSIGNMENT: Copy the list head pointer into the cursor field: *(this + 8) = *(this + 0). [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: When the head pointer (this + 0) is null the list is empty and the reparent walk is skipped. [guard:0, field:this:0x00000000, source:raw]
    // LOOP: Reparent walk: for each node starting at the head, call LinkedListNodePrepend(node) to move the node's value to another list, then advance the cursor (this + 8) to the next node via node+4; the loop ends when the next node or its pointer is null. [callee:0x00490AA0, field:*(this+0x8):0x00000004, field:this:0x00000008, source:raw]
    // LOOP: Free walk: iterate the node chain from the head; for each node read its flags byte at node+8 and its value pointer at node+0. [field:obj:0x00000000, field:obj:0x00000008, source:raw]
    // CALL: When the node's flags byte is non-zero and its value pointer is non-null, call EmptyStub_0170(value) before freeing the value. [callee:0x004B0170, field:obj:0x00000000, source:raw]
    // CALL: Free the node memory with FreeWrapper_7bcf(node), and FreeWrapper_7bcf(value) first when the flags byte marked the value active. [callee:0x00587BCF, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Zero all four DWORD fields of the sentinel: this+0, this+4, this+8 and this+C. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return 1 to signal successful destruction. [source:raw]

    // Conservative worker pseudocode:
    //   cursor = *list;
    //   *list + 8 = *list;
    //   if (*list) {
    //       for (node = *list; node; node = next) {
    //           LinkedListNodePrepend(node);
    //           next = *(node + 4);
    //           *list + 8 = next;
    //           if (!next) break;
    //       }
    //   }
    //   for (node = *list; node; node = next) {
    //       next = *(node + 4);
    //       if (*(byte*)(node + 8) && *(node + 0)) {
    //           EmptyStub_0170(*(node + 0));
    //           FreeWrapper_7bcf(*(node + 0));
    //       }
    //       FreeWrapper_7bcf(node);
    //   }
    //   *list = 0; *(list + 1) = 0; *(list + 2) = 0; *(list + 3) = 0;
    //   return 1;
    // UNRESOLVED: The destination of the reparent step is opaque: LinkedListNodePrepend moves the node's value to another list, but which list (and whether the reparent is a detach of shared values or an actual move) is not established by the packet.
    // UNRESOLVED: The legacy ABI name 'List_Iterator_Full_Destruction' (abi:lead) describes an iterator destruction, whereas the raw source frees every node and the node values; the fill's name 'ListDetachAndFreeAll' is used here.
    // UNRESOLVED: The node layout (value at +0, next at +4, flags at +8) and the meaning of the non-zero flags byte are inferred from the raw source; no class or node type is evidenced.
}
