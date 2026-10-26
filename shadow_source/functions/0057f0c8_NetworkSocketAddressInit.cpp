// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057F0C8
// Canonical corpus name: NetworkSocketAddressInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkSocketAddressInit_0057f0c8.c

void UnknownObject::NetworkSocketAddressInit()
{
    // Builds a sockaddr_in from an IP string and the owning object's port, then connects. Pre-fills the address buffer with AF_INET (2), address INADDR_ANY and port 0 in network byte order via htonl/htons; parses the dotted-quad IP with inet_addr. An invalid IP (-1) dispatches the vtable slot +92 error handler on the a2 object and returns 1. On success the parsed address and the port read from the a2[1160] word are stored, a network packet is built with NetworkPacketConstructor using the context field at a1+0x48, and the connection is issued under a mutex via ThreadSafeCallWithMutex.
    // GUARD: Null guard on a3 (sockaddr buffer): when a3 is 0 the AF_INET pre-initialization is skipped and a3 is left as 0 [source:raw]
    // ASSIGNMENT: Pre-fill sockaddr: family 2 (AF_INET) at a3+0, address htonl(0) at a3+4, and port htons(0) at a3+2 [global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // CALL: inet_addr(a4) parses the dotted-quad IP string into binary network order; result v18 gates the branch [global:0x0059E2F0, source:raw]
    // GUARD: Invalid-IP guard: when v18 == -1 (INADDR_NONE) the success path is skipped and the error handler runs [source:raw]
    // CALL: Error path: indirect thiscall of the method at vtable slot +92 of the a2 object with a1 as argument, then the function returns 1 [source:raw]
    // ASSIGNMENT: On success write the parsed address v18 at a3+4 and the port read from the a2[1160] word at a3+2, replacing the placeholder port [source:raw]
    // CALL: NetworkPacketConstructor(*(a1+72), a3) builds the connection packet from the context field at a1+0x48 and the filled sockaddr [callee:0x0057AFA0, field:this:0x00000048, source:raw]
    // CALL: ThreadSafeCallWithMutex(a1) issues the connection call under a mutex on the context object [callee:0x00584C70, source:raw]
    // RETURN: Success path returns v20, the decompiler's [ebp-38h] frame slot (stack artifact); the invalid-IP path returns 1 [source:raw]

    // Conservative worker pseudocode:
    //   if (a3) { *(WORD*)a3 = 2; *(DWORD*)(a3+4) = htonl(0); *(WORD*)(a3+2) = htons(0); } else a3 = 0;
    //   v18 = inet_addr(a4);
    //   if (v18 == -1) { (*(vtable(a2) + 92))(a2, a1); return 1; }
    //   *(DWORD*)(a3+4) = v18; *(WORD*)(a3+2) = a2[1160];
    //   NetworkPacketConstructor(*(DWORD*)(a1+0x48), a3);
    //   ThreadSafeCallWithMutex(a1);
    //   return v20;   /* [ebp-38h] frame artifact * /
    // UNRESOLVED: The success-path return value v20 is the decompiler's [ebp-38h] frame slot, not a real program value; its content is unknown
    // UNRESOLVED: a2 is the owning object (vtable at a2+0); the identity of the vtable slot +92 error method and the layout of the a1 context are not documented in this packet
    // UNRESOLVED: When a3 is null the later writes at a3+4 and a3+2 would target address 0; the caller contract guaranteeing a non-null a3 on the success path is not evident from this packet
    // UNRESOLVED: The port source a2[1160] is a packet-decimal word index into the owning object, not a named field
}
