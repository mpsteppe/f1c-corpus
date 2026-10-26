// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466250
// Canonical corpus name: FlagSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagSetter_00466250.c

void UnknownObject::SetFlagByteF4()
{
    // Unconditional flag setter: calls FieldSetterCall on the sub-object pointer at this+0x40 with argument 3, then sets the flag byte at this+0xF4 to 1. Returns 0.
    // CALL: Call FieldSetterCall(*(_DWORD **)(this + 64), 3) to set field state on the sub-object at this+0x40 with parameter 3. [abi:lead, callee:0x004988A0, field:this:0x00000040]
    // ASSIGNMENT: Set the byte flag at this+0xF4 to 1 (active). [field:this:0x000000F4, function:0x00466250]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int SetFlagByteF4(int this) {
    //     FieldSetterCall(*(_DWORD **)(this + 64), 3);
    //     *(_BYTE *)(this + 244) = 1;
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of FieldSetterCall's parameter 3 and the target sub-object type at this+0x40 are not evidenced here.
    // UNRESOLVED: Purpose of the flag at this+0xF4 beyond 'active' is not evidenced.
}
