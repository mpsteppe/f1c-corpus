// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1DC0
// Canonical corpus name: LinkedListAppend_1dc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListAppend_1dc0_004a1dc0.c

void UnknownObject::linkedListAppend()
{
    // Appends a node containing data a2 to a linked list described by this (head at +0x0, tail at +0x4, second tracker at +0x8, element count at +0xC). Guarded by the flag byte at +0x10 being non-zero and a2 non-null. Allocates a 12-byte node via OperatorNewNhMallocWrapper, fills it with the data pointer and zeroed next/flag fields, then links it at the tail (updating head/off-0x8 tracker on the first insert) and increments the count. Returns the new node pointer (or 0 when guarded out or allocation fails).
    // GUARD: Proceed only if the flag byte at this+0x10 is non-zero AND a2 is non-null; otherwise skip the append and fall through to return. [field:this:0x00000010, source:raw]
    // CALL: Allocate a 12-byte node via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the new node: data pointer = a2, next pointer = 0, flag byte at +8 = 0. [source:raw]
    // GUARD: Branch on whether the list head at this+0x0 is already non-null (list non-empty). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Non-empty list path: link the old tail (this+0x4) to the new node via *(*tail + 4) = new, set tail (this+0x4) = new node, increment element count at this+0xC. [field:*(this+0x4):0x00000004, field:this:0x00000004, field:this:0x0000000C]
    // STATE_TRANSITION: Empty-list path: set head (this+0x0), second tracker (this+0x8) and tail (this+0x4) all to the new node, and set element count at this+0xC to 1. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C]
    // RETURN: Return the new node pointer (or 0 when the guard fails or allocation returns null). [source:raw]

    // Conservative worker pseudocode:
    //   if (!this[16] || !a2) return 0;
    //   node = OperatorNewNhMallocWrapper(12);
    //   if (!node) return 0;
    //   *(int*)node = a2; *(int*)(node+4) = 0; *(char*)(node+8) = 0;
    //   if (*(int*)this) {
    //     *(int*)(*(int*)(this+4) + 4) = node;
    //     *(int*)(this+4) = node;
    //     ++*(int*)(this+0xC);
    //   } else {
    //     *(int*)this = node; *(int*)(this+8) = node; *(int*)(this+4) = node;
    //     *(int*)(this+0xC) = 1;
    //   }
    //   return node;
    // UNRESOLVED: The semantic role of the second tracker pointer at this+0x8 (written only on first append, never updated on subsequent appends) is unconfirmed.
    // UNRESOLVED: The content/type of the stored data a2 is unknown; the list payload type is not established.
    // UNRESOLVED: The caller ShortComputation_1b70 (0x004A1B70) context is not described.
}
