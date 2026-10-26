// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464740
// Canonical corpus name: LinkedListNodeRemoval
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemoval_00464740.c

void UnknownObject::LinkedListNodeRemoval()
{
    // __thiscall removal of a node whose key equals a2 from a singly-linked list managed by the object at this (head this[0], tail this[1], newest/tail-tracking this[2], count this[3]). Traverses from the head, relinks around the matched node, advances the tracked newest pointer and the tail when needed, decrements the count, and conditionally frees the node's embedded data block (guarded by the flag byte at node + 8) and the node itself via FreeWrapper_7bcf. Returns 1 on success and 0 when a2 is null, the list is empty, or the key is not found. Called from SessionScoringUpdate.
    // ASSIGNMENT: Initialize the result to 0 (failure default). [source:raw]
    // GUARD: If the search key a2 is 0, return the failure result without touching the list. [source:raw]
    // ASSIGNMENT: Start traversal: v4 = head (*this), previous-node pointer v5 = 0. [field:this:0x00000000]
    // GUARD: If the list head (*this) is 0, the list is empty; return the failure result. [field:this:0x00000000]
    // LOOP: Walk the singly-linked list comparing each node's key (*v4) against a2; on each step keep the previous node in v5 and advance via the node's next pointer v4[1]; if the list ends before a match, return the failure result. [field:obj:0x00000004, source:raw]
    // STATE_TRANSITION: If the removed node is the tracked newest/tail pointer (this[2]), advance it to the removed node's next. [field:this:0x00000008]
    // ASSIGNMENT: Relink around the removed node: if a previous node exists set its next pointer (v5[1]) to the removed node's next, otherwise update the head (*this) to the removed node's next. [field:*(obj+0x4):0x00000000, field:this:0x00000000, field:obj:0x00000004]
    // ASSIGNMENT: If the removed node was the tail (this[1] == v4), set the tail to the previous node v5. [field:this:0x00000004]
    // CALCULATION: Decrement the node count this[3]. [field:this:0x0000000C]
    // ASSIGNMENT: When a3 is 0 (do-not-free-data), clear the flag byte at node + 8. [field:obj:0x00000008]
    // GUARD: If the flag byte at node + 8 is set, free the node's embedded data block: release the block pointed to by *v4 through FreeWrapper_7bcf, then free the data handle v7 itself. [field:obj:0x00000008, callee:0x00587BCF]
    // CALL: Free the removed node itself with FreeWrapper_7bcf(v4). [callee:0x00587BCF]
    // RETURN: Return 1 to signal successful removal. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodeRemoval(_DWORD *this, int key, char freeData) {
    //     _DWORD *node = (_DWORD *)*this;
    //     _DWORD *prev = 0;
    //     if (!key || !node) return 0;
    //     while (*node != key) {
    //       prev = node;
    //       node = (_DWORD *)node[1];
    //       if (!node) return 0;
    //     }
    //     if (node == (_DWORD *)this[2]) this[2] = node[1];
    //     if (prev) prev[1] = node[1]; else *this = node[1];
    //     if ((_DWORD *)this[1] == node) this[1] = prev;
    //     --this[3];
    //     if (!freeData) *((_BYTE *)node + 8) = 0;
    //     if (*((_BYTE *)node + 8)) {
    //       void **data = (void **)*node;
    //       if (data) {
    //         if (*data) FreeWrapper_7bcf(*data);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     FreeWrapper_7bcf(node);
    //     return 1;
    //   }
    // UNRESOLVED: The packet lists a node field at offset 0xC (RW, init 0) but no write to a node field at that offset appears in this source text; it may be written by a sibling node-creation path or by the caller, so its role here is left unresolved rather than guessed.
}
