// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595304
// Canonical corpus name: sub_595304
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_595304_00595304.c

void UnknownObject::ZeroInitThreeDwords()
{
    // Unconditional zero-initializer for a 12-byte structure: writes 0 to the dword at this+0x0, the dword at this+0x4 and the dword at this+0x8. Always returns 0. Structural twin of the SmallStructZeroInit cluster representative per cluster analysis; called by sub_5953B8 (0x005953B8).
    // ASSIGNMENT: Zero the first dword field at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the second dword field at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the third dword field at this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Return 0. [source:raw]
    // CALL: Invoked by sub_5953B8 (0x005953B8), the only recorded caller. [caller:0x005953B8, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   return 0;
    // UNRESOLVED: Receiver struct identity and the meaning of its 12 bytes are unknown; the partial ABI record (PARTIAL_Unknown_595304) does not declare a prototype.
}
