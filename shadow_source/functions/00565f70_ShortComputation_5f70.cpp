// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565F70
// Canonical corpus name: ShortComputation_5f70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5f70_00565f70.c

void UnknownObject::ShortComputation_5f70()
{
    // Double-indirect field getter: dereferences the this pointer to obtain an object pointer, then reads and returns the DWORD stored at that object's offset 0xC. No branching or side effects. Called by the vehicle, scene and tire-brand loaders as a vtable-style accessor.
    // CALCULATION: Dereference this (DWORD at offset 0) to obtain the object pointer that owns the accessed field. [field:this:0x00000000, source:raw]
    // CALCULATION: Read the DWORD stored at the object pointer plus offset 0xC. [field:obj:0x0000000C, source:raw]
    // RETURN: Return the DWORD read at obj + 0xC. [source:raw, function:0x00565F70]

    // Conservative worker pseudocode:
    //   int sub_565F70(void* this) {
    //     void* obj = *(void**)this;
    //     return *(int*)((char*)obj + 0xC);
    //   }
    // UNRESOLVED: The object type behind this (the value read at this + 0) is unknown; callers are vehicle/scene/tire-brand loaders.
    // UNRESOLVED: Meaning of the DWORD at obj + 0xC (likely a pointer or vtable-adjacent field) is not established.
}
