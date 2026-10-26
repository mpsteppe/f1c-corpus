// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563410
// Canonical corpus name: sub_563410
// Owner: NetworkAudioReceiver [DERIVED]
// Raw source: functions/sub_563410_00563410.c

void NetworkAudioReceiver::receiveAudioStreamPacket()
{
    // Polls a network socket used for audio streaming data and processes incoming packets. State machine on the object mode field: case 1 = TCP receiver (select + recv into a shared 2047-byte buffer, optional XOR/RC4 decryption, packet header parse and dispatch to audio note/param handlers); case 2 = UDP receiver (select + recvfrom, validity check, port-based dispatch); case 3 = alternate receiver handler. Closes and resets the socket on read failure, timeout, or end-of-stream, and notifies the audio system via AudioValueSetterCall.
    // GUARD: Null guard: if this is null, return 5 (error). [function:0x00563410, source:raw]
    // STATE_TRANSITION: Dispatch on the state machine mode stored at this+0x0 via the jump table at jpt_563421 (case targets loc_563428/loc_56342D/loc_563432, default def_563421): case 1 = TCP receiver, case 2 = UDP receiver, case 3 = alternate receiver handler, default = return 0. [field:this:0x00000000, global:0x00563428, global:0x0056342D, global:0x00563432, global:0x00563437, global:0x0056343C, source:raw]
    // GUARD: TCP case: select() on the socket at this+0x88 with a zero timeout; if not readable, return 0 (idle). [field:this:0x00000088, callee:0x00598654, source:raw]
    // CALL: TCP case: recv() appends up to (2047 - dword_8CFAE0) bytes of the socket into the shared receive buffer byte_8CF288 at the current length offset dword_8CFAE0. [field:this:0x00000088, global:0x008CF288, global:0x008CFAE0, callee:0x00598684, source:raw]
    // GUARD: TCP case: if recv returned -1 or 0 (error/closed): closesocket, set the socket at this+0x88 to -1, reset dword_8CFAE0 to 0, SetFlagIfPointerNonNull(this), AudioValueSetterCall(this, 3) and return 3. [field:this:0x00000088, global:0x008CFAE0, callee:0x0059865A, callee:0x00563DF0, callee:0x00562FE0, source:raw]
    // GUARD: TCP case: if the encryption flag at this+0x55C != -1 (encryption enabled), XOR/RC4-decrypt the newly received bytes via XOREncryptionWithRollingKeyStream(recvResult). [field:this:0x0000055C, callee:0x00565140, guard:0, source:raw]
    // CALCULATION: TCP case: advance the shared buffer length dword_8CFAE0 by the number of bytes received and point the packet cursor v11 at the buffer base byte_8CF288. [global:0x008CF288, global:0x008CFAE0, source:raw]
    // GUARD: TCP case: if the encryption flag at this+0x55C == -1 (no active key stream), check the first-byte marker: if the buffer length exceeds (byte_8CF288[0] XOR 0xEC), XOR the marker byte back, XOR a per-byte key derived from the string at this+44 over byte_8CF289[0..len], initialize the RC4 key schedule via RC4KeyScheduleInitialization(this+156), then XOR-decrypt the remainder of the buffer. [field:this:0x0000055C, global:0x008CF288, global:0x008CF289, callee:0x00565080, callee:0x00565140, guard:1, source:raw]
    // GUARD: TCP case: if the remaining unparsed bytes (cursor minus buffer base) are within 6 bytes of the buffer end, skip parsing: sub_58B130(byte_8CF288, cursor, dword_8CFAE0) compacts/resets the buffer and return 0. [global:0x008CF288, global:0x008CFAE0, callee:0x0058B130, source:raw]
    // LOOP: TCP case: while the packet at the cursor starts with the aFinal marker (sub_588640(cursor, aFinal, 7) true) and the end-flag at this+0x74 is clear: parse one packet header; if fewer than 6 bytes remain, finish via the buffer-compact path. [field:this:0x00000074, global:0x005E4EAC, callee:0x00588640, source:raw]
    // GUARD: TCP case: if the protocol flag at this+0x90 is 6 or 7, hand the packet to sub_563870 for special handling: it returns a consumed length (advance the cursor) on success, 0 to finish parsing, or negative to set the end-flag at this+0x74 to 1. [field:this:0x00000090, field:this:0x00000074, callee:0x00563870, source:raw]
    // CALL: TCP case, standard packets: parse the 6-byte header (packet id dword + subtype word), byte-swap the subtype with ntohs, and dispatch via AudioNoteParamIndexSearchLoop(this, packetId, subtype, sessionId from this+0x98); if it returns -1 (unknown), fall back to ConditionalNetworkUtility with the protocol flag from this+0x90. [field:this:0x00000098, field:this:0x00000090, callee:0x00598630, callee:0x005631D0, callee:0x00563160, source:raw]
    // STATE_TRANSITION: TCP case, stream end: after the parse loop exits, closesocket, set the socket at this+0x88 to -1, reset dword_8CFAE0 to 0; if the protocol flag at this+0x90 is 6 or 7 notify AudioValueSetterCall(this, 0), otherwise AudioValueSetterCall(this, 3); return 0. [field:this:0x00000088, field:this:0x00000090, global:0x008CFAE0, callee:0x0059865A, callee:0x00562FE0, source:raw]
    // CALL: UDP case: select() on the socket at this+0x88 with a zero timeout; loop while readable; recvfrom() up to 1499 bytes into a local buffer with a 16-byte sockaddr source; if sub_587C20(buffer, aFinal) confirms a valid audio packet, byte-swap the source port with ntohs and dispatch via TwoStepDispatch(this, port); on -1 fall back to ConditionalNetworkUtility(this, port, 5). [field:this:0x00000088, global:0x005E4EAC, callee:0x00598654, callee:0x0059864E, callee:0x00587C20, callee:0x00598630, callee:0x005631A0, callee:0x00563160, source:raw]
    // GUARD: UDP case, timeout: if GetTickCount() minus the last-activity timestamp at this+0x8C exceeds 0xBB8 (3000 ms) with no packet, closesocket, set the socket at this+0x88 to -1 and notify AudioValueSetterCall(this, 3); return 0. [field:this:0x0000008C, field:this:0x00000088, callee:0x00564640, callee:0x0059865A, callee:0x00562FE0, source:raw]
    // CALL: Case 3: delegate to the alternate receiver handler sub_563AB0 (not represented in the packet evidence) and return its result. [source:raw]
    // RETURN: Default case: return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (!this) return 5;
    //   switch (this->mode) {
    //     case 1: /* TCP * /
    //       if (select(sock, zeroTimeout) > 0) {
    //         n = recv(sock, buf + bufLen, 2047 - bufLen, 0);
    //         if (n == -1 || n == 0) { closesocket(sock); sock = -1; bufLen = 0; setFlag(this); setAudioValue(this, 3); return 3; }
    //         if (encKey != -1) xorDecrypt(n);
    //         bufLen += n;
    //         if (encKey == -1 && bufLen > (buf[0] ^ 0xEC)) {
    //           buf[0] ^= 0xEC; xorKeyStream(buf+1); rc4Init(keyBuf); xorDecryptRest();
    //         }
    //         while (cursorWithinBuffer()) {
    //           if (matchesMarker(aFinal) && !endFlag) {
    //             if (bufLen - cursor < 6) { compactBuffer(); return 0; }
    //             if (proto == 6 || proto == 7) { n = handleSpecial(); if (n >= 0) cursor += n; else endFlag = 1; }
    //             else { id = dwordAt(cursor); sub = ntohs(wordAt(cursor+4)); cursor += 6;
    //                    if (searchParam(id, sub, session) == -1) dispatchUnknown(this, sub, proto); }
    //           }
    //         }
    //         closesocket(sock); sock = -1; bufLen = 0;
    //         setAudioValue(this, (proto == 6 || proto == 7) ? 0 : 3);
    //       }
    //       break;
    //     case 2: /* UDP * /
    //       while (select(sock, zeroTimeout) > 0) {
    //         if (recvfrom(sock, buf, 1499, &from, &fromLen) != -1 && isValid(buf, aFinal)) {
    //           port = ntohs(from.port);
    //           if (dispatchUdp(this, port) == -1) dispatchUnknown(this, port, 5);
    //         }
    //       }
    //       if (GetTickCount() - lastActivity > 3000) { closesocket(sock); sock = -1; setAudioValue(this, 3); }
    //       break;
    //     case 3: return alternateReceiver();
    //     default: return 0;
    //   }
    //   return 0;
    // UNRESOLVED: MilesSoundSystemStreamVolumeSet (0x00406659) is listed as a callee but no call to it appears in the decompiled body; it is likely reached through an indirect/obfuscated path.
    // UNRESOLVED: The byte_FF00000000005431/435/436/438/439 globals are non-canonical addresses that look like jump-table or disassembly artifacts from the switch region near jpt_563421; their semantic role is unknown.
    // UNRESOLVED: Case 3 dispatches to sub_563AB0, which has no packet evidence ref, so its identity and return contract are unknown.
    // UNRESOLVED: The string used as the per-byte XOR key lives at this+44 and the RC4 key-schedule buffer at this+156; neither offset is present in the field evidence list, so only the encryption-enable flag this+0x55C is bound.
    // UNRESOLVED: Whether byte_8CF288's first byte + 0xEC marker scheme is a frame-length or packet-start marker is DERIVED from the branch structure, not proven.
}
