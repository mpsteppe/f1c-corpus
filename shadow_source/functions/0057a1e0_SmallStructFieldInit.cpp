// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A1E0
// Canonical corpus name: SmallStructFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructFieldInit_0057a1e0.c

void UnknownObject::SmallStructFieldInit()
{
    // Constructor/initializer of a small structure: sets a DWORD at this+0x4 to 0, a byte at this+0x8 to 0, a byte at this+0x28 to 1 (the only non-zero write), and bytes at this+0x29, 0x2A, 0x2B, 0x2C to 0. Returns 0. No reads, no globals, no calls. Called from ConstructorVTableSetInit, sub_57BA10, and AudioStreamConstructWithVTableInit, consistent with a shared small sub-structure set up during construction.
    // ASSIGNMENT: Set DWORD at this+0x4 to 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set byte at this+0x8 to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set byte at this+0x28 to 1 (the only non-zero initialization). [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Set byte at this+0x29 to 0. [field:this:0x00000029, source:raw]
    // ASSIGNMENT: Set byte at this+0x2A to 0. [field:this:0x0000002A, source:raw]
    // ASSIGNMENT: Set byte at this+0x2B to 0. [field:this:0x0000002B, source:raw]
    // ASSIGNMENT: Set byte at this+0x2C to 0. [field:this:0x0000002C, source:raw]
    // RETURN: Return 0. [abi:lead, function:0x0057A1E0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_57A1E0(int this) {
    //     *(_DWORD *)(this + 4) = 0;
    //     *(_BYTE *)(this + 8) = 0;
    //     *(_BYTE *)(this + 40) = 1;
    //     *(_BYTE *)(this + 41) = 0;
    //     *(_BYTE *)(this + 42) = 0;
    //     *(_BYTE *)(this + 43) = 0;
    //     *(_BYTE *)(this + 44) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Object identity is unknown; caller names (ConstructorVTableSetInit, AudioStreamConstructWithVTableInit) hint at a construction-time helper but provide no class evidence.
    // UNRESOLVED: Semantics of the field at this+0x28 being set to 1 are unknown.
}
