// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478350
// Canonical corpus name: sub_478350
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_478350_00478350.c

void UnknownObject::ResourceStateChangeMonitor()
{
    // Monitors a resource's state: reads the resource handle at this+0xE0, dereferences a state value at the resource object +0x2C, and compares it against the cached value at this+0xE4. When the state differs, updates the cache, calls ProfileIconPathSetter(this), and notifies through the vtable at this+0 (method at offset +44) with argument 1. Returns 0 in all paths.
    // GUARD: Guard on the resource handle at this + 0xE0 (this[56]): if null, skip all state monitoring and return 0. [field:this:0x000000E0, source:raw]
    // CALCULATION: Read the fresh resource state value from the resource object at obj + 0x2C. [field:obj:0x0000002C, source:raw]
    // GUARD: Compare the cached value at this + 0xE4 (this[57]) against the fresh state; when equal, skip the update and notification. [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Update the cached state this + 0xE4 (this[57]) to the fresh resource state. [field:this:0x000000E4, source:raw]
    // CALL: Call ProfileIconPathSetter(this) after the cache is updated. [callee:0x00478390]
    // CALL: Notify through the vtable at this + 0: call the __thiscall method at vtable offset +44 with argument 1. [field:this:0x00000000, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_478350(_DWORD *this) {
    //     void *res = this[56];
    //     if (res) {
    //       int state = *(int*)((char*)res + 0x2C);
    //       if (this[57] != state) {
    //         this[57] = state;
    //         ProfileIconPathSetter(this);
    //         ((void (__thiscall *)(void*, int))*(int*)*(int*)this + 44)(this, 1);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Evidence lists a read of this + 0x254, but no visible operation in the raw source consumes it; its role is unknown.
    // UNRESOLVED: Semantics of the state value at obj + 0x2C and of the notify argument (1) are unknown.
    // UNRESOLVED: Identity of the vtable method at offset +44 is unknown.
}
