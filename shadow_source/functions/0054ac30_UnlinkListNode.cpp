// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054AC30
// Canonical corpus name: DoublyLinkedListUnlink_ac30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListUnlink_ac30_0054ac30.c

void UnknownObject::UnlinkListNode()
{
    // Unlinks node a2 from a doubly linked list whose head pointer is stored at this+0x204. Node layout per the raw source: next at node+0x10, prev at node+0x140. When the node has a prev, sets prev->next to the node's next; when it has a next, sets next->prev to the node's prev; when the node is the list head (this[129] == a2), advances the head to the node's next (the list becomes empty if the node had no next). Returns 0. Called by SceneGraph during scene-graph cleanup.
    // GUARD: If the removed node's prev pointer (a2+0x140) is non-null, take the prev-linking path; a null prev means the node is the head. [source:raw]
    // ASSIGNMENT: Set the prev node's next pointer (v2+0x10) to the removed node's next (a2+0x10), splicing the node out from the prev side. [source:raw]
    // GUARD: If the removed node's next pointer (a2+0x10) is non-null, take the next-linking path; a null next means the node is the tail. [source:raw]
    // ASSIGNMENT: Set the next node's prev pointer (v3+0x140) to the removed node's prev (a2+0x140), splicing the node out from the next side. [source:raw]
    // GUARD: If the removed node is the list head (this[129] == a2), take the head-update path. [field:this:0x00000204, source:raw]
    // ASSIGNMENT: Advance the list head at this+0x204 (this[129]) to the removed node's next (a2+0x10); if the node had no next, the list becomes empty (head = 0). [field:this:0x00000204, source:raw]
    // RETURN: Return 0. [function:0x0054AC30, source:raw]

    // Conservative worker pseudocode:
    //   int UnlinkListNode(_DWORD* this, _DWORD* node) {
    //     if (node[80]) node[80][4] = node[4];
    //     if (node[4]) node[4][80] = node[80];
    //     if (this[129] == node) this[129] = node[4];
    //     return 0;
    //   }
    // UNRESOLVED: Concrete node and container types are unknown; the prev at node+0x140, next at node+0x10 and head at this+0x204 are unnamed fields.
    // UNRESOLVED: The caller SceneGraph (0x0054A770) suggests the list belongs to a scene-graph object/child list, but owner and container identity are not established by this packet.
    // UNRESOLVED: The ABI lead name DoublyLinkedListUnlink is LEGACY trust and not independently verified.
}
