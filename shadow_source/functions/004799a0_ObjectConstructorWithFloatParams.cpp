// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004799A0
// Canonical corpus name: ObjectConstructorWithFloatParams
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithFloatParams_004799a0.c

void UnknownObject::ObjectConstructorWithFloatParams()
{
    // Unconditional thiscall constructor. Calls VtableSetWithInitCall with two raw literal arguments (1163575296, 1177792512, the bit patterns of a large float range), installs the vtable off_5A5710 at +0x0, sets the enable/active flag byte at +0xF0 to 1, and returns this. No guards; straight-line initialization.
    // CALL: Invoke VtableSetWithInitCall(this, 1163575296, 1177792512) to initialize the object's range fields from the two literal arguments. [abi:lead, callee:0x00466980, source:raw]
    // ASSIGNMENT: Install the type vtable by writing the address of off_5A5710 into the vtable pointer at this+0x0. [field:this:0x00000000, global:0x005A5710, source:raw]
    // ASSIGNMENT: Set the flag/enable byte at this+0xF0 to 1 (active). [field:this:0x000000F0, source:raw]
    // RETURN: Return the this pointer as the constructor result. [source:raw]

    // Conservative worker pseudocode:
    //   int ObjectConstructorWithFloatParams(this) {
    //     VtableSetWithInitCall((_DWORD*)this, 1163575296, 1177792512);
    //     *(_DWORD*)this = &off_5A5710;
    //     *(_BYTE*)(this + 0xF0) = 1;
    //     return this;
    //   }
    // UNRESOLVED: Concrete object type/owner identity unknown; vtable off_5A5710 is not mapped to a class.
    // UNRESOLVED: Semantics of the two init arguments (a large float range) depend on VtableSetWithInitCall at 0x00466980.
    // UNRESOLVED: Purpose of the flag byte at +0xF0 is not evident from this constructor alone.
}
