// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B8C0
// Canonical corpus name: SocketAddressInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SocketAddressInitialization_0057b8c0.c

void UnknownObject::SocketAddressInitialization()
{
    // Initializes a local/remote socket address pair: writes AF_INET (2) into both family words at offsets 0x0 and 0x10, stores network-byte-order zero IPs at 0x4 and 0x14 via htonl(0), zero ports at 0x2 and 0x12 via htons(0), then delegates remaining setup to SockAddrPairInit.
    // ASSIGNMENT: Set first socket address family word at this+0x0 to 2 (AF_INET). [field:this:0x00000000]
    // ASSIGNMENT: Store first IP address at this+0x4 as htonl(0) (network byte order zero). [field:this:0x00000004, global:0x0059E2D8]
    // ASSIGNMENT: Store first port at this+0x2 as htons(0) (network byte order zero). [field:this:0x00000002, global:0x0059E2F4]
    // ASSIGNMENT: Set second socket address family word at this+0x10 to 2 (AF_INET). [field:this:0x00000010]
    // ASSIGNMENT: Store second IP address at this+0x14 as htonl(0) (network byte order zero). [field:this:0x00000014, global:0x0059E2D8]
    // ASSIGNMENT: Store second port at this+0x12 as htons(0) (network byte order zero). [field:this:0x00000012, global:0x0059E2F4]
    // CALL: Delegate further socket address pair setup to SockAddrPairInit, passing this. [callee:0x0057B910]
    // CALL: Called by sub_57BA10 as part of socket address construction. [caller:0x0057BA10]
    // RETURN: Return the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void SocketAddressInitialization(SockAddrPair* this) {
    //     this->family_first = AF_INET;         // 2 at +0x0
    //     this->port_first   = htons(0);       // +0x2
    //     this->ip_first     = htonl(0);       // +0x4
    //     this->family_second = AF_INET;       // 2 at +0x10
    //     this->port_second   = htons(0);      // +0x12
    //     this->ip_second     = htonl(0);      // +0x14
    //     SockAddrPairInit(this);
    //     return this;
    //   }
    // UNRESOLVED: SockAddrPairInit (0x0057B910) payload is out of scope; this function only delegates to it.
}
