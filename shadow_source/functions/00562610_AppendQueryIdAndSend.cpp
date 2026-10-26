// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562610
// Canonical corpus name: sub_562610
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562610_00562610.c

void UnknownObject::AppendQueryIdAndSend()
{
    // Appends a \queryid\N.M token to a network send buffer and transmits it over UDP. When the buffer is non-empty, increments a per-socket query-id counter (a1[56]), formats a \queryid\%d.%d token from the stored base id (a1[55]) and the new counter value, concatenates it onto buf, sends the buffer via sendto (16-byte sockaddr), then clears buf. Returns sendto's result, or 0 when the buffer was empty.
    // GUARD: Proceed only when strlen(buf) is non-zero; otherwise return 0 without sending [source:raw]
    // ASSIGNMENT: v5 = a1[56] + 1; store v5 back into a1[56] (increment the per-socket query-id counter) [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v7, "\\queryid\\%d.%d", a1[55], v5) formats the query-id token from the stored base id and the new counter [callee:0x0058815F, global:0x005E4E90, source:raw]
    // CALL: strcat(buf, v7) appends the formatted query-id token to the send buffer [source:raw]
    // CALL: result = sendto(*a1, buf, strlen(buf), 0, a2, 16) transmits the buffer over UDP to the given sockaddr [callee:0x00598672, source:raw]
    // ASSIGNMENT: *buf = 0 clears the send buffer to empty after transmission [source:raw]
    // RETURN: Return result (sendto's status, or 0 when the buffer was empty) [function:0x00562610, source:raw]
    // CALL: Invoked by FilePathNameLookup (005622C0), sub_562710 (00562710) and sub_5629B0 (005629B0) as the shared query-id append-and-send helper [caller:0x005622C0, caller:0x00562710, caller:0x005629B0]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (strlen(buf) != 0) {
    //     v5 = a1[56] + 1;
    //     a1[56] = v5;
    //     StringFormatWithBufferOverflowCheck(v7, "\\queryid\\%d.%d", a1[55], v5);
    //     strcat(buf, v7);
    //     result = sendto(*a1, buf, strlen(buf), 0, a2, 16);
    //     *buf = 0;
    //   }
    //   return result;
    // UNRESOLVED: a1 is a SOCKET handle object but its layout (where the query-id base and counter live) is not documented; a1[55]/a1[56] are dword indices only
    // UNRESOLVED: The meaning of the \queryid\ base (a1[55]) and the purpose of sending query ids is unknown from this function alone
}
