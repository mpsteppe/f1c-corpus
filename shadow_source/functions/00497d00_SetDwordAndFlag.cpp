// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00497D00
// Canonical corpus name: TwoFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetter_00497d00.c

void UnknownObject::SetDwordAndFlag()
{
    // Two-field thiscall setter: stores parameter a2 into the DWORD field at this+0x18A8, sets the byte field at this+0x18EC to 1 (activation/dirty flag), and returns a2. Unconditional, no guards. Called by sub_49A5D0.
    // ASSIGNMENT: Store a2 to the DWORD field at this+0x18A8. [field:this:0x000018A8, source:raw]
    // ASSIGNMENT: Set the byte field at this+0x18EC to the literal 1. [field:this:0x000018EC, source:raw]
    // RETURN: Return a2 (the stored value); invoked by sub_49A5D0. [caller:0x0049A5D0, function:0x00497D00, source:raw]

    // Conservative worker pseudocode:
    //   int sub_497D00(int this, int a2) {
    //     *(int *)(this + 0x18A8) = a2;
    //     *(char *)(this + 0x18EC) = 1;
    //     return a2;
    //   }
    // UNRESOLVED: Meaning of the two written fields (data field at 0x18A8 and flag at 0x18EC) is not established by this packet; the flag is set to 1 unconditionally.
}
