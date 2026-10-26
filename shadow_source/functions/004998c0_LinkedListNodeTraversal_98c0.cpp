// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004998C0
// Canonical corpus name: LinkedListNodeTraversal_98c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeTraversal_98c0_004998c0.c

void UnknownObject::LinkedListNodeTraversal_98c0()
{
    // Advances a linked-list iterator one step: reads the next node pointer at node+72 from the current node stored at this+0x14, replaces this+0x14 with it, and returns true while a node remains. Returns false when the current node is NULL (end of list).
    // ASSIGNMENT: Read the current iterator node pointer stored at this+0x14. [source:raw, field:this:0x00000014]
    // GUARD: Guard on the current node at this+0x14 being non-NULL; when it is NULL the list is exhausted and the function returns false. [source:raw, guard:0]
    // ASSIGNMENT: Advance the iterator: store the next node pointer (read from the current node at offset 72) back into this+0x14. [source:raw, field:this:0x00000014]
    // RETURN: Return whether the new current node at this+0x14 is non-NULL. [source:raw, field:this:0x00000014]

    // Conservative worker pseudocode:
    //   bool sub_4998C0(_DWORD *this) {
    //     _DWORD *node = (_DWORD *)this[5];            // this+0x14
    //     if (node)
    //       this[5] = *(_DWORD **)((char *)node + 72); // next
    //     return this[5] != 0;
    //   }
    // UNRESOLVED: The list node type and the meaning of the next pointer at node+72 are not established beyond this function's pointer math.
    // UNRESOLVED: Owner object type is unknown; this+0x14 is interpreted as the iterator cursor.
}
