// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407C90
// Canonical corpus name: LinkedListNodeRemovalWithVTableRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemovalWithVTableRelease_00407c90.c

void UnknownObject::LinkedListNodeRemovalWithVTableRelease()
{
    // Removes from a singly linked list the node whose value pointer (node+0) equals a2, then releases the removed node's value through its vtable and frees the node. The list head is at this+0x18, tail at this+0x1C, traversal cursor at this+0x20 and node count at this+0x24; each node is 12 bytes with value at +0, next at +4 and an ownership flag byte at +8. First a scan walks the list comparing each node's value to a2, then a second walk from the head tracks the predecessor so the node can be unlinked; head/tail/cursor pointers and the count are updated, and if the node's flag byte and value are both set the value object's virtual release method is called with argument 1 before FreeWrapper_7bcf frees the node.
    // GUARD: Returns null when the head pointer at this+0x18 is null (empty list), and again when the head node's value (node+0) is null; the scan also bails as soon as a null next pointer is hit [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Initializes the traversal cursor this+0x20 from the head pointer this+0x18 [field:this:0x00000020, field:this:0x00000018, source:raw]
    // LOOP: First scan advances the cursor this+0x20 through each node's next pointer (node+4), comparing the node's value (node+0, also read through the cursor) against a2 until a match or a null node [field:this:0x00000020, field:*(this+0x20):0x00000000, source:raw]
    // GUARD: Proceeds to unlinking only when a2 is non-null; a second walk restarts from the head this+0x18, reading the head node's value, and tracks the predecessor of the matching node [field:this:0x00000018, field:*(this+0x18):0x00000000, source:raw]
    // ASSIGNMENT: Unlinks the node: the predecessor's next (or the head this+0x18 when there is no predecessor) is set to the removed node's next, and the tail this+0x1C is rewound to the predecessor when the removed node was the tail (its value read through the tail-node pointer) [field:this:0x00000018, field:this:0x0000001C, field:*(this+0x1C):0x00000000, field:*(*(this+0x1C)+0x0):0x00000000, source:raw]
    // CALCULATION: Advances the cursor this+0x20 to the removed node's successor when the removed node was the current cursor [field:this:0x00000020, source:raw]
    // STATE_TRANSITION: Decrements the node count this+0x24 after unlinking [field:this:0x00000024, source:raw]
    // CALL: When the removed node's ownership flag byte (node+8) and its value pointer (node+0) are both set, calls the value object's virtual release method (indirect vtable call) with argument 1 [source:raw]
    // CALL: Frees the unlinked 12-byte node via FreeWrapper_7bcf and returns its result [callee:0x00587BCF, source:raw]
    // CALL: Invoked by ShortComputation_6250 (00406250) [caller:0x00406250, source:raw]

    // Conservative worker pseudocode:
    //   cursor = this.head;
    //   if (cursor && *cursor) {
    //     for (cursor = this.head; cursor; cursor = cursor->next) {
    //       if (cursor->value == a2) break;
    //     }
    //     if (a2 && cursor) {
    //       prev = NULL;
    //       for (n = this.head; n && n != cursor; n = n->next) prev = n;
    //       if (cursor == this.cursor) this.cursor = cursor->next;
    //       if (prev) prev->next = cursor->next; else this.head = cursor->next;
    //       if (this.tail == cursor) this.tail = prev;
    //       --this.count;
    //       if (cursor->ownsValue && cursor->value) cursor->value->release(1);
    //       FreeWrapper_7bcf(cursor);
    //     }
    //   }
    // UNRESOLVED: The virtual release call target is indirect through the value object's vtable; the concrete class of the list's value objects is not determinable from this packet
    // UNRESOLVED: The ownership flag byte at node+8 and the semantics of the release argument 1 are inferred from the call shape only
    // UNRESOLVED: Existing analysis (skeletons_filled) labels this list a mutex/sync object list with offsets shifted by 0x10; that object identity is not corroborated by packet evidence
}
