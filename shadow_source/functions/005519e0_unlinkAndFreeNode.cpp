// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005519E0
// Canonical corpus name: DoublyLinkedListNodeRemoval_19e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemoval_19e0_005519e0.c

void UnknownObject::unlinkAndFreeNode()
{
    // Unlinks a node from a doubly linked list: if the node has a predecessor (a2[11]) its next pointer is set to the successor (a2[12]); if it has a successor its previous pointer is set to the predecessor; if the node is the list head (this[70] at offset 0x118) the head is advanced to the successor. Then runs a cleanup callback, a stub, and frees the node, returning 0.
    // GUARD: Read the predecessor node pointer a2[11]; if non-null proceed to link it forward [source:raw]
    // ASSIGNMENT: Set the predecessor's next pointer (at prev+48) to the successor node a2[12] [source:raw]
    // GUARD: Read the successor node pointer a2[12]; if non-null proceed to link it backward [source:raw]
    // ASSIGNMENT: Set the successor's previous pointer (at next+44) to the predecessor node a2[11] [source:raw]
    // GUARD: If the removed node is the list head stored at offset 0x118, advance the head [field:this:0x00000118, source:raw]
    // ASSIGNMENT: Set the head pointer this[70] at offset 0x118 to the successor node a2[12] [field:this:0x00000118, source:raw]
    // CALL: Run the cleanup callback CallWrapperReturning0 before deletion [callee:0x00550AC0, source:raw]
    // CALL: Invoke EmptyStub_7470 on the node before freeing [callee:0x00557470, source:raw]
    // CALL: Deallocate the node memory via FreeWrapper_7bcf [callee:0x00587BCF, source:raw]
    // RETURN: Return 0 to signal success [function:0x005519E0, source:raw]

    // Conservative worker pseudocode:
    //   int unlink(void* this, Node* node) {
    //     if (node->prev) node->prev->next = node->next;
    //     if (node->next) node->next->prev = node->prev;
    //     if (node == this->head) this->head = node->next;
    //     CallWrapperReturning0();
    //     EmptyStub_7470(node);
    //     FreeWrapper_7bcf(node);
    //     return 0;
    //   }
}
