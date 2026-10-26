// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004066C0
// Canonical corpus name: MutexProtectedValueReadWithTimeout
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedValueReadWithTimeout_004066c0.c

void UnknownObject::MutexProtectedValueReadWithTimeout()
{
    // Reads a mutex-protected integer value from the object. Waits on the mutex handle at this+0x50 with the configured timeout at this+0x54, reads the value at this+0x4C when the wait succeeds (result 0 or 128), releases the mutex, and returns that value. Returns -1 when the mutex handle is null or the wait fails.
    // GUARD: Guard on the mutex handle at this+0x50 being non-null; when null the function skips the wait and returns the default -1. [source:raw, field:this:0x00000050]
    // CALL: Call WaitForSingleObject on the mutex handle at this+0x50 with the timeout at this+0x54, and store the wait result. [source:raw, global:0x0059E1A0, field:this:0x00000050, field:this:0x00000054]
    // GUARD: Guard on the wait result being 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED); only then is the protected value read. [source:raw, global:0x0059E1A0]
    // ASSIGNMENT: Read the protected integer value at this+0x4C into the result when the wait succeeded. [source:raw, field:this:0x0000004C]
    // GUARD: Re-check the mutex handle at this+0x50 for non-null before releasing it. [source:raw, field:this:0x00000050]
    // CALL: Call ReleaseMutex on the mutex handle at this+0x50 after the value read. [source:raw, global:0x0059E1A4, field:this:0x00000050]
    // RETURN: Return the read value, or the default -1 when the mutex was null or the wait failed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4066C0(_DWORD *this) {
    //     int result = -1;
    //     if (this[20]) {
    //       DWORD waitResult = WaitForSingleObject(this[20], this[21]);
    //       if (waitResult == 0 || waitResult == 128) {
    //         result = this[19];
    //         if (this[20]) ReleaseMutex(this[20]);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the protected integer at this+0x4C is not established from this function alone.
    // UNRESOLVED: Semantics of the timeout value at this+0x54 (units, sentinel values) are caller-side.
}
