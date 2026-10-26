// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005179E0
// Canonical corpus name: sub_5179E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5179E0_005179e0.c

void UnknownObject::StreamResourceInit()
{
    // Initializes a stream/resource object: validates a marker byte and a size, installs default alloc/free callback wrappers when empty, allocates a 24-byte internal buffer via the allocator callback, then configures signedness, bit-width exponent and a 1<<v6-sized resource table produced by sub_5276C5. On success resets the resource with ResourceResetWithCounter; on any failure cleans up through sub_5179A2 and returns a negative error code. Called from sub_517AC5.
    // GUARD: Header validation: a3 null, *a3 not equal to 49, or a4 not equal to 56 fails with -6 [source:raw]
    // RETURN: Returns -6 when the marker guard fails [source:raw]
    // GUARD: Returns -2 immediately when the receiver a1 is null [source:raw]
    // ASSIGNMENT: Clears this+0x18 (reset counter/state flag) unconditionally at entry [field:this:0x00000018, source:raw]
    // GUARD: Guard on the allocator callback slot this+0x20 being zero (guard:0) [guard:0, field:this:0x00000020, source:raw]
    // ASSIGNMENT: When the allocator slot was empty, installs DelegationWrapper_803a as default and clears this+0x28 [global:0x0052803A, field:this:0x00000020, field:this:0x00000028, source:raw]
    // ASSIGNMENT: When the free-callback slot this+0x24 is empty, installs FreeWrapper_9351 as default (packet guard:1) [guard:1, field:this:0x00000024, global:0x00519351, source:raw]
    // CALL: Indirect allocator call: (this+0x20 callback)(this+0x28 context, 1, 24); the returned buffer is stored at this+0x1C [field:this:0x00000020, field:this:0x00000028, field:this:0x0000001C, source:raw]
    // GUARD: Guard on the allocation result; a null buffer falls through to the -4 error path [source:raw]
    // ASSIGNMENT: Initializes the buffer: clears the size field at buffer+20 and the signedness flag at buffer+12 to 0 [field:this:0x0000002C, field:this:0x00000030, source:raw]
    // STATE_TRANSITION: When a2 is negative, stores its magnitude in v6 and sets the buffer signedness flag (buffer+12) to 1 [field:this:0x0000002C, source:raw]
    // GUARD: Rejects out-of-range size: v6 outside 8..15 takes the cleanup-and--2 path [source:raw]
    // ASSIGNMENT: Writes the bit-width exponent v6 to buffer+16 [field:this:0x00000030, source:raw]
    // CALL: Calls sub_5276C5(a1, ChecksumCRCComputation when unsigned else 0, 1<<v6) to build the resource table, stored at buffer+20 [callee:0x005276C5, global:0x00527F21, source:raw]
    // GUARD: Guard on the resource-table pointer at buffer+20; null takes the -4 error path [source:raw]
    // CALL: On success calls ResourceResetWithCounter(a1) and returns 0 [callee:0x00517963, source:raw]
    // CALL: On any failure path calls sub_5179A2(a1) (cleanup) before returning the error code [callee:0x005179A2, source:raw]
    // RETURN: Returns -2 (bad size), -4 (allocation/table failure) or -6 (bad marker) on failure paths [source:raw]
    // CALL: Invoked by sub_517AC5 as part of stream/resource construction [caller:0x00517AC5, source:raw]

    // Conservative worker pseudocode:
    //   if (!a3 || *a3 != 49 || a4 != 56) return -6;
    //   if (!a1) return -2;
    //   wasReset = (a1[8] == 0);
    //   a1[6] = 0;
    //   if (wasReset) { a1[8] = DelegationWrapper_803a; a1[10] = 0; }
    //   if (!a1[9]) a1[9] = FreeWrapper_9351;
    //   buf = a1[8](a1[10], 1, 24);
    //   a1[7] = buf;
    //   if (buf) {
    //     *(buf+20) = 0; *(buf+12) = 0;
    //     if (a2 < 0) { v6 = -a2; *(buf+12) = 1; }
    //     if (v6 < 8 || v6 > 15) rc = -2;
    //     else {
    //       *(buf+16) = v6;
    //       *(buf+20) = sub_5276C5(a1, *(buf+12) == 0 ? ChecksumCRCComputation : 0, 1 << v6);
    //       if (*(buf+20)) { ResourceResetWithCounter(a1); return 0; }
    //       rc = -4;
    //     }
    //     sub_5179A2(a1);
    //     return rc;
    //   }
    //   return -4;
    // UNRESOLVED: Packet guard:1 is recorded against this+0x28 while the raw source guards the free-callback slot a1[9] (this+0x24); the guard-to-field mapping is inconsistent and left as recorded
    // UNRESOLVED: The packet field refs for the 24-byte buffer internals (this+0x2C, this+0x30) are mapped onto buffer+12/buffer+16 in the skeleton but the arithmetic from this+0x1C is ambiguous; the buffer layout is not proven
    // UNRESOLVED: The purpose of buffer+20 (the sub_5276C5 result) has no dedicated packet field evidence ref
    // UNRESOLVED: sub_5276C5 (resource table builder) and sub_5179A2 (cleanup) are unnamed
}
