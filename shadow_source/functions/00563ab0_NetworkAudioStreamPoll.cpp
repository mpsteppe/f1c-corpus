// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563AB0
// Canonical corpus name: sub_563AB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_563AB0_00563ab0.c

void UnknownObject::NetworkAudioStreamPoll()
{
    // Network audio stream receiver/poller. Builds an fd_set from the active entries of a UDP socket array (28-byte stride, capped at 64), polls readability with a zero-timeout select, recvfroms datagrams from verified peers, feeds them into the audio mixer, detects a completion marker to fire a callback, deactivates idle sockets after 3000 ms, and either tears the socket array down (shutdown flag set or all packets sent with no active sockets) or activates new sources from an interpolation pool by sending a handshake datagram.
    // ASSIGNMENT: Initialize the poll state: reset the active/ready counters, zero the select timeout, set the peer address length to 16, and read the socket count from this+0x6C. [field:this:0x0000006C, source:raw]
    // GUARD: When the socket count at this+0x6C is zero the whole network phase is skipped and the function returns 0. [guard:0, field:this:0x0000006C]
    // LOOP: Build the select set: iterate the socket array rooted at this+0x8 with a 28-byte entry stride, adding active entries (flag at entry+4 non-zero) to the fd_set up to the 64-slot limit. [field:this:0x00000008, field:*(this+0x8):0x00000000, field:*(this+0x8):0x00000004]
    // CALL: Poll readability with a zero-timeout select over up to 64 sockets. [callee:0x00598654]
    // CALL: For each readable socket (fd-set membership test), verify the datagram source matches the expected address/port stored at entry+16 and entry+14, receive up to 1499 bytes with recvfrom, and deactivate the entry (clear the entry+4 flag) when recvfrom reports an error. [callee:0x00598690, callee:0x0059864E, field:*(this+0x8):0x00000000, field:*(this+0x8):0x00000004]
    // CALL: Search the received buffer for the completion marker literal and feed the datagram into the audio mixer update loop. [callee:0x00587C20, callee:0x00564390, global:0x005E4EAC]
    // CALL: When the completion marker is found, compute the reference total via sub_563E70, invoke the completion callback held at this+0x78 with this+0x7C and a percentage derived from this+0x70, and deactivate the entry. [callee:0x00563E70, field:this:0x00000078, field:this:0x0000007C, field:this:0x00000070]
    // LOOP: Timeout sweep: deactivate any entry whose last-activity timestamp (entry+8) is more than 3000 ms old by GetTickCount. [callee:0x00564640, field:this:0x00000008, field:*(this+0x8):0x00000004]
    // GUARD: Cleanup decision: either the shutdown flag at this+0x74 is set, or the activated count at this+0x70 reached the reference total from this+0x4 (computed by sub_563E70) with no sockets still active. [callee:0x00563E70, field:this:0x00000074, field:this:0x00000070, field:this:0x00000004]
    // CALL: Tear down the socket array with NetworkSocketArrayCleanup and reset the audio value with AudioValueSetterCall. [callee:0x00563DC0, callee:0x00562FE0]
    // LOOP: Activation phase: while the activated count at this+0x70 is below the reference total from this+0x4, take the next source from the interpolation pool, build its address and port via the string/short helpers and inet_addr/htons, increment the count, record the activation timestamp, and send the initial handshake datagram through sendto using the payload and size lookup tables. [callee:0x005648B0, callee:0x00564490, callee:0x005644A0, callee:0x00598666, callee:0x0059866C, callee:0x00598672, callee:0x00564640, global:0x005B89A0, global:0x005E4F38, field:this:0x00000004, field:this:0x00000070, field:this:0x00000008]
    // RETURN: Return 0 after processing, from both the cleanup and the activation paths. [source:raw]

    // Conservative worker pseudocode:
    //   // Build fd_set from active socket entries at this+8 (28-byte stride), cap 64.
    //   // select(64, readfds, 0, 0, zero-timeout); on data verify peer addr/port, recvfrom up to 1499 bytes.
    //   // Feed buffer into the audio mixer; detect the completion marker; fire the callback; deactivate entry.
    //   // Deactivate entries idle over 3000 ms.
    //   // If shutdown flag set or all packets sent with no active sockets: cleanup array and reset audio value.
    //   // Else activate new sources from the interpolation pool (addr/port + sendto handshake); return 0.
    // UNRESOLVED: The five byte_FF hardware/memory-mapped globals are not referenced in the visible source text; their role in the receive/send path is unestablished.
    // UNRESOLVED: The concrete targets of the indirect completion callback (this+0x78) and of the audio mixer update loop are unknown.
    // UNRESOLVED: The 28-byte entry layout and the interpolation-pool payload/size lookup tables are inferred from access patterns, not confirmed types.
}
