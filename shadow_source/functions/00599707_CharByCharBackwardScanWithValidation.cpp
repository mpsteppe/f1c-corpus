// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599707
// Canonical corpus name: CharByCharBackwardScanWithValidation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CharByCharBackwardScanWithValidation_00599707.c

void UnknownObject::CharByCharBackwardScanWithValidation()
{
    // Scans a3 bytes of the buffer at a1 backward (starting one byte past the end), feeding each byte to FileIOWrapperWithLock against the stream object a2. Returns 1 when every byte was accepted (a3 consumed entirely); on the first -1 return from FileIOWrapperWithLock it stops and returns 0. A residual drain block that reads bytes back from a2 via StreamGetcWithUnderflowHandler appears unreachable in the given control flow. Called by CharValidationAgainstEncodingTableWithLocaleFall (00598FD4) and FileOffsetPositionValidation (0059A01E).
    // ASSIGNMENT: v3 = a3 (remaining count) and v5 = a1 + a3 (one-past-end cursor); v4 = (a3 == 0) records the empty-input success flag [function:0x00599707, source:raw]
    // GUARD: Scan loop is entered only when a3 != 0; an empty buffer falls through to the success return [function:0x00599707, source:raw]
    // LOOP: do/while backward scan: pre-decrement v5 and read one byte (v6 = *(unsigned __int8 *)--v5), continuing while v3 is non-zero [function:0x00599707, source:raw]
    // CALL: FileIOWrapperWithLock(v6, a2): hands each scanned byte to the stream; the -1 sentinel marks a rejected byte [callee:0x0059685F, source:raw]
    // GUARD: if FileIOWrapperWithLock returns -1, break out of the scan early with v3 still non-zero (failure path) [function:0x00599707, source:raw]
    // STATE_TRANSITION: --v3 per accepted byte; v4 is recomputed as (v3 == 0) after the loop, and the scan returns 1 when the whole buffer was accepted [function:0x00599707, source:raw]
    // RETURN: return 1 when v4 is true (a3 == 0 either initially or fully consumed) [function:0x00599707, source:raw]
    // CALL: Fallback drain block calls StreamGetcWithUnderflowHandler(a2) in a do/while over v8 [callee:0x00589FCC, source:raw]
    // RETURN: return 0 on the failure path (v4 false, i.e. not all bytes accepted) [function:0x00599707, source:raw]
    // CALL: Invoked by CharValidationAgainstEncodingTableWithLocaleFall (00598FD4) and FileOffsetPositionValidation (0059A01E) [caller:0x00598FD4, caller:0x0059A01E]

    // Conservative worker pseudocode:
    //   v3 = a3; v5 = a1 + a3; v4 = (a3 == 0);
    //   if (a3 != 0) {
    //     do {
    //       v6 = *(unsigned __int8 *)--v5;
    //       if (FileIOWrapperWithLock(v6, a2) == -1) break;
    //       --v3;
    //     } while (v3);
    //     v4 = (v3 == 0);
    //   }
    //   if (v4) return 1;
    //   v8 = 1;
    //   if (!v3) {
    //     do { StreamGetcWithUnderflowHandler(a2); --v8; } while (v8);
    //   }
    //   return 0;
    // UNRESOLVED: The fallback block (v8 = 1; if (!v3) { do StreamGetcWithUnderflowHandler(a2); --v8; } while (v8);) is unreachable as written: reaching it requires v4 == false, hence v3 != 0, so the inner if(!v3) never fires. Likely a compiler artifact; the intended drain behavior is not verifiable here.
    // UNRESOLVED: FileIOWrapperWithLock is treated as a per-byte validator/writer only via its -1 sentinel; its exact semantics are outside this function.
}
