// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B910
// Canonical corpus name: SockAddrPairInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SockAddrPairInit_0057b910.c

void UnknownObject::SockAddrPairInit()
{
    // Initializes two socket address structures: the first at byte offsets 0x0 (family word set to 2, i.e. AF_INET), 0x2 (port set to 0 via htons), 0x4 (IP dword set to 0 via htonl); the second at byte offsets 0x10 (family word set to 2), 0x12 (port set to 0 via htons), 0x14 (IP dword set to 0 via htonl). All values use network byte order. Called by SocketAddressInitialization (0x0057B8C0). Returns the htons(0) port value (0).
    // ASSIGNMENT: Set the first address-family word at this+0x0 to 2 (AF_INET). [field:this:0x00000000, source:raw]
    // CALCULATION: Set the first port word at this+0x2 to htons(0) via the htons import. [field:this:0x00000002, global:0x0059E2F4, source:raw]
    // CALCULATION: Set the first IP dword at this+0x4 to htonl(0) via the htonl import. [field:this:0x00000004, global:0x0059E2D8, source:raw]
    // ASSIGNMENT: Set the second address-family word at this+0x10 to 2 (AF_INET). [field:this:0x00000010, source:raw]
    // CALCULATION: Set the second port word at this+0x12 to htons(0) via the htons import. [field:this:0x00000012, global:0x0059E2F4, source:raw]
    // CALCULATION: Set the second IP dword at this+0x14 to htonl(0) via the htonl import. [field:this:0x00000014, global:0x0059E2D8, source:raw]
    // RETURN: Return the htons(0) port value (0). [function:0x0057B910, source:raw]

    // Conservative worker pseudocode:
    //   *(WORD*)(this + 0x0) = 2;            // AF_INET
    //   *(WORD*)(this + 0x2) = htons(0);     // port 0
    //   *(DWORD*)(this + 0x4) = htonl(0);    // IP 0
    //   *(WORD*)(this + 0x10) = 2;           // AF_INET
    //   *(WORD*)(this + 0x12) = htons(0);    // port 0
    //   *(DWORD*)(this + 0x14) = htonl(0);   // IP 0
    //   return htons(0);
    // UNRESOLVED: The owning object that holds the two sockaddr structures is not evidenced by the packet.
    // UNRESOLVED: The layout gap between the first structure (0x0-0x8) and the second (0x10 onward) implies an intervening field that is not evidenced by the packet.
}
