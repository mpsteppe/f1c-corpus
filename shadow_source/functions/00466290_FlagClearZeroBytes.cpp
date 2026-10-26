// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466290
// Canonical corpus name: FlagClearZeroBytes
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FlagClearZeroBytes_00466290.c

void UnknownObject::FlagClearZeroBytes()
{
    // Clears two flag bytes, this+0xF4 and this+0xF5, to 0 and forwards the sub-object pointer stored at this+0x40 to FieldSetterCall with parameter 2. Returns 0. No guards; all operations are unconditional.
    // CALL: Forward the pointer at this+0x40 to FieldSetterCall with parameter 2, setting the sub-object field state. [callee:0x004988A0, field:this:0x00000040, source:raw]
    // ASSIGNMENT: Clear the flag byte at this+0xF4 to 0. [field:this:0x000000F4, source:raw]
    // ASSIGNMENT: Clear the flag byte at this+0xF5 to 0. [field:this:0x000000F5, source:raw]
    // RETURN: Return 0. [function:0x00466290, source:raw]

    // Conservative worker pseudocode:
    //   int FlagClearZeroBytes(int this) {
    //     FieldSetterCall(*(_DWORD**)(this + 0x40), 2);
    //     *(_BYTE*)(this + 0xF4) = 0;
    //     *(_BYTE*)(this + 0xF5) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The meaning of FieldSetterCall parameter 2 for the sub-object at this+0x40 is DERIVED in existing analysis (clear action) but not deterministically established by this function alone.
    // UNRESOLVED: Whether this+0xF4 and this+0xF5 are independent flags or adjacent members of a larger field block is unresolved.
}
