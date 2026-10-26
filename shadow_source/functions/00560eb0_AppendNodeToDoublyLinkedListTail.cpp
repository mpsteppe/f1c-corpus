// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560EB0
// Canonical corpus name: AppendNodeToDoublyLinkedListTail
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AppendNodeToDoublyLinkedListTail_00560eb0.c

void UnknownObject::AppendNodeToDoublyLinkedListTail()
{
    // Appends a node to the tail of a doubly linked list. First unlinks the incoming node from any list it already belongs to: its previous node's next pointer is redirected around it and its next node's previous pointer is redirected back. Then, if the list head (this[11], offset 0x2C) is set, the function walks the next-pointer chain (+52/0x34) to the last node and writes the new node into that tail's next slot; otherwise the head becomes the new node. Finally the node's previous pointer is set to the old tail, its next pointer cleared to 0, and bit 2 (value 4) is set in its flags dword (+36). Returns the updated flags value.
    // ASSIGNMENT: Unlink step 1: if the incoming node's previous pointer (+48, a2[12]) is non-null, that previous node's next pointer (+52/0x34) is redirected to the incoming node's next (a2[13]) [source:raw]
    // ASSIGNMENT: Unlink step 2: if the incoming node's next pointer (+52, a2[13]) is non-null, that next node's previous pointer (+48) is redirected back to the incoming node's previous (a2[12]) [source:raw]
    // ASSIGNMENT: Initialize the tail to 0 and read the list head from this+0x2C (this[11]) to decide between the empty-list and non-empty-list paths [field:this:0x0000002C, source:raw]
    // LOOP: Non-empty path: walk the next-pointer chain (offsets +52/0x34) starting from the head node until the terminal node is reached, remembering each step as the running tail [field:this:0x0000002C, field:*(*(this+0x60)+0x34):0x00000034, source:raw]
    // ASSIGNMENT: Non-empty path: write the new node into the next-pointer slot (+52/0x34) of the terminal tail node [field:*(*(this+0x60)+0x34):0x00000034, source:raw]
    // ASSIGNMENT: Empty path: the list head at this+0x2C becomes the new node [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Finish linking: the new node's previous pointer (+48) is set to the running tail, its next pointer (+52) cleared to 0, and its flags dword (+36) is OR'd with 4 (bit 2) [source:raw]
    // RETURN: Returns the updated node flags value [source:raw]
    // CALL: Reached from DoublyLinkedListNodeMover (0054ba00) as a list-tail append helper [caller:0x0054BA00, source:raw]

    // Conservative worker pseudocode:
    //   int AppendNodeToDoublyLinkedListTail(this, node) {
    //     // unlink node from any list it currently belongs to
    //     if (node.prev) node.prev.next = node.next;   // +48 -> +52/0x34
    //     if (node.next) node.next.prev = node.prev;   // +52 -> +48
    //     tail = 0;
    //     if (this.head) {                             // this+0x2C (this[11])
    //       tail = this.head;
    //       for (n = this.head.next; n; n = n.next) tail = n;   // follow +52/0x34
    //       tail.next = node;
    //     } else {
    //       this.head = node;
    //     }
    //     node.prev = tail;
    //     node.next = 0;
    //     node.flags |= 4;                             // flags dword at +36, bit 2
    //     return node.flags;
    //   }
    // UNRESOLVED: Meaning of bit 2 (value 4) set in the node flags dword at +36 is not established by this packet; prior analysis labels it an in-list/active flag (DERIVED).
    // UNRESOLVED: Packet field evidence field:this:0x00000060 (a list-descriptor pointer) has no explicit access in the raw source shown; the head pointer this+0x2C and the descriptor at this+0x60 may describe the same list or a secondary one.
    // UNRESOLVED: Node offsets +48/+52 (prev/next) and the flags dword +36 appear in the raw source but have no separate packet field evidence entries.
    // UNRESOLVED: The unlink-first behavior implies nodes may be moved between lists without being freed, but the lifecycle of the removed node is outside this function.
}
