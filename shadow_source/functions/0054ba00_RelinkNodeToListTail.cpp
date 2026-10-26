// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054BA00
// Canonical corpus name: DoublyLinkedListNodeMover
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeMover_0054ba00.c

void UnknownObject::RelinkNodeToListTail()
{
    // Unlinks node a2 from its current doubly-linked list by patching its neighbours' prev/next pointers, then checks the global list container at dword_8B8F28 and replaces the container head when a2 was the head. If a3 is non-zero, the tree nodes of a2 are accumulated via TreeNodeAccumulator. The node is then appended to the tail of `this`'s list (this+0x44): if the list is non-empty the chain is walked to its tail, otherwise a2 seeds the head. a2's back-pointers (prev, next, owner) are rewritten, and finally a2's sublist (a2+560) is appended to `this`'s sublist (this+560) when both exist.
    // CALCULATION: Read a2's previous and next pointers (a2[18], a2[19]) to begin the unlink. [source:raw]
    // ASSIGNMENT: Patch the neighbours out of the list: if a2's previous node exists set prev.next (node+76) to a2's next; if a2's next node exists set next.prev (node+72) to a2's previous. [source:raw]
    // GUARD: Check the list container's head pointer: when a2 equals the head (container+264) of the global container at dword_8B8F28, replace the head with a2's next and re-read the container. [global:0x008B8F28, field:*(this+0x90):0x0000004C, source:raw]
    // GUARD: If a3 is non-zero, run tree-node accumulation over a2. [callee:0x00544C50, source:raw]
    // CALL: TreeNodeAccumulator(v7, a2) recursively accumulates a2's tree nodes against the list container. [callee:0x00544C50, global:0x008B8F28, source:raw]
    // GUARD: Read `this`'s list head (this+0x44); when non-null the chain is walked to its tail, otherwise a2 seeds the head. [field:this:0x00000044, source:raw]
    // LOOP: Walk the chain through each node's next pointer (node+76) until the tail node is reached. [source:raw]
    // ASSIGNMENT: Append a2 at the tail: write a2 into the tail node's next slot (packet field *(*(this+0x90)+0x4C)), or seed this+0x44 with a2 when the list was empty. [field:this:0x00000044, field:*(*(this+0x90)+0x4C):0x0000004C, source:raw]
    // ASSIGNMENT: Rewrite a2's back-pointers: a2.prev = previous tail walk_cursor, a2.next = 0, a2.owner = this. [source:raw]
    // GUARD: Sublist merge: read a2's sublist (a2[140]) and `this`'s sublist (this[140], packet field this+0x230); proceed only when both are non-null. [field:this:0x00000230, source:raw]
    // CALL: AppendNodeToDoublyLinkedListTail(a2_sublist) appends a2's sublist to `this`'s sublist tail. [callee:0x00560EB0, field:this:0x00000230]
    // RETURN: Return the walk/head-seed result (zero when a2 was appended to a non-empty list), or the result of the sublist append when both sublists existed. [source:raw]

    // Conservative worker pseudocode:
    //   prev = a2->prev; next = a2->next;
    //   if (prev) prev->next = next;
    //   if (next) next->prev = prev;
    //   container = dword_8B8F28;
    //   if (a2 == container->head) container->head = next;
    //   if (a3) TreeNodeAccumulator(container, a2);
    //   tail = this->listHead;
    //   if (tail) { while (tail->next) tail = tail->next; tail->next = a2; }
    //   else this->listHead = a2;
    //   a2->prev = tail; a2->next = 0; a2->owner = this;
    //   if (a2->sublist && this->sublist) return AppendNodeToDoublyLinkedListTail(a2->sublist);
    //   return result;
    // UNRESOLVED: The packet's field *(*(this+0x90)+0x4C) ('next pointer of the list head's tail node, patched during unlink') does not map unambiguously onto a single line of the decompiled text; its exact role is inferred.
    // UNRESOLVED: The packet's field *(this+0x90) ('list container next pointer, for head update check') is associated with the container head update, but the code reads the head via dword_8B8F28+264 rather than this+0x90; the two views may be of the same container, which is not proven.
    // UNRESOLVED: The semantic role of the global container at dword_8B8F28 and the meaning of the subtree accumulation under a3 are unknown.
    // UNRESOLVED: The purpose of merging sublists (this+0x230 and a2+560) is not established.
}
