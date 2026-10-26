// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005662CA
// Canonical corpus name: sub_5662CA
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5662CA_005662ca.c

void UnknownObject::getVtableEntryAt0xC()
{
    // Vtable entry getter: reads the vtable pointer stored at this+0x0, then returns the dword stored at vtable offset +0xC (the fourth vtable slot, a virtual function pointer). No calls, guards, globals, or side effects; the thunk only resolves and returns the vtable entry.
    // ASSIGNMENT: Read the vtable pointer from this+0x0. [field:this:0x00000000, source:raw]
    // CALCULATION: Read the dword at vtable offset +0xC (fourth vtable slot) from the object reached through this+0x0. [field:obj:0x0000000C, field:this:0x00000000, source:raw]
    // RETURN: Return the dword read from vtable offset +0xC as the function result. [source:raw, function:0x005662CA]

    // Conservative worker pseudocode:
    //   int getVtableEntryAt0xC(void* this) {
    //     return *(DWORD*)(*(DWORD*)this + 12);
    //   }
    // UNRESOLVED: Whether the returned value is a virtual function pointer to be invoked elsewhere or a data value stored in the vtable region is not evidenced.
    // UNRESOLVED: The owner class and the identity of the virtual method at vtable slot +0xC are unknown.
}
