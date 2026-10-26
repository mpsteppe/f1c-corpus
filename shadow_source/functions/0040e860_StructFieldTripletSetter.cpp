// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E860
// Canonical corpus name: ShortComputation_e860
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_e860_0040e860.c

void UnknownObject::StructFieldTripletSetter()
{
    // Straight-line field setter: stores a2 into the WORD at this+8, writes the constant 6 into the DWORD at this+0x1C, writes a3 into the DWORD at this+0x20, and returns a2 sign-extended to int.
    // ASSIGNMENT: Store a2 (truncated to the low 16 bits) into the WORD field at this+8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the constant 6 into the DWORD field at this+0x1C (mode/selector value). [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Write a3 into the DWORD field at this+0x20 (pointer or identifier). [field:this:0x00000020, source:raw]
    // RETURN: Return a2 sign-extended (result low word holds a2, high word its sign extension). [function:0x0040E860, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40E860(int this, short a2, int a3) {
    //     *(_WORD *)(this + 8) = a2;
    //     *(_DWORD *)(this + 0x1C) = 6;
    //     *(_DWORD *)(this + 0x20) = a3;
    //     return (int)a2;
    //   }
    // UNRESOLVED: The meaning of the constant 6 and the roles of a2/a3 depend on the caller sub_40FE50, which is not analyzed in this packet.
}
