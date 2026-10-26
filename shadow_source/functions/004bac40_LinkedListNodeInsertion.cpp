// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAC40
// Canonical corpus name: LinkedListNodeInsertion_ac40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsertion_ac40_004bac40.c

void UnknownObject::LinkedListNodeInsertion()
{
    // Dual-list node insertion. When a2 is non-null, a tagged 12-byte node (payload=a2, tag=1) is allocated and appended to a first linked list (head this+0x0, tail this+0x4, anchor this+0x8, count this+0xC). It then builds a second linked list (head this+0x10, anchor this+0x14/+0x18, count this+0x1C) of 8 or 32 nodes, each holding the base value *a2 plus a running stride of 432 bytes per step; nodes whose computed value is zero are skipped. The tag selects which value stream the node belongs to.
    // GUARD: If a2 is null, skip the entire first-list insertion section. [source:raw]
    // CALL: Allocate a 12-byte node for the first list with OperatorNewNhMallocWrapper(12); on success initialize node[0]=a2, node[4]=0, node[8]=1 (tag 1). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the node to the first list: if the head this[0] is non-null, point the old tail's next field (this[1]+4) at the node; otherwise set head this[0] and anchor this[2] to the node. Then set tail this[1] to the node and increment the count this[3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALCULATION: Set the secondary-list iteration count to 32 when a3 is non-zero, otherwise 8. [source:raw]
    // LOOP: Loop over the secondary count; each step computes the node value v7 = v6 + *v3 with the stride accumulator v6 advancing by 432 and *v3 re-read from a2 each iteration. [source:raw]
    // CALL: When the computed value v7 is non-zero, allocate a 12-byte secondary-list node with OperatorNewNhMallocWrapper(12); on success initialize node[0]=v7, node[4]=0, node[8]=0 (tag 0). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Link the secondary node at the front of the second list: if the head this[4] is non-null, set new-node next (v8+4) to the old head; otherwise set both anchors this[5] and this[6] to the node. Then set head this[4] to the node and increment the count this[7]. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return the loop counter, which reaches 0 after the fixed secondary count completes. Invoked from CollisionObjectInsertion (0x004B48E0) to build collision sub-list nodes. [caller:0x004B48E0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2) {
    //     node = OperatorNewNhMallocWrapper(12);
    //     if (node) { node[0] = a2; node[1] = 0; *(byte*)(node+8) = 1; }
    //     if (*this) *(this[1]+4) = node; else { *this = node; this[2] = node; }
    //     this[1] = node; ++this[3];
    //   }
    //   count = a3 ? 32 : 8;
    //   for (v6 = 0; count; --count, v6 += 432) {
    //     v7 = v6 + *a2;
    //     if (v7) {
    //       n = OperatorNewNhMallocWrapper(12);
    //       if (n) { n[0] = v7; n[1] = 0; *(byte*)(n+8) = 0; }
    //       if (this[4]) *(n+4) = this[4]; else { this[5] = n; this[6] = n; }
    //       this[4] = n; ++this[7];
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: The meaning of the 432-byte stride and the semantic distinction between tag-1 (first list) and tag-0 (secondary list) nodes is inferred from structure only; the caller CollisionObjectInsertion (0x004B48E0) assigns the collision context.
    // UNRESOLVED: The exact identity of the object owning this dual-list layout is unknown; the two anchors this+0x14 and this+0x18 are both set on first insertion, and the packet does not disambiguate their roles.
}
