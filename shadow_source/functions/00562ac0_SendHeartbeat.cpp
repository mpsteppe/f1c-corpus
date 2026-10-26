// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562AC0
// Canonical corpus name: sub_562AC0
// Owner: NetworkHeartbeatSender [DERIVED]
// Raw source: functions/sub_562AC0_00562ac0.c

void NetworkHeartbeatSender::SendHeartbeat()
{
    // Composes and sends a UDP heartbeat message. Builds the header "\heartbeat\%d\gamename\%s" (format string at 0x005E4ED8) into a 256-byte buffer from the game id at a1+228 and game name at a1+8; when a2 is non-zero appends a "\statechanged\%d" segment (format string at 0x005E4EC4). Sends the buffer via sendto using the socket at a1+4 against the peer sockaddr at a1+236 with length 16, then records the send time by storing GetTickCount() into a1+216 and returns it. Called from TickCountComparisonHandleInactivityTimeout (00561ed0).
    // CALL: Build the heartbeat header into buf via StringFormatWithBufferOverflowCheck with format string "\heartbeat\%d\gamename\%s" (0x005E4ED8), game id from a1+228 and game name from a1+8. [callee:0x0058815F, global:0x005E4ED8]
    // GUARD: If a2 is non-zero, append the "\statechanged\%d" segment (format string 0x005E4EC4) to the message buffer at the current strlen position. [callee:0x0058815F, global:0x005E4EC4]
    // CALL: Send the assembled message via sendto using the socket at a1+4, the buffer, its strlen, zero flags, the peer sockaddr at a1+236 and length 16. [callee:0x00598672]
    // ASSIGNMENT: Record the send timestamp: store GetTickCount() into a1+216. [callee:0x00564640]
    // RETURN: Return the recorded tick count. [function:0x00562AC0, source:raw]

    // Conservative worker pseudocode:
    //   DWORD SendHeartbeat(void *a1, int state) {
    //     char buf[256];
    //     StringFormatWithBufferOverflowCheck(buf, "\\heartbeat\\%d\\gamename\\%s",
    //       *(_DWORD *)((char *)a1 + 228), (char *)a1 + 8);
    //     if (state)
    //       StringFormatWithBufferOverflowCheck(buf + strlen(buf), "\\statechanged\\%d", state);
    //     sendto(*(_DWORD *)((char *)a1 + 4), buf, strlen(buf), 0,
    //       (struct sockaddr *)((char *)a1 + 236), 16);
    //     *(_DWORD *)((char *)a1 + 216) = GetTickCount();
    //     return *(_DWORD *)((char *)a1 + 216);
    //   }
    // UNRESOLVED: Field semantics at a1+4 (socket), a1+216 (last-send timestamp), a1+228 (game id) and a1+236 (peer sockaddr) are inferred from call usage, not from named packet fields.
    // UNRESOLVED: Payload safety depends on the 256-byte buf and strlen-based sizing; no explicit bound beyond that is visible.
}
