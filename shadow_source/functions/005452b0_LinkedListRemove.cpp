// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005452B0
// Canonical corpus name: LinkedListRemove
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListRemove_005452b0.c

void UnknownObject::LinkedListRemove()
{
    // Doubly-linked list node removal. Unlinks node a2 from its list by patching prev->next (offset +76) and next->prev (offset +72), each guarded on the neighbour pointer being non-zero. If the removed node is the current head (this+0x108), the head advances to node->next. Returns a2, or the new head when the head node itself is removed.
    // ASSIGNMENT: result initialized to a2, the node being removed [source:raw]
    // ASSIGNMENT: Read the prev pointer stored at node+72; when non-zero, write the removed node's next pointer (node+76) into prev+76 so the predecessor skips the removed node [source:raw]
    // ASSIGNMENT: Read the next pointer stored at node+76; when non-zero, write the removed node's prev pointer (node+72) into next+72 so the successor skips the removed node [source:raw]
    // GUARD: Head update is conditional on the removed node being the current head: this[66] == a2, i.e. this+0x108 == a2 [field:this:0x00000108, source:raw]
    // ASSIGNMENT: When the head is removed, advance this+0x108 to the removed node's next pointer (node+76) and set result to that new head [field:this:0x00000108, source:raw]
    // RETURN: Return result: a2 normally, or the new head (node->next) when the removed node was the list head [function:0x005452B0, source:raw]
    // UNKNOWN: Called by F_3DSoundSourceDestructor (0x00545150) and ArithmeticComparison_9170 (0x00549170); neither caller's link-node layout is evidenced in this packet [caller:0x00545150, caller:0x00549170]

    // Conservative worker pseudocode:
    //   prev = *(node + 72);
    //   if (prev) *(prev + 76) = *(node + 76);
    //   next = *(node + 76);
    //   if (next) *(next + 72) = *(node + 72);
    //   if (this[66] == node) { this[66] = *(node + 76); result = *(node + 76); }
    //   return result;
    // UNRESOLVED: The owning object's type is unknown; only its head pointer at +0x108 is evidenced
    // UNRESOLVED: The node layout (prev at +72, next at +76) is evident only from this function's own reads/writes; no caller-side node structure is available in the packet
}
