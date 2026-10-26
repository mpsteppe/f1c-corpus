// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005459D0
// Canonical corpus name: LinkedListRemove_59d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListRemove_59d0_005459d0.c

void UnknownObject::LinkedListRemove_59d0()
{
    // Removes a doubly-linked-list node (a2) from a list owned by this. Reads the node's prev pointer at node+48 (0x30) and, when non-null, writes the node's next pointer (node+52) into prev+52; reads the node's next pointer at node+52 (0x34) and, when non-null, writes the node's prev pointer (node+48) into next+48. When the removed node is the current head (this[87] == a2, i.e. this+0x15C), the head advances to node->next and that new head becomes the return value; otherwise returns a2.
    // ASSIGNMENT: result initialized to a2, the node being removed [source:raw]
    // ASSIGNMENT: Read the prev pointer at node+48 (0x30); when non-zero write the removed node's next pointer (node+52) into prev+52 so the predecessor's next link skips the removed node [source:raw]
    // ASSIGNMENT: Read the next pointer at node+52 (0x34); when non-zero write the removed node's prev pointer (node+48) into next+48 so the successor's prev link skips the removed node [source:raw]
    // GUARD: Head advance is guarded on the removed node being the current head: this[87] == a2, i.e. this+0x15C == a2 [field:this:0x0000015C, source:raw]
    // ASSIGNMENT: When the head node is removed, advance this+0x15C to the removed node's next pointer (node+52) and set result to that new head [field:this:0x0000015C, source:raw]
    // RETURN: Return result: a2 normally, or the new head (node->next) when the removed node was the list head [function:0x005459D0, source:raw]
    // UNKNOWN: Called by F_3DSoundSourceDestructor (0x00545150) during 3D sound source teardown; the caller's node layout is not evidenced in this packet [caller:0x00545150]

    // Conservative worker pseudocode:
    //   int LinkedListRemove_59d0(_DWORD *this, int a2) {
    //     result = a2;
    //     prev = *(a2 + 48);  if (prev) *(prev + 52) = *(a2 + 52);
    //     next = *(a2 + 52);  if (next) *(next + 48) = *(a2 + 48);
    //     if (this[87] == a2) { this[87] = *(a2 + 52); result = *(a2 + 52); }
    //     return result;
    //   }
    // UNRESOLVED: Owner class is unknown; only the list-head pointer at this+0x15C and the node link layout (prev +48, next +52) are evidenced within this function
    // UNRESOLVED: The node link offsets +48/+52 are read/written only inside this function; no independent node structure is available in the packet
}
