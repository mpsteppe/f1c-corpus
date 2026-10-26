// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B038
// Canonical corpus name: ObjectInitWithVTable_b038
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInitWithVTable_b038_0059b038.c

void UnknownObject::ConstructStdOutOfRange()
{
    // std::out_of_range exception vtable constructor. Constructs the logic_error base via CObjectConstructorWithVtable(a2, a3), then overwrites the object's vtable pointer (this+0x0) with the std::out_of_range vtable (0x005B9D8C) and returns the object pointer.
    // CALL: Call CObjectConstructorWithVtable(a2, a3) to construct the logic_error base exception (string copy and flag transfer). [callee:0x0059AE7D, source:raw]
    // ASSIGNMENT: Overwrite this+0x0 with the std::out_of_range vtable pointer at 0x005B9D8C. [field:this:0x00000000, global:0x005B9D8C, source:raw]
    // RETURN: Return the constructed object pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *ConstructStdOutOfRange(_DWORD *this, int a2, int a3) {
    //       CObjectConstructorWithVtable(a2, a3);
    //       *this = &std::out_of_range::vftable;
    //       return this;
    //   }
    // UNRESOLVED: Parameters a2/a3 (one passed via EBP) are forwarded to CObjectConstructorWithVtable; their semantics are not visible at this call site.
}
