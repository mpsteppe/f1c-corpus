// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005630D0
// Canonical corpus name: sub_5630D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5630D0_005630d0.c

void UnknownObject::UdpBroadcastStatusSend()
{
    // Broadcasts an 8-byte status payload (aStatus) as a UDP datagram over a contiguous range of ports: iterates the port counter from a2 up to a3 stepping by a4, converts each port with htons, fills a sockaddr with the broadcast address, and calls sendto on the socket handle stored at a1+136. After the loop it calls AudioValueSetterCall(a1, 2) and records GetTickCount() at a1+140 before returning 0.
    // ASSIGNMENT: Initialize v4 = a2 as the port loop counter, set to.sa_family = 2 (AF_INET), and write the broadcast address -1 into the dword at to.sa_data+2 (255.255.255.255). [source:raw]
    // LOOP: Iterate v4 over the port range while v4 <= a3, incrementing v4 by a4 each pass. [source:raw]
    // CALL: Convert the current port to network byte order: v6 = htons(v4). [callee:0x0059866C, source:raw]
    // ASSIGNMENT: Load the SOCKET handle v7 = *(DWORD*)(a1 + 136) and store v6 as the port word in to.sa_data. [source:raw]
    // CALL: Send the 8-byte status string aStatus to the broadcast address on the current port: sendto(v7, aStatus, 8, 0, &to, 16). [callee:0x00598672, global:0x005E4F50, source:raw]
    // CALL: After the broadcast loop, notify the audio layer: AudioValueSetterCall(a1, 2). [callee:0x00562FE0, source:raw]
    // ASSIGNMENT: Timestamp the last broadcast: *(DWORD*)(a1 + 140) = GetTickCount(). [callee:0x00564640, source:raw]
    // RETURN: Return 0 unconditionally as the completion status. [function:0x005630D0, source:raw]
    // CALL: Invoked by MultiStageInitializationChainWithErrorChecking (0x00563020) as part of startup, consistent with LAN discovery/heartbeat broadcasting. [caller:0x00563020, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5630D0(int obj, u_short start_port, int end_port, __int16 step) {
    //     u_short port = start_port;
    //     sockaddr to;
    //     to.sa_family = 2;
    //     *(DWORD*)&to.sa_data[2] = -1;
    //     for (; port <= end_port; port += step) {
    //       u_short nport = htons(port);
    //       SOCKET sock = *(DWORD*)(obj + 136);
    //       *(WORD*)to.sa_data = nport;
    //       sendto(sock, aStatus, 8, 0, &to, 16);
    //     }
    //     AudioValueSetterCall(obj, 2);
    //     *(DWORD*)(obj + 140) = GetTickCount();
    //     return 0;
    //   }
    // UNRESOLVED: The packet globals byte_FF00000000005430 and byte_FF00000000005431 are absent from the raw C and look like decompiler artifacts of the sockaddr layout; their write semantics are not reconstructed.
    // UNRESOLVED: Owner and layout of the object at a1 (SOCKET at +136, tick timestamp at +140) are unknown beyond these two offsets.
    // UNRESOLVED: The exact content of the aStatus payload and the purpose of the AudioValueSetterCall(2) notification are external.
}
