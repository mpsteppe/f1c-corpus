// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456280
// Canonical corpus name: TripleFieldSetter_6280
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldSetter_6280_00456280.c

void UnknownObject::setTripleFields()
{
    // Unconditional three-DWORD setter: writes three caller-supplied values into consecutive fields at this+0x0, this+0x4 and this+0x8, then returns the third value. Called by F_3DSoundEmitter (0x00456170).
    // ASSIGNMENT: Store a2 into field this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store a3 into field this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Store a4 into field this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return a4 (the value written to this+0x8). [function:0x00456280]

    // Conservative worker pseudocode:
    //   this[0] = a2;
    //   this[1] = a3;
    //   this[2] = a4;
    //   return a4;
    // UNRESOLVED: Object type owning offsets 0x0/0x4/0x8 is unknown; the semantic role of the three stored values cannot be determined from this function alone.
}
