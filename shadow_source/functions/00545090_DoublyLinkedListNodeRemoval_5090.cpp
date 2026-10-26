// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545090
// Canonical corpus name: DoublyLinkedListNodeRemoval_5090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemoval_5090_00545090.c

void UnknownObject::DoublyLinkedListNodeRemoval_5090()
{
    // Removes a doubly-linked-list node (a2) from a list owned by this. Reads the node's prev pointer at node+436 (0x1B4) and, when non-null, writes the node's next pointer (node+440) into prev+440; reads the node's next pointer at node+440 (0x1B8) and, when non-null, writes the node's prev pointer (node+436) into next+436. When the removed node is the current head (this[62] == a2, i.e. this+0xF8), the head advances to node->next and that new head becomes the return value; otherwise returns a2.
    // ASSIGNMENT: result initialized to a2, the node being removed [source:raw]
    // ASSIGNMENT: Read the prev pointer at node+436 (0x1B4); when non-zero write the removed node's next pointer (node+440) into prev+440 so the predecessor's next link skips the removed node [source:raw]
    // ASSIGNMENT: Read the next pointer at node+440 (0x1B8); when non-zero write the removed node's prev pointer (node+436) into next+436 so the successor's prev link skips the removed node [source:raw]
    // GUARD: Head advance is guarded on the removed node being the current head: this[62] == a2, i.e. this+0xF8 == a2 [field:this:0x000000F8, source:raw]
    // ASSIGNMENT: When the head node is removed, advance this+0xF8 to the removed node's next pointer (node+440) and set result to that new head [field:this:0x000000F8, source:raw]
    // RETURN: Return result: a2 normally, or the new head (node->next) when the removed node was the list head [function:0x00545090, source:raw]
    // UNKNOWN: Called by SceneGraphTreeDestructor (0x00544EF0) during scene-graph tree teardown; the caller's node layout is not evidenced in this packet [caller:0x00544EF0]

    // Conservative worker pseudocode:
    //   int DoublyLinkedListNodeRemoval_5090(_DWORD *this, int a2) {
    //     result = a2;
    //     prev = *(a2 + 436);  if (prev) *(prev + 440) = *(a2 + 440);
    //     next = *(a2 + 440);  if (next) *(next + 436) = *(a2 + 436);
    //     if (this[62] == a2) { this[62] = *(a2 + 440); result = *(a2 + 440); }
    //     return result;
    //   }
    // UNRESOLVED: Owner class is unknown; only the list-head pointer at this+0xF8 and the node link layout (prev +436, next +440) are evidenced within this function
    // UNRESOLVED: The node link offsets +436/+440 are read/written only inside this function; no independent node structure is available in the packet
}
