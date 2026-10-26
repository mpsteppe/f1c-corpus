// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585F60
// Canonical corpus name: MutexWaitWithSuccessCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexWaitWithSuccessCheck_00585f60.c

void UnknownObject::MutexWaitWithSuccessCheck()
{
    // __thiscall mutex waiter. Reads the mutex handle at this+0x50 (this[20]) and the timeout at this+0x54 (this[21]). If the handle is non-null, calls WaitForSingleObject with that timeout; returns `this` when the wait result is 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), otherwise returns 0.
    // ASSIGNMENT: Load the mutex handle from this[20] (byte offset 0x50) and the timeout from this[21] (byte offset 0x54). [field:this:0x00000050, field:this:0x00000054, source:raw]
    // GUARD: Guard on the handle being non-null before waiting; a null handle fails the wait immediately. [field:this:0x00000050, source:raw]
    // CALL: Call WaitForSingleObject(handle, timeout). [global:0x0059E1A0, source:raw]
    // GUARD: Accept the wait result if it equals 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED); any other result (including WAIT_TIMEOUT) fails the check. [global:0x0059E1A0, source:raw]
    // RETURN: Return `this` on a successful wait, otherwise return 0. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *MutexWaitWithSuccessCheck(_DWORD *this) {
    //     void *handle = (void *)this[20];
    //     if (handle) {
    //       DWORD r = WaitForSingleObject(handle, this[21]);
    //       if (r == 0 || r == 128) return this;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The owning class of `this` is unknown (object layout only exposes handle and timeout at 0x50/0x54).
    // UNRESOLVED: The meaning of a null handle (skip vs failure) is ambiguous from this function alone; the caller sub_5837F0 may distinguish them.
}
