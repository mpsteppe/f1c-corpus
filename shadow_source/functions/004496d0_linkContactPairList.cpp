// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004496D0
// Canonical corpus name: ContactPairLinkedListBuilder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ContactPairLinkedListBuilder_004496d0.c

void UnknownObject::linkContactPairList()
{
    // When the object's element count is nonzero, links a run of nodes in the buffer at +0x8 into a singly linked list by writing each node's next-pointer (offset +0x1C within a 0x20-byte node) to point at the following node, then returns the buffer base. When the count is zero, returns 0.
    // GUARD: Read element count from this+0x0; if zero, skip the list-building path. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Capture element count (*this) into result as the early-return value. [field:this:0x00000000]
    // GUARD: Only build links when count-1 is greater than 0 (i.e. at least two elements). [field:this:0x00000000]
    // LOOP: For each node index i from 0 to count-2, write node i+1's address (buffer + 0x20*(i+1)) into node i's next field at buffer + 0x20*i + 0x1C; advance 0x20 bytes per node. [field:this:0x00000008, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the address of the following node into the current node's next-pointer slot (+0x1C) using the buffer base from this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return this[2] (the node buffer base) when the count is nonzero. [field:this:0x00000008]
    // RETURN: Return *this (0) when the count is zero. [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   count = this->count;
    //   if (count == 0) return 0;
    //   if (count > 1) {
    //       for (i = 0; i < count - 1; i++)
    //           node(buffer + 0x20*i)->next = buffer + 0x20*(i+1);
    //   }
    //   return buffer;
    // UNRESOLVED: Node type unknown: 0x20-byte stride and next-pointer offset +0x1C are read from the raw source only; no struct definition evidence exists.
    // UNRESOLVED: The canonical name ContactPairLinkedListBuilder and the prelabel twin (00410ad0, cluster_copy DERIVED) are semantic proposals, not confirmed linkage semantics.
}
