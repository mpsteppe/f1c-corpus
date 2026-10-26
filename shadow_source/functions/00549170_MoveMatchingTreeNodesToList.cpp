// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00549170
// Canonical corpus name: ArithmeticComparison_9170
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_9170_00549170.c

void UnknownObject::MoveMatchingTreeNodesToList()
{
    // Walks a node list starting from this[58] (head at this+0xE8), advancing through each node's forward pointer at node+0x14. For each node it runs RecursiveTreeStringSearch to look for a matching child; when a match is found it moves that node from the source list rooted at *this to the target list managed by this via LinkedListRemove and DoublyLinkedListAppend_90b0. Returns the last append result.
    // LOOP: Iterate i from this[58] (list head at this+0xE8), advancing through each node's forward pointer at node+0x14 until i is null. [field:this:0x000000E8, field:*(this+0xFC):0x00000014, source:raw]
    // ASSIGNMENT: Initialize local search result v4 to 0. [source:raw]
    // CALL: Search node i's tree for a matching child, storing any found node into v4. [callee:0x0054BC60, source:raw]
    // ASSIGNMENT: Set result to v4, the candidate found node. [source:raw]
    // GUARD: When v4 is nonzero, move the found node from the source list rooted at *this to the target list. [source:raw]
    // CALL: Remove the found node v4 from the source list rooted at *this. [callee:0x005452B0, field:this:0x00000000, source:raw]
    // CALL: Append the found node v4 to the target list managed by this. [callee:0x005490B0, source:raw]
    // RETURN: Return result, the last append result (or the last search output). [source:raw]

    // Conservative worker pseudocode:
    //   for (i = this[58]; i != 0; i = *(int*)(i + 20)) {
    //       v4 = 0;
    //       RecursiveTreeStringSearch(i, &v4);
    //       if (v4 != 0) {
    //           LinkedListRemove(*this, v4);
    //           result = DoublyLinkedListAppend_90b0(this, v4);
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The packet labels the iteration field base as *(this+0xFC) with displacement 0x14, but the raw source advances through nodes reachable from this[58]; the tree each node points into is not identified.
    // UNRESOLVED: What RecursiveTreeStringSearch matches (string key, tree node, node address) is not grounded beyond its name.
    // UNRESOLVED: The source list rooted at *this and the target list managed by this are not confirmed to be distinct container types.
}
