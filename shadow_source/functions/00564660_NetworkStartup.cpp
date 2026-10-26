// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564660
// Canonical corpus name: NetworkStartup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkStartup_00564660.c

void UnknownObject::NetworkStartup()
{
    // One-call Winsock bootstrap: declares a local WSAData structure on the stack and returns the result of WSAStartup(0x101, &WSAData), i.e. a request for Winsock version 1.1. The caller's result value is the Winsock startup error/status code.
    // CALL: Call WSAStartup with requested version 0x101 (Winsock 1.1) and a pointer to a local WSAData structure. [abi:lead, callee:0x0059869C, function:0x00564660, source:raw]
    // RETURN: Return the WSAStartup result code (0 on success, nonzero Winsock error otherwise). [source:raw]
    // CALL: Invoked by sub_561BF0 (0x00561BF0) and MemoryObjectAllocator (0x00562B50) as part of network/allocator startup. [caller:0x00561BF0, caller:0x00562B50]

    // Conservative worker pseudocode:
    //   // Bootstrap the Winsock library.
    //   WSADATA data;
    //   return WSAStartup(0x101, &data);
    // UNRESOLVED: Whether the returned WSAStartup status is checked by either caller is not evidenced in the packet.
    // UNRESOLVED: Owner object identity is UNKNOWN; the function is a free-standing initializer with no this-object evidence.
    // UNRESOLVED: The WSAData structure contents are discarded locally; no data is persisted.
}
