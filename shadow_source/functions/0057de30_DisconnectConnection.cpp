// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057DE30
// Canonical corpus name: sub_57DE30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57DE30_0057de30.c

void UnknownObject::DisconnectConnection()
{
    // Network connection teardown. Under mutex1 it unlinks connection node a2 from the active list, runs a node destructor and frees the node; under mutex2 it clears one struct field and reads a callback result; it gracefully closes the socket, under mutex3 resets the ring buffer and all connection fields, reprepends the node to the free list, releases all three mutexes, then invokes a vtable callback at 0x94 if the struct path ran.
    // GUARD: Acquire mutex1 (handle this+0xABC) via WaitForSingleObject with timeout this+0xAC0; proceed with the list pointer only if the handle exists and the wait returns 0 or WAIT_TIMEOUT (128). [field:this:0x00000ABC, field:this:0x00000AC0, global:0x0059E1A0]
    // GUARD: If connection node a2 is non-null, perform the unlink-and-cleanup path on the active list. [field:this:0x00000AAC]
    // LOOP: Traverse the singly-linked list at this+0xAAC comparing each node's value dword to a2, remembering the previous node; node[1] is the next pointer. [field:this:0x00000AAC, field:*(this+0xAAC):0x00000004]
    // ASSIGNMENT: Unlink the found node: update the list tail (this+0xAB4) when the removed node is the tail, fix the head or previous-node link, update the list cursor (this+0xAB0) when it pointed at the removed node, and decrement the list count (this+0xAB8). [field:this:0x00000AAC, field:this:0x00000AB0, field:this:0x00000AB4, field:this:0x00000AB8, field:*(this+0xAAC):0x00000004]
    // CALL: Run the node destructor sub_491E40 on the removed node, then free the node with FreeWrapper_7bcf. [callee:0x00491E40, callee:0x00587BCF]
    // GUARD: If StructFieldGetter_b2e0(a2) returns a struct pointer, protect its field access with mutex2 (handle this+0xAD8, timeout this+0xADC). [callee:0x0057B2E0, field:this:0x00000AD8, field:this:0x00000ADC]
    // ASSIGNMENT: Zero the struct's field at +28, then release mutex2 via ReleaseMutex. [callee:0x0057B2E0, field:this:0x00000AD8, global:0x0059E1A4]
    // ASSIGNMENT: Mark the struct-path flag (v17 = 1) and capture v18 = ReadFieldAtOffset0x14(structptr) as the value passed to the trailing callback. [callee:0x005871F0, callee:0x0057B2E0]
    // CALL: Gracefully close the connection socket: OffsetGetter(a2) resolves the socket pointer, then SocketGracefulClose(socket, 1). [callee:0x0057B6B0, callee:0x0057C8E0]
    // GUARD: Acquire mutex3 (handle this+0xBEC, timeout this+0xBF0) to protect the connection-state reset. [field:this:0x00000BEC, field:this:0x00000BF0, global:0x0059E1A0]
    // CALL: RingBufferHeadTailReset on the connection ring buffer at a2+54. [callee:0x0057B530]
    // ASSIGNMENT: Reset the connection struct: zero a2+0..28, set a2+32 to -1, zero the byte at a2+40 and the dwords at a2+44/a2+48, and zero the word at a2+52. [source:raw]
    // CALL: LinkedListNodeAllocPrepend(a2, 0) reprepends the connection node to the free list, then release mutex3 via ReleaseMutex. [callee:0x00583210, field:this:0x00000BEC, global:0x0059E1A4]
    // CALL: Release mutex1 (handle this+0xABC) via ReleaseMutex when it was acquired. [field:this:0x00000ABC, global:0x0059E1A4]
    // CALL: If the struct-path flag is set, invoke the vtable callback at offset 0x94 (this->vtable[0x94]) with (this, v18). [field:this:0x00000000, field:obj:0x00000094]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   // Connection teardown: unlink a2 from the active list, close the socket,
    //   // reset the connection struct, reprepend the node to the free list.
    //   list = NULL;
    //   if (this->mutex1 && (WaitForSingleObject(this->mutex1, this->timeout1) == 0 || == 128))
    //       list = (char*)this + 0xAAC;
    //   if (a2) {
    //       if (list && *(DWORD**)list) {
    //           prev = NULL; node = **(DWORD***)list;
    //           while (node && *node != a2) { prev = node; node = node[1]; }
    //           if (node) {
    //               if (node == *(DWORD**)(list + 8)) *(DWORD**)(list + 8) = node[1];
    //               if (prev) prev[1] = node[1]; else **(DWORD***)list = node[1];
    //               if (*(DWORD**)(list + 4) == node) *(DWORD**)(list + 4) = prev;
    //               --*(DWORD*)(list + 12);
    //               sub_491E40(node);
    //               FreeWrapper_7bcf(node);
    //           }
    //       }
    //       if (p = StructFieldGetter_b2e0(a2)) {
    //           if (this->mutex2) WaitForSingleObject(this->mutex2, this->timeout2);
    //           *(DWORD*)(p + 28) = 0;
    //           if (this->mutex2) ReleaseMutex(this->mutex2);
    //           flag = 1; cbResult = ReadFieldAtOffset0x14(p);
    //       }
    //       SocketGracefulClose(OffsetGetter(a2), 1);
    //       if (this->mutex3) WaitForSingleObject(this->mutex3, this->timeout3);
    //       RingBufferHeadTailReset((WORD*)(a2 + 54));
    //       *(DWORD*)(a2+0) = 0; *(DWORD*)(a2+4) = 0; *(DWORD*)(a2+8) = 0;
    //       *(DWORD*)(a2+12) = 0; *(DWORD*)(a2+16) = 0; *(DWORD*)(a2+20) = 0;
    //       *(DWORD*)(a2+24) = 0; *(DWORD*)(a2+28) = 0; *(DWORD*)(a2+32) = -1;
    //       *(DWORD*)(a2+36) = 0; *(BYTE*)(a2+40) = 0; *(DWORD*)(a2+44) = 0;
    //       *(DWORD*)(a2+48) = 0; *(WORD*)(a2+52) = 0;
    //       LinkedListNodeAllocPrepend(a2, 0);
    //       if (this->mutex3) ReleaseMutex(this->mutex3);
    //   }
    //   if (this->mutex1) ReleaseMutex(this->mutex1);
    //   if (flag) (this->vtable[0x94])(this, cbResult);
    //   return 0;
    // UNRESOLVED: The node field at +8 of the list-head target (field:*(this+0xAAC):0x00000008) is read but its exact role is unconfirmed.
    // UNRESOLVED: The struct returned by StructFieldGetter_b2e0 and its field at +28 are not identified.
    // UNRESOLVED: The vtable callback at 0x94 and its argument v18 have unknown semantics.
    // UNRESOLVED: The a2 connection struct layout is partially inferred (a2+32 = -1 sentinel, a2+54 ring-buffer words); not cross-checked against an allocation site.
    // UNRESOLVED: A WAIT_TIMEOUT (128) result from mutex1 is treated as granted access; the intent is unconfirmed.
    // UNRESOLVED: WaitForSingleObject and ReleaseMutex are imported via globals 0x0059E1A0/0x0059E1A4; import resolution not verified.
}
