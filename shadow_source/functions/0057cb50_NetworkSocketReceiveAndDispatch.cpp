// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057CB50
// Canonical corpus name: sub_57CB50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57CB50_0057cb50.c

void UnknownObject::NetworkSocketReceiveAndDispatch()
{
    // Network receive-and-dispatch loop driven by a socket and a direction flag (a3: datagram vs stream). Polls the socket with select() on a zero timeout, then either recvfrom() (datagram) or recv() (stream) into a per-object buffer obtained from this+2680. Stream data is pushed into per-connection ring buffers (2-byte length header at the front, message length = v85+v86+4), popped when a complete message is buffered, copied into a stack message buffer, and dispatched through a vtable entry at obj+0x58. Datagram path resolves the peer address via SocketAddressResolution/NetworkSocketAddressQuery and dispatches through sub_57BF00. Both paths maintain two mutex-protected linked lists on `this`: a connection list (head this+0xAAC, mutex this+0xABC) that stores last-receive timestamps, and a message-event list (head this+0xAC8, mutex this+0xAD8) that maps the sender address to an event ID. recv failures are mapped via WSAGetLastError() to human-readable strings and reported through MutexProtectedLinkedListLookupByID; WSA 10040 reallocates the receive buffer and retries. Returns 1 when a complete message was dispatched, 0 otherwise; the outer loop is bounded to a single pass by v72.
    // CALL: Poll the socket with select(0, &readfds, 0, 0, &timeout) using a zero timeout; readfds is built from s (fd_array[0] = s, fd_count = 1). On -1, query WSAGetLastError() and call sub_57D400(-1); otherwise v61 records whether the socket is readable. [global:0x0059E2E4, global:0x0059E324, callee:0x0057D400, source:raw]
    // GUARD: Branch on a3: when a3 is set (datagram) and the socket is readable, jump straight to the receive loop; when a3 is clear (stream), readable sockets also jump to the receive loop, otherwise the stream path resolves the peer address and checks for buffered data first. [source:raw]
    // CALL: Stream path: if the peer address is unresolved (v60 == 0), resolve it via SocketAddressResolution on the sockaddr stored at this+2692 ((this+673)*4). Zeroes are packed with htonl(0)/htons(0) and the current address is saved by Copy4DwordsStructToStruct((_DWORD*)this + 673, v83). [callee:0x0057B9A0, callee:0x0057B9F0, global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // CALL: Connection-list scan under the mutex at this+0xABC (WaitForSingleObject with timeout this+0xAC0; 0 and 128 accepted, ReleaseMutex after). Starting from the head node at this+0xAAC, walk the list (next at +0x4) and find the connection whose socket field at conn+0x20 equals s (or -1); if conn+0x1038 (ring-buffer used count) is >= 4, set v5 so the receive loop starts immediately. The null head (this+0xAAC == 0) is an early-out guard. [global:0x0059E1A0, global:0x0059E1A4, callee:0x0057D400, field:this:0x00000AAC, field:this:0x00000AB4, field:this:0x00000ABC, field:this:0x00000AC0, field:*(this+0xAAC):0x00000000, field:*(this+0xAB4):0x00000004, field:*(*(this+0xAB4)+0x4):0x00000000, field:*(*(this+0xAAC)+0x0):0x00000020, field:*(*(this+0xAAC)+0x0):0x00001038, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00001038, guard:1, source:raw]
    // CALL: Receive-buffer setup: obtain the buffer pointer via sub_563E70(this+2680) and its size via SimpleFieldGetter_bfc0(this+2680); initialize the `from` sockaddr with AF_INET (sa_family=2) and zero port/address via htonl(0)/htons(0). [callee:0x00563E70, callee:0x0055BFC0, global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // CALL: Datagram path: recvfrom(s, buffer, size, 0, &from, &fromlen) (fromlen=16); the peer port is byte-swapped with ntohs; sub_57BF00(this, buffer, count, &from) is checked first and jumps to the end on success; otherwise the peer is resolved with NetworkSocketAddressQuery on this+2692 using the from-address components. [global:0x0059E2E0, global:0x0059E2CC, callee:0x0057BF00, callee:0x0057B950, source:raw]
    // CALL: Stream path: recv(s, buffer, cap, 0) where cap is the buffer size clamped against 4096 minus the matched connection's used count at conn+0x1038; v59 is set before the call and cleared when bytes arrive, and the peer address is resolved lazily with SocketAddressResolution. [global:0x0059E304, field:*(*(this+0xAAC)+0x0):0x00001038, callee:0x0057B9A0, source:raw]
    // CALL: Ring-buffer ingestion for stream data: when the found connection's used count (conn+0x1038) is >= 4 (guard:0), read the 4-byte header (v85/v86) with ReadBytesFromCircularBufferWithWrapAround on the ring buffer at conn+54, compute the full message length v38 = v86 + v85 + 4, and when the buffered count is sufficient pop v38 bytes with RingBufferPopWithWrapCheck into the receive buffer; received bytes are first appended with RingBufferPushWithWrapCheck. [callee:0x0057B550, callee:0x0057B630, callee:0x0057B5C0, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00001038, guard:0, source:raw]
    // CALCULATION: Message completeness check: copy the received bytes into the stack buffer (qmemcpy of v67 bytes, capped at 0x604) and accept the message only when v67 == v86 + v85 + 4; on acceptance set v64 = 1. [source:raw]
    // CALL: Timestamp the receive: read the current time via MutexGuardedTimerRead(this) and save the sender address into this+2692 storage with Copy4DwordsStructToStruct((_DWORD*)this + 673, &from). [callee:0x00584F90, callee:0x0057B9F0, source:raw]
    // CALL: Timestamp back-write: re-lock the connection-list mutex (this+0xABC, timeout this+0xAC0) and walk from head this+0xAAC to find the connection whose primary (conn+0x4/conn+0x2) or secondary (conn+0x14/conn+0x12) IP/port pair matches the sender address, then store the timestamp into conn+0x2C (float). [global:0x0059E1A0, global:0x0059E1A4, field:this:0x00000AAC, field:this:0x00000AB4, field:this:0x00000ABC, field:this:0x00000AC0, field:*(this+0xAAC):0x00000000, field:*(this+0xAB4):0x00000004, field:*(*(this+0xAB4)+0x4):0x00000000, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000002, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000004, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000012, field:*(*(*(this+0xAB4)+0x4)+0x0):0x00000014, field:*(*(*(this+0xAB4)+0x4)+0x0):0x0000002C, source:raw]
    // CALL: Message-event lookup: lock the second mutex (this+0xAD8 handle, this+0xADC timeout) and walk the message-event list starting from head this+0xAC8 (next pointers at +0x4, node data at +0x0) comparing each entry with NetworkMessageEventComparisonWithShortMasking against the sender address; on match read the event ID with ReadFieldAtOffset0x14, otherwise v69 stays -1. The null head (this+0xAC8 == 0) is an early-out guard. [global:0x0059E1A0, global:0x0059E1A4, callee:0x0057B840, callee:0x005871F0, field:this:0x00000AC8, field:this:0x00000AD0, field:this:0x00000AD8, field:this:0x00000ADC, field:*(this+0xAC8):0x00000000, field:*(this+0xAD0):0x00000004, field:*(*(this+0xAD0)+0x4):0x00000000, guard:2, source:raw]
    // CALL: Dispatch: call the virtual entry at obj+0x58 (read the vtable pointer at this+0x0 and call its member at +88) to obtain a message object v55; unpack the received message with BufferUnpackWithSizeCheckByteWordCopy(&v85, v55), store the resolved event ID at v56+4, and run the message through VTableDispatchWithConditionalBranch(v56). [field:this:0x00000000, field:obj:0x00000058, callee:0x0057D660, callee:0x00585400, source:raw]
    // CALL: Receive-error handling: when hostlong == -1, switch on WSAGetLastError(); the WSA 10040 (message too long) case calls BufferReallocationAndDataCopy(512) to enlarge the receive buffer and retries the receive loop. [global:0x0059E324, callee:0x005875C0, source:raw]
    // STATE_TRANSITION: WSA error-string mapping: the error switch maps each WSA code to a human-readable message string (aFault/aInvalid/aNotSocket/aNotSupported/aNetworkDown/aNetworkReset/aAborted/aTcpConnectionR/aNotConnected/aShutdown/aTimedOut/aNotInitialised) via the dispatch tables jpt_57D249 and byte_57D3B0, with the byte globals at 0xFF00000000005430-0xFF00000000005439 referenced for the message payload. [global:0x0057D378, global:0x0057D3B0, global:0x005E542C, global:0x005E5438, global:0x005E5440, global:0x005E5448, global:0x005E5454, global:0x005E5464, global:0x005E5470, global:0x005E5480, global:0x005E5490, global:0x005E5498, global:0x005E54A8, global:0x005E54B8, global:0xFF00000000005430, global:0xFF00000000005431, global:0xFF00000000005435, global:0xFF00000000005436, global:0xFF00000000005438, global:0xFF00000000005439, source:raw]
    // STATE_TRANSITION: Error/close reporting: pack a sockaddr (LOWORD=2, HIWORD=htons(0), v78=htonl(0)) into this+2692 storage, then hand the error string (or aClosedGraceful when hostlong == 0, indicating a clean close) to MutexProtectedLinkedListLookupByID; either path sets v62 = 1 to terminate the loop. [callee:0x0057DFF0, callee:0x0057B9F0, global:0x005E54D0, global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // LOOP: Outer poll loop: repeats while v62 is clear (no error/close reported) and the received-data flag v59 is set, bounded to a single pass by the v72 counter (returns v64 once v72 >= 1); v64 is 1 only when a complete message was dispatched. [source:raw]
    // CALL: Called by NetworkAccept (0x00580190), which passes the accepted socket and the datagram/stream direction flag. [caller:0x00580190, source:raw]

    // Conservative worker pseudocode:
    //   char NetworkSocketReceiveAndDispatch(char *this, SOCKET s, char datagram) {
    //     char complete = 0; fd_set readfds = {1, {s}}; timeval t = {0,0};
    //     int stop = 0, pass = 0;
    //     do {
    //       int readable = 0, got = 0, recvRes = 0;
    //       int sel = select(0, &readfds, 0, 0, &t);
    //       if (sel == -1) { WSAGetLastError(); sub_57D400(-1); }
    //       else readable = sel != 0;
    //       if (datagram) { if (!readable) continue; }
    //       else if (!readable) {
    //         if (!v60) v60 = SocketAddressResolution((sockaddr*)(this+2692), s);
    //         // lock this+0xABC; scan connection list from this+0xAAC for conn->socket == s;
    //         // ready |= conn->ringUsed(conn+0x1038) >= 4; unlock
    //       }
    //       if (ready) {
    //         char endRecv = 0;
    //         while (!stop) {
    //           int len = 0;
    //           char *buf = sub_563E70(this+2680);
    //           int size = SimpleFieldGetter_bfc0(this+2680);
    //           sockaddr from = {2,0,0};
    //           if (datagram) {
    //             int n = recvfrom(s, buf, size, 0, &from, &fromlen);
    //             from.port = ntohs(from.port);
    //             if (sub_57BF00(this, buf, n, &from)) { endRecv = 1; continue; }
    //             got = 1; len = n;
    //             if (n <= 0) { endRecv = 1; continue; }
    //             v60 = NetworkSocketAddressQuery(this+2692, from..., s);
    //           } else {
    //             int ok = 1;
    //             if (!readable) ok = 0;
    //             else {
    //               // lock; cap size to 4096 - conn->ringUsed; unlock
    //               if (size > 0) { got = 1; recvRes = recv(s, buf, size, 0); ok = recvRes > 0; }
    //             }
    //             if (ok) {
    //               // lock; find conn by socket; if got&&recvRes>0 RingBufferPushWithWrapCheck(conn+54,buf,recvRes);
    //               // if conn->ringUsed>=4 && ReadBytesFromCircularBufferWithWrapAround(conn+54,&v85,4)
    //               //   len = v86+v85+4; if enough && RingBufferPopWithWrapCheck(conn+54,buf,len) len set;
    //               // unlock
    //             }
    //           }
    //           if (!ok) { endRecv = 1; continue; }
    //           if (len <= 0) { endRecv = 1; continue; }
    //           if ((unsigned)len <= 0x604) {
    //             qmemcpy(&v85, buf, len);
    //             if (len == v86+v85+4) {
    //               complete = 1;
    //               float ts = MutexGuardedTimerRead(this);
    //               Copy4DwordsStructToStruct((_DWORD*)this+673, &from);
    //               // lock; find conn whose port/ip matches from (primary 0x4/0x2 or secondary 0x14/0x12);
    //               //   conn->lastRecv(0x2C) = ts; unlock
    //               int eventId = -1;
    //               // lock this+0xAD8; walk list from this+0xAC8;
    //               //   if NetworkMessageEventComparisonWithShortMasking(node,&from) eventId = ReadFieldAtOffset0x14(node); unlock
    //               void *msg = (*(void* (__thiscall **)(void*))(*(void**)this + 88))(this);
    //               if (msg) {
    //                 BufferUnpackWithSizeCheckByteWordCopy(&v85, msg);
    //                 *(int*)((char*)msg+4) = eventId;
    //                 VTableDispatchWithConditionalBranch(msg);
    //               }
    //             }
    //           }
    //           if (got) {
    //             if (recvRes == -1) {
    //               switch (WSAGetLastError()) {
    //                 case 10040: BufferReallocationAndDataCopy(512); continue; // retry
    //                 case 10014: s= aFault; ... case 10093: s = aNotInitialised; default: break;
    //               }
    //               // build sockaddr; Copy4DwordsStructToStruct(this+2692,&addr);
    //               // MutexProtectedLinkedListLookupByID(addr..., s); stop = 1; break;
    //             }
    //             if (recvRes == 0) {
    //               // build sockaddr; MutexProtectedLinkedListLookupByID(addr..., aClosedGraceful); stop = 1;
    //             }
    //           }
    //           if (endRecv) break;
    //         }
    //       }
    //       if (++pass >= 1) return complete;
    //     } while (1);
    //   }
    // UNRESOLVED: Meaning of field obj+0x58: the only 0x58-sized offset in the packet is the vtable member at +88 on the object behind this+0x0; its exact handler semantics are unknown.
    // UNRESOLVED: Ring-buffer and message struct layouts: v85/v86 header interpretation (two uint16 fields summing to payload) is inferred from the 4-byte header read and the v67 == v86+v85+4 completeness check; the true wire format is not in the packet.
    // UNRESOLVED: The exact semantics of sub_57BF00 (datagram pre-dispatch) and sub_57D400 (select error hook) are external to this function's packet evidence.
    // UNRESOLVED: Connection and message-event list node identities (bases *(*(this+0xAB4)+0x4)+0x0 and *(*(this+0xAD0)+0x4)+0x0) are only known through field offsets; equality of offsets across lists does not prove identical structures.
    // UNRESOLVED: WSA string-bytes at 0xFF00000000005430-0xFF00000000005439 are referenced by the error dispatch but their exact encoding/usage is unverified.
}
