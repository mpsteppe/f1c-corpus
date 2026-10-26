// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059865A
// Canonical corpus name: closesocket
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/closesocket_0059865a.c

void UnknownObject::closesocket()
{
    // Import thunk for the Winsock closesocket function: takes a socket handle s and forwards the call to the imported function at __imp_closesocket (0x0059E2E8), returning the import's result. The function consists of nothing but the forwarding call.
    // CALL: Forward the socket handle: invoke __imp_closesocket(s), the imported Winsock closesocket at 0x0059E2E8. [global:0x0059E2E8, source:raw]
    // RETURN: Return the result produced by the forwarded import call. [function:0x0059865A, source:raw]
    // CALCULATION: Legacy ABI label closesocket corroborates the forwarding target as the Winsock socket-close API. [abi:lead, source:raw]
    // CALL: Invoked by SocketCloseAndCleanup (0x00561F80), sub_562D90 (0x00562D90), sub_563410 (0x00563410) and NetworkSocketArrayCleanup (0x00563DC0). [caller:0x00561F80, caller:0x00562D90, caller:0x00563410, caller:0x00563DC0, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall closesocket(SOCKET s) {
    //       return __imp_closesocket(s);
    //   }
    // UNRESOLVED: The thunk is a plain import forward; no object or module context beyond the Winsock import is evidenced.
}
