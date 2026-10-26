// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598636
// Canonical corpus name: getsockname
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/getsockname_00598636.c

void UnknownObject::getsockname()
{
    // Import thunk for the Winsock getsockname() function. Forwards (s, name, namelen) unchanged to the __imp_getsockname import at 0x0059E2D0 and returns the resulting error code. Called by the networking layer: sub_561BF0.
    // CALL: Forwards (s, name, namelen) unchanged through the __imp_getsockname import at 0x0059E2D0 [global:0x0059E2D0, source:raw, abi:lead]
    // RETURN: Returns the error code produced by the imported getsockname() call [source:raw, function:0x00598636]
    // CALL: Called by sub_561BF0 [caller:0x00561BF0, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall getsockname(SOCKET s, struct sockaddr *name, int *namelen) {
    //       return __imp_getsockname(s, name, namelen);
    //   }
}
