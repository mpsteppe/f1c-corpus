// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004080B0
// Canonical corpus name: sub_4080B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4080B0_004080b0.c

void UnknownObject::LinkedListFindByFirstDword()
{
    // Searches a singly linked list for a node whose data's first DWORD equals a2. Head pointer is stored at this+0x38, traversal cursor at this+0x40, and each node carries its data pointer at +0 and a next-node pointer at +4. Returns the matching data pointer, or 0 when the list is empty or no node matches.
    // ASSIGNMENT: Read the linked-list head pointer from this+0x38 into the traversal cursor field this+0x40, resetting the cursor to the start. [field:this:0x00000038, field:this:0x00000040, source:raw]
    // GUARD: If the head pointer is null, return 0 (empty list). [source:raw]
    // ASSIGNMENT: Dereference the cursor to obtain the data pointer of the current node (result = *cursor). [field:*(this+0x40):0x00000000, source:raw]
    // LOOP: While the first DWORD of the current node's data differs from a2, advance the cursor to the next node via the next pointer stored at node+4, re-read its data pointer, and return 0 if the cursor ever becomes null. [field:this:0x00000040, source:raw]
    // RETURN: Return the data pointer of the node whose first DWORD equals a2, or 0 when the traversal ends without a match. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4080B0(_DWORD *this, int a2) {
    //     _DWORD **cursor = (_DWORD **)this[14];
    //     this[16] = cursor;
    //     if (!cursor) return 0;
    //     _DWORD *data = *cursor;
    //     while (data && *data != a2) {
    //       if (this[16]) this[16] = *(_DWORD *)(this[16] + 4);
    //       cursor = (_DWORD **)this[16];
    //       if (!cursor) return 0;
    //       data = *cursor;
    //     }
    //     return data;
    //   }
    // UNRESOLVED: The node count field at this+0x44 is recorded as a struct field but is not read by this function, which only uses the head and cursor fields.
    // UNRESOLVED: The identity of the a2 key and the meaning of the matched data pointer depend on the caller's list layout.
}
