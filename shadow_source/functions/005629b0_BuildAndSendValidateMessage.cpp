// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005629B0
// Canonical corpus name: sub_5629B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5629B0_005629b0.c

void UnknownObject::BuildAndSendValidateMessage()
{
    // Builds a network message over a UDP socket: when the validation string a4 is non-empty and at most 128 chars, it is copied, combined with existing object data at a1+72 via sub_562150, Base64-encoded, formatted as a "\\validate\\%s" segment, and appended to the output buffer through sub_562710. A mandatory final segment formatted from the aFinal global is always appended, then the composed buffer is sent with sub_562610. If a4 exceeds 128 chars the function returns 0 immediately without sending.
    // GUARD: If *a4 is non-zero (validation string a4 is non-empty), enter the validation branch. [source:raw]
    // CALCULATION: Set result to 0 and compute v6 = strlen(a4). [source:raw]
    // GUARD: If v6 > 128 the validation string is too long for the local buffer v9; return result (0) immediately. [source:raw]
    // ASSIGNMENT: Copy the validation string into the local buffer: strcpy(v9, a4). [source:raw]
    // CALL: Call sub_562150(a1 + 72, strlen(a1 + 72), v9, v6): process the existing data at object offset 72 together with the validation string. [callee:0x00562150, source:raw]
    // CALL: Call Base64Encode(v9, v6, v11) to Base64-encode the validation data into buffer v11. [callee:0x00562090, source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(v10, "\\validate\\%s", v11): format the validation path segment into v10 using the global aValidateS format. [callee:0x0058815F, global:0x005E4EB4, source:raw]
    // ASSIGNMENT: Set v7 = buf in the validation branch. [source:raw]
    // CALL: Call sub_562710(a1, a2, buf, v10): append the validation segment into the output buffer buf. [callee:0x00562710, source:raw]
    // ASSIGNMENT: Else branch (a4 empty): set v7 = buf without appending a validation segment. [source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(v10, aFinal): format the mandatory final segment from the global aFinal string. [callee:0x0058815F, global:0x005E4EAC, source:raw]
    // CALL: Call sub_562710(a1, a2, v7, v10): append the final segment to the output buffer. [callee:0x00562710, source:raw]
    // RETURN: Return the result of sub_562610(a1, a2, v7), which sends the composed buffer over the socket. [callee:0x00562610, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5629B0(int a1, const struct sockaddr *a2, char *buf, const char *a4) {
    //     if (*a4) {
    //       int result = 0;
    //       int v6 = strlen(a4);
    //       if (v6 > 128) return result;
    //       strcpy(v9, a4);
    //       sub_562150(a1 + 72, strlen((const char *)(a1 + 72)), (int)v9, v6);
    //       Base64Encode(v9, v6, v11);
    //       StringFormatWithBufferOverflowCheck(v10, "\\validate\\%s", v11);
    //       v7 = buf;
    //       sub_562710((SOCKET *)a1, a2, buf, v10);
    //     } else {
    //       v7 = buf;
    //     }
    //     StringFormatWithBufferOverflowCheck(v10, aFinal);
    //     sub_562710((SOCKET *)a1, a2, v7, v10);
    //     return sub_562610((SOCKET *)a1, a2, v7);
    //   }
    // UNRESOLVED: Content of the final segment string aFinal (global 0x005E4EAC) is not present in this packet.
    // UNRESOLVED: Purpose of the data at object offset a1 + 72 and what sub_562150 does with it is unknown.
    // UNRESOLVED: Claim that this is player/session validation on the game networking path is a DERIVED hypothesis, not packet evidence.
}
