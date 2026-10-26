// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562E30
// Canonical corpus name: sub_562E30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_562E30_00562e30.c

void UnknownObject::SendGameServerListQuery()
{
    // TCP session handshake and server-list query. Receives up to 255 bytes on the socket at a1+136, validates the response against the "secure" string via sub_587C20, XOR-decodes 6 bytes against the per-session key at a1+44, then sends a \gamename\...\gamever\...\validate\...\enctype\2\...\queryid\1.1\ handshake line. It then selects a list argument (aGroups for state 6, aInfo2 for state 7, off_5E4FD4 otherwise) and sends a \list\...\gamename\...\final\ query, adding a where clause from a2 when present. On success signals completion via AudioValueSetterCall(a1, 1) and returns 0; returns 3 on network failure and 5 on validation failure.
    // CALL: recv on the socket at a1+136 into buf with max length 255 and flags 0. [callee:0x00598684, source:raw]
    // GUARD: When recv returns -1, return 3 (network failure). [source:raw]
    // ASSIGNMENT: Null-terminate the received data: buf[v3] = 0. [source:raw]
    // CALL: Parse/decode the received buffer with sub_587C20(buf, aSecure). [callee:0x00587C20, global:0x005E503C, source:raw]
    // GUARD: When sub_587C20 returns 0 (failed validation), return 5. [source:raw]
    // CALL: Decode 6 bytes at the parsed offset v4+8 via sub_564C70. [callee:0x00564C70, source:raw]
    // LOOP: XOR each of the 6 decoded bytes with the per-session key bytes at a1+44. [source:raw]
    // CALL: Pad the validation token buffer v14 with spaces via PadOutputWithSpacesUpToLengthLimit. [callee:0x00564B80, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck builds the gamename/gamever/location/validate/enctype/queryid handshake line into buf from a1+76, a18, and the padded v14. [callee:0x0058815F, global:0x005E4FE8, global:0x005E5038, source:raw]
    // CALL: send the handshake line on the socket at a1+136. [callee:0x0059867E, source:raw]
    // GUARD: When send returns -1 or 0, return 3 (network failure). [source:raw]
    // STATE_TRANSITION: Select the list argument from the state value at a1+144: 6 selects aGroups and clears a1+1460, 7 selects aInfo2 and clears a1+1460, otherwise off_5E4FD4 is used. [global:0x005E4FE0, global:0x005E4FD8, global:0x005E4FD4, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck builds the \list\...\gamename\...\final\ query: with the where clause from a2 when a2 is non-null, otherwise without it; a1+12 is the gamename. [callee:0x0058815F, global:0x005E4F90, global:0x005E4FAC, source:raw]
    // CALL: send the list query on the socket at a1+136. [callee:0x0059867E, source:raw]
    // GUARD: When the second send returns -1 or 0, return 3 (network failure). [source:raw]
    // CALL: Signal completion/state transition via AudioValueSetterCall(a1, 1). [callee:0x00562FE0, source:raw]
    // RETURN: Return 0 on success; return 3 on network failure and 5 on validation failure. [function:0x00562E30, source:raw]

    // Conservative worker pseudocode:
    //   int sub_562E30(Session *s, const char *where) {
    //     int n = recv(s->sock, buf, 255, 0);
    //     if (n == -1) return 3;
    //     buf[n] = 0;
    //     int dec = sub_587C20(buf, aSecure);
    //     if (!dec) return 5;
    //     sub_564C70(dec + 8, 6);
    //     for (int i = 0; i < 6; ++i) ((char*)(dec + 8))[i] ^= ((char*)s)[44 + i];
    //     char v14[64];
    //     PadOutputWithSpacesUpToLengthLimit(v14);
    //     StringFormatWithBufferOverflowCheck(buf, "\\gamename\\%s\\gamever\\%s\\location\\0\\validate\\%s\\enctype\\2\\final\\\\queryid\\1.1\\", s->gameName, a18, v14);
    //     if (send(s->sock, buf, strlen(buf), 0) <= 0) return 3;
    //     const char *listArg = off_5E4FD4;
    //     if (s->state == 6)      { listArg = aGroups; s->flags = 0; }
    //     else if (s->state == 7) { listArg = aInfo2;  s->flags = 0; }
    //     if (where)
    //       StringFormatWithBufferOverflowCheck(buf, "\\list\\%s\\gamename\\%s\\where\\%s\\final\\", listArg, s->gameShort, where);
    //     else
    //       StringFormatWithBufferOverflowCheck(buf, "\\list\\%s\\gamename\\%s\\final\\", listArg, s->gameShort);
    //     if (send(s->sock, buf, strlen(buf), 0) <= 0) return 3;
    //     AudioValueSetterCall(s, 1);
    //     return 0;
    //   }
    // UNRESOLVED: Whether a1+44 is a static key or a per-session-derived key is not determined here; only the XOR reduction is evidenced.
    // UNRESOLVED: Mapping of the two list-format string globals (aListSGamenameS_0 at 0x005E4F90 vs aListSGamenameS at 0x005E4FAC) to the where/no-where format lines is not independently evidenced; the raw source shows the literals inline.
    // UNRESOLVED: Role of the a1+1460 clear and the exact meaning of states 6 and 7 (groups/info) is skeleton-labeled only.
    // UNRESOLVED: Single known caller is DeviceInitializationWithStateSetup (0x00562C90); the session initialization that populates a1 fields is not examined in this packet.
}
