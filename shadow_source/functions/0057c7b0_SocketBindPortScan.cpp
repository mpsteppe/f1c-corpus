// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057C7B0
// Canonical corpus name: SocketBindPortScan
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SocketBindPortScan_0057c7b0.c

void UnknownObject::SocketBindPortScan()
{
    // Binds a Winsock socket s to a local port, starting at requested port a2 and, on failure, scanning forward up to 100 ports (incrementing v2). Each iteration builds a sockaddr_in with address family 2 (AF_INET), a zeroed address, and the candidate port in network byte order via htons, then calls bind with a 16-byte sockaddr. If bind succeeds, returns the bound port (network-order value). If bind fails and WSAGetLastError() is not 10022 (WSAEINVAL) and fewer than 100 attempts have been made, it retries with the next port; otherwise it returns -1.
    // ASSIGNMENT: Build the candidate socket address: set the address family to 2 (AF_INET), zero the address fields, and store the candidate port (a2+v2) into the sockaddr port slot, converted to network byte order via htons. [global:0x0059E2F4, source:raw]
    // CALL: Convert the local address 0 to network byte order via htonl before it is placed into the sockaddr. [global:0x0059E2D8, source:raw]
    // CALL: Bind the socket s to the constructed 16-byte sockaddr via bind. [global:0x0059E2D4, source:raw]
    // GUARD: On bind failure, query WSAGetLastError; if the error is not 10022 and the attempt counter has not reached 100, increment the attempt counter and retry with the next port, otherwise return -1. [global:0x0059E324, source:raw]
    // RETURN: Return the successfully bound port value; return -1 when the scan is exhausted or the error is 10022. [source:raw]

    // Conservative worker pseudocode:
    //   int SocketBindPortScan(SOCKET s, __int16 a2) {
    //     int v2 = 0;
    //     while (true) {
    //       sockaddr_in name = {};
    //       name.sin_family = 2;
    //       name.sin_port = htons(a2 + v2);
    //       if (bind(s, (sockaddr*)&name, 16) == 0) return name.sin_port;
    //       if (WSAGetLastError() != 10022 && ++v2 < 100) continue;
    //       return -1;
    //     }
    //   }
    // UNRESOLVED: The constants 10022 (WSAEINVAL) and the 100-port scan limit are taken verbatim from the raw source; their policy rationale is not stated.
    // UNRESOLVED: The sockaddr layout and the role of the stack fields v5 and v6 initialized into sa_data are only partially determined from the raw source.
    // UNRESOLVED: byte_FF00000000005430 and byte_FF00000000005431 are flagged by the packet as written but resolve outside the normal data range (bad-address artifacts); the instruction that touches them is not identified.
}
