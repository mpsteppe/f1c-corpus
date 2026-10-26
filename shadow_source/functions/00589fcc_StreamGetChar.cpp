// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589FCC
// Canonical corpus name: StreamGetcWithUnderflowHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamGetcWithUnderflowHandler_00589fcc.c

void UnknownObject::StreamGetChar()
{
    // Reads one byte from a buffered stream protected by a critical section. Decrements the remaining byte count; on underflow (count goes negative) it refills the buffer via sub_58C255, otherwise it reads a byte from the current buffer pointer and advances the pointer. Always enters and leaves the stream critical section and returns the byte read.
    // CALL: Enter the stream critical section via StreamBufferLockViaCriticalSection(a1). [callee:0x0058C1B1, source:raw]
    // CALCULATION: Decrement the remaining byte count a1[1] by one. [field:this:0x00000004, source:raw]
    // GUARD: Dispatch on the underflow flag: when --a1[1] < 0 the buffer is exhausted and v2 = sub_58C255(a1) refills it. [callee:0x0058C255, field:this:0x00000004, source:raw]
    // CALCULATION: Otherwise read a byte from the current buffer position v2 = *(unsigned __int8 *)(*a1)++ and advance the buffer pointer. [field:this:0x00000000, source:raw]
    // CALL: Leave the stream critical section via AddressRangeCriticalSectionLeave(a1). [callee:0x0058C203, source:raw]
    // RETURN: Return the byte v2 read from the stream. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_589FCC(DWORD* stream) {
    //     StreamBufferLockViaCriticalSection(stream);
    //     int ch;
    //     if (--stream[1] < 0) ch = sub_58C255(stream);
    //     else ch = *(unsigned __int8*)(*stream)++;
    //     AddressRangeCriticalSectionLeave(stream);
    //     return ch;
    //   }
    // UNRESOLVED: The legacy ABI name 'Stream_getc_with_Underflow_Handler' (abi:lead) is consistent with the raw source but is not independently confirmed.
    // UNRESOLVED: The stream object layout (current buffer pointer at offset 0, remaining byte count at offset 4) and the refill semantics of sub_58C255 are not further evidenced.
}
