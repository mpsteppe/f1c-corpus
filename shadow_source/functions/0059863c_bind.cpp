// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059863C
// Canonical corpus name: bind
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/bind_0059863c.c

void UnknownObject::bind()
{
    // Import thunk for the Winsock bind() function. Forwards (s, name, namelen) unchanged to the __imp_bind import at 0x0059E2D4 and returns the resulting error code. Called by the networking layer: sub_561BF0.
    // CALL: Forwards (s, name, namelen) unchanged through the __imp_bind import at 0x0059E2D4 [global:0x0059E2D4, source:raw, abi:lead]
    // RETURN: Returns the error code produced by the imported bind() call [source:raw, function:0x0059863C]
    // CALL: Called by sub_561BF0 [caller:0x00561BF0, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall bind(SOCKET s, const struct sockaddr *name, int namelen) {
    //       return __imp_bind(s, name, namelen);
    //   }
}
