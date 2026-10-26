// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAD70
// Canonical corpus name: CollisionNodeListInsertion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionNodeListInsertion_004bad70.c

void UnknownObject::CollisionNodeListInsertion()
{
    // __thiscall linked-list insertion on a list object whose head/tail/count fields occupy this+0x0..0xC. When a2 is non-null, allocates a 12-byte node (flag byte 1, data = a2) and appends it to the primary list. Then, when the byte a3 is zero (loop count = 2), a second staggered pass walks *a2 plus a 884-byte stride and appends one flag-byte-0 node per stride position to a second list at this+0x10..0x1C. Returns the countdown result, which is 0 after the loop runs.
    // ASSIGNMENT: Alias v3 = a2 so the loop can re-read the data pointer. [source:raw]
    // GUARD: Guard on a2 being non-null before any primary-list work. [source:raw]
    // CALL: Allocate a 12-byte node with OperatorNewNhMallocWrapper(12) for the primary list. [callee:0x00587C03, source:raw]
    // GUARD: Branch on allocation success; on failure the node pointer is forced to 0. [source:raw]
    // ASSIGNMENT: Initialize the node: node[0] = a2, node[1] = 0 (next), node byte 8 = 1 (primary-node flag). [source:raw]
    // GUARD: Guard on *this (head) being non-null to choose the append vs. empty-list path. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Non-empty path: link the new node to the tail at this+0x4 via tail->next (this[1] + 4) = v5. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Empty path: head (*this) = v5 and this+0x8 (this[2]) = v5. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Update the tail pointer this+0x4 (this[1]) = v5 and increment the count this+0xC (++this[3]). [field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALCULATION: Compute the secondary loop count: result = (a3 != 0) ? 0 : 2, so the loop runs exactly twice when a3 is zero and never otherwise. [source:raw]
    // GUARD: Guard on the secondary loop count being non-zero before entering the stride walk. [source:raw]
    // LOOP: Countdown loop over the computed loop count (2 when a3 == 0), re-reading the data pointer from a2 each iteration. [source:raw]
    // CALCULATION: Compute the secondary data entry v8 = v7 + *v3, where v7 advances by the 884-byte stride and *v3 is the data pointer a2. [source:raw]
    // GUARD: Guard on the derived entry v8 being non-null before allocating a secondary node. [source:raw]
    // CALL: Allocate a 12-byte secondary node with OperatorNewNhMallocWrapper(12). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the secondary node: node[0] = v8, node[1] = 0 (next), node byte 8 = 0 (secondary-node flag). [source:raw]
    // GUARD: Guard on the secondary tail this+0x10 (this[4]) being non-null to choose append vs. empty-list path. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Append path: node[1] = this[4] (tail); empty path: this+0x14 (this[5]) = v9 and this+0x18 (this[6]) = v9. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Update the secondary tail this+0x10 (this[4]) = v9 and increment the count this+0x1C (++this[7]). [field:this:0x00000010, field:this:0x0000001C, source:raw]
    // CALCULATION: Advance the stride base v7 += 884, decrement the loop counter (result = --v11) and break when it reaches zero. [source:raw]
    // RETURN: Return the countdown result (0 after the secondary loop completes). [source:raw]
    // CALL: Called by NetworkMessageDispatch (0x004B54E0); the prelabel notes a structural twin relation to LinkedListNodeInsertion_ac40 per the packet's cluster-copy hint. [caller:0x004B54E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4BAD70(_DWORD *list, _DWORD *data, char a3) {
    //     if (data) {
    //       _DWORD *node = OperatorNewNhMallocWrapper(12);
    //       if (node) { node[0] = data; node[1] = 0; *(char*)&node[2] = 1; }
    //       if (list[0]) *(_DWORD*)(list[1] + 4) = node;
    //       else { list[0] = node; list[2] = node; }
    //       list[1] = node;
    //       ++list[3];
    //     }
    //     int loops = a3 != 0 ? 0 : 2;
    //     if (loops) {
    //       int base = 0;
    //       while (1) {
    //         int entry = base + *data;
    //         if (entry) {
    //           _DWORD *node = OperatorNewNhMallocWrapper(12);
    //           if (node) { node[0] = entry; node[1] = 0; *(char*)&node[2] = 0; }
    //           if (list[4]) node[1] = list[4];
    //           else { list[5] = node; list[6] = node; }
    //           list[4] = node;
    //           ++list[7];
    //         }
    //         base += 884;
    //         if (!--loops) break;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The 884-byte stride and the base *a2 that the secondary pass walks over imply a fixed-size per-entry data layout that is unknown here.
    // UNRESOLVED: Fields this+0xC and this+0x1C are recorded read-only in the packet yet are incremented as counts; their true access classification is unresolved.
    // UNRESOLVED: Meaning of the byte a3 (0 vs non-zero) and of the node flag byte at node+8 (1 primary vs 0 secondary) is caller-defined.
    // UNRESOLVED: Names CollisionNodeListInsertion and the structural twin relation to LinkedListNodeInsertion_ac40 are prelabel/cluster DERIVED, not confirmed.
}
