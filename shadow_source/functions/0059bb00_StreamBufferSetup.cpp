// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059BB00
// Canonical corpus name: sub_59BB00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59BB00_0059bb00.c

void UnknownObject::StreamBufferSetup()
{
    // Stream buffer setup (cdecl, a1 = stream object, a2 = caller buffer, a3 = mode, a4 = requested size). Validates the mode/size contract (a3 == 4 always allowed; otherwise a4 >= 2 and a3 == 0 or 64), rounds the size down to even (a4 & 0xFFFFFFFE), enters the stream critical section, flushes pending writes via BufferFlushWrite, resets stream state via sub_58C411 and clears the flag word this[0xC] (mask 0xC2F3). It then selects the buffer: an embedded internal buffer at a1 + 20 with effective size 2 for mode bit 4, the caller buffer a2 for the non-null case, or a heap allocation via MallocWrapperForNhMalloc(v5) (flag 0x408 set on success, dword_8D3EC8 incremented and -1 returned on failure). All paths write this[0x4] = 0, this[0x18] = size, this[0x8] = buffer pointer and this[0x0] = buffer pointer, leave the critical section via AddressRangeCriticalSectionLeave, and return 0.
    // GUARD: Validate the mode/size contract: mode a3 == 4 always passes; otherwise a4 must be >= 2 and a3 must be 0 or 64; any violation returns -1. [source:raw]
    // CALCULATION: Round the requested buffer size down to an even value: v5 = a4 & 0xFFFFFFFE. [source:raw]
    // CALL: Enter the stream critical section via StreamBufferLockViaCriticalSection(a1), flush pending writes via BufferFlushWrite(a1), and reset stream state via sub_58C411(a1). [callee:0x0058C1B1, callee:0x0058A05A, callee:0x0058C411]
    // ASSIGNMENT: Clear the stream flag bits in this[0xC] by masking the word with 0xC2F3. [field:this:0x0000000C]
    // GUARD: Mode a3 with bit 4 set: set flag bit 4 in this[0xC] and use the embedded internal buffer at a1 + 20 with effective size 2. [field:this:0x0000000C]
    // GUARD: Caller-supplied buffer (a2 non-null): set the external-buffer flags (high byte of the flag word | 5) in this[0xC] and use a2 as the buffer pointer. [field:this:0x0000000C]
    // CALL: No external buffer: allocate the internal buffer via MallocWrapperForNhMalloc(v5); on success set flag 0x408 in this[0xC]; on failure increment dword_8D3EC8 and fail with -1. [callee:0x0058A935, field:this:0x0000000C, global:0x008D3EC8]
    // ASSIGNMENT: Common buffer setup: this[0x4] = 0, this[0x18] = v5 (buffer size), this[0x8] = buffer pointer, this[0x0] = buffer pointer. [field:this:0x00000004, field:this:0x00000018, field:this:0x00000008, field:this:0x00000000]
    // CALL: Leave the stream critical section via AddressRangeCriticalSectionLeave(a1). [callee:0x0058C203]
    // RETURN: Return -1 on mode/size validation failure and on allocation failure; return 0 on success. [source:raw]
    // CALL: Called by ConditionalDelegateCallWithNullGuard (0x00599232) and LocaleEncodingCheck (0x0059A2D0) as a shared stream-buffer setup primitive. [caller:0x00599232, caller:0x0059A2D0]

    // Conservative worker pseudocode:
    //   v8 = 0;
    //   if (a3 != 4 && (a4 < 2 || (a3 && a3 != 64))) return -1;
    //   v5 = a4 & 0xFFFFFFFE;
    //   StreamBufferLockViaCriticalSection(a1);
    //   BufferFlushWrite((_DWORD *)a1);
    //   sub_58C411(a1);
    //   *(_WORD *)(a1 + 12) &= 0xC2F3;
    //   v6 = *(_DWORD *)(a1 + 12);
    //   if ((a3 & 4) != 0) {
    //       *(_DWORD *)(a1 + 12) = v6 | 4;
    //       v7 = a1 + 20;
    //       v5 = 2;
    //   } else if (a2) {
    //       BYTE1(v6) |= 5;
    //       *(_DWORD *)(a1 + 12) = v6;
    //       v7 = a2;
    //   } else {
    //       v7 = MallocWrapperForNhMalloc(v5);
    //       if (!v7) {
    //           ++dword_8D3EC8;
    //           v8 = -1;
    //           AddressRangeCriticalSectionLeave(a1);
    //           return v8;
    //       }
    //       *(_WORD *)(a1 + 12) |= 0x408;
    //   }
    //   *(_DWORD *)(a1 + 4) = 0;
    //   *(_DWORD *)(a1 + 24) = v5;
    //   *(_DWORD *)(a1 + 8) = v7;
    //   *(_DWORD *)a1 = v7;
    //   AddressRangeCriticalSectionLeave(a1);
    //   return v8;
    // UNRESOLVED: The exact meaning of the mode values (4, 0, 64) and the flag bits 4, 0x408 and 0xC2F3 in this[0xC] are DERIVED from the corpus fill; the packet only shows the numeric writes.
    // UNRESOLVED: dword_8D3EC8 is incremented on allocation failure and read by the fill as a failure/file-open counter; its exact role is not stated by the packet.
    // UNRESOLVED: sub_58C411 (stream-state reset helper) and the byte at a1 + 20 (embedded internal buffer) have no further layout evidence in the packet.
    // UNRESOLVED: The stream object's exact type and the meaning of this[0x0]/this[0x4]/this[0x8]/this[0x18] as buffer-position/count/base/size are inferred from the write pattern, not documented by the packet.
}
