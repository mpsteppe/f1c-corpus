// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431D40
// Canonical corpus name: PhysicsBufferAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsBufferAlloc_00431d40.c

void UnknownObject::PhysicsBufferAlloc()
{
    // Constructor-style initializer for a physics buffer allocator. Allocates three buffers via OperatorNewNhMallocWrapper (two of 80 bytes, one of 128 bytes), stores each pointer and its size as adjacent DWORDs at this+0x0/0x4, this+0x8/0xC and this+0x10/0x14, zeroes the first byte of every buffer, zeroes the ten trailing DWORDs this+0x18..+0x3C, and returns this. Called by Thunk_1bc0 (0x00431BC0).
    // CALL: Allocates the first 80-byte buffer via OperatorNewNhMallocWrapper(80) [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Stores the first buffer pointer at this+0x0 and its size 80 at this+0x4, then zeroes the first byte of the buffer [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: Allocates the second 80-byte buffer via OperatorNewNhMallocWrapper(80) [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Stores the second buffer pointer at this+0x8 and its size 80 at this+0xC, then zeroes the first byte of the buffer [field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Allocates the third 128-byte buffer via OperatorNewNhMallocWrapper(128) [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Stores the third buffer pointer at this+0x10 and its size 128 at this+0x14, then zeroes the first byte of the buffer [field:this:0x00000010, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zeroes the ten trailing DWORDs this+0x18, +0x1C, +0x20, +0x24, +0x28, +0x2C, +0x30, +0x34, +0x38, +0x3C [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // CALL: Invoked by Thunk_1bc0 (0x00431BC0) as the construction path for the physics buffer allocator [caller:0x00431BC0, source:raw]
    // RETURN: Returns this as the initialized allocator object [source:raw]

    // Conservative worker pseudocode:
    //   this[0] = OperatorNewNhMallocWrapper(80); *(this[0]) = 0; this[1] = 80;
    //   this[2] = OperatorNewNhMallocWrapper(80); *(this[2]) = 0; this[3] = 80;
    //   this[4] = OperatorNewNhMallocWrapper(128); *(this[4]) = 0; this[5] = 128;
    //   for (i = 6; i <= 15; ++i) this[i] = 0;
    //   return this;
    // UNRESOLVED: The ten zeroed DWORDs at this+0x18..+0x3C have no named role (counters or flags) in any packet evidence
    // UNRESOLVED: The buffers are allocated here but no deallocation path appears in this packet
}
