// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C2A0
// Canonical corpus name: sub_55C2A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55C2A0_0055c2a0.c

void UnknownObject::LinkedListTailAppend()
{
    // Appends a node to the tail of a doubly linked list. Head pointer lives at this+0x1518 (this[1350]); node links are prev at node+0x1C and next at node+0x20. If the list is non-empty it walks from the head to the tail via next pointers, then sets a2's prev (+0x1C) to the old tail and the old tail's next (+0x20) to a2. If the list is empty it sets the head to a2. Returns a2 in all paths.
    // GUARD: Read head pointer this[1350] at offset 0x1518; if null the list is empty and the new node becomes the head. [field:this:0x00001518, function:0x0055C2A0, source:raw]
    // LOOP: Walk from the head following next pointers at node+0x20 until the tail (node whose next is null) is reached. [field:*(*(this+0x1538)+0x20):0x00000020, function:0x0055C2A0, source:raw]
    // ASSIGNMENT: Non-empty path: set a2's prev (+0x1C) to the old tail and set the old tail's next (+0x20) to a2. [field:*(*(this+0x1538)+0x20):0x00000020, field:this:0x00001518, function:0x0055C2A0, source:raw]
    // ASSIGNMENT: Empty path: set head this[1350] (offset 0x1518) to a2. [field:this:0x00001518, function:0x0055C2A0, source:raw]
    // RETURN: Return a2 (the appended node) in all paths. [function:0x0055C2A0, source:raw]

    // Conservative worker pseudocode:
    //   if this.head (this+0x1518) is null:
    //       this.head = node;
    //       return node;
    //   else:
    //       tail = this.head;
    //       while tail.next (tail+0x20) != 0: tail = tail.next;
    //       node.prev (node+0x1C) = tail;
    //       tail.next (tail+0x20) = node;
    //       return node;
    // UNRESOLVED: Unlike a fully initializing append, a2's next (+0x20) is never explicitly zeroed here and the empty path does not initialize a2's links; the caller is expected to have pre-initialized the new node.
    // UNRESOLVED: The packet field base *(*(this+0x1538)+0x20) is the existing analysis's interpretation of the next-pointer location; raw source accesses this[1350] and node+0x20 directly, and 0x1538 is not read in the raw source.
    // UNRESOLVED: Node layout (prev at +0x1C, next at +0x20) is inferred from raw-source offsets 28 and 32; no node type name is known.
}
