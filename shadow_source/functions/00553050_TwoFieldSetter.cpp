// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553050
// Canonical corpus name: TwoFieldSetter_3050
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetter_3050_00553050.c

void UnknownObject::TwoFieldSetter()
{
    // Unconditional two-field setter: writes argument a2 into this[23] (offset 0x5C) and argument a3 into this[24] (offset 0x60), then returns a2. No guards, no reads. Matches the existing analysis TwoFieldSetter_3050.
    // ASSIGNMENT: Write a2 into this[23] at offset 0x5C. [field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Write a3 into this[24] at offset 0x60. [field:this:0x00000060, source:raw]
    // RETURN: Return a2 unchanged. [function:0x00553050, source:raw]
    // CALL: Called by sub_4988D0 (0x004988D0) and GuardedDelegation (0x0053D2B0) to set the pair of fields. [caller:0x004988D0, caller:0x0053D2B0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_553050(_DWORD* this, int a2, int a3) {
    //     this[23] = a2;
    //     this[24] = a3;
    //     return a2;
    //   }
    // UNRESOLVED: Semantic meaning of the two DWORD arguments (scale factors, positions or counts passed by value) depends on the calling contexts in sub_4988D0 and GuardedDelegation.
    // UNRESOLVED: Owner class of this is unknown; the fields are written but never read inside this function.
}
