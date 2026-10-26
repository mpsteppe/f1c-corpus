// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489BA0
// Canonical corpus name: UIListSearchAndSelect
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListSearchAndSelect_00489ba0.c

void UnknownObject::UIListSearchAndSelect()
{
    // Searches a linked list of UI list nodes by string comparison against the node label, walking from the list head stored at this+0x90 through next-node pointers at node+0x8C. When a node whose label matches the search string a2 is found, calls UIListSelectionHandler(this, index, a3) to select it and returns 0. Returns -1 when either argument or the head is null, or when the list is exhausted without a match.
    // ASSIGNMENT: Load the linked-list head pointer v4 from this[36] (this+0x90) and seed the match index v5 to 1. [field:this:0x00000090, source:raw]
    // GUARD: If the search string a2 is null or the head pointer v4 is null, return -1 immediately. [source:raw]
    // LOOP: Traverse the linked list until the string match breaks the loop or the list ends. [source:raw]
    // ASSIGNMENT: Read the current node's label string from node+0xB0; if that pointer is null, fall back to the global byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Call sub_588410(label, a2) as a string comparison; a zero return (match) breaks the loop. [callee:0x00588410, source:raw]
    // CALCULATION: Advance to the next node through the next-node pointer at node+0x8C and increment the match index v5. [field:*(this+0x11C):0x0000008C, source:raw]
    // GUARD: If the list is exhausted without a match (next pointer null), return -1. [source:raw]
    // CALL: Call UIListSelectionHandler(this, v5, a3) to select the matched item at the found index. [callee:0x00489AB0]
    // RETURN: Return 0 to signal a successful search and selection. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_489BA0(this, const char* search, char flag) {
    //     int node = this[36];
    //     int index = 1;
    //     if (!search || !node)
    //       return -1;
    //     for (;;) {
    //       char* label = *(char**)(node + 176);
    //       if (!label)
    //         label = byte_5EA438;
    //       if (!sub_588410(label, search))
    //         break;
    //       node = *(int*)(node + 140);
    //       ++index;
    //       if (!node)
    //         return -1;
    //     }
    //     UIListSelectionHandler(this, index, flag);
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the third argument a3 passed through to UIListSelectionHandler are unknown.
    // UNRESOLVED: Purpose of the this+0x140 field recorded in the packet is unknown; it is not referenced by this function.
    // UNRESOLVED: The node label at node+0xB0 and the list layout have no standalone evidence ref in the packet.
}
