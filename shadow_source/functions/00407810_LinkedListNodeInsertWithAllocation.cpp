// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00407810
// Canonical corpus name: LinkedListNodeInsertWithAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsertWithAllocation_00407810.c

void UnknownObject::LinkedListNodeInsertWithAllocation()
{
    // Allocates a 108-byte view/projection structure, initializes it with ViewProjectionStructInit, then allocates a 12-byte linked-list node holding it and inserts the node at the tail of the list rooted at this. The insertion is gated on the enable flag at this+0x88 and on a2 being non-null. When the list is empty (head this+0x8 is null) the node becomes both head this+0x8 and first-reference this+0x10; otherwise it links after the current tail this+0xC. The tail is advanced to the new node and the count at this+0x14 is incremented. The initialized 108-byte structure is returned even when the 12-byte node allocation fails.
    // GUARD: Returns 0 immediately when the enable flag at this+0x88 (this[34]) is zero [field:this:0x00000088, source:raw]
    // GUARD: Returns 0 immediately when a2 is null [source:raw]
    // CALL: OperatorNewNhMallocWrapper(108) allocates the 108-byte structure; a null result also returns 0 [callee:0x00587C03, source:raw]
    // CALL: ViewProjectionStructInit initializes the 108-byte structure with (v5, a2, a3, a4, this); a null result returns 0 [callee:0x004057F0, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates the node; on success it is initialized to [0]=v6, [4]=0, [8]=0, otherwise the node pointer is nulled [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If the head at this+0x8 (this[2]) is non-null, the old tail's next at this+0xC+4 is set to the new node; otherwise the node becomes both head this+0x8 and first-reference this+0x10 [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, source:raw]
    // ASSIGNMENT: The tail pointer this+0xC (this[3]) is advanced to the new node [field:this:0x0000000C, source:raw]
    // CALCULATION: The node count at this+0x14 (this[5]) is incremented [field:this:0x00000014, source:raw]
    // RETURN: Returns v6, the initialized 108-byte structure, regardless of whether the node allocation succeeded [source:raw]

    // Conservative worker pseudocode:
    //   if (!this[34]) return 0;
    //   if (!a2) return 0;
    //   v5 = OperatorNewNhMallocWrapper(108);
    //   if (!v5) return 0;
    //   v6 = ViewProjectionStructInit(v5, a2, a3, a4, this);
    //   if (!v6) return 0;
    //   v7 = OperatorNewNhMallocWrapper(12);
    //   if (v7) { *(void**)v7 = v6; *(void**)(v7+4) = 0; *(char*)(v7+8) = 0; } else v7 = 0;
    //   if (this[2]) { *(void**)(this[3]+4) = v7; } else { this[2] = v7; this[4] = v7; }
    //   this[3] = v7;
    //   ++this[5];
    //   return v6;
    // UNRESOLVED: The owner object of the linked list and the meaning of the enable flag at this+0x88 are not identified; the 0x88 gate also appears in sibling list-insert functions
    // UNRESOLVED: The 12-byte node layout beyond the payload pointer and byte flag at +8 is assumed minimal but not structurally verified
    // UNRESOLVED: Why the function returns the initialized structure when node allocation failed (leaving the list unupdated) is unresolved
}
