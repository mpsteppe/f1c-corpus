// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410B20
// Canonical corpus name: ShortComputation_0b20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_0b20_00410b20.c

void UnknownObject::InsertListNodeAtIndex()
{
    // Computes an element pointer from the array at this+0x10 using a 36-byte stride and an index read from a2+4, then calls LinkedListNodeInsert_0ad0(this, element) and returns the inserted node pointer. Called by VehgenScnFileLoader.
    // CALCULATION: Read the index as the dword at a2+4. [source:raw]
    // CALCULATION: Compute the element pointer as *(this+0x10) + 36 * index (36-byte element stride). [field:this:0x00000010, source:raw]
    // CALL: Call LinkedListNodeInsert_0ad0(this, element) to insert the computed element into the list. [field:this:0x00000010, source:raw]
    // RETURN: Return the pointer returned by LinkedListNodeInsert_0ad0 (the inserted node). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_410B20(_DWORD *this, int a2) {
    //       _DWORD *element = (_DWORD *)(this[4] + 36 * *(_DWORD *)(a2 + 4));
    //       return LinkedListNodeInsert_0ad0(this, element);
    //   }
    // UNRESOLVED: LinkedListNodeInsert_0ad0 is not in the packet callee list; its address and contract are unknown.
    // UNRESOLVED: Element type and meaning of the 36-byte stride (array at this+0x10) depend on the caller's layout.
    // UNRESOLVED: Semantics of the index field a2+4 (index into which array) are unknown.
    // UNRESOLVED: Packet prelabel describes this as a getter returning field 0x10, but the raw source returns the result of the insert call; raw source is authoritative.
}
