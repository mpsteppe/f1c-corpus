// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497510
// Canonical corpus name: DoublyLinkedListNodeInsert
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeInsert_00497510.c

void UnknownObject::DoublyLinkedListNodeInsert()
{
    // Appends an element to a doubly-linked list. Increments the operation counter at this+0x2C and calls two simple setters, then, when a2 is non-null, allocates a 16-byte list node carrying data a2 and a flag byte 1 at node+12. If the list is empty (this+0x4 == 0) the new node becomes head, tail and secondary pointer (this+0x4/+0x8/+0xC); otherwise it is linked after the current tail (this+0x8) with forward/backward pointers at node+4/node+8. Node count this+0x10 is incremented on every successful insert. Returns a2.
    // ASSIGNMENT: Increments the operation counter at this+0x2C (this[11]) on every call [field:this:0x0000002C, source:raw]
    // CALL: SimpleSetter_fdf0 invoked with this as the receiver [callee:0x0054FDF0, source:raw]
    // CALL: SimpleSetter_fc40 invoked with constant argument 1 [callee:0x0054FC40, source:raw]
    // GUARD: Node allocation and list insertion only run when the payload argument a2 is non-null; otherwise only the counter increment and setter calls execute [source:raw]
    // CALL: OperatorNewNhMallocWrapper allocates 16 bytes for the new list node [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initializes the new node: data=a2 at node+0, next=0 at node+4, prev=0 at node+8, flag byte 1 at node+12 [source:raw]
    // GUARD: Empty-list fast path: when the head pointer this+0x4 is zero, the new node becomes head (this+0x4), secondary (this+0xC) and tail (this+0x8), the count is incremented and a2 returned early [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Non-empty append: links the new node after the current tail — old tail's next (this+0x8 + 4) = new node, new node's prev (node+8) = old tail, then this+0x8 = new node [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Increments the node count at this+0x10 (this[4]) on each successful insert [field:this:0x00000010, source:raw]
    // RETURN: Returns a2, the payload argument, on every path [source:raw]
    // CALL: Invoked by sub_492460 (00492460) as the list insertion primitive [caller:0x00492460, source:raw]

    // Conservative worker pseudocode:
    //   ++this[11];
    //   SimpleSetter_fdf0(this);
    //   SimpleSetter_fc40(1);
    //   if (a2) {
    //     node = OperatorNewNhMallocWrapper(16);
    //     if (node) { node->data = a2; node->next = 0; node->prev = 0; node->flag = 1; }
    //     if (!this[1]) { this[1] = node; this[3] = node; this[2] = node; ++this[4]; return a2; }
    //     this[2]->next = node; node->prev = this[2]; this[2] = node; ++this[4];
    //   }
    //   return a2;
    // UNRESOLVED: The side effects of SimpleSetter_fdf0 and SimpleSetter_fc40 are opaque from this packet; their arguments (this and constant 1) are recorded but their targets are unknown
    // UNRESOLVED: The node-internal offsets (data+0, next+4, prev+8, flag+12) appear only in the raw source and have no separate field evidence reference
    // UNRESOLVED: The role of the secondary pointer this+0xC (set with head on first insert but never consulted here) is unresolved
}
