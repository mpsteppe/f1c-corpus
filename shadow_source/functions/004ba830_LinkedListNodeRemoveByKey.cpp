// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA830
// Canonical corpus name: LinkedListNodeRemoval_a830
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemoval_a830_004ba830.c

void UnknownObject::LinkedListNodeRemoveByKey()
{
    // Singly linked list node removal by key value. Walks the list from the head pointer at this+0, comparing each node's first dword against the key a2 and advancing via the next pointer at node+4; returns 0 when the key is null, the list is empty, or the key is not found. On a match it unlinks the node (updating the head at this+0, the second list pointer at this+4, and the tail pointer at this+8), decrements the element count at this+0xC, clears the node's flag byte at +8 unless a3 is set, frees the node's owned data via FreeWrapper_7bcf (preceded by EmptyStub_0170) when that flag remains set, then frees the node itself and returns 1.
    // GUARD: Early return 0 when the search key a2 is null: no removal is attempted. [source:raw]
    // ASSIGNMENT: Initialize result to 0 and start traversal: v4 = head pointer stored at this+0, previous pointer v5 = 0. [field:this:0x00000000, source:raw]
    // GUARD: When the head pointer at this+0 is non-null, begin the node walk; otherwise fall through to the result-returning tail. [field:this:0x00000000, source:raw]
    // LOOP: Walk the list: while the current node's first dword differs from a2, remember it as v5 and advance v4 via the next pointer at node+4; if the walk reaches a null next pointer the key was not found. [field:obj:0x00000004, source:raw]
    // RETURN: Return 0 immediately when the walk exhausts the list without matching a2. [source:raw]
    // GUARD: If the matched node is the tail pointer stored at this+0x8, advance the tail to the node's next pointer at +4. [field:this:0x00000008, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Unlink the node: capture its next pointer at +4, then make the previous node's next (or the head at this+0 when there is no previous) point past the removed node. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // GUARD: If the second list pointer at this+0x4 currently references the removed node, back it up to the previous node v5. [field:this:0x00000004, source:raw]
    // CALCULATION: Decrement the element count stored at this+0xC. [field:this:0x0000000C, source:raw]
    // GUARD: When the free-data flag a3 is not set, clear the node's flag byte at node+8. [field:obj:0x00000008, source:raw]
    // GUARD: When the node's flag byte at +8 is non-zero, the node owns its data pointer (first dword of the node); if that data pointer is non-null, run EmptyStub_0170() and FreeWrapper_7bcf on the data. [field:obj:0x00000008, callee:0x004B0170, callee:0x00587BCF, source:raw]
    // CALL: Free the node structure itself with FreeWrapper_7bcf(v4). [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 to report that the node was removed. [source:raw]

    // Conservative worker pseudocode:
    //   char LinkedListNodeRemoveByKey(_DWORD* this, int key, char freeData) {
    //     if (!key) return 0;
    //     _DWORD* prev = 0;
    //     _DWORD* node = *this;                 // head at this+0
    //     if (node) {
    //       while (*node != key) {
    //         prev = node;
    //         node = (_DWORD*)node[1];          // next at node+4
    //         if (!node) return 0;
    //       }
    //       if (node == (_DWORD*)this[2]) this[2] = node[1];   // tail at this+0x8
    //       if (prev) prev[1] = node[1]; else *this = node[1]; // relink
    //       if ((_DWORD*)this[1] == node) this[1] = prev;      // pointer at this+0x4
    //       --this[3];                          // count at this+0xC
    //       if (!freeData) *((_BYTE*)node + 8) = 0;
    //       if (*((_BYTE*)node + 8)) {
    //         if (*node) { EmptyStub_0170(); FreeWrapper_7bcf((void*)*node); }
    //       }
    //       FreeWrapper_7bcf(node);
    //       return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Node field at +0xC (packet-declared, initialized to 0) has no visible access in the raw source; possibly decompiler artifact or padding.
    // UNRESOLVED: Role of the second list pointer at this+0x4 (head/cursor/tail ambiguity) is not fully determined; only the head at this+0 and the tail at this+0x8 show clear behavior.
    // UNRESOLVED: Purpose of the EmptyStub_0170() call that precedes the data free is unknown.
}
