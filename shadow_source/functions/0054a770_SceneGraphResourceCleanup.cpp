// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A770
// Canonical corpus name: SceneGraph
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneGraph_0054a770.c

void UnknownObject::SceneGraphResourceCleanup()
{
    // Scene graph node destructor / resource cleanup. If the head of the first linked list at this+0x204 is non-null, walks the list reading each node's next pointer, unqueues, unlinks and frees every node (QueueResourceCleanup, DoublyLinkedListUnlink, FreeWrapper). Conditionally runs FieldCleanupWithNullCheck when this+0x1EC is set and LinkedNodeDestruction when this+0x1E0 is set. If the second list head at this+0x224 is non-null, walks it via the next pointer at this+0x228, frees every node, then zeroes this+0x224. Frees a 56-byte-stride array at this+0x22C, calling EmptyStub_0170 per element, then zeroes the pointer. Returns 0.
    // GUARD: Guard on the first linked-list head at this+0x204 being non-null before draining it. [field:this:0x00000204, function:0x0054A770, source:raw]
    // LOOP: Walk the first linked list starting at this+0x204, following each node's next pointer (reaches this+0x214); per node: QueueResourceCleanup, DoublyLinkedListUnlink, FreeWrapper. [field:this:0x00000214, callee:0x0054C410, callee:0x0054AC30, callee:0x00587BCF, source:raw]
    // CALL: After the walk drains, run QueueResourceCleanup, DoublyLinkedListUnlink and FreeWrapper once more on the last node. [callee:0x0054C410, callee:0x0054AC30, callee:0x00587BCF, source:raw]
    // GUARD: If this+0x1EC is non-null, call FieldCleanupWithNullCheck(this) for child-resource cleanup. [field:this:0x000001EC, callee:0x00561940, source:raw]
    // GUARD: If this+0x1E0 is non-null, call LinkedNodeDestruction(this) for linked child-resource teardown. [field:this:0x000001E0, callee:0x0054FA50, source:raw]
    // LOOP: Walk the second linked list at this+0x224 following each node's next pointer (reaches this+0x228), freeing every node with FreeWrapper_7bcf. [field:this:0x00000224, field:this:0x00000228, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero this+0x224 after the second list is drained and freed. [field:this:0x00000224, function:0x0054A770, source:raw]
    // CALCULATION: For the array at this+0x22C, read the element count stored just before the array base and walk backwards 56 bytes per element; call EmptyStub_0170 for each element. [field:this:0x0000022C, callee:0x004B0170, source:raw]
    // CALL: Free the array base with FreeWrapper_7bcf and zero this+0x22C. [field:this:0x0000022C, callee:0x00587BCF, source:raw]
    // RETURN: Return 0 at the end of cleanup. [function:0x0054A770, source:raw]

    // Conservative worker pseudocode:
    //   if (this->list1_head) {
    //     for (node = this->list1_head; node; node = node->next) {
    //       QueueResourceCleanup(node); DoublyLinkedListUnlink(node); FreeWrapper(node);
    //     }
    //   }
    //   if (this->field_1EC) FieldCleanupWithNullCheck(this);
    //   if (this->field_1E0) LinkedNodeDestruction(this);
    //   if (this->list2_head) {
    //     for (node = this->list2_head; node; node = node->next) { FreeWrapper(node); }
    //     this->list2_head = 0;
    //   }
    //   if (this->array_22C) {
    //     for (p = base + count*56; count; count--) { p -= 56; EmptyStub_0170(); }
    //     FreeWrapper(base);
    //     this->array_22C = 0;
    //   }
    //   return 0;
    // UNRESOLVED: Element layout of the 56-byte-stride array at this+0x22C and what EmptyStub_0170 (0x004B0170) does per element are unknown.
    // UNRESOLVED: Next-pointer offsets of the two linked-list node structures are implied by the raw dereferences (this+0x214, this+0x228) but the node type is unnamed.
    // UNRESOLVED: The child-resource distinction between FieldCleanupWithNullCheck (0x00561940) and LinkedNodeDestruction (0x0054FA50) is not confirmed.
}
