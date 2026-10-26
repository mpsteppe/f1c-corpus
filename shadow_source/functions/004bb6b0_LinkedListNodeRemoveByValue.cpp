// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB6B0
// Canonical corpus name: sub_4BB6B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BB6B0_004bb6b0.c

void UnknownObject::LinkedListNodeRemoveByValue()
{
    // Singly linked list node removal by value. Walks the list from the head pointer at this+0, comparing each node's first dword against the value a2 and advancing via the next pointer at node+4; returns 0 when a2 is null, the list is empty, or the value is not found. On a match it unlinks the node (updating the head at this+0, the second list pointer at this+4, and the tail pointer at this+8), decrements the element count at this+0xC, clears the node's flag byte at +8 unless a3 is set, frees the node's owned data via FreeWrapper_7bcf when that flag remains set, then frees the node itself and returns 1.
    // GUARD: Early return 0 when the search value a2 is null: no removal is attempted. [source:raw]
    // ASSIGNMENT: Initialize result to 0 and start traversal: v4 = head pointer stored at this+0, previous pointer v5 = 0. [field:this:0x00000000, source:raw]
    // GUARD: When the head pointer at this+0 is non-null, begin the node walk; otherwise fall through to the result-returning tail. [field:this:0x00000000, source:raw]
    // LOOP: Walk the list: while the current node's first dword differs from a2, remember it as v5 and advance v4 via the next pointer at node+4; if the walk reaches a null next pointer the value was not found. [field:obj:0x00000004, field:*(obj+0x4):0x00000000, field:*(obj+0x4):0x00000004, source:raw]
    // RETURN: Return 0 immediately when the walk exhausts the list without matching a2. [source:raw]
    // GUARD: If the matched node is the tail pointer stored at this+0x8, advance the tail to the node's next pointer at +4. [field:this:0x00000008, field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Unlink the node: capture its next pointer at +4, then make the previous node's next (or the head at this+0 when there is no previous) point past the removed node. [field:this:0x00000000, field:obj:0x00000004, source:raw]
    // GUARD: If the second list pointer at this+0x4 currently references the removed node, back it up to the previous node v5. [field:this:0x00000004, source:raw]
    // CALCULATION: Decrement the element count stored at this+0xC. [field:this:0x0000000C, source:raw]
    // GUARD: When the free-data flag a3 is not set, clear the node's flag byte at node+8. [field:*(obj+0x4):0x00000008, source:raw]
    // GUARD: When the node's flag byte at +8 is non-zero, free the node's owned data pointer (first dword of the node) via FreeWrapper_7bcf. [field:*(obj+0x4):0x00000008, callee:0x00587BCF, source:raw]
    // CALL: Free the node structure itself with FreeWrapper_7bcf(v4). [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 to report that the node was removed. [source:raw]

    // Conservative worker pseudocode:
    //   char LinkedListNodeRemoveByValue(int* this, int value, char freeData) {
    //     if (!value) return 0;
    //     int* prev = 0;
    //     int* node = *this;                    // head at this+0
    //     if (node) {
    //       while (*(_DWORD*)node != value) {
    //         prev = node;
    //         node = *(_DWORD**)(node + 4);     // next at node+4
    //         if (!node) return 0;
    //       }
    //       if (node == this[2]) this[2] = *(_DWORD*)(node + 4);   // tail at this+0x8
    //       if (prev) *(_DWORD*)(prev + 4) = *(_DWORD*)(node + 4); else *this = *(_DWORD*)(node + 4);
    //       if (this[1] == node) this[1] = prev; // pointer at this+0x4
    //       --this[3];                          // count at this+0xC
    //       if (!freeData) *(_BYTE*)(node + 8) = 0;
    //       if (*(_BYTE*)(node + 8)) FreeWrapper_7bcf(*(LPVOID*)node);
    //       FreeWrapper_7bcf((LPVOID)node);
    //       return 1;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Role of the second list pointer at this+0x4 (head/cursor/tail ambiguity) is not fully determined; only the head at this+0 and the tail at this+0x8 show clear behavior.
    // UNRESOLVED: Why this variant directly frees the node's data without the EmptyStub_0170() call that its structural twin (004BA830) performs.
}
