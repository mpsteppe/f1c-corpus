// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BF630
// Canonical corpus name: ZeroInit4Ints
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInit4Ints_004bf630.c

void UnknownObject::ZeroInit4Ints()
{
    // Zero-initializes four consecutive dwords of a __thiscall object starting at this+0 (offsets 0x0, 0x4, 0x8, 0xC). Returns the unchanged this pointer. Pure field writer with no guards, globals, or callees.
    // ASSIGNMENT: Write 0 to this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0 to this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write 0 to this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write 0 to this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return the this pointer (result = this). [source:raw]
    // CALL: Used by AIDriverCountSetup (0x004BFD90), GameFilterDataLoader (0x004C0DB0) and StructInitWithZeroFillSubCall (0x0056D3E0) to zero a four-dword block at object setup time. [caller:0x004BFD90, caller:0x004C0DB0, caller:0x0056D3E0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4BF630(_DWORD *this) {
    //     this[0] = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[3] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Which object owns the four zeroed dwords is unknown; callers span AI driver setup, filter-data loading and struct-init paths.
    // UNRESOLVED: Semantic role of the individual dwords is unknown.
}
