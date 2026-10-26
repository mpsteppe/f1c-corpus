// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589898
// Canonical corpus name: BufferedCharacterWriteWithOverflowHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferedCharacterWriteWithOverflowHandling_00589898.c

void UnknownObject::BufferedCharacterWriteWithOverflowHandling()
{
    // Buffered single-character write with overflow handling. Takes a character a1 and a stream-buffer control struct a2 (a2[0] is the current byte cursor, a2[1] the remaining-capacity counter). Decrements the capacity counter; if it goes negative the buffer is full and the overflow path sub_58CF35(a1, a2) is taken, otherwise the low byte of a1 is written at the cursor and the cursor advances. The whole operation is wrapped in a critical-section lock/unlock pair. Returns the written byte value on the normal path, or the overflow path's result.
    // CALL: Enter the buffer's critical section via StreamBufferLockViaCriticalSection(a2). [callee:0x0058C1B1, source:raw]
    // CALCULATION: Decrement the remaining-capacity counter a2[1] and test whether it fell below zero, detecting buffer overflow. [source:raw]
    // GUARD: If a2[1] < 0 the buffer is full: take the overflow path, else write in place. [source:raw]
    // CALL: Overflow path: call sub_58CF35(a1, a2) (flush/reserve handler) and store its result in v3. [callee:0x0058CF35, source:raw]
    // ASSIGNMENT: Normal path: v3 = (unsigned __int8)a1, then write that byte at the current cursor *a2 and advance the cursor (*a2)++. [source:raw]
    // CALL: Leave the buffer's critical section via AddressRangeCriticalSectionLeave(a2). [callee:0x0058C203, source:raw]
    // RETURN: Return v3, the written byte value or the overflow path's result. [source:raw]

    // Conservative worker pseudocode:
    //   int BufferedCharacterWriteWithOverflowHandling(int ch, int *buf) {
    //     int result;
    //     StreamBufferLockViaCriticalSection(buf);
    //     if (--buf[1] < 0) {
    //       result = sub_58CF35(ch, buf);  // buffer full: flush/reserve path
    //     } else {
    //       result = (unsigned char)ch;
    //       *((unsigned char *)*buf)++ = (unsigned char)ch;  // write byte, advance cursor
    //     }
    //     AddressRangeCriticalSectionLeave(buf);
    //     return result;
    //   }
    // UNRESOLVED: Identity and exact behavior of the overflow handler sub_58CF35 are unknown; whether it flushes buffered bytes to a destination or grows the buffer is unproven.
    // UNRESOLVED: The layout of the a2 control struct beyond the cursor (a2[0]) and capacity counter (a2[1]) is not evidenced.
    // UNRESOLVED: What stores the written byte stream and when buffered data is flushed to its final destination is outside this function's evidence.
}
