// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A473
// Canonical corpus name: ObjectInitWithBufferDataPointerAssignment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithBufferDataPointerAssignment_0059a473.c

void UnknownObject::ObjectInitWithBufferDataPointerAssignment()
{
    // Initializes a buffer/stream object. Stores a flag byte at offset 0x48 computed as (a3 == 1). When a3 is zero, runs a locale-facet initialization branch: null-checks the facet pointer at 0x4C, conditionally acquires its locale refcount when the sentinel guard (this != -76) holds, and clears the pointer field at 0x44. Then calls SelfReferentialPointerRingInit, stores the external data pointer a2 at 0x50, and sets the capacity boundaries at 0x3C/0x40 and the start position at 0x38 from the global dword_8D5A60.
    // ASSIGNMENT: Set flag byte at this+0x48 to (a3 == 1); distinguishes final from incremental initialization. [field:this:0x00000048]
    // GUARD: Guard on a3 == 0: when a3 is zero, run the locale-facet init branch; otherwise skip it. [source:raw]
    // CALL: NullCheckWithVirtualDispatch on the locale facet pointer stored at this+0x4C. [callee:0x00598C70, source:raw]
    // GUARD: Sentinel guard (this != -76) before acquiring the facet refcount, so the acquire only runs for a valid receiver. [callee:0x00598C1C, source:raw]
    // CALL: LocaleRefcountAcquireUnderLock on the facet at this+0x4C, retaining the locale. [callee:0x00598C1C, source:raw]
    // ASSIGNMENT: Clear the pointer field at this+0x44 to 0 (only inside the a3 == 0 branch). [field:this:0x00000044]
    // CALL: SelfReferentialPointerRingInit(this): set up the object's self-referential pointer ring. [callee:0x0059A4C9]
    // ASSIGNMENT: Store the external buffer data pointer a2 at this+0x50. [field:this:0x00000050]
    // ASSIGNMENT: Set capacity field at this+0x40 to the global capacity value dword_8D5A60. [field:this:0x00000040, global:0x008D5A60]
    // ASSIGNMENT: Initialize buffer start position at this+0x38 to 0. [field:this:0x00000038]
    // ASSIGNMENT: Initialize buffer end position at this+0x3C to the global capacity value dword_8D5A60. [field:this:0x0000003C, global:0x008D5A60]
    // RETURN: Return the global capacity value dword_8D5A60. [global:0x008D5A60]

    // Conservative worker pseudocode:
    //   int sub_59A473(char* this, int data_ptr, int mode) {
    //     this[0x48] = (mode == 1);
    //     if (mode == 0) {
    //       NullCheckWithVirtualDispatch(this + 0x4C);
    //       if (this != -76) LocaleRefcountAcquireUnderLock(this + 0x4C);
    //       *(int*)(this + 0x44) = 0;
    //     }
    //     SelfReferentialPointerRingInit(this);
    //     *(int*)(this + 0x50) = data_ptr;
    //     *(int*)(this + 0x40) = dword_8D5A60;
    //     *(int*)(this + 0x38) = 0;
    //     *(int*)(this + 0x3C) = dword_8D5A60;
    //     return dword_8D5A60;
    //   }
    // UNRESOLVED: The locale facet pointer at this+0x4C appears only in the raw source, not in the packet fields list; its type and ownership are unknown.
    // UNRESOLVED: Meaning of the (a3 == 1) flag beyond distinguishing init modes is unclear.
    // UNRESOLVED: dword_8D5A60 is treated as a capacity/limit constant per prior analysis but its identity is DERIVED only.
    // UNRESOLVED: Callers LocaleObjectConstructorWithVTableSetup (00599cb7) and ConditionalCallbackWithNullCheck (0059a44c) call this initializer with different object types; the concrete class is unknown.
}
