// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E22B
// Canonical corpus name: sub_58E22B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58E22B_0058e22b.c

void UnknownObject::FileWriteWithLock()
{
    // Locked file-write wrapper (cdecl, takes a file slot, buffer and byte count). When the slot is in range (a1 < uNumber) and the slot's descriptor flag bit 0 is set (descriptor array dword_8D4920, slot selected by a1 >> 5 and 36 * (a1 & 0x1F) + 4), it enters a critical section, delegates the actual write to sub_58E290(a1, lpBuffer, nNumberOfBytesToWrite), leaves the critical section and returns that result. Otherwise it writes error code 9 and error offset 0 through two TLS getters and returns -1.
    // GUARD: Success path requires a1 < uNumber AND the byte at dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4 to have bit 0 set. [global:0x008D4920, global:0x008D4A20, source:raw]
    // CALL: Enter the file critical section via CriticalSectionEnterWithLazyInit(a1). [callee:0x00595A61, source:raw]
    // CALL: Delegate the write: v3 = sub_58E290(a1, lpBuffer, nNumberOfBytesToWrite). [callee:0x0058E290, source:raw]
    // CALL: Leave the file critical section via FileCriticalSectionLeave(a1). [callee:0x00595AC0, source:raw]
    // RETURN: Return v3, the result of the delegated write, on the success path. [source:raw]
    // STATE_TRANSITION: Error path: store error code 9 through the TLS getter at 0058afcf. [callee:0x0058AFCF, source:raw]
    // STATE_TRANSITION: Error path: store error offset 0 through the second TLS getter at 0058afd8. [callee:0x0058AFD8, source:raw]
    // RETURN: Return -1 on the error path (invalid slot or flag cleared). [source:raw]
    // CALL: Called by sub_5886A7 (005886a7), BufferFlushWrite (0058a05a), sub_58CF35 (0058cf35) and sub_59C1E7 (0059c1e7) as the serialized write entry point. [caller:0x005886A7, caller:0x0058A05A, caller:0x0058CF35, caller:0x0059C1E7, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 < uNumber && (dword_8D4920[a1 >> 5][36 * (a1 & 0x1F) + 4] & 1) != 0) {
    //     CriticalSectionEnterWithLazyInit(a1);
    //     v3 = sub_58E290(a1, lpBuffer, nNumberOfBytesToWrite);
    //     FileCriticalSectionLeave(a1);
    //     return v3;
    //   }
    //   *TLSOffsetGetter() = 9;
    //   *TLSOffsetGetter_afd8() = 0;
    //   return -1;
    // UNRESOLVED: The layout of the descriptor rows indexed by dword_8D4920 (36 bytes per slot, flag byte at +4) is not documented in this packet; the 36-byte stride and +4 flag position are taken directly from the raw source arithmetic.
    // UNRESOLVED: Semantics of TLS error code 9 and of the two TLS getters are caller-visible state, not explained here.
    // UNRESOLVED: The prelabel notes this is a structural twin of sub_58C331 (0058c331); that relationship is not independently verified in this packet.
}
