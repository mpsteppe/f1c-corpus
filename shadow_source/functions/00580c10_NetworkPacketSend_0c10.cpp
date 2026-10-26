// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00580C10
// Canonical corpus name: NetworkPacketSend_0c10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkPacketSend_0c10_00580c10.c

void UnknownObject::NetworkPacketSend_0c10()
{
    // Allocates and enqueues a network packet on a mutex-protected send queue. Builds a 4-DWORD header (first word low = 2, first word high = htons(0), second word = htonl(0)) and copies it into this+0xA84. Under a counter mutex (this+0xB3C, timeout this+0xB40) the send counter at this+0xB38 is incremented and its previous value is written to the caller's out-parameter *a2. Under the queue mutex (this+0xAD8, timeout this+0xADC) a 32-byte packet object is allocated via OperatorNewNhMallocWrapper(32) and initialized by ObjectInitWithVTableFieldSet with the sequence number, the current queue count this+0xAD4 and the size argument a3. When 0 < a3 <= 2 the packet's buffer headers are copied under a third mutex (this+0x640, timeout this+0x644) via CopyBufferHeaderFieldsCallInit (a4 set) or via sub_57DD40 (a4 clear). A 12-byte queue node is then allocated, linked at the queue tail this+0xACC (initializing the head this+0xAC8 and cursor this+0xAD0 on first insert), and the queue count this+0xAD4 is incremented. Always returns 1.
    // ASSIGNMENT: Builds the 4-DWORD header v19: low word of v19[0] = 2, v19[1] = htonl(0), high word of v19[0] = htons(0). [global:0x0059E2D8, global:0x0059E2F4, source:raw]
    // CALL: Copy4DwordsStructToStruct(this + 0xA84, v19) copies the 4-DWORD header into the receiver buffer. [callee:0x0057B9F0, source:raw]
    // GUARD: The send counter is incremented only when the counter mutex at this+0xB3C is present and WaitForSingleObject returns 0 (signaled) or 128 (WAIT_TIMEOUT); otherwise the counter pointer is nulled and dereferencing it is a degenerate path. [field:this:0x00000B3C, field:this:0x00000B40, global:0x0059E1A0, source:raw]
    // CALL: WaitForSingleObject(counter mutex at this+0xB3C, timeout this+0xB40) acquires the counter mutex. [field:this:0x00000B3C, field:this:0x00000B40, global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Writes the pre-increment send counter to the caller's out-parameter *a2 and increments the counter at this+0xB38. [field:this:0x00000B38, source:raw]
    // CALL: ReleaseMutex(counter mutex at this+0xB3C) releases the counter mutex when it is present. [field:this:0x00000B3C, global:0x0059E1A4, source:raw]
    // GUARD: The queue is accessed only when the queue mutex at this+0xAD8 is present and WaitForSingleObject returns 0 or 128. [field:this:0x00000AD8, field:this:0x00000ADC, global:0x0059E1A0, source:raw]
    // CALL: WaitForSingleObject(queue mutex at this+0xAD8, timeout this+0xADC) acquires the queue mutex. [field:this:0x00000AD8, field:this:0x00000ADC, global:0x0059E1A0, source:raw]
    // CALCULATION: Captures the current queue node count v21[3] (this+0xAD4) into a local before allocating the new packet. [field:this:0x00000AD4, source:raw]
    // CALL: OperatorNewNhMallocWrapper(32) allocates the 32-byte packet data block. [callee:0x00587C03, source:raw]
    // UNKNOWN: The local guard v20 is set to 0 before and -1 after the allocation/initialization, matching an MSVC SEH local-unwind pattern registered to the SEH scope at SEH_580C10. [global:0x0059CACB, source:raw]
    // CALL: ObjectInitWithVTableFieldSet(v13, *a2, v12, a3) initializes the packet object with the sequence number, the captured queue count, and the size argument a3. [callee:0x0057B780, source:raw]
    // GUARD: The extra buffer-header copy path runs only when the size argument a3 is greater than 0 and at most 2. [source:raw]
    // GUARD: Within the size-limited path, the copy-buffer-header branch is taken when the flag argument a4 is non-zero, otherwise the sub_57DD40 branch is taken. [source:raw]
    // CALL: WaitForSingleObject(third mutex at this+0x640, timeout this+0x644) acquires the mutex guarding the copy-buffer-header path. [field:this:0x00000640, field:this:0x00000644, global:0x0059E1A0, source:raw]
    // CALL: CopyBufferHeaderFieldsCallInit(v14) copies the additional buffer header fields into the packet object. [callee:0x00587370, source:raw]
    // CALL: ReleaseMutex(third mutex at this+0x640) releases the mutex guarding the copy-buffer-header path. [field:this:0x00000640, global:0x0059E1A4, source:raw]
    // CALL: sub_57DD40(this, v19, v14) sends the packet through the alternative path when the flag argument a4 is clear. [callee:0x0057DD40, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates the 12-byte queue node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initializes the 12-byte queue node: node[0] = packet pointer v14, node[4] = 0, node[8] = 1. [source:raw]
    // GUARD: When the queue head this+0xAC8 is non-empty the node is linked behind the current tail this+0xACC; otherwise the node becomes the head this+0xAC8 and the cursor this+0xAD0. [field:this:0x00000AC8, field:this:0x00000ACC, field:this:0x00000AD0, source:raw]
    // ASSIGNMENT: Updates the queue tail this+0xACC to the new node and increments the queue node count this+0xAD4. [field:this:0x00000ACC, field:this:0x00000AD4, source:raw]
    // CALL: ReleaseMutex(queue mutex at this+0xAD8) releases the queue mutex when it is present. [field:this:0x00000AD8, global:0x0059E1A4, source:raw]
    // RETURN: Returns 1 on all paths. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_580C10(int this, int *out_seq, int size, char flag) {
    //     DWORD v19[4];
    //     LOWORD(v19[0]) = 2; HIWORD(v19[0]) = htons(0); v19[1] = htonl(0);
    //     Copy4DwordsStructToStruct((_DWORD *)(this + 0xA84), v19);
    //     _DWORD *cnt = 0;
    //     if (*(void **)(this + 0xB3C) &&
    //         ((v = WaitForSingleObject(*(void **)(this + 0xB3C), *(_DWORD *)(this + 0xB40))) == 0 || v == 128))
    //       cnt = (_DWORD *)(this + 0xB38);
    //     *out_seq = (*cnt)++;
    //     if (*(void **)(this + 0xB3C)) ReleaseMutex(*(void **)(this + 0xB3C));
    //     _DWORD *q = 0;
    //     if (*(void **)(this + 0xAD8) &&
    //         ((v = WaitForSingleObject(*(void **)(this + 0xAD8), *(_DWORD *)(this + 0xADC))) == 0 || v == 128))
    //       q = (_DWORD *)(this + 0xAC8);
    //     int count = q[3];
    //     _DWORD *pkt = OperatorNewNhMallocWrapper(32);
    //     _DWORD *obj = pkt ? ObjectInitWithVTableFieldSet(pkt, *out_seq, count, size) : 0;
    //     if (size > 0 && size <= 2) {
    //       if (flag) {
    //         if (*(void **)(this + 0x640)) WaitForSingleObject(*(void **)(this + 0x640), *(_DWORD *)(this + 0x644));
    //         CopyBufferHeaderFieldsCallInit(obj);
    //         if (*(void **)(this + 0x640)) ReleaseMutex(*(void **)(this + 0x640));
    //       } else {
    //         sub_57DD40((int **)this, v19, (int)obj);
    //       }
    //     }
    //     if (obj) {
    //       _DWORD *node = OperatorNewNhMallocWrapper(12);
    //       if (node) { node[0] = obj; node[1] = 0; *((_BYTE *)node + 8) = 1; } else node = 0;
    //       if (*q) *(_DWORD *)(q[1] + 4) = node;
    //       else { *q = node; q[2] = node; }
    //       q[1] = node;
    //       ++q[3];
    //     }
    //     if (*(void **)(this + 0xAD8)) ReleaseMutex(*(HANDLE *)(this + 0xAD8));
    //     return 1;
    //   }
    // UNRESOLVED: The exact wire format of the 4-DWORD header v19 and the meaning of this+0xA84 are unresolved.
    // UNRESOLVED: The distinction in behavior between CopyBufferHeaderFieldsCallInit and sub_57DD40 (both invoked for 0 < a3 <= 2) is unresolved.
    // UNRESOLVED: The owning class behind the queue, counter and mutex fields is unknown.
    // UNRESOLVED: No static caller was found in the packet; the invocation context is unresolved.
}
