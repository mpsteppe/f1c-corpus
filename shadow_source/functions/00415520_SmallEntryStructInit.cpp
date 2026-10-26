// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415520
// Canonical corpus name: SmallEntryStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallEntryStructInit_00415520.c

void UnknownObject::SmallEntryStructInit()
{
    // Initializes a 20-byte small entry struct: clears the DWORD at this+0x0 to 0, resets the DWORD at this+0x4 to -1, reinitializes the global path string buffer byte_5EA438 via StringCopyWithBufferRealloc, resets the DWORDs at this+0x8 and this+0xC to -1, clears the byte at this+0x10 to 0, and returns this. Called by NamedEntryLookupInFormatList, VehicleListBuilderFromGlobalArray and SceneListBuilderFromGlobalArray during entry setup.
    // ASSIGNMENT: Clears the DWORD link field at this+0x0 to 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Resets the DWORD at this+0x4 to -1 (entry id/type field). [field:this:0x00000004, source:raw]
    // CALL: Calls StringCopyWithBufferRealloc(&byte_5EA438) to reinitialize the global default path string buffer as part of entry initialization. [callee:0x00566650, global:0x005EA438, source:raw]
    // ASSIGNMENT: Resets the DWORD at this+0x8 to -1. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Resets the DWORD at this+0xC to -1. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clears the byte at this+0x10 to 0. [field:this:0x00000010, source:raw]
    // RETURN: Returns this, the initialized entry struct. [function:0x00415520, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *SmallEntryStructInit(DWORD *this) {
    //     this[0] = 0;
    //     this[1] = -1;
    //     StringCopyWithBufferRealloc(&byte_5EA438);
    //     this[2] = -1;
    //     this[3] = -1;
    //     ((BYTE *)this)[16] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The exact purpose of the -1-initialized DWORDs at this+0x4/0x8/0xC and the byte at this+0x10 is not evidenced beyond reset-on-init; the struct spans only 20 bytes (0x14).
    // UNRESOLVED: Why byte_5EA438 is reinitialized during entry init is not evidenced; StringCopyWithBufferRealloc may carry side effects beyond the string copy.
}
