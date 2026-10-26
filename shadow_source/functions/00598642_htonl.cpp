// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598642
// Canonical corpus name: htonl
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/htonl_00598642.c

void UnknownObject::htonl()
{
    // Import thunk for the Winsock htonl() function. Forwards (hostlong) unchanged to the __imp_htonl import at 0x0059E2D8 and returns the network-byte-order result. Called by the networking layer: sub_561BF0.
    // CALL: Forwards (hostlong) unchanged through the __imp_htonl import at 0x0059E2D8 [global:0x0059E2D8, source:raw, abi:lead]
    // RETURN: Returns the network-byte-order result produced by the imported htonl() call [source:raw, function:0x00598642]
    // CALL: Called by sub_561BF0 [caller:0x00561BF0, source:raw]

    // Conservative worker pseudocode:
    //   u_long __stdcall htonl(u_long hostlong) {
    //       return __imp_htonl(hostlong);
    //   }
}
