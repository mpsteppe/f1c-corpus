// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057E860
// Canonical corpus name: UDPSocketBind
// Owner: NetworkSocket [DERIVED]
// Raw source: functions/UDPSocketBind_0057e860.c

void NetworkSocket::UDPSocketBind()
{
    // UDP socket bind entry point. Builds a 16-byte sockaddr_in in the local buffer v4 (address family AF_INET = 2, INADDR_ANY via htonl(0), port 0 via htons(0)) and copies it to the persistent socket-address field at this+0xA84 (this+673 DWORDs) via Copy4DwordsStructToStruct. Then dispatches on sub_586CA0(a2): a non-zero result selects the query-matching bind path NetworkPacketSendWithQueryMatching(this, a2, v4), otherwise the direct bind path sub_57D6C0(this, a2, v4); the chosen path's result is returned.
    // CALCULATION: Build the sockaddr_in in v4: LOWORD = 2 (AF_INET), INADDR_ANY via htonl(0), and port 0 via htons(0). [global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // CALL: Copy the 16-byte sockaddr_in from v4 into the persistent socket-address field at this+0xA84 (this + 673 DWORDs) via Copy4DwordsStructToStruct. [callee:0x0057B9F0, source:raw]
    // GUARD: Dispatch on the byte result of sub_586CA0(a2): non-zero selects the query-matching bind path, zero selects the direct bind path. [callee:0x00586CA0, source:raw]
    // CALL: When sub_586CA0(a2) is non-zero, call NetworkPacketSendWithQueryMatching(this, a2, v4) as the query-matching bind path. [callee:0x0057D8D0, source:raw]
    // CALL: Otherwise call sub_57D6C0(this, a2, v4) as the direct bind path. [callee:0x0057D6C0, source:raw]
    // RETURN: Return the result of whichever bind path was dispatched. [function:0x0057E860, source:raw]

    // Conservative worker pseudocode:
    //   char sub_57E860(_DWORD *this, unsigned int a2) {
    //     _DWORD sockaddr[4];
    //     LOWORD(sockaddr[0]) = 2;            /* AF_INET * /
    //     sockaddr[1] = htonl(0);            /* INADDR_ANY * /
    //     HIWORD(sockaddr[0]) = htons(0);    /* port 0 * /
    //     Copy4DwordsStructToStruct(this + 673, sockaddr);
    //     if (sub_586CA0(a2))
    //       return NetworkPacketSendWithQueryMatching(this, a2, sockaddr);
    //     return sub_57D6C0(this, a2, sockaddr);
    //   }
    // UNRESOLVED: The selection criterion inside sub_586CA0(a2) that chooses query-matching versus direct bind is not known.
    // UNRESOLVED: Whether this+0xA84 is a persistent socket-address field consumed by later send/receive paths is unverified.
    // UNRESOLVED: Owner identity is inferred only from the legacy ABI lead 'UDP_Socket_Bind'; the owning class is unknown.
}
