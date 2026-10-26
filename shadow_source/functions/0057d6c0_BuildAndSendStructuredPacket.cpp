// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057D6C0
// Canonical corpus name: sub_57D6C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57D6C0_0057d6c0.c

void UnknownObject::BuildAndSendStructuredPacket()
{
    // Builds a structured packet into a local buffer via StructuredMemoryCopyWithHeaderPrepend(a2, buf) with length v4 = buf[0] + buf[1] + 4, fills a sockaddr from the four dwords of a3 (address family/port/address), then sends it over the object's UDP socket this[591] (offset 0x93C) with sendto. Returns 1 on success. On failure, dispatches on WSAGetLastError: most WSA error codes log via MutexProtectedLinkedListLookupByID with a per-code error string, WSAENOBUFS (10055) retries through ThreadSafeMutexQueueWithTimedWait and dispatches a vtable callback from FieldGetter_5cc0 plus EmptyStub_0170. All failure paths return 0.
    // CALL: Build the structured packet: StructuredMemoryCopyWithHeaderPrepend(a2, buf) fills the local buffer with a header-prepended copy of a2. [callee:0x0057D5D0, function:0x0057D6C0, source:raw]
    // CALCULATION: Compute the send length from the packet header words: v4 = buf[0] + buf[1] + 4. [source:raw]
    // ASSIGNMENT: Populate the destination sockaddr from a3: address family and low port word from *a3, port high word via hostshort[1] = htons(HIWORD(*a3)), and the three address dwords from a3[1], a3[2], a3[3]. [global:0x0059E2F4, source:raw]
    // ASSIGNMENT: Load the socket handle for the send: v6 = this[591] (field at offset 0x93C). [field:this:0x0000093C, source:raw]
    // CALL: Send the datagram: sendto(v6, buf, v4, 0, &to, 16). [global:0x0059E2F8, source:raw]
    // GUARD: Success guard: if sendto returns -1 continue to error dispatch, otherwise return 1. [source:raw]
    // CALL: Read the failure code via WSAGetLastError() to select the error branch. [global:0x0059E324, source:raw]
    // STATE_TRANSITION: Dispatch on the WSA error code via the jump table jpt_57D79F with parameter data byte_57D878; cases 10038, 10047, 10049, 10050, 10053, 10054, 10058 and 10060 take the logging path, 10055 takes the queue-retry path. [global:0x0057D850, global:0x0057D878, source:raw]
    // CALL: Log each connection error via MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], errorString): 10038->aWsaenotsock, 10047->aWsaeafnosuppor, 10049->aWsaeaddrnotava, 10050->aWsaenetdown, 10053->aWsaeconnaborte, 10054->aWsaeconnreset, 10058->aWsaeshutdown, 10060->aWsaetimedout; result is set to 0. [callee:0x0057DFF0, global:0x005E62B0, global:0x005E625C, global:0x005E626C, global:0x005E62BC, global:0x005E6290, global:0x005E6280, global:0x005E62A0, global:0x005E624C, source:raw]
    // CALL: WSAENOBUFS (10055) retry path: ThreadSafeMutexQueueWithTimedWait((int)a3, &v12, 1); on success obtain v8 = FieldGetter_5cc0(this) and invoke the vtable callback at slot 56 (offset 0x38) with v8 and v12, then call EmptyStub_0170; result is set to 0. [callee:0x0057EE80, callee:0x00585CC0, callee:0x004B0170, source:raw]
    // RETURN: Return 0 on every send-failure path; return 1 only when sendto succeeded. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_57D6C0(_DWORD *this, unsigned int a2, _DWORD *a3) {
    //     unsigned __int16 buf[770]; struct sockaddr to;
    //     StructuredMemoryCopyWithHeaderPrepend(a2, buf);
    //     int v4 = buf[0] + buf[1] + 4;
    //     // populate sockaddr to from a3[0..3], port = htons(HIWORD(a3[0]))
    //     SOCKET s = this[591];
    //     if (sendto(s, (const char*)buf, v4, 0, &to, 16) != -1) return 1;
    //     switch (WSAGetLastError()) {
    //       case 10038: case 10047: case 10049: case 10050:
    //       case 10053: case 10054: case 10058: case 10060:
    //         MutexProtectedLinkedListLookupByID(*a3, a3[1], a3[2], a3[3], errString);
    //         return 0;
    //       case 10055:
    //         if (ThreadSafeMutexQueueWithTimedWait((int)a3, &v12, 1)) {
    //           int v8 = FieldGetter_5cc0(this);
    //           (*(void (__thiscall **)(int, int))(*(_DWORD*)v8 + 56))(v8, v12);
    //           EmptyStub_0170();
    //         }
    //         return 0;
    //       default: return 0;
    //     }
    //   }
    // UNRESOLVED: The exact layout of the sockaddr fields written from a3 (family/port/address vs. any 4-dword struct) is inferred from the sendto usage; the meaning of each a3 dword is not proven.
    // UNRESOLVED: The vtable callback at slot 56 of the object returned by FieldGetter_5cc0 is unresolved.
    // UNRESOLVED: The write-only globals byte_FF00000000005430 and byte_FF00000000005431 sit outside the normal data range and look like a decompiler artifact; their role is unknown.
    // UNRESOLVED: Exact relationship between this object and the two callers is not established.
}
