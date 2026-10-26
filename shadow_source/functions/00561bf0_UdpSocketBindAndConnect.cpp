// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561BF0
// Canonical corpus name: sub_561BF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_561BF0_00561bf0.c

void UnknownObject::UdpSocketBindAndConnect()
{
    // Creates a UDP socket (AF_INET/SOCK_DGRAM/IPPROTO_UDP), binds it to the first available local port in the range [hostshort, hostshort+100], then connects it to the GameSpy master server. Host string a2 is resolved into a sockaddr_in per candidate port; a resolved loopback address (127.0.0.1) is zeroed so the bind picks an explicit local address. On success calls sub_561D40 to prepare the socket object and returns the result of sub_561FF0(aMasterOpenspyN, 27900, object+236), which completes the master-server connection. Returns 1 if socket creation fails and 2 if binding (or getsockname when port 0 was requested) fails.
    // ASSIGNMENT: Save a1 into v10 and, if a1 is non-null, write 0 through it (output-initialization) [source:raw]
    // CALL: Call NetworkStartup() to initialize the Winsock/network subsystem [source:raw, callee:0x00564660]
    // CALL: Create socket with socket(2, 2, 17) = AF_INET, SOCK_DGRAM, IPPROTO_UDP [source:raw, callee:0x00598648]
    // GUARD: If socket() returned -1 (INVALID_SOCKET), return 1 immediately [source:raw]
    // ASSIGNMENT: Initialize the port scan: v12 = hostshort (start of the bind range) [source:raw]
    // CALL: Build sockaddr_in for the current candidate port: sub_562010(a2, v12, &name, 0) [source:raw, callee:0x00562010]
    // CALL: Compute htonl(0x7F000001u), the loopback address in network byte order [source:raw, callee:0x00598642]
    // GUARD: If the resolved address equals loopback, zero the address field so the bind uses the local interface rather than 127.0.0.1 [source:raw]
    // CALL: Bind the socket to the candidate address/port: bind(v11, &name, 16) [source:raw, callee:0x0059863C]
    // LOOP: While bind fails, increment the candidate port v12 and retry until a bind succeeds or v12 reaches hostshort+100 [source:raw]
    // GUARD: If the whole bind range failed (v12 advanced past the range, non-zero), return 2 [source:raw]
    // ASSIGNMENT: When the requested port was 0 (v12 == 0), set namelen to 16 and call getsockname(v11, &name, &namelen) to learn the OS-assigned port; return 2 if it fails [source:raw, callee:0x00598636]
    // CALL: Read the bound port back with ntohs(*(u_short*)name.sa_data) (result is discarded) [source:raw, callee:0x00598630]
    // CALL: Prepare the socket object: sub_561D40(v11, v11, a4, a5, a6, a7, a8, a9, a10) [source:raw, callee:0x00561D40]
    // ASSIGNMENT: If no output pointer was supplied, use the default object: v10 = &off_5E4DFC [source:raw, global:0x005E4DFC]
    // RETURN: Complete the master-server connection: return sub_561FF0(v11, aMasterOpenspyN, 27900, *v10 + 236) [source:raw, callee:0x00561FF0, global:0x005E4E00]

    // Conservative worker pseudocode:
    //   v10 = a1;
    //   if (a1) *a1 = 0;
    //   NetworkStartup();
    //   s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    //   if (s == -1) return 1;
    //   port = hostshort;
    //   for (;;) {
    //       sub_562010(a2, port, &name, 0);
    //       if (*(uint32_t*)&name.sa_data[2] == htonl(0x7F000001u))
    //           *(uint32_t*)&name.sa_data[2] = 0;
    //       if (bind(s, &name, 16) == 0) break;
    //       if (++port >= hostshort + 100) {
    //           if (port) return 2;
    //       }
    //   }
    //   if (port == 0) {
    //       int len = 16;
    //       if (getsockname(s, &name, &len)) return 2;
    //       ntohs(*(u_short*)name.sa_data);
    //   }
    //   sub_561D40(s, s, a4, a5, a6, a7, a8, a9, a10);
    //   if (!v10) v10 = &off_5E4DFC;
    //   return sub_561FF0(s, aMasterOpenspyN, 27900, *v10 + 236);
    // UNRESOLVED: Arguments a4..a10 are passed through verbatim to sub_561D40 with unknown meaning.
    // UNRESOLVED: The value *v10 + 236 handed to sub_561FF0 is a field at offset 236 of the network socket object; its identity is unknown.
    // UNRESOLVED: The ntohs(getsockname) result is computed and discarded; the port-0 branch appears vestigial.
    // UNRESOLVED: Return codes 1 and 2 distinguish socket-creation vs bind/getsockname failure, but the caller's interpretation is not evidenced here.
    // UNRESOLVED: The overflow check on hostshort + 100 wraps the candidate port in an undefined way; semantics of the unsigned-overflow path are not resolvable from the raw text.
}
