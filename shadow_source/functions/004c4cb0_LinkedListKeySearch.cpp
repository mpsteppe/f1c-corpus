// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C4CB0
// Canonical corpus name: LinkedListKeySearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListKeySearch_004c4cb0.c

void UnknownObject::LinkedListKeySearch()
{
    // Linked-list key search: seeds the iteration field this[4] from the list head this[2], then walks nodes comparing the search key a2 against each node's data value. Returns 1 on the first match, 0 when the head is null, the first node data pointer is null, or the list is exhausted without a match.
    // ASSIGNMENT: Initialize result to 0 and set the iteration field this[4] (offset 0x10) to the list head this[2] (offset 0x8). [field:this:0x00000008, field:this:0x00000010, source:raw]
    // GUARD: Return 0 immediately when the head pointer this[2] is null or the first node's data pointer (dereferenced from the current node, base *(this+0x10)) is null. [field:this:0x00000008, field:*(this+0x10):0x00000000, source:raw]
    // LOOP: While a2 does not equal the current node's data value, advance the iteration field this[4] through the node's +4 next link and re-read the data pointer; continue until a match or a null link is reached. [field:*(this+0x10):0x00000000, field:this:0x00000010, source:raw]
    // RETURN: Return 1 when a node whose data value equals a2 is found. [source:raw]
    // RETURN: Return 0 when the traversal reaches a null node or the list is exhausted without a match. [source:raw]

    // Conservative worker pseudocode:
    //   char searchKey(_DWORD* this, int key) {
    //     this[4] = this[2];
    //     if (this[4] && *(this[4])) {
    //       int* data = *this[4];
    //       while (key != *data) {
    //         this[4] = this[4] ? *(_DWORD*)(this[4] + 4) : 0;
    //         if (!this[4] || !*(this[4])) return 0;
    //         data = *this[4];
    //       }
    //       return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: field:this:0x00000014 (count) is listed as read by the packet but is not referenced in the raw source; its role in the search is unknown.
    // UNRESOLVED: The node's +4 link is treated as a next pointer, but the node layout (data pointer at node+0 and link at node+4) is not independently confirmed.
    // UNRESOLVED: Owner object identity is unknown; callers suggest vehicle filtering/grid selection list management, which is not confirmed.
}
