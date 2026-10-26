// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561E30
// Canonical corpus name: NetworkPacketReceive
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkPacketReceive_00561e30.c

void UnknownObject::NetworkPacketReceive()
{
    // Polls the UDP socket (this+0x0) for incoming packets. Gated on the enable flag this+0xE4; when zero the function returns the flag value without touching the socket. Otherwise it builds a single-socket fd_set and loops on select() with a zero timeout. For every readable socket it calls recvfrom() into the global buffer buf (max 255 bytes), null-terminates the received data, and dispatches the packet via FilePathNameLookup with the sender address. The loop breaks when select returns -1 or 0, and the last select result (or the flag value) is returned.
    // GUARD: The receive loop runs only when the flag this+0xE4 is non-zero; otherwise the function returns the flag value unchanged [field:this:0x000000E4, source:raw]
    // ASSIGNMENT: Initializes the poll state: fromlen set to 16, zero timeout, and a single-entry fd_set built from the socket at this+0x0 [field:this:0x00000000, source:raw]
    // LOOP: Polling loop: select(64, &readfds, 0, 0, &timeout) with zero timeout; breaks when select returns -1 or 0 [callee:0x00598654, field:this:0x00000000, source:raw]
    // CALL: Receives one packet: recvfrom(this+0x0 socket, buf, 255, 0, &from, &fromlen) [callee:0x0059864E, global:0x008CEF80, field:this:0x00000000, source:raw]
    // ASSIGNMENT: When recvfrom returns a non-error length v4, the buffer is null-terminated: buf[v4] = 0 [global:0x008CEF80, source:raw]
    // CALL: Dispatches the received packet data via FilePathNameLookup(v4, &from) using the sender address [callee:0x005622C0, global:0x008CEF80, source:raw]
    // RETURN: Returns the last select() result, or the this+0xE4 flag value when the guard failed [callee:0x00598654, field:this:0x000000E4, source:raw]

    // Conservative worker pseudocode:
    //   fromlen = 16;
    //   timeout.tv_sec = 0; timeout.tv_usec = 0;
    //   result = this+0xE4;
    //   if (result) {
    //     readfds.fd_count = 1;
    //     readfds.fd_array[0] = *this;
    //     while (1) {
    //       result = select(64, &readfds, 0, 0, &timeout);
    //       if (result == -1 || result == 0) break;
    //       n = recvfrom(*this, buf, 255, 0, &from, &fromlen);
    //       if (n != -1) {
    //         buf[n] = 0;
    //         FilePathNameLookup(n, &from);
    //       }
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Globals byte_FF00000000005435, byte_FF00000000005436, byte_FF00000000005438 and byte_FF00000000005439 are flagged as written by packet facts but do not appear in the raw decompiled body; their 0xFF-prefixed addresses look like decompiler artifacts
    // UNRESOLVED: The meaning of the flag at this+0xE4 (socket bound vs. receive enabled) and the object type behind this SOCKET pointer are not established
    // UNRESOLVED: select()'s first argument (64) is larger than the fd_set count and is unverified as meaningful
}
