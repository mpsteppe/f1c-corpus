// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048A3B0
// Canonical corpus name: ByteSetterAt0xe0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteSetterAt0xe0_0048a3b0.c

void UnknownObject::ByteSetterAt0xe0()
{
    // __thiscall setter: stores byte a2 into this[224] (offset 0xE0) and returns the stored value. Structural twin of SimpleSetter_8bc0 (cluster representative 00488bc0) per cluster evidence.
    // ASSIGNMENT: Store a2 into this[224] (offset 0xE0). [source:raw, field:this:0x000000E0]
    // RETURN: Return the stored value a2. [source:raw]
    // CALL: Called by FunctionCallWrapper_85b0 (0x004685B0), PlayerStatsDisplayCleanup (0x00469D30), ConstructorWithVTableAndSubInit (0x0046A4E0), ShortComputation_b580 (0x0046B580), sub_475150 (0x00475150) and sub_47C6C0 (0x0047C6C0) to set the byte field on an unknown owner. [caller:0x004685B0, caller:0x00469D30, caller:0x0046A4E0, caller:0x0046B580, caller:0x00475150, caller:0x0047C6C0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_48A3B0(BYTE *this, char a2) {
    //     char result = a2;
    //     this[224] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Purpose of the byte field at this[224] (offset 0xE0) and the meaning of a2 are unknown; the owner object type is not established.
    // UNRESOLVED: The cluster relation to SimpleSetter_8bc0 (cluster representative 00488bc0) is structural only; shared-field semantics are not confirmed.
}
