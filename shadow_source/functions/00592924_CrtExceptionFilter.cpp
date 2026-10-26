// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592924
// Canonical corpus name: sub_592924
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592924_00592924.c

void UnknownObject::CrtExceptionFilter()
{
    // CRT structured-exception filter. Reads the thread-local storage block, searches the exception-handler record table for a matching record keyed by the exception parameter, and returns to the Win32 unhandled-exception filter when no usable record is found. Otherwise dispatches: handler value 5 clears the record slot and returns 1 (treated as handled/terminate), handler value 1 returns -1 (continue search), and any other handler maps the record's structured exception code to a signal number (130/131/132/133/134/138 or 129 for the divide/overflow code family) then invokes the handler with the mapped code. Called by sub_58A19E (0058a19e).
    // CALL: TLSValueRetrievalWithInit obtains the thread-local storage block for the current thread [callee:0x0058E0C7, source:raw]
    // CALL: ArrayOfStructStrideSearch(a1, TLS[20]) searches the exception-handler record table rooted in the TLS block for a record matching a1 [callee:0x00592A62, source:raw]
    // GUARD: If no matching handler record is found, return UnhandledExceptionFilter(ExceptionInfo) so the Win32 default filter processes the fault [global:0x0059E11C, source:raw]
    // GUARD: If the handler function pointer at record+8 is null, return UnhandledExceptionFilter(ExceptionInfo) [global:0x0059E11C, source:raw]
    // GUARD: If handler pointer equals 5, the record is treated as terminated: clear record+8 to 0 and return 1 (handled) [source:raw]
    // ASSIGNMENT: If handler pointer is not 1, save TLS[21] into v11, store ExceptionInfo into TLS[21] for the duration of dispatch, and restore it afterward [source:raw]
    // GUARD: Dispatch mode v6 = record+4: when equal to 8 the exception-code-to-signal mapping path runs; otherwise the record slot is cleared and the handler is invoked directly with v6 [source:raw]
    // LOOP: Zero-fill the handler-state entries from index dword_5E7888 up to dword_5E7888 + dword_5E788C inside the TLS array at TLS[20], each entry 12 bytes wide with the zero written at entry-end minus 4 [global:0x005E7888, global:0x005E788C, source:raw]
    // STATE_TRANSITION: Map the structured exception code at record+0 to a signal number in TLS[22]: -1073741683 to 130, -1073741682 to 131, -1073741681 to 134, -1073741680 to 129, -1073741679 to 132, -1073741678 to 138, -1073741677 to 133; the previous TLS[22] value v10 is restored after the handler call [source:raw]
    // CALL: Invoke the mapped handler with argument 8, then restore TLS[22] to v10 [source:raw]
    // RETURN: After dispatch (or when the handler was 1), return -1 to signal the filter chain to continue [source:raw]
    // CALL: This filter is invoked from sub_58A19E (0058a19e) [caller:0x0058A19E, source:raw]

    // Conservative worker pseudocode:
    //   tls = TLSValueRetrievalWithInit();
    //   rec = ArrayOfStructStrideSearch(a1, tls[20]);
    //   if (!rec) return UnhandledExceptionFilter(ExceptionInfo);
    //   handler = rec[2];
    //   if (!handler) return UnhandledExceptionFilter(ExceptionInfo);
    //   if (handler == 5) { rec[2] = 0; return 1; }
    //   if (handler != 1) {
    //     saved = tls[21]; tls[21] = ExceptionInfo;
    //     mode = rec[1];
    //     if (mode == 8) {
    //       for (i = dword_5E7888; i < dword_5E7888 + dword_5E788C; ++i)
    //         ((int*)tls[20])[3*i + 2] = 0;
    //       sig = map_code_to_signal(rec[0]);
    //       prev = tls[22]; tls[22] = sig;
    //       handler(8);
    //       tls[22] = prev;
    //     } else {
    //       rec[2] = 0;
    //       handler(mode);
    //     }
    //     tls[21] = saved;
    //   }
    //   return -1;
    // UNRESOLVED: The seven structured exception codes appear only as negative decimal literals (-1073741683..-1073741677) in the raw source; the specific Win32 codes and the exact semantics of the mapped signal numbers (129..134, 138) are not further identified by this packet
    // UNRESOLVED: The TLS slots TLS[20]/TLS[21]/TLS[22] and the 12-byte handler-state entry layout have no field facts in this packet
    // UNRESOLVED: dword_5E7888/dword_5E788C roles as exception-entry count and handler count are DERIVED from the existing analysis and are not proven here
}
