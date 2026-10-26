// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053C630
// Canonical corpus name: DoublyLinkedListUnlink
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListUnlink_0053c630.c

void UnknownObject::DoublyLinkedListUnlink()
{
    // Unlinks node a1 from a doubly linked list whose prev/next links live at offsets 0x1E4/0x1E8: if a1's prev (a1+0x1E4) exists, patches prev->next (prev+0x1E8) to a1's next (a1+0x1E8); if a1's next (a1+0x1E8) exists, patches next->prev (next+0x1E4) to a1's prev (a1+0x1E4). If the list head dword_8B8F28 equals a1, the head is advanced to a1's next and that new head becomes the return value; otherwise the return value is a1. Called from audio-engine paths AudioEngineInitialization (0x00546010) and MutexSemaphoreCleanup (0x005461B0).
    // ASSIGNMENT: Read the prev node pointer from a1+0x1E4 into v2. [field:this:0x000001E4, function:0x0053C630, source:raw]
    // GUARD: Guard: only patch the prev link when v2 (prev node) is non-null. [source:raw]
    // ASSIGNMENT: Write a1's next pointer (a1+0x1E8) into the prev node's next field (prev+0x1E8), splicing this node out of the forward chain. [field:this:0x000001E8, field:*(this+0x1E4):0x000001E8, source:raw]
    // ASSIGNMENT: Read the next node pointer from a1+0x1E8 into v3. [field:this:0x000001E8, source:raw]
    // GUARD: Guard: only patch the next link when v3 (next node) is non-null. [source:raw]
    // ASSIGNMENT: Write a1's prev pointer (a1+0x1E4) into the next node's prev field (next+0x1E4), splicing this node out of the backward chain. [field:this:0x000001E4, field:*(this+0x1E8):0x000001E4, source:raw]
    // GUARD: Guard: if dword_8B8F28 (list head) equals a1, this node is the head of the list. [global:0x008B8F28, source:raw]
    // ASSIGNMENT: Advance the list head: set result and dword_8B8F28 to a1's next pointer (a1+0x1E8), so the head becomes the following node. [field:this:0x000001E8, global:0x008B8F28, source:raw]
    // RETURN: Return result: the new head when a1 was the head, otherwise a1 itself. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_53C630(node* a1) {
    //     result = a1;
    //     prev = a1->prev(0x1E4);
    //     if (prev) prev->next(0x1E8) = a1->next(0x1E8);
    //     next = a1->next(0x1E8);
    //     if (next) next->prev(0x1E4) = a1->prev(0x1E4);
    //     if (head == a1) { result = a1->next(0x1E8); head = result; }
    //     return result;
    //   }
    // UNRESOLVED: Link offsets 0x1E4/0x1E8 are prev/next for the list (per existing analysis), but the owning object and the list's head-holder semantics beyond the head pointer are not evidenced here.
    // UNRESOLVED: The exact reason the return value changes to the new head only in the head-removal case is not established by this packet.
}
