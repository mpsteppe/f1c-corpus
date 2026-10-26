// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D090
// Canonical corpus name: VirtualDispatchConditionalAudio
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VirtualDispatchConditionalAudio_0040d090.c

void UnknownObject::VirtualDispatchConditionalAudio()
{
    // Conditionally dispatches a virtual method on a stored object and resets two state words on a global object. If this[2] is non-null, invokes the virtual at vtable+16 on it. If dword_8AFE88 is non-null, zeros the dwords at offsets 424 and 420 of that object.
    // ASSIGNMENT: Read the stored object pointer v1 from this[2]. [field:this:0x00000008, source:raw]
    // GUARD: If this[2] is non-null, dispatch the virtual method at vtable offset 16 on the object. [field:this:0x00000008, source:raw]
    // CALL: Call (*(this[2]->vtable + 16))(this[2]) as a __thiscall virtual dispatch. [field:*(this+0x8):0x00000010, field:this:0x00000008, source:raw]
    // GUARD: If dword_8AFE88 is non-null, clear two state words on the referenced global object. [global:0x008AFE88, source:raw]
    // ASSIGNMENT: Write 0 to the dword at dword_8AFE88 + 424. [global:0x008AFE88, source:raw]
    // ASSIGNMENT: Write 0 to the dword at dword_8AFE88 + 420. [global:0x008AFE88, source:raw]
    // RETURN: Return the last computed result (0 when the global branch ran, otherwise the virtual call result). [source:raw]

    // Conservative worker pseudocode:
    //   int VirtualDispatchConditionalAudio(void *this) {
    //     int result;
    //     void *obj = ((int*)this)[2];
    //     if (obj)
    //       result = (*(int (__thiscall **)(int))(*(int*)obj + 16))(obj);
    //     if (dword_8AFE88) {
    //       result = 0;
    //       *(DWORD*)(dword_8AFE88 + 424) = 0;
    //       *(DWORD*)(dword_8AFE88 + 420) = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object at this[2], its class, and the virtual at vtable+16.
    // UNRESOLVED: Identity of the global object dword_8AFE88 and the meaning of the reset words at +420 and +424.
    // UNRESOLVED: Relation between the virtual dispatch result and the 0 return value of the global branch.
}
