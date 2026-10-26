// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562D90
// Canonical corpus name: sub_562D90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562D90_00562d90.c

void UnknownObject::TcpSocketConnect()
{
    // Connects a TCP socket to the host named by the global string at 0x005E4EF8 (::name) on port 0x70E4 (28900). Builds an AF_INET sockaddr, using inet_addr on the hostname and falling back to gethostbyname when that returns -1, then creates a stream socket with socket(AF_INET, SOCK_STREAM, IPPROTO_TCP) storing the handle at this[34] (offset 0x88), and connects. Returns 0 on success, 1 if socket creation failed, 2 if hostname resolution failed, 3 if connect failed (closing the socket first). Called by DeviceInitializationWithStateSetup (0x00562C90).
    // CALCULATION: Build the AF_INET sockaddr: set sa_family to 2, store htons(0x70E4) as the port in network byte order, and place the result of inet_addr(::name) into the address field. [callee:0x0059866C, callee:0x00598666, global:0x005E4EF8, source:raw]
    // GUARD: If inet_addr(::name) returned -1, fall back to resolving the host via gethostbyname(::name); if gethostbyname returns null, return error code 2 (resolution failure). [callee:0x00598666, callee:0x00598660, global:0x005E4EF8, source:raw]
    // ASSIGNMENT: On successful gethostbyname, copy the first address from the resolved host's h_addr_list into the sockaddr address field. [callee:0x00598660, source:raw]
    // CALL: Create a TCP stream socket with socket(2, 1, 6) and store the returned handle into this[34] (offset 0x88). [callee:0x00598648, field:this:0x00000088, source:raw]
    // GUARD: If socket() returned -1 (invalid socket), return error code 1 without attempting to connect. [callee:0x00598648, field:this:0x00000088, source:raw]
    // CALL: Call connect on the socket handle with the 16-byte sockaddr; when it returns 0, return 0 as success. [callee:0x00598678, source:raw]
    // CALL: On connect failure, close the socket via closesocket(this[34]) and return error code 3. [callee:0x0059865A, field:this:0x00000088, source:raw]
    // RETURN: Return the status code: 0 success, 1 socket creation failure, 2 hostname resolution failure, 3 connect failure. [function:0x00562D90, source:raw]

    // Conservative worker pseudocode:
    //   build sockaddr_in { family=2, port=htons(0x70E4), addr=inet_addr(::name) }
    //   if addr == -1: h=gethostbyname(::name); if !h return 2; addr = *h.h_addr_list[0]
    //   s = socket(2, 1, 6); this[34] = s; if s == -1 return 1
    //   if connect(s, &sockaddr, 16) == 0 return 0
    //   closesocket(this[34]); return 3
    // UNRESOLVED: The two high-address byte writes at 0xFF00000000005430 and 0xFF00000000005431 are packet evidence but never appear in the rendered raw source; their purpose is unresolved.
    // UNRESOLVED: What the stored socket handle at this[34] is later used for is not established from this packet.
}
