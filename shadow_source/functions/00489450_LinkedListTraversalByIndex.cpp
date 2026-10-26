// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489450
// Canonical corpus name: LinkedListTraversalByIndex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListTraversalByIndex_00489450.c

void UnknownObject::LinkedListTraversalByIndex()
{
    // Returns the node at index this+0x168 of a linked list whose head is at this+0x90, following each node's next pointer at +0x8C. If the index is negative, returns null immediately. If the index exceeds the list length, the walk ends at the null next pointer and null is returned. Called by UIScreenTextAccessor (0x00489920) and UIScreenTextAccessor_9950 (0x00489950).
    // ASSIGNMENT: Load the index v1 = this[90] (index/count at this+0x168) and initialize the result to null. [field:this:0x00000168, source:raw]
    // GUARD: If the index at this+0x168 is negative, skip the walk entirely and return null. [field:this:0x00000168, source:raw]
    // ASSIGNMENT: Seed the walk: result = this[36], the list head at this+0x90. [field:this:0x00000090, source:raw]
    // LOOP: While the current node is non-null: break when the remaining index reaches zero or below, otherwise advance to the next node via its next pointer at +0x8C and decrement the remaining index. [field:*(this+0x11C):0x0000008C, source:raw]
    // RETURN: Return the node reached at the requested index, or null when the index is negative or the list ends early. [function:0x00489450, source:raw]

    // Conservative worker pseudocode:
    //   void *LinkedListTraversalByIndex(void **this) {
    //       int remaining = this[90];
    //       void *node = 0;
    //       if (remaining >= 0) {
    //           for (node = this[36]; node; --remaining) {
    //               if (remaining <= 0)
    //                   break;
    //               node = *(void **)(node + 140);
    //           }
    //       }
    //       return node;
    //   }
    // UNRESOLVED: The packet field base *(this+0x11C) for the node next pointer at +0x8C does not appear in the raw source, which addresses each node directly; the identity of that indirect base and the node type are unevidenced.
    // UNRESOLVED: The list owner class and what the returned node represents to the UI screen-text accessors are unevidenced.
}
