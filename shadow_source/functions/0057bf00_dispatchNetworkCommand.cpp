// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057BF00
// Canonical corpus name: sub_57BF00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57BF00_0057bf00.c

void UnknownObject::dispatchNetworkCommand()
{
    // Server-side dispatch of an incoming network command string. It caches the length of a command prefix once into dword_8D3C14, rejects strings that do not carry that prefix, then splits the remainder into a bounded scratch token. Depending on which follow-up prefix the token carries it either (a) answers a connection request with a status reply over UDP (building the reply from getsockname's local port/address, formatting IP:port into a sendto buffer, and handling the this+0x5D server-state byte that lowers the reply code from 4 to 3), (b) updates a mutex-protected lobby/session state value 1-5 parsed from a decimal command token, or (c) performs a direct-connect sequence: bind-port scan with connect retry on WSAEADDRINUSE, registration of the peer in a mutex-protected linked-list node, two virtual dispatch/notify rounds with packet construction, and node teardown. The function returns 1 on most handled paths and 0 only on the prefix-reject path.
    // GUARD: One-time init of the command-prefix length: if byte_8D3C10 bit 0 is clear, set the flag and cache strlen(off_5E537C[0]) into dword_8D3C14; v5 is that cached length on both paths. [global:0x008D3C10, global:0x008D3C14, global:0x005E537C, source:raw]
    // GUARD: Early reject: if the incoming length a3 does not exceed the cached prefix length, or the incoming a2 does not start with the prefix string off_5E537C[0] (sub_588640 prefix match), return 0 without processing. [callee:0x00588640, global:0x005E537C, source:raw]
    // CALCULATION: Builds the command token: v6 = a3 minus the cached prefix length, capped at 79; clears the first byte of v68 and the v71 flag, copies the suffix a2+dword_8D3C14 into v68 via sub_587DD0, and NUL-terminates v68 at v6. [callee:0x00587DD0, source:raw]
    // GUARD: Connection-request branch: when the token v68 does not start with the second prefix off_5E5384[0] (sub_588640 mismatch), fall through to the later branches; otherwise proceed with the status-reply / direct-connect handling. [callee:0x00588640, global:0x005E5384, source:raw]
    // GUARD: Status-reply path: proceeds only when the mutex-protected state read MutexProtectedPointerReadRelease(this) equals 4. [callee:0x00585D20, source:raw]
    // CALCULATION: Queries the local address: builds a sockaddr name with sa_family 2, address htonl(0) and port htons(0), then calls getsockname on the socket at this+0x938 (namelen 16) and converts the returned port back to host order with ntohs. [field:this:0x00000938, global:0x0059E2CC, global:0x0059E2D0, global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // GUARD: Peer-name comparison: when getsockname succeeded and the token remainder after the off_5E5384 prefix equals the peer-name string stored on the object (this+2328), the full status-reply branch runs; a mismatch sets the reply code to 2. [field:this:0x00000938, global:0x005E5384, source:raw]
    // CALL: Status-reply send: when the vtable status check StatusCheckViaVTableDispatch(0, 0) passes, formats into buf via StringFormatWithBufferOverflowCheck with the local port and the four octets plus port of the remote address from a4, rebuilds the peer sockaddr (htons on the port), and sends the reply with sendto on the socket at this+0x93C, then returns 1. [callee:0x00585220, callee:0x0058815F, global:0x005E537C, global:0x005E5388, field:this:0x0000093C, global:0x0059E2F4, global:0x0059E2F8, source:raw]
    // GUARD: Guard on the server-state byte this+0x5D: its non-zero value (compared against 0) lowers the status reply code from 4 to 3 via v12 = 4 - (byte != 0). [guard:0, field:this:0x0000005D, source:raw]
    // CALL: Reduced status reply: formats '%s%s%d' into buf with v12 as the code, appends the peer name as ' (%s)' when the code is 2, rebuilds the peer sockaddr from a4, and sends the reply with sendto on the socket at this+0x93C, then returns 1. [callee:0x0058815F, global:0x005E537C, global:0x005E538C, field:this:0x0000093C, global:0x0059E2F4, global:0x0059E2F8, source:raw]
    // GUARD: Command-token branch: when the token v68 starts with the third prefix off_5E5388[0] (sub_588640 match), continue into the state-change handling. [callee:0x00588640, global:0x005E5388, source:raw]
    // GUARD: State-change gate: when the token continues with off_5E538C and the mutex-protected state read MutexProtectedPointerReadRelease(this) equals 1, the lobby-state write path runs; otherwise the function returns 1 without modifying state. [callee:0x00588640, callee:0x00585D20, global:0x005E538C, source:raw]
    // CALL: State-write preamble: ThreadSafeWriteWithMutex(0) is issued, then StrlenFormatCallWrapper parses the token after the off_5E538C prefix with the format string aD_3 into v69, storing the parsed length into namelen. [callee:0x00585CD0, callee:0x005887ED, global:0x005E538C, global:0x005E53EC, source:raw]
    // CALL: State-mutex acquisition: reads the mutex handle at this+0x618 and its timeout at this+0x61C and calls WaitForSingleObject; on WAIT_OBJECT_0 (0) or WAIT_ABANDONED (128) the base pointer this+1476 is used for the state write, otherwise a null target is used. [field:this:0x00000618, field:this:0x0000061C, global:0x0059E1A0, source:raw]
    // STATE_TRANSITION: State write under mutex: switch on the parsed length writes 2, 3, 4 or 5 into the state field at this+0x5C4 (with the payload copied/terminated into the adjacent this+0x5C8 buffer), and the default writes 1; afterwards ReleaseMutex is called on the handle when the field at this+0x5C4+84 is set. [field:this:0x000005C4, field:this:0x000005C8, global:0x0059E1A4, source:raw]
    // GUARD: Direct-connect gate: when the mutex-protected state read MutexProtectedPointerReadRelease(this) is not 1, the function returns 1 and skips the direct-connect sequence. [callee:0x00585D20, source:raw]
    // CALCULATION: Direct-connect addressing: builds the local sockaddr name (family 2, address htonl(0), port htons(0)), copies the peer sockaddr from a4 into v57, and parses '%d %d.%d.%d.%d:%d' from the token after the off_5E5388 prefix via StrlenFormatCallWrapper into the port/octet fields that are then stored into name.sa_data. [callee:0x005887ED, global:0x005E5388, global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // LOOP: Socket bind-scan retry loop: repeatedly creates a socket via NetworkSocketCreate until one succeeds, binds it to base port this+0x910 plus an offset (v54+50) via SocketBindPortScan, and connects to the peer sockaddr; on WSAEADDRINUSE (10048) with fewer than 50 attempts it closes and retries after Sleep(10); otherwise SocketGracefulClose and return 1. [callee:0x0057BEE0, callee:0x0057C7B0, callee:0x0057C8E0, field:this:0x00000910, global:0x0059E0DC, global:0x0059E2FC, global:0x0059E324, source:raw]
    // CALL: On a successful connect the lobby state is advanced with ThreadSafeWriteWithMutex(2). [callee:0x00585CD0, source:raw]
    // CALL: Node-list mutex acquisition: reads the mutex handle at this+0xBEC and its timeout at this+0xBF0 and calls WaitForSingleObject; on success the base pointer this+3020 is used for the node list access, otherwise a null target. [field:this:0x00000BEC, field:this:0x00000BF0, global:0x0059E1A0, source:raw]
    // CALCULATION: Node inspection: ShortComputation_a780 runs on the node-list entry, the node pointer is read from the list head (base *(this+0xBE4) field 0), the node active flag byte at field 8 of that node is cleared to 0, and sub_5817A0 validates the node; a failed validation nulls the node pointer. [callee:0x004BA780, callee:0x005817A0, field:*(this+0xBE4):0x00000000, field:*(this+0xBE4):0x00000008, field:this:0x00000BE4, source:raw]
    // CALL: Node allocation/cleanup when no valid node was found: allocates via OperatorNewNhMallocWrapper(4), constructs the object with ObjectAllocationWithSEH when the allocation succeeded, zero-fills it with ZeroFillMemoryRegionWithStep, and obtains a node through LinkedListNodeRemovalWithCleanupCallback on the list entry. [callee:0x00587C03, callee:0x005830C0, callee:0x00583530, callee:0x00582EB0, source:raw]
    // CALL: Releases the node-list mutex at this+0xBEC with ReleaseMutex when the stored handle is non-null. [field:this:0x00000BEC, global:0x0059E1A4, source:raw]
    // CALL: Setter(v35, s) stores the connected socket handle into the node. [callee:0x004979C0, source:raw]
    // CALCULATION: Queries the peer endpoint: advances a buffer with PointerAdvance and calls getpeername on socket s with a length of 16, capturing the remote address into the node-side sockaddr. [callee:0x0057B6A0, global:0x0059E31C, source:raw]
    // CALL: Copies the 16-byte peer struct from a4 into the node with F_16ByteStructCopy. [callee:0x0057B680, source:raw]
    // CALL: Cleanup mutex acquisition: reads the mutex handle at this+0x640 and its timeout at this+0x644 and calls WaitForSingleObject; on success the base pointer this+1572 is used for the reset, otherwise a null target. [field:this:0x00000640, field:this:0x00000644, global:0x0059E1A0, source:raw]
    // CALL: FieldResetWithSubCall runs against the cleanup target, resetting the per-peer fields. [callee:0x005870E0, source:raw]
    // CALL: Releases the cleanup mutex at this+0x640 with ReleaseMutex when the stored handle is non-null. [field:this:0x00000640, global:0x0059E1A4, source:raw]
    // CALL: First virtual dispatch: reads the vtable pointer at this+0 and calls the virtual method at slot this+0x58 (obj+0x58) to obtain the session object v42. [field:this:0x00000000, field:obj:0x00000058, source:raw]
    // CALL: First notify round: sub_586800(0, 6, 1, 2, -1) is issued, the local sockaddr name is passed through SingleFunctionCallWrapper_6a00 with length 16, NetworkPacketConstructor builds the packet from the session object's packet buffer (v42+72), and ThreadSafeCallWithMutex runs the session notify call. [callee:0x00586800, callee:0x00586A00, callee:0x0057AFA0, callee:0x00584C70, source:raw]
    // CALL: Second virtual dispatch: calls the same vtable slot this+0x58 (obj+0x58) again to obtain v43, then issues sub_586800(0, 3, 1, 2, -1), computes the result of ArithmeticComparison_5020(this), copies up to 16 bytes of it into the v65 scratch via sub_587DD0 when non-null (else clears v65), and sends the result through SingleFunctionCallWrapper_6a00 with length 17, NetworkPacketConstructor and ThreadSafeCallWithMutex on v43. [callee:0x00586800, callee:0x00586A00, callee:0x0057AFA0, callee:0x00584C70, callee:0x00585020, callee:0x00587DD0, field:this:0x00000000, field:obj:0x00000058, source:raw]
    // CALL: Teardown: sub_57DC10(v35) is invoked on the node to finish the per-peer session cleanup. [callee:0x0057DC10, source:raw]
    // RETURN: Returns 1 on every handled command path; the only 0 return is the prefix-reject path. [function:0x0057BF00, source:raw]

    // Conservative worker pseudocode:
    //   // one-time cache of the command-prefix length into dword_8D3C14
    //   if (!(byte_8D3C10 & 1)) { byte_8D3C10 |= 1; dword_8D3C14 = strlen(off_5E537C[0]); }
    //   if (a3 <= dword_8D3C14 || sub_588640(a2, off_5E537C[0], dword_8D3C14)) return 0;
    //   // token = suffix after the prefix, capped at 79 chars
    //   v6 = min(a3 - dword_8D3C14, 79); sub_587DD0(v68, a2 + dword_8D3C14, v6); v68[v6] = 0;
    //   if (starts_with(v68, off_5E5384[0])) {
    //     if (MutexProtectedPointerReadRelease(this) == 4) {
    //       getsockname(socket at this+0x938);
    //       if (peer-name after prefix == string at this+2328) {
    //         if (StatusCheckViaVTableDispatch(0, 0)) { sendto(status reply with local port + IP); return 1; }
    //         code = 4 - (byte at this+0x5D != 0);
    //       } else code = 2;
    //       sendto(reduced '%s%s%d' reply, appending ' (%s)' when code == 2); return 1;
    //     }
    //     return 1;
    //   }
    //   if (starts_with(v68, off_5E5388[0])) {
    //     if (starts_with(v68, off_5E538C) && MutexProtectedPointerReadRelease(this) == 1) {
    //       ThreadSafeWriteWithMutex(0);
    //       parse token after off_5E538C via aD_3 into v69 (namelen = parsed length);
    //       lock mutex at this+0x618;
    //       switch (namelen) { 2: state=2, copy v69; 3: state=3; 4: state=4; 5: state=5; default: state=1 }
    //       ReleaseMutex(handle at this+0x618);
    //     }
    //     return 1;
    //   }
    //   if (MutexProtectedPointerReadRelease(this) != 1) return 1;
    //   // direct-connect path
    //   parse '%d %d.%d.%d.%d:%d' from token after off_5E5388 into the peer endpoint;
    //   loop { socket = NetworkSocketCreate(this); SocketBindPortScan(socket, port at this+0x910 + tries + 50);
    //     if (connect(socket, peer, 16) == 0) break;
    //     if (WSAGetLastError() != 10048 || ++tries > 50) { SocketGracefulClose; return 1; }
    //     SocketGracefulClose; Sleep(10); }
    //   ThreadSafeWriteWithMutex(2);
    //   acquire node-list mutex at this+0xBEC;
    //   node = inspect/create node (ShortComputation_a780, active flag 0, allocation/zero-fill/cleanup helpers);
    //   ReleaseMutex(handle at this+0xBEC);
    //   Setter(node, socket); getpeername(socket, ...); F_16ByteStructCopy(node, a4);
    //   acquire cleanup mutex at this+0x640; FieldResetWithSubCall; ReleaseMutex(handle at this+0x640);
    //   v42 = vtable_slot(this+0x58)(this); sub_586800(0,6,1,2,-1); ... NetworkPacketConstructor; ThreadSafeCallWithMutex;
    //   v43 = vtable_slot(this+0x58)(this); sub_586800(0,3,1,2,-1); ... NetworkPacketConstructor; ThreadSafeCallWithMutex;
    //   sub_57DC10(node);
    //   return 1;
    // UNRESOLVED: The format/string constants aS_9 (0x5C721C), aDDDDDD (0x5E53F8), aSSDDDDDD (0x5E540C) and aSSD (0x5E5424) appear in the packet as referenced data but are not visible as operands of the decompiled body; their exact formats are unknown.
    // UNRESOLVED: The switch jump table jpt_57C718 (0x57C798) and the SEH handler SEH_57BF00 (0x59C9B9) are referenced by the packet but their control-flow roles are not visible in the decompiled body (the body is a linear if/else chain with no switch).
    // UNRESOLVED: byte_FF00000000005430 and byte_FF00000000005431 sit far outside the image (non-image addresses) and are referenced with write access; their role is unexplained by the decompiled body and may originate from a patched/hooked data reference.
    // UNRESOLVED: The precise wire protocol (exact byte meaning of a2/a3/a4, the four prefixes, and the 1-5 state values) is reconstructed only to DERIVED level and would need runtime observation to confirm.
    // UNRESOLVED: The object type owning all the this+* mutex/socket/state fields is unknown; only the vtable-dispatch pattern at slot this+0x58 is evidenced.
}
