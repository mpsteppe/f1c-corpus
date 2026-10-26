// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598648
// Canonical corpus name: socket
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/socket_00598648.c

void UnknownObject::socket()
{
    // Import thunk for the Winsock socket() function. Forwards (af, type, protocol) unchanged to the __imp_socket import (0x0059E2DC) and returns the resulting SOCKET handle. Called by the networking layer: sub_561BF0, SocketArrayCreate (00562D20), sub_562D90 and CreateUdpBroadcastSocket (00563080).
    // CALL: Forwards (af, type, protocol) unchanged through the __imp_socket import at 0x0059E2DC [global:0x0059E2DC, source:raw, abi:lead]
    // RETURN: Returns the SOCKET handle produced by the imported socket() call [source:raw, function:0x00598648]
    // CALL: Called by sub_561BF0 [caller:0x00561BF0, source:raw]
    // CALL: Called by SocketArrayCreate (00562D20) [caller:0x00562D20, source:raw]
    // CALL: Called by sub_562D90 [caller:0x00562D90, source:raw]
    // CALL: Called by CreateUdpBroadcastSocket (00563080) [caller:0x00563080, source:raw]

    // Conservative worker pseudocode:
    //   return __imp_socket(af, type, protocol);
}
