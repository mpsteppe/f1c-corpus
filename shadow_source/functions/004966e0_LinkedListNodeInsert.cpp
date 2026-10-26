// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004966E0
// Canonical corpus name: LinkedListNodeInsert_66e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsert_66e0_004966e0.c

void UnknownObject::LinkedListNodeInsert()
{
    // Appends a 16-byte node carrying value a2 to a doubly-linked list owned by this. Allocates the node via OperatorNewNhMallocWrapper(16), initializes it (value at +0, next at +4, prev at +8, byte flag at +12), links it after the tail, updates the tail pointer, and increments the node count. On an empty list it also sets the head and a secondary pointer. No action is taken when a2 is NULL.
    // GUARD: Early return when a2 is NULL: if the value argument is zero, the function performs no action. [source:raw]
    // CALL: OperatorNewNhMallocWrapper(16): allocate 16 bytes for a new list node; the result pointer is held in v3. [callee:0x00587C03, source:raw]
    // GUARD: Branch on the allocation result: if v3 is non-NULL the new node is initialized; otherwise v3 is forced to 0 and the dead NULL node is still linked below. [source:raw]
    // ASSIGNMENT: Initialize the new 16-byte node: *(DWORD*)v3 = a2 (value), *(v3+4) = 0 (next), *(v3+8) = 0 (prev), *(BYTE*)(v3+12) = 0 (byte flag). [source:raw]
    // GUARD: Branch on the list head this[1591] (this+0x18DC): if non-NULL (list non-empty) link the new node after the tail; otherwise set both this[1591] (head) and this[1593] (secondary) to the new node. [field:this:0x000018DC, field:this:0x000018E4, source:raw]
    // ASSIGNMENT: On the non-empty path: set the old tail's next pointer *(this[1592]+4) to the new node and the new node's prev *(v3+8) to the old tail this[1592]. [field:this:0x000018E0, source:raw]
    // ASSIGNMENT: Update the tail pointer this[1592] (this+0x18E0) to the new node. [field:this:0x000018E0, source:raw]
    // CALCULATION: Increment the node count this[1594] (this+0x18E8) by 1. [field:this:0x000018E8, source:raw]
    // RETURN: void function; returns implicitly after the append. [function:0x004966E0, source:raw]

    // Conservative worker pseudocode:
    //   void LinkedListNodeInsert(void* this, int a2) {
    //     if (!a2) return;
    //     int* v3 = OperatorNewNhMallocWrapper(16);
    //     if (v3) { v3[0] = a2; v3[1] = 0; v3[2] = 0; *((char*)v3 + 12) = 0; }
    //     else { v3 = 0; }
    //     if (this[0x18DC / 4]) { *(int*)(this[0x18E0 / 4] + 4) = v3; *(int*)(v3 + 8) = this[0x18E0 / 4]; }
    //     else { this[0x18DC / 4] = v3; this[0x18E4 / 4] = v3; }
    //     this[0x18E0 / 4] = v3;
    //     ++this[0x18E8 / 4];
    //   }
    // UNRESOLVED: The node's internal offsets (+4 next, +8 prev, +12 byte) have no field evidence refs in the packet and are described only from the raw source text.
    // UNRESOLVED: The meaning of the byte flag at node+12 is unknown.
    // UNRESOLVED: this+0x18E4 (this[1593]) is set alongside the head on first append; its role as a current/read cursor comes from the skeleton fill (DERIVED) and is not confirmed by the raw source.
    // UNRESOLVED: On allocation failure the NULL node is still linked into the list; whether the list tolerates a NULL node is unconfirmed.
    // UNRESOLVED: The owner object type is not established by the packet; the LEGACY ABI name 'Linked_List_Node_Insert_4966e0' identifies the function, not its class.
}
