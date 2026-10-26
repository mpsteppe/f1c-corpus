// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562950
// Canonical corpus name: sub_562950
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562950_00562950.c

void UnknownObject::SendEchoFormatted()
{
    // Guards the length of input string a4 against the 0x546 bound, formats it as an '\echo\%s' message into a stack buffer via StringFormatWithBufferOverflowCheck, then hands the formatted message to sub_562710 along with the socket arguments and returns its result. Over-long input returns null without sending.
    // ASSIGNMENT: Initialize result to 0 (null return for the over-long path). [source:raw]
    // GUARD: Proceed only when strlen(a4) is at most 0x546; longer input returns null. [source:raw]
    // CALL: Format the '\echo\%s' pattern from global aEchoS with a4 into stack buffer v7 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005E4EA0]
    // CALL: Forward the formatted message to sub_562710(a1, a2, buf, v7). [callee:0x00562710]
    // RETURN: Return sub_562710's result when formatted, otherwise the null result from the guard path. [source:raw]

    // Conservative worker pseudocode:
    //   char *SendEchoFormatted(SOCKET *a1, const struct sockaddr *a2, char *buf, const char *a4) {
    //     char v7[1400];
    //     if (strlen(a4) <= 0x546) {
    //       StringFormatWithBufferOverflowCheck(v7, aEchoS, a4);
    //       return sub_562710(a1, a2, buf, v7);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Role of the SOCKET a1, sockaddr a2 and buf arguments in sub_562710 is unknown here.
    // UNRESOLVED: Semantics of the 0x546 length bound relative to the 1400-byte stack buffer are not established.
    // UNRESOLVED: Behavior and return contract of callee sub_562710 are unknown here.
}
