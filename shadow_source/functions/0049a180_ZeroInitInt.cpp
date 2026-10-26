// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A180
// Canonical corpus name: ZeroInitInt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInitInt_0049a180.c

void UnknownObject::ZeroInitInt()
{
    // Zeroes the first dword of a structure (this[0], byte offset 0x0) and returns this. Structural twin of sub_464D20 (00464d20) per cluster analysis; used as a per-field zero-init helper by ShortComputation_53e0 and LargeStructZeroInit.
    // ASSIGNMENT: Set the dword at byte offset 0x0 (this[0]) to the literal 0. [field:this:0x00000000, source:raw]
    // RETURN: Return the this pointer. [function:0x0049A180, source:raw]

    // Conservative worker pseudocode:
    //   this->field_0x0 = 0;
    //   return this;
    // UNRESOLVED: Owner struct and the meaning of the zeroed field are not evidenced by the packet.
    // UNRESOLVED: Prelabel marks it a structural twin of 00464d20 (DERIVED), not independently confirmed.
}
