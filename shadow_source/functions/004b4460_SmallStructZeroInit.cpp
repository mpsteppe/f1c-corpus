// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4460
// Canonical corpus name: SmallStructZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructZeroInit_004b4460.c

void UnknownObject::SmallStructZeroInit()
{
    // Unconditional zero-initializer for a 10-byte structure: writes 0 to the dword at this+0x0, the dword at this+0x4, and the word at this+0x8. Always returns 0. Called by wrapper and buffer-transfer helpers.
    // ASSIGNMENT: Zero the first dword field at this+0x0. [field:this:0x00000000]
    // ASSIGNMENT: Zero the second dword field at this+0x4. [field:this:0x00000004]
    // ASSIGNMENT: Zero the word field at this+0x8 (2 bytes). [field:this:0x00000008]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   this[1] = 0;
    //   ((WORD*)this)[4] = 0;
    //   return 0;
    // UNRESOLVED: Receiver struct identity and the meaning of its 10 bytes are unknown.
}
