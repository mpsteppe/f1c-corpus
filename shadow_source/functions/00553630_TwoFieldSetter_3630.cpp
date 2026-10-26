// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553630
// Canonical corpus name: TwoFieldSetter_3630
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoFieldSetter_3630_00553630.c

void UnknownObject::TwoFieldSetter_3630()
{
    // Simple unconditional two-field setter. Writes a2 to this[2] (this+0x8) and a3 to this[3] (this+0xC). Returns a2. No guards. Consistent with existing analysis labeling it a position/offset pair setter.
    // ASSIGNMENT: this[2] (this+0x8) = a2; unconditional write of the first parameter. [field:this:0x00000008, source:raw, function:0x00553630]
    // ASSIGNMENT: this[3] (this+0xC) = a3; unconditional write of the second parameter. [field:this:0x0000000C, source:raw, function:0x00553630]
    // RETURN: Return a2 (the first parameter), retained as the function result. [source:raw, function:0x00553630]

    // Conservative worker pseudocode:
    //   this[2] = a2;
    //   this[3] = a3;
    //   return a2;
    // UNRESOLVED: The semantic role of the two written fields (this+0x8, this+0xC) is unknown; existing analysis tentatively calls them position/offset values but this is not independently confirmed.
}
