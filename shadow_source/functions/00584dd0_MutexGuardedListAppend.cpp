// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584DD0
// Canonical corpus name: sub_584DD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_584DD0_00584dd0.c

void UnknownObject::MutexGuardedListAppend()
{
    // Thread-safe list insertion. Reads the mutex handle at this+0x570 and, if non-null, waits on it with the timeout at this+0x574 (WAIT_OBJECT_0 or WAIT_ABANDONED accepted), appends node a2 to a linked list via LinkedListNodeAppend_6000, records success, then releases the mutex. Returns a boolean success flag.
    // ASSIGNMENT: Load the mutex handle from this+0x570 (this[348]) and the list object base this+344 (this[344]); initialize the success flag to 0. [field:this:0x00000570, source:raw]
    // GUARD: Guard on the mutex handle being non-null; when it is null the function skips all synchronization and returns the 0 flag. [field:this:0x00000570, source:raw]
    // CALL: Call WaitForSingleObject with the mutex handle and the timeout read from this+0x574 (this[349]). [field:this:0x00000574, global:0x0059E1A0, source:raw]
    // GUARD: Guard on the wait result being 0 (signaled) or 128 (WAIT_ABANDONED); other results skip the append and release. [source:raw]
    // CALL: Append node a2 to the linked list via LinkedListNodeAppend_6000(a2, 0); set the success flag to 1 when it returns non-zero. [callee:0x00586000, source:raw]
    // CALL: Release the mutex handle via ReleaseMutex when it is non-null. [field:this:0x00000570, global:0x0059E1A4, source:raw]
    // RETURN: Return the success flag (1 if the append succeeded, otherwise 0). [source:raw]

    // Conservative worker pseudocode:
    //   char sub_584DD0(_DWORD* this, int a2) {
    //     void* mutex = (void*)this[348];
    //     char ok = 0;
    //     if (mutex) {
    //       DWORD r = WaitForSingleObject(mutex, this[349]);
    //       if (r == 0 || r == 128) {
    //         if (LinkedListNodeAppend_6000(a2, 0)) ok = 1;
    //         if (this[348]) ReleaseMutex((void*)this[348]);
    //       }
    //     }
    //     return ok;
    //   }
    // UNRESOLVED: The node a2 and the appended list structure (base at this+344, buffer at this[348]) are not further identified here.
    // UNRESOLVED: Owner identity is unknown; the list/mutex pairing only implies a shared producer-consumer container.
}
