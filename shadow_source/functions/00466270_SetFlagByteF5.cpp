// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466270
// Canonical corpus name: ShortComputation_6270
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_6270_00466270.c

void UnknownObject::SetFlagByteF5()
{
    // Unconditional flag setter: calls FieldSetterCall on the sub-object pointer at this+0x40 with argument 3, then sets the flag byte at this+0xF5 to 1. Returns 0.
    // CALL: Call FieldSetterCall(*(_DWORD **)(this + 64), 3) to set field state on the sub-object at this+0x40 with parameter 3. [abi:lead, callee:0x004988A0, field:this:0x00000040]
    // ASSIGNMENT: Set the byte flag at this+0xF5 to 1 (active). [field:this:0x000000F5, function:0x00466270]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int SetFlagByteF5(int this) {
    //     FieldSetterCall(*(_DWORD **)(this + 64), 3);
    //     *(_BYTE *)(this + 245) = 1;
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of FieldSetterCall's parameter 3 and the target sub-object type at this+0x40 are not evidenced here.
    // UNRESOLVED: Purpose of the flag at this+0xF5 beyond 'active' is not evidenced.
}
