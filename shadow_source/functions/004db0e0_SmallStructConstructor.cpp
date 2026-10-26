// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB0E0
// Canonical corpus name: SmallStructConstructor_b0e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructConstructor_b0e0_004db0e0.c

void UnknownObject::SmallStructConstructor()
{
    // Small __thiscall constructor for a 4-field object. Writes type code 1 at +0x4 and flag 1 at +0x8, zero-initializes +0xC, then installs the vtable off_5AD034 at +0x0. Returns the original this pointer. Called by Direct3DObjectFactory (0x004DAEA0); no branches, no calls.
    // ASSIGNMENT: Save the incoming this pointer as the result value. [source:raw]
    // ASSIGNMENT: Initialize the field at +0x4 with literal 1 (type/identifier code). [field:this:0x00000004]
    // ASSIGNMENT: Initialize the byte field at +0x8 with literal 1 (active/visible flag). [field:this:0x00000008]
    // ASSIGNMENT: Zero-initialize the field at +0xC (reserved slot). [field:this:0x0000000C]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5AD034. [field:this:0x00000000, global:0x005AD034]
    // RETURN: Return the saved this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *SmallStructConstructor(_DWORD *this) {
    //     _DWORD *result = this;
    //     this[1] = 1;
    //     *((_BYTE *)this + 8) = 1;
    //     this[3] = 0;
    //     *this = &off_5AD034;
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object type whose vtable is off_5AD034 is unknown.
    // UNRESOLVED: Meaning of the constant fields (code 1 at +0x4, flag 1 at +0x8) is not established by packet evidence.
}
