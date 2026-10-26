// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476660
// Canonical corpus name: SeasonPathMatchSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonPathMatchSearch_00476660.c

void UnknownObject::SeasonPathMatchSearch()
{
    // Walks a linked list of season scene nodes (head stored at this+0xF0, cursor at this+0xF8), comparing each node's path string at node+0x3C against the global season path (dword_7D0434, fallback byte_5EA438) via the string-compare helper sub_588410. Stores the count of visited nodes as the match index at this+0x174 and always finishes by dispatching the virtual method at vtable offset 152.
    // GUARD: Skip the search when the list head at this+0xF0 is null or its first node value is null. [field:this:0x000000F0, source:raw]
    // ASSIGNMENT: Initialize the traversal cursor this+0xF8 to the list head (this+0xF0) and reset the match index this+0x174 to 0. [field:this:0x000000F0, field:this:0x000000F8, field:this:0x00000174]
    // LOOP: Iterate the linked list, reading each node's path string at node+0x3C (base *(this+0xF0)); use byte_5EA438 as the node path when the node string is null. [field:*(this+0xF0):0x0000003C, global:0x005EA438, source:raw]
    // CALL: Compare the global season path dword_7D0434 (fallback byte_5EA438 when null) against the node path with sub_588410; a return of 0 means equality. [callee:0x00588410, global:0x007D0434, global:0x005EA438, source:raw]
    // GUARD: Break the loop when the paths match; the visited-node count v4 becomes the match index stored at this+0x174. [field:this:0x00000174, source:raw]
    // STATE_TRANSITION: On each non-match, advance the cursor this+0xF8 to the next node (node+0x4); when the list ends without a match, dispatch the virtual method at vtable offset 152 (vtable read from this+0x0). [field:this:0x00000000, field:this:0x000000F8, source:raw]
    // RETURN: Return the result of the virtual method at vtable offset 152 dispatched on this (vtable read from this+0x0); runs after a match is stored or when the list is empty/ended. Invoked from SeasonSceneInitialization. [field:this:0x00000000, caller:0x00477720, source:raw]

    // Conservative worker pseudocode:
    //   cursor = this->listHead;                 // this+0xF0 -> this+0xF8
    //   matchIndex = 0;                          // this+0x174
    //   while (cursor) {
    //       nodePath = cursor->path ? cursor->path : byte_5EA438;   // node+0x3C
    //       seasonPath = dword_7D0434 ? dword_7D0434 : byte_5EA438;
    //       if (sub_588410(seasonPath, nodePath) == 0) break;       // match
    //       ++matchIndex;
    //       cursor = cursor->next;               // node+0x4
    //   }
    //   this->matchIndex = matchIndex;
    //   return this->vtbl[152/4](this);
    // UNRESOLVED: field:obj:0x00000098 and field:this:0x000000FC are read fields recorded by extraction but have no corresponding operation in the raw source; their role is undetermined.
}
