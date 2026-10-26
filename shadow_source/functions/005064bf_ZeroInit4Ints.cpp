// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005064BF
// Canonical corpus name: ZeroInit4Ints_64bf
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInit4Ints_64bf_005064bf.c

void UnknownObject::ZeroInit4Ints()
{
    // Zero-initializes four consecutive dwords of a __thiscall object starting at this+0 (offsets 0x0, 0x4, 0x8, 0xC). Returns the unchanged this pointer. Pure field writer with no guards, globals, or callees.
    // ASSIGNMENT: Write 0 to this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write 0 to this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write 0 to this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write 0 to this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return the this pointer (result = this). [source:raw]
    // CALL: Used by NetworkPacketSendReceive (0x0050070D) and SurfaceBlitOperation (0x0050099C) to zero a four-dword block at setup time. [caller:0x0050070D, caller:0x0050099C, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_5064BF(_DWORD *this) {
    //     this[0] = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[3] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Which object owns the four zeroed dwords is unknown; callers span network packet and surface blit paths.
    // UNRESOLVED: Semantic role of the individual dwords is unknown.
}
