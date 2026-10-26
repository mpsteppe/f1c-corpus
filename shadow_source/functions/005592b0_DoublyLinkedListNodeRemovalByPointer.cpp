// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005592B0
// Canonical corpus name: DoublyLinkedListNodeRemovalByPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListNodeRemovalByPointer_005592b0.c

void UnknownObject::DoublyLinkedListNodeRemovalByPointer()
{
    // Removes a specific node (a2) from a doubly-linked list rooted at this+0x148. Walks from the list head comparing node pointers until a2 is found; if found, relinks the previous node's next link to the next node and the next node's back link to the previous node, updates the head at this+0x148 when a2 was the head, then runs sub-resource cleanup sub_5574B0, the no-op stub EmptyStub_7470, and frees the node via FreeWrapper_7bcf. In all paths it decrements the node count at this+0x144 and, when that count was 1, clears the head to 0. Returns 0.
    // ASSIGNMENT: Start the walk at the list head stored in this+0x148. [field:this:0x00000148]
    // GUARD: Guard: proceed with the removal only when the list head at this+0x148 is non-null; otherwise jump straight to the count decrement. [field:this:0x00000148]
    // LOOP: Walk the list following each node's forward (next) link until the current node equals the target a2, or bail out early when the chain ends without finding a2. [source:raw]
    // ASSIGNMENT: Read the previous-node pointer (node+100) and, if non-null, set its +104 forward link to the removed node's next, relinking around the target. [source:raw]
    // ASSIGNMENT: Read the next-node pointer (node+104) and, if non-null, set its +100 backward link to the removed node's previous, completing the unlink. [source:raw]
    // ASSIGNMENT: If the removed node was the list head, set the head at this+0x148 to the removed node's next. [field:this:0x00000148]
    // CALL: Call sub_5574B0 on the removed node to clean up its sub-resources before freeing. [callee:0x005574B0]
    // CALL: Call EmptyStub_7470 on the removed node (no-op stub invoked before the free). [callee:0x00557470]
    // CALL: Call FreeWrapper_7bcf to heap-free the removed node. [callee:0x00587BCF]
    // STATE_TRANSITION: Decrement the node count at this+0x144; if the count was 1 before the decrement, clear the list head at this+0x148 to 0. [field:this:0x00000144, field:this:0x00000148]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5592B0(_DWORD* this, _DWORD* target) {
    //     _DWORD* node = this[82];
    //     if (node) {
    //       while (node != target) {
    //         node = node[26];
    //         if (!node) goto done;
    //       }
    //       if (node[25]) *(node[25] + 104) = node[26];
    //       if (node[26]) *(node[26] + 100) = node[25];
    //       if (node == this[82]) this[82] = node[26];
    //       sub_5574B0(node);
    //       EmptyStub_7470(node);
    //       FreeWrapper_7bcf(node);
    //     }
    //   done:
    //     if (this[81]-- == 1) this[82] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Fields this+0x214, this+0x218 and this+0x27C are listed in the deterministic facts but are not visible in the raw source text for this function; they are accounted for as unresolved evidence.
    // UNRESOLVED: The removed node's object type and the exact cleanup contract of sub_5574B0 are unknown.
}
