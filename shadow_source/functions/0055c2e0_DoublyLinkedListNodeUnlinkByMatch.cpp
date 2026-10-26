// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C2E0
// Canonical corpus name: DoublyLinkedListNodeUnlinkByMatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeUnlinkByMatch_0055c2e0.c

void UnknownObject::DoublyLinkedListNodeUnlinkByMatch()
{
    // Walks a doubly-linked list starting at head this+0x1518, compares each node pointer against argument a2, and on a match unlinks that node by relinking prev->next and next->prev (node prev/next live at node+0x1C/+0x20). If the removed node is the head, advances the head to the removed node's next. Returns the matched node pointer, or the new head after a head removal, or 0 if the list is empty or a2 is not found. Legacy ABI label Doubly_Linked_List_Node_Unlink_by_Match; sole observed caller ResourceCascadeCleanup (0x005539F0).
    // GUARD: Load head from this+0x1518; if null the list is empty and the function returns 0 immediately. [field:this:0x00001518, source:raw]
    // LOOP: Walk the list from head following each node's next pointer (node+0x20) until the node pointer equals a2; if the walk reaches a null next before matching, return 0. [field:*(this+0x1538):0x00000020, field:*(*(this+0x1538)+0x20):0x00000020, source:raw]
    // ASSIGNMENT: Read prev pointer of the matched node from node+0x1C. [field:*(this+0x1538):0x0000001C, source:raw]
    // ASSIGNMENT: If the matched node's prev is non-null, write prev->next (prev+0x20) = matched->next so the previous node skips the removed node. [field:*(*(this+0x1538)+0x1C):0x00000020, field:*(this+0x1538):0x00000020, source:raw]
    // ASSIGNMENT: Read next pointer of the matched node from node+0x20. [field:*(this+0x1538):0x00000020, source:raw]
    // ASSIGNMENT: If the matched node's next is non-null, write next->prev (next+0x1C) = matched->prev so the following node skips back over the removed node. [field:*(*(this+0x1538)+0x20):0x0000001C, field:*(this+0x1538):0x0000001C, source:raw]
    // STATE_TRANSITION: If the matched node equals the stored head, advance the head to the matched node's next and store it back at this+0x1518. [field:this:0x00001518, field:*(this+0x1538):0x00000020, source:raw]
    // RETURN: Return the matched node pointer; after a head removal the returned value is the new head (the removed node's next). Returns 0 when the list is empty or no node matches a2. [source:raw]
    // CALL: Invoked by ResourceCascadeCleanup (0x005539F0); this unlink-by-match is part of the resource cascade cleanup path. [caller:0x005539F0]
    // UNKNOWN: Legacy ABI lead labels this routine Doubly_Linked_List_Node_Unlink_by_Match; the proposed name and function identity are anchored to that lead and the packet address. [abi:lead, function:0x0055C2E0]

    // Conservative worker pseudocode:
    //   node = this[1350];
    //   if (node == 0) return 0;
    //   while (node != a2) {
    //     node = node[0x20];
    //     if (node == 0) return 0;
    //   }
    //   prev = node[0x1C];
    //   if (prev != 0) prev[0x20] = node[0x20];
    //   next = node[0x20];
    //   if (next != 0) next[0x1C] = node[0x1C];
    //   if (this[1350] == node) {
    //     this[1350] = node[0x20];
    //     return this[1350];
    //   }
    //   return node;
    // UNRESOLVED: Node struct fields at node+0x1C (prev) and node+0x20 (next) are unnamed; only their linked-list roles are evident.
    // UNRESOLVED: After a head removal the return value is the new head rather than the removed node; likely a decompiler artifact of the reassigned `result` register.
    // UNRESOLVED: The owning object type is unknown; the list head at this+0x1518 belongs to an unnamed owner.
    // UNRESOLVED: Only one caller (ResourceCascadeCleanup, 0x005539F0) is observed; the list elements and their allocation sites are unknown.
    // UNRESOLVED: Not on the tick frame path; call frequency unmeasured.
}
