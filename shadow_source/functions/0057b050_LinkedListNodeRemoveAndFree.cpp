// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B050
// Canonical corpus name: LinkedListNodeRemovalWithMemoryFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemovalWithMemoryFree_0057b050.c

void UnknownObject::LinkedListNodeRemoveAndFree()
{
    // Removes the first node whose stored data equals a2 from a singly-linked list, frees the node and optionally its data, and decrements the node count. Guards on null key (a2) and null head (this+0x8). Walks nodes from the head tracking a predecessor, comparing each node's data field (+0x0) against a2; on exhaustion returns 0. On a match: if the node is the tracked tail2 at this+0x10, that pointer advances to the node's next; unlinks by rewiring the predecessor's next (or the head at this+0x8 when there is no predecessor); if the node was the tail at this+0xC, the tail rewinds to the predecessor; decrements the count at this+0x14. If the node's flag byte (+0x8) is set, frees the node's data via FreeWrapper_7bcf, then frees the node itself. Returns 1 on success.
    // GUARD: If the key a2 is null, return 0 immediately (nothing to remove). [function:0x0057B050, source:raw]
    // GUARD: If the head pointer at this+0x8 (this[2]) is null, return 0 immediately (empty list). [field:this:0x00000008, source:raw]
    // LOOP: Linear scan: from the head, walk node-next pointers comparing each node's data field (+0x0) against a2, keeping the predecessor (prev); return 0 when the walk runs out without a match. [field:this:0x00000008, field:*(this+0xC):0x00000000, field:*(this+0xC):0x00000004, source:raw]
    // STATE_TRANSITION: If the matched node equals the secondary tail/iterator at this+0x10, advance that pointer to the matched node's next (+0x4). [field:this:0x00000010, field:*(this+0xC):0x00000004, source:raw]
    // ASSIGNMENT: Unlink the matched node: the predecessor's next (+0x4) becomes the node's next, or when there is no predecessor the head at this+0x8 becomes the node's next. [field:this:0x00000008, field:*(this+0xC):0x00000004, source:raw]
    // ASSIGNMENT: If the matched node was the tail at this+0xC, rewind the tail to the predecessor. [field:this:0x0000000C, source:raw]
    // CALCULATION: Decrement the node count at this+0x14 (this[5]). [field:this:0x00000014, source:raw]
    // GUARD: If the matched node's flag byte at +0x8 is set, free the node's data pointer (+0x0) with FreeWrapper_7bcf before freeing the node. [field:*(this+0xC):0x00000008, field:*(this+0xC):0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Free the unlinked node structure itself with FreeWrapper_7bcf. [callee:0x00587BCF, function:0x0057B050, source:raw]
    // RETURN: Return 1 to signal successful removal (or 0 when the key/head guards fired or no matching node was found). [function:0x0057B050, source:raw]

    // Conservative worker pseudocode:
    //   bool LinkedListNodeRemoveAndFree(List* this, void* key) {
    //     if (!key) return false;
    //     Node* node = this->head;
    //     if (!node) return false;
    //     Node* prev = 0;
    //     while (node->data != key) {
    //       prev = node; node = node->next;
    //       if (!node) return false;
    //     }
    //     if (node == this->tail2) this->tail2 = node->next;
    //     if (prev) prev->next = node->next; else this->head = node->next;
    //     if (this->tail == node) this->tail = prev;
    //     --this->count;
    //     if (node->flag) FreeWrapper_7bcf(node->data);
    //     FreeWrapper_7bcf(node);
    //     return true;
    //   }
    // UNRESOLVED: The exact meaning of the secondary pointer at this+0x10 (tail2) is not evidenced; the fill names it a secondary tail but the caller context is absent.
    // UNRESOLVED: Node layout (data at +0x0, next at +0x4, flag byte at +0x8) is inferred from the raw body; packet field evidence uses base *(this+0xC) for the node fields.
    // UNRESOLVED: No caller is evidenced in this packet, so the owning container type remains unknown.
}
