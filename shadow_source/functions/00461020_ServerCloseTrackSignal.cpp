// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00461020
// Canonical corpus name: ServerCloseTrackSignal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ServerCloseTrackSignal_00461020.c

void UnknownObject::ServerCloseTrackSignal()
{
    // Sends the network "closing track" signal for the server session: encodes a progress-bar event, allocates and flags a network message object, dispatches it, clears the session open flag at this+0x29, builds a log-string node, and either appends it to the debug-log linked list at this+0x1B770..0x1B77C or frees it depending on the logging-enabled global at 0x007D0398. Returns the updated node count when appended, else the logging flag value, or the free result.
    // CALL: Encode a progress-bar event via ProgressBarEventEncode(4, 37, 0, 255, low dword of dbl_8AFEA0, 1). [callee:0x004B33B0, global:0x008AFEA0, abi:lead, function:0x00461020, source:raw]
    // CALL: Obtain a message object with COMVTableCallVia0x60(*(this+0x3FB8)) and mark it active by writing byte 1 at v2+4. [callee:0x0057A680, field:this:0x00003FB8]
    // CALL: Dispatch the "closing track" network message via NetworkSendDispatch with the packet v9, an encoded length derived from ((v9[0] >> 8) & 0x3FF) + 8, and the message object v2. [callee:0x0057A6A0]
    // CALL: Invoke the COM virtual method with VirtualMethodDispatch(*(this+0x3FB8), v2) to send/commit the message. [callee:0x0057A690, field:this:0x00003FB8]
    // ASSIGNMENT: Clear the session open/closed flag at this+0x29 (track closed). [field:this:0x00000029]
    // CALL: Allocate an 8-byte log-string node; on success initialize *v4=0 and v4[1]=-1, otherwise v4=0. [callee:0x00587C03]
    // CALL: Copy the "ClosingTrack" message string (aClosingTrack at 0x005C60F8) into the reallocated buffer via StringCopyWithBufferRealloc. [callee:0x00566650, global:0x005C60F8]
    // GUARD: When the session type global dword_7C569C is not 5 and StringSplitLoop(1, aDDevF119992002_1, 4876) succeeds, write the log line: DebugLogWrite(&dword_8AD25C, *v4) using byte_5EA438 as the fallback path when *v4 is null. [callee:0x004D7A50, callee:0x004D7AA0, global:0x007C569C, global:0x005C5CE4, global:0x005EA438, global:0x008AD25C]
    // GUARD: When dword_7D0398 (logging enabled) is nonzero and v4 is valid: allocate a 12-byte list node (v7[0]=v4, v7[4]=0, v7[8]=0) and append it to the debug-log linked list; when the head this+0x1B770 is set, link the previous tail this+0x1B774's +4 slot to v7, otherwise initialize head this+0x1B770 and secondary this+0x1B778 to v7; update the tail this+0x1B774 to v7 and increment the node count at this+0x1B77C. [global:0x007D0398, callee:0x00587C03, field:this:0x0001B770, field:this:0x0001B774, field:this:0x0001B778, field:this:0x0001B77C, field:*(this+0x1B774):0x00000004]
    // GUARD: Else when dword_7D0398 is zero and v4 is valid: free the string buffer *v4 with FreeWrapper_7bcf if non-null, free the node v4 itself, and return the free result. [global:0x007D0398, callee:0x00587BCF]
    // RETURN: Return the logging flag dword_7D0398 when no node was appended, or the updated node count from this+0x1B77C after a successful append. [global:0x007D0398, caller:0x00463760]

    // Conservative worker pseudocode:
    //   int ServerCloseTrackSignal(int this) {
    //     ProgressBarEventEncode(4, 37, 0, 255, LODWORD(dbl_8AFEA0), 1);
    //     int msg = COMVTableCallVia0x60(*(this+0x3FB8));
    //     *(char*)(msg+4) = 1;
    //     NetworkSendDispatch(pkt, ((pkt[0]>>8)&0x3FF)+8, msg, 1, 1, -1, 0);
    //     VirtualMethodDispatch(*(this+0x3FB8), msg);
    //     *(char*)(this+0x29) = 0;
    //     void **node = OperatorNewNhMallocWrapper(8);
    //     if (node) { node[0] = 0; node[1] = (void*)-1; }
    //     StringCopyWithBufferRealloc(aClosingTrack);
    //     if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 4876))
    //       DebugLogWrite(&dword_8AD25C, node ? node[0] : (void*)byte_5EA438);
    //     int result = dword_7D0398;
    //     if (dword_7D0398 && node) {
    //       int entry = OperatorNewNhMallocWrapper(12);
    //       if (entry) { *(void**)entry = node; *(entry+4) = 0; *(byte*)(entry+8) = 0; }
    //       if (*(this+0x1B770)) *(*(this+0x1B774)+4) = entry;
    //       else { *(this+0x1B770) = entry; *(this+0x1B778) = entry; }
    //       *(this+0x1B774) = entry;
    //       result = ++*(this+0x1B77C);
    //     } else if (node) {
    //       if (node[0]) FreeWrapper_7bcf(node[0]);
    //       return FreeWrapper_7bcf(node);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The message object v2 layout (only byte +4 is set) and the meaning of the NetworkSendDispatch arguments (1, 1, -1, 0) are caller-side/network-protocol contracts not resolved here.
    // UNRESOLVED: The packet buffer v9 is written by NetworkSendDispatch; its structure and the ((v9[0]>>8)&0x3FF)+8 length derivation are not resolved.
    // UNRESOLVED: The precise role of dword_7C569C (session type; 5 excludes dev logging) is DERIVED from the existing analysis, not proven here.
    // UNRESOLVED: byte_5EA438 is treated as a fallback log path string but its content is not known from this packet.
}
