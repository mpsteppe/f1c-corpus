// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581070
// Canonical corpus name: sub_581070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_581070_00581070.c

void UnknownObject::FindNodeByKeyAndCopy()
{
    // Thread-safe lookup in a linked list whose head is at this+0xAC8: acquires the list mutex (this+0xAD8, timeout this+0xADC), walks node-to-node via each node's next pointer (+4) until a node's data field at +0x14 equals parameter a2, then calls CopyBufferHeaderFieldsCallInit on the matched data. If found, a second mutex (this+0x640, timeout this+0x644) protects a CopyBufferHeaderFieldsCallInit into a local buffer, which is finalized via SetVtablePointerAndCallInit. Returns 1 when a matching node was found, 0 otherwise.
    // CALL: Initialize the local object/vtable context with fixed parameters (-1, 255, 0) via ObjectInitWithVTableSetup. [callee:0x00587030, source:raw]
    // GUARD: Acquire the first list mutex (handle at this+0xAD8) with timeout this+0xADC via WaitForSingleObject; the traversal proceeds only when the wait returned 0 (signaled) or 128 (already owned). [field:this:0x00000AD8, field:this:0x00000ADC, global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Select the traversal base v5: this+0xAC8 when the mutex was acquired, null otherwise. [field:this:0x00000AC8, source:raw]
    // GUARD: When the list head (this+0xAC8) is null the traversal is skipped entirely and the function falls through to cleanup. [guard:0, field:this:0x00000AC8, source:raw]
    // LOOP: Walk the linked list: the cursor is held at this+0xAD0 (initialized to the head's data pointer), each node advances through its next pointer (+4) to the following node's data field, and the walk continues while the current data field at +0x14 differs from a2. [field:this:0x00000AD0, field:*(this+0xAD0):0x00000004, field:*(*(this+0xAD0)+0x4):0x00000000, field:*(this+0xAC8):0x00000000, source:raw]
    // GUARD: Match check: the loop terminates when the current node's data field at +0x14 equals a2. [field:*(*(*(this+0xAD0)+0x4)+0x0):0x00000014, source:raw]
    // CALL: On match, call CopyBufferHeaderFieldsCallInit on the matched node data. [callee:0x00587370, field:*(*(*(this+0xAD0)+0x4)+0x0):0x00000014, source:raw]
    // ASSIGNMENT: Set the found flag v14 to 1 when a matching node was processed. [source:raw]
    // CALL: Release the first list mutex (this+0xAD8) via ReleaseMutex when it was acquired. [global:0x0059E1A4, field:this:0x00000AD8, source:raw]
    // GUARD: When a match was found, acquire the second mutex (this+0x640) with timeout this+0x644 via WaitForSingleObject before copying the buffer. [global:0x0059E1A0, field:this:0x00000640, field:this:0x00000644, source:raw]
    // CALL: CopyBufferHeaderFieldsCallInit into the local 28-byte buffer v15 under the second mutex. [callee:0x00587370, source:raw]
    // CALL: Release the second mutex (this+0x640) via ReleaseMutex. [global:0x0059E1A4, field:this:0x00000640, source:raw]
    // CALL: Finalize the local buffer via SetVtablePointerAndCallInit before returning. [callee:0x005870D0, source:raw]
    // RETURN: Return the found flag v14: 1 if a node whose data field at +0x14 equals a2 was found and copied, 0 otherwise. [function:0x00581070, source:raw]

    // Conservative worker pseudocode:
    //   char sub_581070(int this, int a2) {
    //     char found = 0;
    //     ObjectInitWithVTableSetup(-1, 255, 0);
    //     int base = 0;
    //     if (*(this+0xAD8) &&
    //         (r = WaitForSingleObject(*(this+0xAD8), *(this+0xADC))) == 0 || r == 128)
    //       base = this + 0xAC8;
    //     if (base && *(int*)base) {
    //       int cursor = *(int*)base;
    //       int data = *(int*)cursor;
    //       while (data && *(data + 0x14) != a2) {
    //         cursor = *(cursor + 4);
    //         if (!cursor) break;
    //         data = *(int*)cursor;
    //       }
    //       if (data && *(data + 0x14) == a2) {
    //         CopyBufferHeaderFieldsCallInit(data);
    //         found = 1;
    //       }
    //     }
    //     if (*(this+0xAD8)) ReleaseMutex(*(this+0xAD8));
    //     if (found) {
    //       if (*(this+0x640)) WaitForSingleObject(*(this+0x640), *(this+0x644));
    //       CopyBufferHeaderFieldsCallInit(buf);
    //       if (*(this+0x640)) ReleaseMutex(*(this+0x640));
    //     }
    //     SetVtablePointerAndCallInit(buf);
    //     return found;
    //   }
    // UNRESOLVED: The semantic role of the local 28-byte buffer v15 (destination of the second copy) is not established by this packet.
    // UNRESOLVED: The purpose of the second mutex (this+0x640) versus the list mutex (this+0xAD8) — e.g. a reader/writer or buffer-pool split — is unknown.
    // UNRESOLVED: SEH handler registration at 0x0059CB08 is flagged by facts but does not appear in the raw source text.
}
