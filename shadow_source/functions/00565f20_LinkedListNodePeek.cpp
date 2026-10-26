// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565F20
// Canonical corpus name: LinkedListNodePeek
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodePeek_00565f20.c

void UnknownObject::LinkedListNodePeek()
{
    // Advances an enumeration cursor through a linked list: reads the list head's current node pointer at obj+0x8, and if it is non-null replaces it with that node's next pointer (node+0x4). Returns true when the resulting current node exists and its first field (data pointer) is non-zero.
    // ASSIGNMENT: Load the list head pointer: v1 = *this (list head at this+0x0). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Load the current node pointer: v2 = *(v1 + 0x8). [field:obj:0x00000008, source:raw]
    // GUARD: Guard: if the current node pointer v2 is non-null, advance the cursor. [source:raw]
    // ASSIGNMENT: Advance: *(v1 + 0x8) = *(v2 + 0x4) — replace the list head's current-node slot with the current node's next pointer. [field:obj:0x00000008, field:*(obj+0x8):0x00000004, source:raw]
    // ASSIGNMENT: Reload the (possibly advanced) current node: v3 = *(v1 + 0x8). [field:obj:0x00000008, source:raw]
    // RETURN: Return v3 != 0 && *v3 != 0 — true when the current node exists and holds a data pointer. [field:*(obj+0x8):0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_565F20(int *listHead) {
    //     int head = *listHead;
    //     int node = *(int*)(head + 8);
    //     if (node)
    //       *(int*)(head + 8) = *(int*)(node + 4);
    //     int *cur = *(int**)(head + 8);
    //     return cur != 0 && *cur != 0;
    //   }
    // UNRESOLVED: Whether the cursor advance also consumes data (node ownership) or is a pure peek; caller semantics decide.
    // UNRESOLVED: Meaning of the first field of each node (data pointer) beyond the non-zero check.
}
