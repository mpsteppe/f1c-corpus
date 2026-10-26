// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054ABE0
// Canonical corpus name: LinkedListAppend_abe0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListAppend_abe0_0054abe0.c

void UnknownObject::LinkedListAppend_abe0()
{
    // Appends a node to a linked list. Reads the list head at this+0x204; when the list is non-empty it walks the next-pointer chain (node+16) to the tail and links the new node after it, otherwise it installs the new node as the head. The new node's prev pointer (+320) is set to the old tail (or 0) and its next pointer (+16) to 0. Returns the old head, or the new node when the list was empty.
    // ASSIGNMENT: Read the list head pointer stored at this+0x204 and use it as the starting tail candidate. [field:this:0x00000204, source:raw]
    // GUARD: Guard on the head being non-null: a non-null head takes the append-after-tail path, a null head takes the empty-list initialization path. [field:this:0x00000204, source:raw]
    // LOOP: Walk from the head to the tail by following the node next-pointer field at +0x10 (reached through the sub-structure referenced at this+0x214), continuing while the next pointer is non-null. [field:*(*(this+0x214)+0x10):0x00000010, field:this:0x00000214, source:raw]
    // ASSIGNMENT: Link the old tail's next pointer (+0x10) to the newly appended node a2. [field:*(*(this+0x214)+0x10):0x00000010, source:raw]
    // ASSIGNMENT: Set the new node's prev pointer (a2+320) to the old tail. [source:raw]
    // ASSIGNMENT: Clear the new node's next pointer (a2+16) so it terminates the list. [source:raw]
    // ASSIGNMENT: Empty-list path: store the new node as the list head at this+0x204. [field:this:0x00000204, source:raw]
    // ASSIGNMENT: Empty-list path: clear the new node's prev pointer (a2+320) and next pointer (a2+16). [source:raw]
    // RETURN: Return the previous head when the list was non-empty, or the new node when the list was empty. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_54ABE0(_DWORD* this, _DWORD* node) {
    //     _DWORD* tail = this[129];
    //     if (tail) {
    //       for (_DWORD* n = tail[4]; n; n = n[4]) tail = n;
    //       tail[4] = node;
    //       node[80] = tail;
    //       node[4] = 0;
    //     } else {
    //       tail = node;
    //       this[129] = node;
    //       node[80] = 0;
    //       node[4] = 0;
    //     }
    //     return tail;
    //   }
    // UNRESOLVED: Concrete node and container types are unknown; the head at this+0x204 and the sub-structure pointer at this+0x214 are unnamed fields.
    // UNRESOLVED: The relationship between this+0x204 and the sub-structure at this+0x214 is unresolved from the raw source alone.
    // UNRESOLVED: The single caller sub_54A870 was not analyzed; it may reveal the node/container layout.
}
