// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584C70
// Canonical corpus name: ThreadSafeCallWithMutex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSafeCallWithMutex_00584c70.c

void UnknownObject::mutexGuardedListAppend()
{
    // Acquires a mutex with a timeout, appends a node to a linked list under the lock, releases the mutex, and returns a success flag.
    // GUARD: Proceed only if the mutex handle at this+0x554 is non-null. [field:this:0x00000554]
    // CALL: Call WaitForSingleObject(this+0x554, this+0x558) to acquire the mutex with the configured timeout. [field:this:0x00000554, field:this:0x00000558, global:0x0059E1A0]
    // GUARD: Proceed only when the wait result is 0 (signaled) or 128 (abandoned); a timeout or error blocks the append. [global:0x0059E1A0, source:raw]
    // CALL: Append the node a2 to the list by calling LinkedListNodeAppend_6000(a2, 0); a non-zero result sets the success flag. [callee:0x00586000, source:raw]
    // CALL: Release the mutex via ReleaseMutex(this+0x554) after the append completes. [field:this:0x00000554, global:0x0059E1A4]
    // RETURN: Return the success flag (1 if the node was appended, else 0). [source:raw]

    // Conservative worker pseudocode:
    //   success = 0;
    //   if (this+0x554 != 0) {
    //     wait = WaitForSingleObject(this+0x554, this+0x558);
    //     if (wait == 0 || wait == 128) {
    //       if (LinkedListNodeAppend_6000(a2, 0)) success = 1;
    //       ReleaseMutex(this+0x554);
    //     }
    //   }
    //   return success;
    // UNRESOLVED: The meaning of the second argument 0 passed to LinkedListNodeAppend_6000 and the identity of the appended node a2 are unknown.
    // UNRESOLVED: The units of the timeout value this+0x558 (assumed milliseconds from WaitForSingleObject) are not confirmed.
}
