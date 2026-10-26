// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054BAA0
// Canonical corpus name: DoublyLinkedListNodeTransplant
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeTransplant_0054baa0.c

void UnknownObject::DoublyLinkedListNodeTransplant()
{
    // Doubly-linked list node transplant: unlinks node a2 from its current list (via its prev/next pointers at dword indices 18 and 19), updates the owning list head this+0x44 if a2 was the head, then appends a2 to the tail of a global list rooted at dword_8B8F28+264. If a2 carries a sublist (a2[140]) it is handed to DoublyLinkedNodeRemovalGlobalListReInsert, and a2[16] is cleared.
    // ASSIGNMENT: v2 = a2[18]: capture a2's previous-link pointer before mutation. [source:raw]
    // GUARD: If v2 (a2[18]) is nonzero, write a2[19] into (v2 + 76): the old predecessor's next link is redirected to skip over a2. [source:raw]
    // GUARD: result = a2[19]; if a2's next link is nonzero, write a2[18] into result[18]: the old successor's previous link is redirected to skip over a2. [source:raw]
    // GUARD: If the list head this[17] (this+0x44) equals a2, advance the head to a2[19] and, if the new head is nonzero, clear its previous link (result[18] = 0). [field:this:0x00000044, source:raw]
    // GUARD: Global-list insert path is gated on dword_8B8F28 being nonzero; otherwise the whole append block is skipped. [global:0x008B8F28, source:raw]
    // GUARD: v4 = *(dword_8B8F28 + 264) (current global-list tail). If nonzero, walk the chain from *(v4 + 76) following i[19] to the last node, then set last[19] = a2; if empty, store a2 directly at dword_8B8F28 + 264. [source:raw]
    // ASSIGNMENT: Link a2 into the global list as the new tail: a2[18] = result (former last node), a2[19] = 0. [source:raw]
    // GUARD: Sublist transplant: only when a2[140] is nonzero, a2[16] is nonzero, and that container's [140] is nonzero, call DoublyLinkedNodeRemovalGlobalListReInsert(a2[140]). [callee:0x00560F40, source:raw]
    // ASSIGNMENT: a2[16] = 0: clear the container link on the transplanted node. [source:raw]
    // RETURN: Return the last computed result value (the current tail, the stored container, or the reinsert result). [source:raw]
    // CALL: Invoked by ConditionalResourceRelease (004E0D70) on the per-frame tick path. [caller:0x004E0D70, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_54BAA0(this, _DWORD *a2) {
    //     v2 = a2[18];
    //     if (v2) *(v2 + 76) = a2[19];
    //     result = a2[19];
    //     if (result) result[18] = a2[18];
    //     if (this[17] == a2) {
    //       result = a2[19]; this[17] = result;
    //       if (result) result[18] = 0;
    //     }
    //     if (dword_8B8F28) {
    //       v4 = *(dword_8B8F28 + 264); result = 0;
    //       if (v4) {
    //         result = *(dword_8B8F28 + 264);
    //         for (i = *(v4 + 76); i; i = i[19]) result = i;
    //         result[19] = a2;
    //       } else { *(dword_8B8F28 + 264) = a2; }
    //       a2[18] = result; a2[19] = 0;
    //     }
    //     if (a2[140]) {
    //       result = a2[16];
    //       if (result && result[140]) result = DoublyLinkedNodeRemovalGlobalListReInsert(a2[140]);
    //     }
    //     a2[16] = 0;
    //     return result;
    //   }
    // UNRESOLVED: Identity and layout of the global list at dword_8B8F28+264 (a UI/context root per existing analysis) is not grounded in this packet.
    // UNRESOLVED: Node fields at dword indices 16, 17, 18, 19 and 140 (container link, list head, prev, next, sublist) are typed only by their linkage roles; their element types are unknown.
    // UNRESOLVED: Whether the tail walk and the sublist reinsert share the same global list is not provable from this packet.
}
