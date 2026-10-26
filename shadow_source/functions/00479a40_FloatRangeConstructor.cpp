// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479A40
// Canonical corpus name: FloatRangeConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatRangeConstructor_00479a40.c

void UnknownObject::FloatRangeConstructor()
{
    // Unconditional thiscall constructor. Calls VtableSetWithInitCall with two raw literal arguments (-1082130432, 1065353216, the bit patterns of a -1.0..1.0 float range), installs the vtable off_5A5938 at +0x0, zeroes the dword field at +0x100, and returns this. No guards; straight-line initialization.
    // CALL: Invoke VtableSetWithInitCall(this, -1082130432, 1065353216) to initialize the object's range fields from the two literal arguments. [abi:lead, callee:0x00466980, source:raw]
    // ASSIGNMENT: Install the type vtable by writing the address of off_5A5938 into the vtable pointer at this+0x0. [field:this:0x00000000, global:0x005A5938, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x100 (this[64]). [field:this:0x00000100, source:raw]
    // RETURN: Return the this pointer as the constructor result. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* FloatRangeConstructor(_DWORD* this) {
    //     VtableSetWithInitCall(this, -1082130432, 1065353216);
    //     *this = &off_5A5938;
    //     this[64] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Concrete object type/owner identity unknown; vtable off_5A5938 is not mapped to a class.
    // UNRESOLVED: Semantics of the two init arguments (a -1.0..1.0 float range) depend on VtableSetWithInitCall at 0x00466980.
    // UNRESOLVED: Purpose of the zeroed dword at +0x100 is not evident from this constructor alone.
}
