// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057EE80
// Canonical corpus name: ThreadSafeMutexQueueWithTimedWait
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSafeMutexQueueWithTimedWait_0057ee80.c

void UnknownObject::TimedWaitQueueDequeue()
{
    // Thread-safe timed-wait dequeue from a mutex-protected linked list, called from sub_57D6C0. Waits on the mutex at this+0xAD8 for dwMilliseconds; on timeout (258) or failure (-1) it returns 0 without releasing. Otherwise it walks a linked list starting from the head at this+0xAC8 using the cursor at this+0xAD0, comparing each node's data pointer against a2 via NetworkMessageEventComparisonWithShortMasking. On a match it stores ReadFieldAtOffset0x14 of the node data into *a3 and returns 1; on exhaustion it returns 0. Always releases the mutex when it was acquired.
    // ASSIGNMENT: Initialize the result flag v5 to 0 (not-found default). [source:raw]
    // CALL: Wait on the mutex handle at this+0xAD8 via WaitForSingleObject with the caller-supplied dwMilliseconds timeout. [global:0x0059E1A0, field:this:0x00000AD8, source:raw]
    // GUARD: If the wait result equals 258 (WAIT_TIMEOUT) or -1 (WAIT_FAILED), skip the search body, keep v5 at 0, and jump straight to the release path. [source:raw]
    // ASSIGNMENT: Initialize the list cursor this+0xAD0 to the head pointer stored at this+0xAC8. [field:this:0x00000AD0, field:this:0x00000AC8, source:raw]
    // GUARD: Enter the search only when the head pointer at this+0xAC8 is non-null and its first dword (the node data pointer) is non-null. [field:*(this+0xAC8):0x00000000, source:raw]
    // LOOP: While NetworkMessageEventComparisonWithShortMasking(nodeData, a2) returns false, advance the cursor: read the next node link from *(cursor+0x4), store it into this+0xAD0, and load the next node's data pointer from its first dword; if the next node is null, set v5 to 0 and exit the search. [callee:0x0057B840, field:*(this+0xAD0):0x00000004, field:*(*(this+0xAD0)+0x4):0x00000000, field:this:0x00000AD0, source:raw]
    // ASSIGNMENT: On a match, set v5 to 1 and store ReadFieldAtOffset0x14(nodeData) into the caller output *a3. [callee:0x005871F0, source:raw]
    // CALL: After the search, if the mutex handle at this+0xAD8 is non-null, release it via ReleaseMutex. [global:0x0059E1A4, field:this:0x00000AD8, source:raw]
    // RETURN: Return v5: 1 when a matching node was found and its field written, 0 on timeout, failure, empty list, or no match. [source:raw]

    // Conservative worker pseudocode:
    //   char TimedWaitQueueDequeue(this, match, out, dwMilliseconds) {
    //     result = 0;
    //     wait = WaitForSingleObject(*(HANDLE*)(this + 0xAD8), dwMilliseconds);
    //     if (wait == 258 || wait == -1)
    //       return 0;
    //     *(void**)(this + 0xAD0) = *(void**)(this + 0xAC8); /* cursor = head * /
    //     head = *(void**)(this + 0xAC8);
    //     if (head && *(void**)head) {
    //       nodeData = *(void**)head;
    //       for (;;) {
    //         if (NetworkMessageEventComparisonWithShortMasking(nodeData, match)) break;
    //         next = *(void**)(*(void**)(this + 0xAD0) + 4);
    //         *(void**)(this + 0xAD0) = next;
    //         if (!next) { result = 0; goto release; }
    //         nodeData = *(void**)next;
    //       }
    //       result = 1;
    //       *out = ReadFieldAtOffset0x14(nodeData);
    //     }
    //   release:
    //     mutex = *(void**)(this + 0xAD8);
    //     if (mutex) ReleaseMutex(mutex);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the match parameter a2 and of the short-masking comparison performed by NetworkMessageEventComparisonWithShortMasking.
    // UNRESOLVED: Meaning of the node-data field at +0x14 that is read into the output *a3.
    // UNRESOLVED: Purpose and message semantics of the mutex-protected linked list stored in the this object.
    // UNRESOLVED: Persistence of the cursor this+0xAD0, which survives until the next dequeue.
}
