// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005490B0
// Canonical corpus name: DoublyLinkedListAppend_90b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_90b0_005490b0.c

void UnknownObject::AppendDoublyLinkedNode()
{
    // Appends node a2 to a singly-walked node chain rooted at this[59] (byte offset +0xEC). When the head is non-null it walks the chain through each node's next pointer at node+0x4C until the tail, then links tail+0x4C = a2, sets a2+0x48 (prev) to the old tail, and zeroes a2+0x4C (next) and a2+0x44. When the head is null it makes a2 the new head (this+0xEC = a2) and zeroes the same three node fields. Returns the previous tail, or 0 when the list was empty. Invoked by ArithmeticComparison_9170 (0x00549170).
    // GUARD: Branches on head this+0xEC (this[59]): non-null selects the append-to-existing-tail path, null selects the new-head path [field:this:0x000000EC, source:raw]
    // LOOP: Walk the chain: for (i = node+0x4C; i; i = *(i+0x4C)) keep result = i, stopping at the tail whose next pointer is null [field:*(*(this+0x138)+0x4C):0x0000004C, source:raw]
    // ASSIGNMENT: Tail path: link old tail to new node, tail+0x4C = a2 [field:*(*(this+0x138)+0x4C):0x0000004C, source:raw]
    // ASSIGNMENT: Tail path: a2+0x48 (prev) = old tail; a2+0x4C (next) = 0; a2+0x44 = 0 [source:raw]
    // ASSIGNMENT: Empty-list path: this+0xEC = a2 (a2 becomes the head); a2+0x48 = 0; a2+0x4C = 0; a2+0x44 = 0 [field:this:0x000000EC, source:raw]
    // RETURN: Returns the previous tail (or 0 when the list was empty); the function is invoked by ArithmeticComparison_9170 (0x00549170) [function:0x005490B0, caller:0x00549170, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   head = this+0xEC;
    //   if (head) {
    //     tail = head;
    //     for (node = head+0x4C; node; node = node+0x4C) tail = node;
    //     tail+0x4C = a2; a2+0x48 = tail; a2+0x4C = 0; a2+0x44 = 0;
    //     return tail;
    //   } else {
    //     this+0xEC = a2; a2+0x48 = 0; a2+0x4C = 0; a2+0x44 = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The packet flags this+0x138 as a read base for the +0x4C next-pointer field, but the raw decompiled source accesses the head directly via this[59] (+0xEC) and walks nodes through +0x4C; the role of this+0x138 in the chain is not verifiable from this packet
    // UNRESOLVED: The semantic purpose of node field +0x44 (zeroed on every append) is unknown
    // UNRESOLVED: The 0x4C field is treated as a forward next pointer here, but the name_index may interpret sibling/prev links differently; not confirmed
}
