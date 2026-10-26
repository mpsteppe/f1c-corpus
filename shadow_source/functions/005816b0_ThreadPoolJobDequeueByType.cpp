// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005816B0
// Canonical corpus name: ThreadPoolJobDequeueByType
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadPoolJobDequeueByType_005816b0.c

void UnknownObject::ThreadPoolJobDequeueByType()
{
    // Dequeues the first node of a mutex-protected linked list whose type field (read via ReadFieldAtOffset0x14) equals a2. Acquires the mutex handle this+0xAD8 with timeout this+0xADC via WaitForSingleObject (proceeding on result 0 or 128), walks the list advancing through each node's next link, and on a match copies the node payload into the output parameter a3 via sub_57B800, setting the result flag to 1. Releases the mutex via ReleaseMutex when its handle is non-null and returns the flag (1 found, 0 not found).
    // GUARD: List walk proceeds only when the mutex-protected list head at this+0xAC8 is non-null [guard:0, field:this:0x00000AC8, source:raw]
    // CALL: Acquires the list mutex handle at this+0xAD8 via WaitForSingleObject with the timeout this+0xADC; treated as acquired when the result is 0 or 128 [global:0x0059E1A0, field:this:0x00000AD8, field:this:0x00000ADC, source:raw]
    // ASSIGNMENT: Initializes the walk/iteration pointer at this+0xAD0 from the head node pointer stored at this+0xAC8, and reads the first node through the head node's first dword [field:this:0x00000AD0, field:*(this+0xAC8):0x00000000, field:this:0x00000AC8, source:raw]
    // LOOP: Walks the linked list comparing each node's type read via ReadFieldAtOffset0x14 against the requested type a2, advancing through each node's next link [callee:0x005871F0, source:raw]
    // CALL: On a matching node, copies/dequeues its payload into the output parameter a3 via sub_57B800 [callee:0x0057B800, source:raw]
    // STATE_TRANSITION: Dequeue result flag set to 1 when a matching node was found and dequeued [source:raw]
    // CALL: Releases the mutex handle at this+0xAD8 via ReleaseMutex when it is non-null [global:0x0059E1A4, field:this:0x00000AD8, source:raw]
    // RETURN: Returns the dequeue result flag (1 found, 0 not found) [source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   mutex = this[694];                       /* handle at this+0xAD8 * /
    //   if (mutex && WaitForSingleObject(mutex, this[695]) in {0, 128}) {
    //       walk = this + 0xAC8;                 /* list head slot * /
    //       walk[2] = walk[0];                   /* iteration pointer this+0xAD0 = head * /
    //       node = walk[0] ? walk[0][0] : 0;     /* first node * /
    //       while (node && ReadFieldAtOffset0x14(node) != a2) {
    //           if (walk[2]) {
    //               walk[2] = walk[2][1];        /* advance via next link * /
    //               node = walk[2] ? walk[2][0] : 0;
    //           } else {
    //               break;
    //           }
    //       }
    //       if (node) { sub_57B800(a3, node); result = 1; }
    //   }
    //   if (mutex) ReleaseMutex(mutex);
    //   return result;
    // UNRESOLVED: Field this+0xAD4 is recorded as read in packet facts but the raw body never references it; possibly an element-count field used by a sibling queue path
    // UNRESOLVED: When the mutex is not acquired (WaitForSingleObject result neither 0 nor 128) the decompiled flow would dereference a null walk pointer; likely an IDA artifact of a guarded abort path rather than reachable code
}
