// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005550C0
// Canonical corpus name: VTableDispatchGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchGetter_005550c0.c

void UnknownObject::VTableDispatchGetter()
{
    // Reads the sub-object pointer stored at this+0x1100, calls a vtable method on it at byte offset 0x8C (passing the sub-object pointer as the single __stdcall argument), stores the returned integer into *this (this+0x0), and returns that stored value. Unconditional getter dispatch with no branches. Called by sub_553070, sub_553700 and sub_557120.
    // CALL: Load the dispatch-target pointer from this+0x1100 and invoke the vtable method at byte offset 0x8C of that sub-object, passing the sub-object pointer as the argument [field:this:0x00001100, field:*(this+0x1100):0x0000008C, source:raw]
    // ASSIGNMENT: Store the vtable method return value into *this (the integer field at this+0x0) [field:this:0x00000000, source:raw]
    // RETURN: Return the stored value from *this [function:0x005550C0, source:raw]

    // Conservative worker pseudocode:
    //   int VTableDispatchGetter(int *this) {
    //     int result = (*(int (__stdcall **)(int))(*(_DWORD *)this[1088] + 140))(this[1088]);
    //     *this = result;
    //     return result;
    //   }
    // UNRESOLVED: The identity and purpose of the sub-object at this+0x1100 and its vtable method at offset 0x8C are unknown; the owning object type is not identified
    // UNRESOLVED: The meaning of the value stored at *this (this+0x0) for the three callers is not established from this packet
}
