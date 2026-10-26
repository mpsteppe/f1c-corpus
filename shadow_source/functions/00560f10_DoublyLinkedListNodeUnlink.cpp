// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00560F10
// Canonical corpus name: DoublyLinkedListNodeUnlink_0f10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeUnlink_0f10_00560f10.c

void UnknownObject::DoublyLinkedListNodeUnlink()
{
    // Unlinks node a2 from a doubly-linked list. Node fields: +0x30 holds the successor pointer and +0x34 holds the predecessor pointer. The successor's +0x34 and the predecessor's +0x30 slots are patched to bypass the node; the link head stored at this+0x2C is advanced to the node's predecessor when it pointed at a2. Returns a2, or the new head when the unlinked node was the head.
    // GUARD: If node a2 has a successor (a2+0x30 nonzero), set the successor's predecessor slot (successor+0x34) to node a2's predecessor (a2+0x34). [source:raw]
    // GUARD: If node a2 has a predecessor (a2+0x34 nonzero), set the predecessor's successor slot (predecessor+0x30) to node a2's successor (a2+0x30). [source:raw]
    // GUARD: If the link head at this+0x2C equals a2, store a2+0x34 (the node's predecessor) as the new link head at this+0x2C. [field:this:0x0000002C, source:raw]
    // RETURN: Return a2, or the new link head when the unlinked node was the this+0x2C head. [function:0x00560F10, source:raw]

    // Conservative worker pseudocode:
    //   int sub_560F10(DoublyLinkedOwner* this, Node* node) {
    //     if (node->next) node->next->prev = node->prev;
    //     if (node->prev) node->prev->next = node->next;
    //     if (this->head == node) this->head = node->prev;
    //     return this->head == node ? node->prev : node;
    //   }
    // UNRESOLVED: Semantic roles of node offsets +0x30 (successor) and +0x34 (predecessor) are inferred from the unlink symmetry; only this+0x2C has packet field evidence.
    // UNRESOLVED: The relationship between this (owner) and a2 (node) is DERIVED from the structural twin 00476060, not independently proven here.
    // UNRESOLVED: Return-value semantics (node vs new head) and the caller's use of it are not evidenced beyond callers 0x00545150.
}
