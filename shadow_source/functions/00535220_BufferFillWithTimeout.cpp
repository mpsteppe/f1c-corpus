// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00535220
// Canonical corpus name: BufferFillWithTimeout
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferFillWithTimeout_00535220.c

void UnknownObject::BufferFillWithTimeout()
{
    // Fills a tagged read buffer (type byte 119 at object+92) up to a requested count a3. Rejects objects without the 'w' tag and null a1 with -2. Stores the request (a2 at +0, a3 at +4), then loops: while the buffer has no staged bytes (a1+16 == 0) it reads 0x4000 bytes from the file handle at a1+72 into the buffer at a1+64 via FileReadWrapperWithLock, and a short read breaks the loop with the error marker -1 at a1+56. When bytes are staged, sub_535E80(a1, 0) consumes them and records progress at a1+56, repeating until it returns non-zero or the remaining count at a1+4 reaches zero. Finally records sub_536E90(a3) at a1+76 and returns a3 minus the remaining count, i.e. the number of bytes consumed.
    // GUARD: If a1 is null or the type byte at a1+92 is not 119 ('w'), return -2 [source:raw]
    // ASSIGNMENT: Record the request: *(a1) = a2 and *(a1+4) = a3 [source:raw]
    // GUARD: If the requested count a3 is zero, skip the fill loop entirely [source:raw]
    // LOOP: While the buffer has no staged bytes (a1+16 == 0): issue FileReadWrapperWithLock(file handle at a1+72, 1, 0x4000, staging buffer at a1+64); a result other than 0x4000 (short/EOF read) breaks the loop; otherwise mark a1+16 = 0x4000 staged [callee:0x00588678, source:raw]
    // CALL: Consume staged bytes: sub_535E80(a1, 0) returns a progress value stored at a1+56 [callee:0x00535E80, source:raw]
    // LOOP: Repeat consumption until sub_535E80 returns non-zero or the remaining count at a1+4 reaches zero [source:raw]
    // ASSIGNMENT: On a short/failed read, record the error marker -1 at a1+56 [source:raw]
    // CALL: Timing/accounting hook: sub_536E90(a3) result is stored at a1+76 [callee:0x00536E90, source:raw]
    // RETURN: Returns a3 - (a1+4), the requested count minus the remaining count, i.e. bytes actually consumed [source:raw]
    // CALL: On the frame path; invoked by StringLengthDispatch, AudioStreamBufferRead, ConditionalDispatch_6bd0 and BufferWriteWithStringLengthCheck [caller:0x005352B0, caller:0x00535390, caller:0x00566BD0, caller:0x00566C30, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1 || *(byte*)(a1+92) != 119) return -2;
    //   *(a1) = a2; *(a1+4) = a3;
    //   if (a3) {
    //     while (1) {
    //       if (*(a1+16)) goto consume;
    //       *(a1+12) = *(a1+72);
    //       if (ReadLocked(*(a1+72), 1, 0x4000, *(a1+64)) != 0x4000) break;
    //       *(a1+16) = 0x4000;
    //   consume:
    //       *(a1+56) = Consume(a1, 0);
    //       if (*(a1+56) || !*(a1+4)) goto done;
    //     }
    //     *(a1+56) = -1;
    //   }
    //   done:
    //   *(a1+76) = Bookkeep(a3);
    //   return a3 - *(a1+4);
    // UNRESOLVED: The semantics of sub_535E80 (buffer consumption/decode) and sub_536E90 (timing/accounting) are unknown from this packet
    // UNRESOLVED: The 'w' tag at a1+92 implies a tagged buffer object, but no struct layout is evidenced in this packet
    // UNRESOLVED: All object field offsets (+0/+4/+12/+16/+56/+64/+72/+76/+92) come from the raw decompiled source only; the packet carries no field evidence entries for them
    // UNRESOLVED: The relationship between the return value and a1+76 (result of sub_536E90) is not established
}
