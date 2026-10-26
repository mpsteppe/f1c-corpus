// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB490
// Canonical corpus name: sub_4BB490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BB490_004bb490.c

void UnknownObject::DoublyLinkedListAppend()
{
    // Appends a new 12-byte node to a doubly linked list whose head lives at this. Allocates the node with OperatorNewNhMallocWrapper(12), stores the caller value a2 at node+0 and a byte flag a3 at node+8, links node+4 to the current last node, updates the list head (offset 0x0), seeds offsets 0x4/0x8 when the list was empty, increments the count at offset 0xC, and returns 1. Returns 0 when a2 is null.
    // GUARD: Guard on a2: if the caller-supplied value is null, skip insertion and return 0. [source:raw]
    // CALL: Call OperatorNewNhMallocWrapper(12) to allocate a 12-byte node. [source:raw, callee:0x00587C03]
    // ASSIGNMENT: On allocation failure set v5 to 0 so the subsequent link writes are suppressed. [source:raw]
    // ASSIGNMENT: Initialize the new node: node[0] = a2, node[4] = 0, node[8] = a3 (byte). [source:raw]
    // GUARD: Branch on *this (offset 0x0): when the list is non-empty, link node[4] to the previous last node. [source:raw, field:this:0x00000000]
    // ASSIGNMENT: When the list was empty, set both this[1] (offset 0x4) and this[2] (offset 0x8) to the new node. [source:raw, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Write the new node to the list head *this (offset 0x0) so it becomes the last node. [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Increment the element count this[3] at offset 0xC. [source:raw, field:this:0x0000000C]
    // RETURN: Return 1 on successful insertion, 0 when a2 was null. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4BB490(unsigned *list, int value, char flag) {
    //     if (!value) return 0;
    //     Node *node = OperatorNewNhMallocWrapper(12);
    //     if (!node) return 0;
    //     node->value = value;
    //     node->prev = 0;
    //     node->flags = flag;
    //     if (*list) node->prev = *list;
    //     else { list[1] = (unsigned)node; list[2] = (unsigned)node; }
    //     *list = (unsigned)node;
    //     ++list[3];
    //     return 1;
    //   }
    // UNRESOLVED: Exact role of the list fields is inferred: offset 0x0 acts as the tail/last pointer, offsets 0x4 and 0x8 as head/tail seeds on empty list, offset 0xC as a count; the packet does not name them.
    // UNRESOLVED: Semantics of the byte flag a3 stored at node+8 are unknown.
    // UNRESOLVED: Node+4 is only linked to the previous node; a forward link (node+? -> next) is not written here, so this is an append that builds a backward chain.
    // UNRESOLVED: Callers ResourcePoolNodeAllocDealloc (0x00490940) and CollisionObjectListManagement (0x004B4B50) use this for object pools, but the concrete list owner is unknown.
}
