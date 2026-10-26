// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563080
// Canonical corpus name: CreateUdpBroadcastSocket
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CreateUdpBroadcastSocket_00563080.c

void UnknownObject::CreateUdpBroadcastSocket()
{
    // Creates a UDP datagram socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP), stores the resulting handle at this+0x88, then enables the SO_BROADCAST socket option. Returns a failure indicator (1) if socket() returns -1 or setsockopt() returns non-zero, otherwise 0. Invoked during the multi-stage initialization chain by MultiStageInitializationChainWithErrorChecking (00563020).
    // ASSIGNMENT: Set the option buffer optval to 1 (the SO_BROADCAST enable value) before the setsockopt call. [source:raw]
    // CALL: Call socket(2, 2, 17) to create a UDP datagram socket (AF_INET=2, SOCK_DGRAM=2, IPPROTO_UDP=17) and store the result in v2. [callee:0x00598648, source:raw]
    // ASSIGNMENT: Store the socket handle v2 into the socket field at this+0x88 (this[34]). [field:this:0x00000088, source:raw]
    // CALL: Call setsockopt(v2, 0xFFFF, 32, optval, 4) to enable SO_BROADCAST at level 0xFFFF (SOL_SOCKET) with optname 32. [callee:0x0059868A, source:raw]
    // RETURN: Return v2 == -1 || setsockopt-result != 0, i.e. 1 (failure) when socket creation or option setting failed, else 0 (success). [source:raw]
    // CALL: Invoked by MultiStageInitializationChainWithErrorChecking (00563020) as part of the initialization sequence. [caller:0x00563020, source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_563080(_DWORD *this) {
    //     SOCKET s;
    //     char optval[4] = {1};
    //     s = socket(2, 2, 17);
    //     this[34] = s;
    //     return s == -1 || setsockopt(s, 0xFFFF, 32, optval, 4) != 0;
    //   }
    // UNRESOLVED: Identity of the owning object is unknown; only the socket handle field at this+0x88 is evidenced.
    // UNRESOLVED: Which network configuration (broadcast address/port) uses this socket is established by the caller, not this function.
}
