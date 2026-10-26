// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407FB0
// Canonical corpus name: LinkedListSearchByID
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListSearchByID_00407fb0.c

void UnknownObject::LinkedListSearchByID()
{
    // __thiscall boolean linked-list lookup. Searches a singly-linked list for a node whose ID field (node data at +92, i.e. offset 0x5C) equals the requested ID a2. On entry the traversal cursor at this+0x20 is reset to the head pointer held at this+0x18, then walked via the next-node pointer at +4 until the ID matches. Returns 1 when a match is found, 0 when a2 is -1, the head is null, or traversal ends without a match. The legacy ABI label is 'Linked_List_Search_by_ID'.
    // ASSIGNMENT: Initialize the return value to 0 [source:raw]
    // GUARD: Search key -1 (a2 == -1) is rejected outright and returns 0 [source:raw]
    // ASSIGNMENT: Seed the traversal: read the head pointer from this+0x18 (this[6]) and reset the traversal cursor this+0x20 (this[8]) to it [field:this:0x00000018, field:this:0x00000020, source:raw]
    // GUARD: Only proceed when the head pointer v3 is non-null and the node data pointer *v3 (v4) is non-null; otherwise return 0 (empty list) [source:raw]
    // LOOP: Walk the list while the current node's ID field at data offset 0x5C (node data +92) does not equal a2 [field:*(this+0x20):0x0000005C, source:raw]
    // ASSIGNMENT: Advance the traversal cursor: read this+0x20, follow the next-node pointer at +4, store the result back into this+0x20, and load the next node's data pointer for the next iteration [field:this:0x00000020, source:raw]
    // RETURN: Return 1 when a node whose ID at +92 matches a2 is found [field:*(this+0x20):0x0000005C, source:raw]
    // RETURN: Return 0 when the cursor becomes null mid-traversal (end of list); the function is invoked from MemoryAllocation_5160 (00405160) [caller:0x00405160, function:0x00407FB0, source:raw]

    // Conservative worker pseudocode:
    //   char __thiscall LinkedListSearchByID(this, id) {
    //     result = 0;
    //     if (id == -1) return result;
    //     cursor = this[0x18/4];
    //     this[0x20/4] = cursor;
    //     if (cursor) {
    //       node = *cursor;
    //       if (node) {
    //         while (*(node + 92) != id) {
    //           next = this[0x20/4];
    //           if (next) this[0x20/4] = *(next + 4);
    //           node = *this[0x20/4];
    //           if (node) continue;
    //           return 0;
    //         }
    //         return 1;
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The node count at this+0x24 (field 0x00000024) is listed as a read-only field in the packet facts but never appears in the raw decompiled source; its role as a list count is unverifiable from this packet
    // UNRESOLVED: The legacy ABI label 'Linked_List_Search_by_ID' (LEGACY trust) supports the linked-list reading but is not an independent runtime-confirmed owner
}
