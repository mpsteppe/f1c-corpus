// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567980
// Canonical corpus name: LinkedListCount
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListCount_00567980.c

void UnknownObject::LinkedListCount()
{
    // Counts the nodes of a singly-linked list. Reads the head/cursor pointer at this+0x8 (this[2]) and walks it through the next pointer stored at node+4 until null, returning the number of visited nodes. If the head pointer is null the loop never runs and the function returns 0. No fields are written.
    // ASSIGNMENT: Load the head node pointer from this+0x8 into the traversal cursor. [field:this:0x00000008, source:raw]
    // GUARD: If the cursor is null the traversal loop is skipped entirely and 0 is returned. [source:raw]
    // LOOP: Walk the list: while the cursor is non-null, continue traversing; each visited node increments the count. [source:raw]
    // CALCULATION: Advance the cursor to the next node by reading the pointer at node+4. [field:*(this+0xC):0x00000004, source:raw]
    // CALCULATION: Increment the result count for each traversed node. [source:raw]
    // RETURN: Return the number of nodes traversed. [source:raw]
    // CALL: Invoked by sub_47D800 (0047D800) and SeasonRacesSceneSorter (004C5940), both on the list-owner object. [caller:0x0047D800, caller:0x004C5940, source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListCount(int* this) {
    //     int cursor = this[2];
    //     int result = 0;
    //     while (cursor) {
    //       cursor = *(int*)(cursor + 4);
    //       ++result;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Node layout beyond the next pointer at node+4 and the identity of the owning container are not established by this packet.
}
