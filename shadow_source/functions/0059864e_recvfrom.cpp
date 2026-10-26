// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059864E
// Canonical corpus name: recvfrom
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/recvfrom_0059864e.c

void UnknownObject::recvfrom()
{
    // Import thunk for the Winsock recvfrom() function. Forwards (s, buf, len, flags, from, fromlen) unchanged to the __imp_recvfrom import (0x0059E2E0) and returns the integer receive result. Called by the network receive path: NetworkPacketReceive (00561E30), sub_563410 and sub_563AB0.
    // CALL: Forwards (s, buf, len, flags, from, fromlen) unchanged through the __imp_recvfrom import at 0x0059E2E0 [global:0x0059E2E0, source:raw, abi:lead]
    // RETURN: Returns the integer result of the imported recvfrom() call [source:raw, function:0x0059864E]
    // CALL: Called by NetworkPacketReceive (00561E30) [caller:0x00561E30, source:raw]
    // CALL: Called by sub_563410 [caller:0x00563410, source:raw]
    // CALL: Called by sub_563AB0 [caller:0x00563AB0, source:raw]

    // Conservative worker pseudocode:
    //   return __imp_recvfrom(s, buf, len, flags, from, fromlen);
}
