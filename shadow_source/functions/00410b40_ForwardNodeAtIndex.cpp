// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00410B40
// Canonical corpus name: FunctionCallWrapper_0b40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionCallWrapper_0b40_00410b40.c

void UnknownObject::ForwardNodeAtIndex()
{
    // Computes an element pointer from the array at this+0x10 using a 36-byte stride and an index read from a2+4, then calls sub_410AF0(this, element) and returns its result. Called by sub_4C6E80.
    // CALCULATION: Read the index as the dword at a2+4. [source:raw]
    // CALCULATION: Compute the element pointer as *(this+0x10) + 36 * index (36-byte element stride). [field:this:0x00000010, source:raw]
    // CALL: Call sub_410AF0(this, element) with the computed element pointer. [field:this:0x00000010, source:raw]
    // RETURN: Return the integer result of sub_410AF0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_410B40(int *this, int a2) {
    //       int *element = (int *)(this[4] + 36 * *(_DWORD *)(a2 + 4));
    //       return sub_410AF0(this, element);
    //   }
    // UNRESOLVED: sub_410AF0 is not in the packet callee list; its address and contract are unknown.
    // UNRESOLVED: Element type and meaning of the 36-byte stride (array at this+0x10) depend on the caller's layout.
    // UNRESOLVED: Semantics of the index field a2+4 (index into which array) are unknown.
    // UNRESOLVED: Packet prelabel describes this as a getter returning field 0x10, but the raw source returns the result of the forward call; raw source is authoritative.
}
