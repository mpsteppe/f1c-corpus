// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B9A0
// Canonical corpus name: SocketAddressResolution
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SocketAddressResolution_0057b9a0.c

void UnknownObject::SocketAddressResolution()
{
    // Resolves both ends of a connected socket into a two-entry sockaddr array. Initializes the address-length variable to 16, calls getpeername to fill name[0] with the peer address, then calls getsockname to fill name[1] with the local address. Returns true only when both calls succeed (each returning 0).
    // ASSIGNMENT: Initialize the address-length variable to 16 (bytes, the size of a sockaddr). [source:raw]
    // CALL: Call getpeername(socket s, name, &namelen) and record whether it returned 0 (success). [global:0x0059E31C, source:raw]
    // CALL: Call getsockname(socket s, name + 1, &namelen) to resolve the local address into the second sockaddr slot. [global:0x0059E2D0, source:raw]
    // RETURN: Return true only when getsockname returned 0 and the earlier getpeername call also returned 0. [global:0x0059E2D0, global:0x0059E31C, source:raw]

    // Conservative worker pseudocode:
    //   bool SocketAddressResolution(sockaddr* name, SOCKET s) {
    //     int namelen = 16;
    //     bool peer_ok = getpeername(s, &name[0], &namelen) == 0;
    //     return getsockname(s, &name[1], &namelen) == 0 && peer_ok;
    //   }
    // UNRESOLVED: The owning class of the socket and the caller's use of the resolved peer/local addresses in sub_57CB50 are not evidenced by the packet.
    // UNRESOLVED: Whether the two-entry sockaddr array lives in the caller's buffer and whether the returned addresses feed connection identification are not established here.
}
