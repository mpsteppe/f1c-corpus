// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005455F0
// Canonical corpus name: DoublyLinkedListRemove
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListRemove_005455f0.c

void UnknownObject::DoublyLinkedListRemove()
{
    // Removes node a2 from a category-tagged doubly-linked list and decrements the corresponding category counter. The node's low three bits (*a2 & 7) select which of three counter/head pairs on `this` to update (cases 1, 2, 4); otherwise the node itself is treated as its own counter/head slot. After unlink, if the selected head equals the removed node the head advances to node->next.
    // GUARD: Switch on *a2 & 7 selecting the category-specific counter/head pair: case 1 uses this+71/this+72, case 2 uses this+75/this+76, case 4 uses this+73/this+74 (byte offsets 0x124 counter and 0x128 head), default uses the node itself for both. [source:raw, field:this:0x00000124, field:this:0x00000128]
    // ASSIGNMENT: Save the node's backward link: v4 = a2[26] (prev pointer, byte offset 104). [source:raw]
    // GUARD: If v4 (prev) is non-null, set prev's forward link: *(v4 + 108) = a2[27] (next). [source:raw]
    // ASSIGNMENT: Save the node's forward link: v5 = a2[27] (next pointer, byte offset 108). [source:raw]
    // GUARD: If v5 (next) is non-null, set next's backward link: *(v5 + 104) = a2[26] (prev). [source:raw]
    // GUARD: If the selected head (*v3) equals the removed node, advance the head to the node's next: *v3 = a2[27]. [source:raw, field:this:0x00000128]
    // CALCULATION: Decrement the selected category counter: --*result (this 0x124 for case 4). [source:raw, field:this:0x00000124]
    // RETURN: Return the counter pointer that was decremented. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_5455F0(_DWORD *this, _DWORD *node) {
    //     _DWORD *counter, *head;
    //     switch (*node & 7) {
    //       case 1: counter = this + 71; head = this + 72; break;
    //       case 2: counter = this + 75; head = this + 76; break;
    //       case 4: counter = this + 73; head = this + 74; break;
    //       default: counter = node; head = node; break;
    //     }
    //     if (node[26]) *(_DWORD *)((char *)node[26] + 108) = node[27];
    //     if (node[27]) *(_DWORD *)((char *)node[27] + 104) = node[26];
    //     if (*head == node) *head = node[27];
    //     --*counter;
    //     return counter;
    //   }
    // UNRESOLVED: The meaning of the 3-bit category tag (1/2/4) in *a2 is not established here.
    // UNRESOLVED: The callers sub_5454A0 and LinkedListWalkWithDispatch determine which node type and list instances are affected.
}
