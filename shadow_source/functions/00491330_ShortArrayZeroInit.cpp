// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491330
// Canonical corpus name: ShortArrayZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortArrayZeroInit_00491330.c

void UnknownObject::ShortArrayZeroInit()
{
    // Zero-initializer for a short-array region on a _WORD-typed this. Zeroes the words at offsets 0x0, 0x2, 0x4, 0x6 and 0x8, and the dword at offset 0xC (via _DWORD cast at word index 6, covering byte offsets 12 through 15). No reads, no globals, no callees; returns 0. Reached through the thunk at 0x004912F0 and called by LinkedListNodePrepend (0x00490AA0).
    // ASSIGNMENT: Word at offset 0x0 set to 0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Word at offset 0x2 set to 0 [field:this:0x00000002, source:raw]
    // ASSIGNMENT: Word at offset 0x4 set to 0 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Word at offset 0x6 set to 0 [field:this:0x00000006, source:raw]
    // ASSIGNMENT: Dword at offset 0xC (dword index 3 via _DWORD cast, covering byte offsets 12 through 15) set to 0 [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Word at offset 0x8 set to 0 [field:this:0x00000008, source:raw]
    // RETURN: Returns 0 [function:0x00491330, source:raw]
    // CALL: Reached through the thunk at 0x004912F0 and called by LinkedListNodePrepend (0x00490AA0) [caller:0x004912F0, caller:0x00490AA0, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   this[3] = 0;
    //   *(_DWORD*)((char*)this + 12) = 0;
    //   this[4] = 0;
    //   return result;
    // UNRESOLVED: The dword write at offset 0xC overlaps the word slots beyond offset 0x8; whether the region is an array of shorts with a trailing dword or an aliased view is not decided by the packet
    // UNRESOLVED: The thunk at 0x004912F0 (ThunkToFUN00491330) is a forwarder to this function; it is listed as a caller rather than a distinct semantic consumer
}
