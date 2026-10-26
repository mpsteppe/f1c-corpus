// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498E50
// Canonical corpus name: NodeInsertionIntoTree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NodeInsertionIntoTree_00498e50.c

void UnknownObject::NodeInsertionIntoTree()
{
    // Inserts node a2 into a linked list owned by this. Increments the node counter this[22], stores the owner back-link at a2+80, runs a helper computation over four cached fields, then either initializes head/tail (this[18], this[20]) when the list is empty or walks the +72 next-pointers from FieldGetter_8e30(this) to append a2 at the tail.
    // ASSIGNMENT: Increment the node counter this[22]. [field:this:0x00000058]
    // ASSIGNMENT: Store the owner back-link into the new node: *(_DWORD *)(a2 + 80) = this. [source:raw]
    // CALL: Run the insertion-side computation ShortComputation_a9c0(this[1], this[2], this[3], this[4]) using four cached fields. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, callee:0x0049A9C0]
    // CALL: v3 = FieldGetter_8e30(this): retrieve the current list head. [callee:0x00498E30]
    // GUARD: If v3 is nonzero the list already contains at least one node. [source:raw]
    // LOOP: Walk the +72 next pointers from the head to the last node: for (i = *(v3 + 72); i; i = *(i + 72)) v3 = i. [source:raw]
    // ASSIGNMENT: Append a2 as the successor of the last node: *(_DWORD *)(v3 + 72) = a2. [source:raw]
    // RETURN: Return a2 as the inserted node. [source:raw]
    // GUARD: If FieldGetter_8e30 returned zero the list is empty: initialize head and tail to a2. [callee:0x00498E30]
    // ASSIGNMENT: Set head this[18] = a2 and tail this[20] = a2. [field:this:0x00000048, field:this:0x00000050]
    // RETURN: Return a2 as the inserted node. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_498E50(_DWORD *this, int node) {
    //     ++this[22];
    //     *(int *)(node + 80) = (int)this;
    //     ShortComputation_a9c0(this[1], this[2], this[3], this[4]);
    //     int cur = FieldGetter_8e30(this);
    //     if (cur) { for (int i = *(int *)(cur + 72); i; i = *(int *)(i + 72)) cur = i; *(int *)(cur + 72) = node; }
    //     else { this[18] = node; this[20] = node; }
    //     return node;
    //   }
    // UNRESOLVED: Role of ShortComputation_a9c0 during insertion is unknown; it only observes four fields.
    // UNRESOLVED: Purpose of the back-link at node+80 and the exact node/owner relationship is not established.
    // UNRESOLVED: Whether this[18]/this[20] are head/tail pointers or something else is unproven; they are written together only on the empty-list path.
}
