// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D490
// Canonical corpus name: StructFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldInit_0040d490.c

void UnknownObject::StructFieldInit()
{
    // Constructor/initializer that writes eleven literal fields into the object at offsets 0x4 through 0x2C and returns 0. All fields are zeroed except the dword at this+0x28 which is set to 1. No reads, no globals, no callees. The byte at this+0x20 is written as a single zero byte while the rest are dword writes. Called by SimpleSetterWithSubCall, RaceCommentaryDirectorSystem, CameraDirectorResetInit, and StateMachineInitializer, consistent with a shared initialization helper.
    // ASSIGNMENT: Set the local result to 0; this is also the value returned at the end. [source:raw]
    // ASSIGNMENT: Zero the dword at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the dword at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x10. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x1C. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Zero the byte at this+0x20. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x24. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Set the dword at this+0x28 to the literal 1. [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Zero the dword at this+0x2C. [field:this:0x0000002C, source:raw]
    // RETURN: Return the result value 0. [function:0x0040D490, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40D490(int this) {
    //     *(int*)(this + 4) = 0; *(int*)(this + 8) = 0; *(int*)(this + 12) = 0;
    //     *(int*)(this + 16) = 0; *(int*)(this + 20) = 0; *(int*)(this + 24) = 0; *(int*)(this + 28) = 0;
    //     *(char*)(this + 32) = 0; *(int*)(this + 36) = 0;
    //     *(int*)(this + 40) = 1; *(int*)(this + 44) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Owner object identity is unknown; four callers (SimpleSetterWithSubCall, RaceCommentaryDirectorSystem, CameraDirectorResetInit, StateMachineInitializer) reuse it as an init helper but the target type is not established.
    // UNRESOLVED: The field meanings (including why only this+0x28 is set to 1) depend on the owner class layout.
    // UNRESOLVED: Whether the byte write at this+0x20 overlaps an adjacent dword-sized field is unresolved from this function alone.
}
