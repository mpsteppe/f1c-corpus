// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567A30
// Canonical corpus name: LinkedListDestructorWithInnerFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructorWithInnerFree_00567a30.c

void UnknownObject::LinkedListDestructorWithInnerFree()
{
    // Resource destructor. First runs F_9PointerArrayCleanup(this) to clear the object's pointer-array region, then walks the singly-linked list starting at this+0x24. For each node it follows the next link, and when the per-node flag byte is set it frees the node's data pointer (freeing the data's own sub-pointer first when present), then frees the node itself. Finally zeroes the list head fields at 0x24, 0x28, 0x2C, 0x30 and returns 0.
    // CALL: Run F_9PointerArrayCleanup(this) to clear the pointer array region. [callee:0x00567F10, source:raw]
    // ASSIGNMENT: Read the first list node from this+0x24 as the iteration seed. [field:this:0x00000024, source:raw]
    // LOOP: Walk the singly-linked list, following the next pointer of each node until null. [source:raw]
    // GUARD: Per-node: only perform data cleanup when the flag byte in the node is non-zero. [source:raw]
    // GUARD: Per-node: skip data cleanup when the node's data pointer is null. [source:raw]
    // GUARD: Per-node: free the data's sub-pointer only when it is non-null. [field:*(this+0x24):0x00000000, source:raw]
    // CALL: Free the sub-pointer, then the data pointer, then the node itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list head fields at this+0x24, this+0x28, this+0x2C and this+0x30. [field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, source:raw]
    // RETURN: Return 0. [source:raw]
    // CALL: Invoked by SubObjectDestructorChain, FrontendScreenLoadingDisplayHandler and sub_4FE7C0. [caller:0x0040D9FC, caller:0x00476250, caller:0x004FE7C0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_567A30(DWORD *this) {
    //     F_9PointerArrayCleanup(this);
    //     node = (void**)this[9];
    //     while (node) {
    //       next = node[1];
    //       if (*(byte*)node + 8) {
    //         data = *node;
    //         if (data) {
    //           if (*data) FreeWrapper_7bcf(*data);
    //           FreeWrapper_7bcf(data);
    //         }
    //       }
    //       FreeWrapper_7bcf(node);
    //       node = next;
    //     }
    //     this[9] = 0;
    //     this[10] = 0;
    //     this[11] = 0;
    //     this[12] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Node next-link and flag offsets are read from the raw decompiled source only; they have no dedicated packet field evidence entries.
    // UNRESOLVED: The object's overall role (list container owning a nested pointer array) is inferred from the destructor shape, not from a named owner.
}
