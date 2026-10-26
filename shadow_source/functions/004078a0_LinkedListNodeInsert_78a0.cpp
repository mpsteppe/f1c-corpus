// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004078A0
// Canonical corpus name: LinkedListNodeInsert_78a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsert_78a0_004078a0.c

void UnknownObject::LinkedListNodeInsert_78a0()
{
    // Allocates a 96-byte mutex/synchronization object, initializes it with MutexSynchronizationObjectInit, then allocates a 12-byte linked-list node holding it and inserts the node at the tail of the list rooted at this. The insertion is gated on the enable flag at this+0x88. When the list is empty (head this+0x18 is null) the node becomes both head this+0x18 and first-reference this+0x20; otherwise it links after the current tail this+0x1C. The tail is advanced to the new node and the count at this+0x24 is incremented. The initialized 96-byte object is returned even when the 12-byte node allocation fails.
    // GUARD: Returns 0 immediately when the enable flag at this+0x88 (this[34]) is zero [field:this:0x00000088, source:raw]
    // CALL: OperatorNewNhMallocWrapper(96) allocates the 96-byte object; a null result returns 0 [callee:0x00587C03, source:raw]
    // CALL: MutexSynchronizationObjectInit initializes the 96-byte object with (v2, this); a null result returns 0 [callee:0x00406130, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates the node; on success it is initialized to [0]=v3, [4]=0, [8]=0, otherwise the node pointer is nulled [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If the head at this+0x18 (this[6]) is non-null, the old tail's next at this+0x1C+4 is set to the new node; otherwise the node becomes both head this+0x18 and first-reference this+0x20 [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // ASSIGNMENT: The tail pointer this+0x1C (this[7]) is advanced to the new node [field:this:0x0000001C, source:raw]
    // CALCULATION: The node count at this+0x24 (this[9]) is incremented [field:this:0x00000024, source:raw]
    // RETURN: Returns v3, the initialized 96-byte object, regardless of whether the node allocation succeeded [source:raw]

    // Conservative worker pseudocode:
    //   if (!this[34]) return 0;
    //   v2 = OperatorNewNhMallocWrapper(96);
    //   if (!v2) return 0;
    //   v3 = MutexSynchronizationObjectInit(v2, this);
    //   if (!v3) return 0;
    //   v4 = OperatorNewNhMallocWrapper(12);
    //   if (v4) { *(void**)v4 = v3; *(void**)(v4+4) = 0; *(char*)(v4+8) = 0; } else v4 = 0;
    //   if (this[6]) { *(void**)(this[7]+4) = v4; } else { this[6] = v4; this[8] = v4; }
    //   this[7] = v4;
    //   ++this[9];
    //   return v3;
    // UNRESOLVED: The owner object of the linked list and the meaning of the enable flag at this+0x88 are not identified; the same gate pattern appears in a sibling list-insert function
    // UNRESOLVED: The list fields of this function sit at different offsets than the structurally identical sibling list-insert function; this is noted, not used to infer class identity
    // UNRESOLVED: The 12-byte node layout beyond the payload pointer and byte flag at +8 is assumed minimal but not structurally verified
}
