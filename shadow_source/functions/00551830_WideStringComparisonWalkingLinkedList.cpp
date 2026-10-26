// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551830
// Canonical corpus name: WideStringComparisonWalkingLinkedList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WideStringComparisonWalkingLinkedList_00551830.c

void UnknownObject::WideStringComparisonWalkingLinkedList()
{
    // Walks a singly linked list starting from the head pointer stored at this+0x13C (this[79]). For each node it compares the node's name string (reached through the pointer at node+28) against the search key a2 using strcmp; on a match it returns the node pointer, otherwise it advances through the next pointer at node+36. Returns 0 for an empty list and when the end of the list is reached without a match.
    // ASSIGNMENT: Load the list head v2 = this[79] (dword at this+0x13C) as the starting node. [field:this:0x0000013C, source:raw]
    // GUARD: If the head pointer is null the list is empty; return 0 immediately. [field:this:0x0000013C, source:raw]
    // LOOP: While strcmp(a2, *(node+28)+28) is non-zero (node name string does not equal a2), keep walking; a zero strcmp exits the loop with v2 as the matching node. [field:*(this+0x160):0x0000001C, source:raw]
    // GUARD: In the walk step, if the next-node pointer at node+36 is null the end of the list was reached without a match; return 0. [field:*(this+0x160):0x00000024, source:raw]
    // ASSIGNMENT: Advance to the next node: v2 = *(node+36). [field:*(this+0x160):0x00000024, source:raw]
    // RETURN: Return v2, the pointer to the first node whose name matches a2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_551830(this, const char* a2) {
    //     v2 = this[79];                     // this+0x13C, list head
    //     if (!v2) return 0;
    //     while (strcmp(a2, *(v2+28)+28) != 0) {
    //       v2 = *(v2+36);
    //       if (!v2) return 0;
    //     }
    //     return v2;
    //   }
    // UNRESOLVED: The name string is reached via a pointer at node+28 that is itself dereferenced at +28; the intermediate object layout at node+28 is not otherwise described.
    // UNRESOLVED: The packet field base *(this+0x160) for the node fields does not literally match the raw source, which reads the node pointer from this[79] and the fields node-relative (node+28, node+36). Whether the node derives from *(this+0x160) is unproven.
    // UNRESOLVED: The element type and owner class of the linked list are unknown.
}
