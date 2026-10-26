// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486340
// Canonical corpus name: sub_486340
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_486340_00486340.c

void UnknownObject::LinkedListNodeInsertOrAppend()
{
    // Inserts or appends a node a2 into a singly-linked list rooted at this+0x90 (dword index 36). First the three source fields this+0x40, this+0x98 and this+0x9C are copied into the new node at the same offsets. When the flag a3 is nonzero the node is prepended: the old head becomes a2's next pointer (dword index 35, offset 0x8C) and a2 becomes the new head. When a3 is zero and the list is non-empty the code walks to the tail following next pointers and calls FieldSetterAt0x8c to link it; when the list is empty a2 becomes the first node. Finally the node counter at this+0x94 is incremented and the new count is returned.
    // ASSIGNMENT: Copy the source fields this+0x40, this+0x98 and this+0x9C into the new node a2 at the same offsets. [field:this:0x00000040, field:this:0x00000098, field:this:0x0000009C, source:raw]
    // GUARD: Branch on the flag a3: nonzero selects the prepend path, zero selects the append path. [source:raw]
    // ASSIGNMENT: Prepend: chain the old head into a2's next-pointer slot (dword index 35) and store a2 as the new head at this+0x90. [field:this:0x00000090, source:raw]
    // GUARD: Append path: when the list head at this+0x90 is non-null, walk to the tail; when it is null the list is empty. [field:this:0x00000090, source:raw]
    // LOOP: Traverse the list following the next-pointer field at dword index 35 (offset 0x8C) until a node with a null next pointer is found. [source:raw]
    // CALL: Call FieldSetterAt0x8c on the tail node to set its next pointer (offset 0x8C) to the new node a2. [callee:0x00486330, source:raw]
    // ASSIGNMENT: Empty-list append: store a2 as the first node at this+0x90. [field:this:0x00000090, source:raw]
    // CALCULATION: Increment the node counter at this+0x94 and return the new count. [field:this:0x00000094, source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodeInsertOrAppend(int *this, int *a2, int prepend) {
    //     a2[16] = this[16];
    //     a2[38] = this[38];
    //     a2[39] = this[39];
    //     if (prepend) {
    //       a2[35] = this[36];          // chain old head after the new node
    //       this[36] = a2;              // new node becomes head
    //     } else if (this[36]) {
    //       int *tail = this[36];
    //       while (tail[35]) tail = tail[35];
    //       FieldSetterAt0x8c(tail, a2); // append after the tail
    //     } else {
    //       this[36] = a2;              // first node in the list
    //     }
    //     int n = this[37] + 1;
    //     this[37] = n;
    //     return n;                     // node count
    //   }
    // UNRESOLVED: Meaning of the three copied fields (this+0x40, this+0x98, this+0x9C).
    // UNRESOLVED: Purpose of the returned node count (this+0x94) for the callers UIMenuItemCreator (0x00489600) and sub_492A40 (0x00492A40).
    // UNRESOLVED: Fields this+0x11C and this+0x234 are listed in the packet field evidence but are not referenced by the decompiled body.
}
