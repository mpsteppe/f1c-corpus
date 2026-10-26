// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB070
// Canonical corpus name: ConstructorVTable3Fields
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorVTable3Fields_004db070.c

void UnknownObject::ThreeFieldStructConstructor()
{
    // Small __thiscall constructor for a 4-field object. Installs the vtable off_5AD06C at +0x0, stores the caller-supplied integer a2 at +0x4 and the byte a3 at +0x8, and zero-initializes +0xC. Returns the original this pointer. Called by Direct3DObjectFactory (0x004DAEA0) during object construction; no branches, no calls.
    // ASSIGNMENT: Save the incoming this pointer as the result value. [source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5AD06C. [field:this:0x00000000, global:0x005AD06C]
    // ASSIGNMENT: Store caller parameter a2 into the field at +0x4. [field:this:0x00000004]
    // ASSIGNMENT: Store caller byte parameter a3 into the field at +0x8. [field:this:0x00000008]
    // ASSIGNMENT: Zero-initialize the field at +0xC (reserved/null slot). [field:this:0x0000000C]
    // RETURN: Return the saved this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *ThreeFieldStructConstructor(_DWORD *this, int a2, char a3) {
    //     _DWORD *result = this;
    //     *this = &off_5AD06C;
    //     this[1] = a2;
    //     *((_BYTE *)this + 8) = a3;
    //     this[3] = 0;
    //     return result;
    //   }
    // UNRESOLVED: Identity of the object type whose vtable is off_5AD06C is unknown.
    // UNRESOLVED: Semantics of the stored parameters a2 (identifier/code) and a3 (flag byte) depend on the caller in Direct3DObjectFactory.
}
