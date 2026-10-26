// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586000
// Canonical corpus name: LinkedListNodeAppend_6000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeAppend_6000_00586000.c

void UnknownObject::LinkedListNodeAppend_6000()
{
    // Singly-linked list append. Allocates a 12-byte node via OperatorNewNhMallocWrapper: payload dword at node+0, next pointer zeroed at node+4, byte flag at node+8. The node is linked as the new tail: if the list already has a head (offset 0x0) the old tail's next pointer (this[1] + 4) is rewired; otherwise head and the field at offset 0x8 are set to the new node. The tail pointer at offset 0x4 is updated and the node count at offset 0xC is incremented. Returns 1 whenever a2 is non-null (even if allocation failed), otherwise 0.
    // ASSIGNMENT: Initialize the return value to 0 (the a2-null failure path). [source:raw]
    // GUARD: Guard on payload a2 being non-null; when null, return the pre-initialized 0. [source:raw]
    // CALL: Allocate a 12-byte node via OperatorNewNhMallocWrapper(12); a zero result is normalized back to a null node pointer. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the payload a2 into the new node at node+0. [source:raw]
    // ASSIGNMENT: Zero the next pointer of the new node at node+4. [source:raw]
    // ASSIGNMENT: Store the byte flag a3 into the new node at node+8. [source:raw]
    // GUARD: Test whether the list already has a head by reading the first dword at offset 0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Non-empty list: link the old tail's next pointer (this[1] + 4, tail stored at offset 0x4) to the new node. [field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Empty list: set the head at offset 0x0 and the list field at offset 0x8 to the new node. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Update the tail pointer at offset 0x4 to the new node. [field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Increment the node count dword at offset 0xC (this[3]). [field:this:0x0000000C, source:raw]
    // RETURN: Return 1 once the node is appended. [source:raw]
    // RETURN: Return 0 on the a2-null early-exit path. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_586000(List *this, void *payload, char flag) {
    //     if (!payload) return 0;
    //     Node *n = OperatorNewNhMallocWrapper(12);
    //     if (n) { n->payload = payload; n->next = 0; n->byte_flag = flag; }
    //     if (this->head) this->tail->next = n;
    //     else { this->head = n; this->field_8 = n; }
    //     this->tail = n;
    //     ++this->count; // offset 0xC
    //     return 1;
    //   }
    // UNRESOLVED: Semantics of the list field at offset 0x8 are unknown; it is written only when the list was empty, so it may be a cursor, first-node alias or reuse of a union member.
    // UNRESOLVED: The count dword at offset 0xC is classified R (read) in the packet field table although this function increments it; the rw classification may predate this write.
    // UNRESOLVED: Owner object behind `this` and the exact node payload/flag meanings are caller-defined and unknown here.
}
