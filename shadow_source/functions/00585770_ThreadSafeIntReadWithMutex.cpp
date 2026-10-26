// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585770
// Canonical corpus name: ThreadSafeIntReadWithMutex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSafeIntReadWithMutex_00585770.c

void UnknownObject::ThreadSafeIntReadWithMutex()
{
    // Thread-safe accessor: acquires the mutex handle at this offset 0xF0 with the timeout at this offset 0xF4, reads the protected integer at this offset 0xEC, releases the mutex, and returns the read value.
    // CALL: Read the mutex handle from this[60] (offset 0xF0); if non-null, call WaitForSingleObject(handle, timeout from this[61] at offset 0xF4). [field:this:0x000000F0, field:this:0x000000F4, global:0x0059E1A0]
    // GUARD: Treat the lock as acquired only when the handle is non-null and WaitForSingleObject returned 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED); otherwise the read pointer is null. [field:this:0x000000F0, global:0x0059E1A0]
    // ASSIGNMENT: Read the protected integer from this[59] (offset 0xEC). [field:this:0x000000EC]
    // CALL: If the mutex handle is non-null, call ReleaseMutex(handle). [field:this:0x000000F0, global:0x0059E1A4]
    // RETURN: Return the read integer value. [field:this:0x000000EC]

    // Conservative worker pseudocode:
    //   handle = this[60]; ptr = 0;
    //   if (handle && (status = WaitForSingleObject(handle, this[61])) == 0 || status == 128) ptr = this + 59;
    //   value = *ptr;
    //   if (handle) ReleaseMutex(handle);
    //   return value;
    // UNRESOLVED: The decompiled code dereferences a pointer that is null when the mutex wait fails (WaitForSingleObject returned neither 0 nor 128), which would fault on null; this implies callers only invoke the accessor when the handle and lock are valid.
    // UNRESOLVED: Existing analysis identifies WaitForSingleObject and ReleaseMutex as imported globals at 0x0059E1A0 and 0x0059E1A4; the concrete owning object is unidentified.
}
