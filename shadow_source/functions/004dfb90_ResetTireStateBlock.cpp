// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DFB90
// Canonical corpus name: sub_4DFB90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DFB90_004dfb90.c

void UnknownObject::ResetTireStateBlock()
{
    // Constructor-style zero-initializer for a small tire-related state block: clears two byte fields (offsets 0x0 and 0x1) and six dword fields (offsets 0x4, 0x8, 0xC, 0x10, 0x14, 0x18), then returns 0. Invoked from tire-system construction, vehicle reset, and sub_4DFBB0.
    // ASSIGNMENT: Zero the byte field at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the byte field at this+0x1. [field:this:0x00000001, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x10. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zero the dword field at this+0x18. [field:this:0x00000018, source:raw]
    // RETURN: Return 0 as the initializer result. [source:raw]
    // CALL: Called by PhysicsTireSystemConstructor (0x004E4500), VehicleResetClear (0x004E09E0) and sub_4DFBB0 (0x004DFBB0) to re-initialize the state block, placing it on tire-system and vehicle-reset paths. [caller:0x004E4500, caller:0x004E09E0, caller:0x004DFBB0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4DFB90(_BYTE *state) {
    //     state[0] = 0;
    //     state[1] = 0;
    //     *((_DWORD*)state + 1) = 0;
    //     *((_DWORD*)state + 2) = 0;
    //     *((_DWORD*)state + 3) = 0;
    //     *((_DWORD*)state + 4) = 0;
    //     *((_DWORD*)state + 5) = 0;
    //     *((_DWORD*)state + 6) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of each cleared field (the 2-byte prefix plus six dwords) are unknown; caller context only places the block on tire/vehicle-reset paths.
    // UNRESOLVED: Identity of the owning class is unknown.
}
