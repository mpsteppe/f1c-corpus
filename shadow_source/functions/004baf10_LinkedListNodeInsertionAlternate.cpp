// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAF10
// Canonical corpus name: sub_4BAF10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BAF10_004baf10.c

void UnknownObject::LinkedListNodeInsertionAlternate()
{
    // Structural twin of the other LinkedListNodeInsertion with different secondary-list geometry. A tagged 12-byte node (payload=a2, tag=1) is allocated and appended to the first linked list (head this+0x0, tail this+0x4, anchor this+0x8, count this+0xC). The second linked list (head this+0x10, anchor this+0x14/+0x18, count this+0x1C) is only built when a3 is zero, producing at most two nodes at base value *a2 plus a 1016-byte running stride; nodes whose computed value is zero are skipped. Used for vehicle instance list nodes.
    // GUARD: If a2 is null, skip the entire first-list insertion section. [source:raw]
    // CALL: Allocate a 12-byte node for the first list with OperatorNewNhMallocWrapper(12); on success initialize node[0]=a2, node[4]=0, node[8]=1 (tag 1). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the node to the first list: if the head this[0] is non-null, point the old tail's next field (this[1]+4) at the node; otherwise set head this[0] and anchor this[2] to the node. Then set tail this[1] to the node and increment the count this[3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALCULATION: Set the secondary-list iteration count to 0 when a3 is non-zero, otherwise 2; the secondary section runs only when this count is non-zero. [source:raw]
    // LOOP: Loop over the secondary count (2 when a3==0); each step computes the node value v8 = v7 + *v3 with the stride accumulator v7 advancing by 1016 and *v3 re-read from a2 each iteration. [source:raw]
    // CALL: When the computed value v8 is non-zero, allocate a 12-byte secondary-list node with OperatorNewNhMallocWrapper(12); on success initialize node[0]=v8, node[4]=0, node[8]=0 (tag 0). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Link the secondary node at the front of the second list: if the head this[4] is non-null, set new-node next (v9+4) to the old head; otherwise set both anchors this[5] and this[6] to the node. Then set head this[4] to the node and increment the count this[7]. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return the loop counter, which reaches 0 when the secondary loop completes. Invoked from VehicleInstanceListBuilder (0x004B5C50) to build vehicle instance list nodes. [caller:0x004B5C50, source:raw]

    // Conservative worker pseudocode:
    //   if (a2) {
    //     node = OperatorNewNhMallocWrapper(12);
    //     if (node) { node[0] = a2; node[1] = 0; *(byte*)(node+8) = 1; }
    //     if (*this) *(this[1]+4) = node; else { *this = node; this[2] = node; }
    //     this[1] = node; ++this[3];
    //   }
    //   count = a3 ? 0 : 2;
    //   for (v7 = 0; count; --count, v7 += 1016) {
    //     v8 = v7 + *a2;
    //     if (v8) {
    //       n = OperatorNewNhMallocWrapper(12);
    //       if (n) { n[0] = v8; n[1] = 0; *(byte*)(n+8) = 0; }
    //       if (this[4]) *(n+4) = this[4]; else { this[5] = n; this[6] = n; }
    //       this[4] = n; ++this[7];
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: The 1016-byte stride and the at-most-two secondary nodes differ from the 432-byte/8-or-32 pattern of the structural twin; the semantic meaning of the two stride series is not established from this packet alone.
    // UNRESOLVED: The exact identity of the object owning this dual-list layout is unknown; the two anchors this+0x14 and this+0x18 are both set on first insertion, and the packet does not disambiguate their roles.
}
