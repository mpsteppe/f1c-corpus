// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479E30
// Canonical corpus name: ConstructorVTableFUN004668e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorVTableFUN004668e0_00479e30.c

void UnknownObject::ConstructorVTableFUN004668e0()
{
    // Unconditional thiscall constructor. Calls InitVTableSet with two literal arguments (0, 1065353216, the bit pattern of 1.0f forming a 0.0..1.0 float range), installs the vtable off_5A5E40 at +0x0, zeroes the byte field at +0x100, and returns this. No guards; straight-line initialization.
    // CALL: Invoke InitVTableSet((_DWORD*)this, 0, 1065353216) to initialize the object's range fields from the two literal arguments. [abi:lead, callee:0x004668E0, source:raw]
    // ASSIGNMENT: Install the type vtable by writing the address of off_5A5E40 into the vtable pointer at this+0x0. [field:this:0x00000000, global:0x005A5E40, source:raw]
    // ASSIGNMENT: Zero the state/flag byte at this+0x100. [field:this:0x00000100, source:raw]
    // RETURN: Return the this pointer as the constructor result. [source:raw]

    // Conservative worker pseudocode:
    //   int ConstructorVTableFUN004668e0(this) {
    //     InitVTableSet((_DWORD*)this, 0, 1065353216);
    //     *(_DWORD*)this = &off_5A5E40;
    //     *(_BYTE*)(this + 0x100) = 0;
    //     return this;
    //   }
    // UNRESOLVED: Concrete object type/owner identity unknown; vtable off_5A5E40 is not mapped to a class.
    // UNRESOLVED: Semantics of the two init arguments (a 0.0..1.0 float range) depend on InitVTableSet at 0x004668E0.
    // UNRESOLVED: Purpose of the zeroed byte at +0x100 is not evident from this constructor alone.
}
