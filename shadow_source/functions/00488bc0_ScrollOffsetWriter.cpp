// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00488BC0
// Canonical corpus name: SimpleSetter_8bc0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleSetter_8bc0_00488bc0.c

void UnknownObject::ScrollOffsetWriter()
{
    // Trivial setter: stores argument a2 into the DWORD at offset 0xE0 of this (this[56]) and returns a2 unchanged. No guards, globals or callees. Called by ConstructorDualSubInit (0x0048D660) as a field writer.
    // ASSIGNMENT: Stores argument a2 into the DWORD at offset 0xE0 of this (this[56]) unconditionally. [field:this:0x000000E0, source:raw]
    // RETURN: Returns a2 unchanged. [function:0x00488BC0, source:raw]
    // CALL: Invoked by ConstructorDualSubInit (0x0048D660) to set the field at offset 0xE0. [caller:0x0048D660]

    // Conservative worker pseudocode:
    //   this[0xE0] = a2;
    //   return a2;
    // UNRESOLVED: The semantic role of offset 0xE0 (scroll delta per existing analysis) is DERIVED, not independently confirmed.
    // UNRESOLVED: The owning class is unidentified; only one caller (0x0048D660) is recorded in the packet.
}
