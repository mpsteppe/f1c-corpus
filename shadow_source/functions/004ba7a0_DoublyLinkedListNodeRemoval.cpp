// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA7A0
// Canonical corpus name: DoublyLinkedListNodeRemoval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemoval_004ba7a0.c

void UnknownObject::DoublyLinkedListNodeRemoval()
{
    // Removes a node from a linked list by value. Starting from the head this+0x0, walks the chain of next pointers (node+0x4) comparing each node's value (node+0x0) against a2; returns 0 when a2 is null, the list is empty, or the value is not found. On a match the node is unlinked (previous next or head repointed to the removed node's next), the tracked node pointers this+0x4 and this+0x8 are repointed when they referenced the removed node, and the count this+0xC is decremented. Unless a3 is set, the free-data flag byte at node+0x8 is cleared; when that flag remains set the node's data pointer (node+0x0) is freed via EmptyStub_0170 then FreeWrapper_7bcf. The node itself is always freed with FreeWrapper_7bcf, returning 1 on success. Called by NetworkMessageDispatch (004B54E0).
    // GUARD: Return 0 immediately when the search value a2 is null [source:raw]
    // GUARD: Return 0 when the list head this+0x0 is null (empty list) [field:this:0x00000000, source:raw]
    // LOOP: Walk the chain from head this+0x0 following next pointers (node+0x4), comparing each node's value (node+0x0) with a2 and tracking the predecessor; return 0 if the chain ends without a match [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: When the removed node is the tracked node this+0x8, repoint it to the removed node's next pointer (node+0x4) [field:this:0x00000008, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Unlink the node: when a predecessor exists, set its next (node+0x4) to the removed node's next; otherwise the head this+0x0 becomes the removed node's next [field:obj:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: When the removed node is the tracked node this+0x4, repoint it to the predecessor [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Decrement the list count this+0xC by one [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: When a3 is zero, clear the free-data flag byte at node+0x8; then, when that flag byte is set, free the node's data pointer (node+0x0) through EmptyStub_0170 followed by FreeWrapper_7bcf [field:obj:0x00000008, callee:0x004B0170, callee:0x00587BCF, source:raw]
    // CALL: Free the removed node itself with FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 to signal successful removal (and 0 on the earlier failure guards) [source:raw]
    // CALL: Invoked by NetworkMessageDispatch (004B54E0) [caller:0x004B54E0, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a2 == 0) return 0;
    //   v4 = *this; v5 = 0;
    //   if (*this == 0) return 0;
    //   while (*v4 != a2) {
    //     v5 = v4;
    //     v4 = v4[1];
    //     if (v4 == 0) return 0;
    //   }
    //   if (v4 == this[2]) this[2] = v4[1];
    //   v6 = v4[1];
    //   if (v5) v5[1] = v6; else *this = v6;
    //   if (this[1] == v4) this[1] = v5;
    //   --this[3];
    //   if (!a3) *(byte*)(v4 + 8) = 0;
    //   if (*(byte*)(v4 + 8)) {
    //     v7 = *v4;
    //     if (v7) { EmptyStub_0170(); FreeWrapper_7bcf(v7); }
    //   }
    //   FreeWrapper_7bcf(v4);
    //   return 1;
    // UNRESOLVED: Only forward (next) links appear in the raw source; the 'doubly linked' claim in the canonical name is not supported by this packet's evidence
    // UNRESOLVED: The roles of the tracked node pointers this+0x4 and this+0x8 (head/tail/current) cannot be distinguished from this packet alone
    // UNRESOLVED: Node layout is ambiguous against the packet facts: the value/data is read at node+0x0 and the free flag at node+0x8, while field facts also list node+0xC with init literal 0 that the raw source never references
}
