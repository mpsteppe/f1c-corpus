// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599298
// Canonical corpus name: MemoryDeallocationWrapperWithOffsetHeader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryDeallocationWrapperWithOffsetHeader_00599298.c

void UnknownObject::MemoryDeallocationWrapperWithOffsetHeader()
{
    // Userpurge memory wrapper that backs up from the receiver by 8 bytes to reach an offset header, runs ConstructorWithVTableFixup on that header with the second register argument and three stack locals, then conditionally frees the same pointer via FreeWrapper when the low bit of the flag argument is set, and returns the header pointer.
    // ASSIGNMENT: Compute the offset header pointer v3 as the receiver a1 minus 8 [source:raw, function:0x00599298]
    // CALL: ConstructorWithVTableFixup invoked on the offset header (a1 - 8) with a2 and the stack locals v6, v7, v8 [callee:0x00598731, source:raw]
    // GUARD: Free path taken only when the low bit of flag a3 is set (a3 & 1 != 0) [source:raw]
    // CALL: FreeWrapper_7bcf invoked on the offset header pointer v3 inside the guarded branch [callee:0x00587BCF, source:raw]
    // RETURN: Return the offset header pointer v3 [source:raw]

    // Conservative worker pseudocode:
    //   v3 = a1 - 8;
    //   ConstructorWithVTableFixup((char *)v3, a2, v6, v7, v8);
    //   if ((a3 & 1) != 0) {
    //     FreeWrapper_7bcf(v3);
    //   }
    //   return v3;
    // UNRESOLVED: Function uses a userpurge ABI with the receiver in ecx and a second argument in esi; the decompiler warns of a positive stack delta, so the argument passing order and stack locals v6/v7/v8 are only partially trustworthy
    // UNRESOLVED: The purpose of the 8-byte offset header and what ConstructorWithVTableFixup initializes inside it is not established from this packet
    // UNRESOLVED: The exact meaning of flag a3 (allocator bitmask vs. caller-specified flag) is unknown
}
