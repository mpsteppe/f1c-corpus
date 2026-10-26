// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545250
// Canonical corpus name: ActorNodeLinkedListAppend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ActorNodeLinkedListAppend_00545250.c

void UnknownObject::ActorNodeLinkedListAppend()
{
    // Appends an actor node a2 to a singly-linked list managed by this. Sets bit 3 in the node's flag dword at +0x3C and clears its forward link at +0x4C, then registers the node with TreeNodeAccumulator(this, a2). When the list head at this+0x108 is non-null the node is appended to the tail via the +0x4C forward links; otherwise it becomes the new head. The node's backward link at +0x48 is set to the previous tail, or cleared when the node becomes the head.
    // ASSIGNMENT: Set bit 3 in the node's flag dword: v2 = a2[15] | 8 at node+0x3C. [source:raw]
    // ASSIGNMENT: Clear the node's forward link at +0x4C (a2[19] = 0) before insertion. [source:raw]
    // CALL: Register the node with the tree accumulator: TreeNodeAccumulator(this, a2). [callee:0x00544C50, source:raw]
    // GUARD: Read the list head at this+0x108; when it is non-null append to the tail, otherwise make the new node the head. [field:this:0x00000108, source:raw]
    // LOOP: Walk to the list tail following the +0x4C forward links; the extraction derives this chain through the base at this+0x154. [field:*(*(this+0x154)+0x4C):0x0000004C, field:this:0x00000154, source:raw]
    // ASSIGNMENT: Append: set the tail's +0x4C forward link to the new node and set the new node's +0x48 backward link to the old tail. [field:*(*(this+0x154)+0x4C):0x0000004C, source:raw]
    // ASSIGNMENT: Empty-list path: store the new node as head at this+0x108 and clear its +0x48 backward link. [field:this:0x00000108, source:raw]
    // RETURN: Return the accumulator result (or the last walked value). [callee:0x00544C50, source:raw]

    // Conservative worker pseudocode:
    //   int ActorNodeLinkedListAppend(void* this, void* node) {
    //     node[15] = node[15] | 8;        // set bit 3 at +0x3C
    //     node[19] = 0;                   // clear forward link at +0x4C
    //     result = TreeNodeAccumulator(this, node);
    //     tail = this[66];                // this+0x108 list head
    //     if (tail) {
    //       for (next = *(tail + 76); next; next = *(next + 76)) tail = next;
    //       *(tail + 76) = node;          // append at +0x4C
    //       node[18] = tail;              // backward link at +0x48
    //     } else {
    //       this[66] = node;              // new head
    //       node[18] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the flag bit set at node+0x3C is unknown.
    // UNRESOLVED: field:*(*(this+0x154)+0x4C):0x0000004C expresses the tail-walk chain with an extraction-derived base this+0x154; the raw source reads the same +0x4C links starting from the head at this+0x108, so the base mapping is not directly evidenced.
    // UNRESOLVED: The owning class is unknown; caller labels (pit-crew / scene node) are caller-side guesses, not evidence.
}
