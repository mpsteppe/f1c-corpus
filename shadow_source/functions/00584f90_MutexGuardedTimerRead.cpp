// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584F90
// Canonical corpus name: MutexGuardedTimerRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexGuardedTimerRead_00584f90.c

void UnknownObject::MutexGuardedTimerRead()
{
    // Acquires a mutex (this+0xD4) with timeout this+0xD8, reads an accumulated timer double via FloatAdditionReturnsFUN00568d90Param1 (0x00583680) with a NULL timer object when the wait is blocked, releases the mutex, and returns the timer value. Thread-safe timer read.
    // GUARD: Mutex handle at this+0xD4 must be non-NULL before waiting; otherwise timer object passed as NULL. [field:this:0x000000D4, source:raw]
    // CALL: WaitForSingleObject(mutexHandle, this+0xD8 timeout); proceed when return is 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), else blocked and timer object is NULL. [global:0x0059E1A0, field:this:0x000000D4, field:this:0x000000D8, source:raw]
    // CALL: Read accumulated timer double via FloatAdditionReturnsFUN00568d90Param1 (0x00583680); a NULL parameter reads 0. [callee:0x00583680, source:raw]
    // CALL: ReleaseMutex(mutexHandle at this+0xD4) when the handle is non-NULL. [global:0x0059E1A4, field:this:0x000000D4, source:raw]
    // RETURN: Return the timer double read under the mutex. [source:raw]

    // Conservative worker pseudocode:
    //   handle = this->mutex_handle;      // this+0xD4
    //   if (handle != NULL && WaitForSingleObject(handle, this->timeout) in {0, 128})
    //       value = ReadTimer(handle);     // 0x00583680
    //   else
    //       value = ReadTimer(NULL);       // yields 0
    //   if (handle != NULL) ReleaseMutex(handle);
    //   return value;
    // UNRESOLVED: Identity of the object owning the mutex and timer is unknown (UnknownObject).
    // UNRESOLVED: Semantics of FloatAdditionReturnsFUN00568d90Param1 (0x00583680) and why a NULL parameter yields 0 are unproven.
    // UNRESOLVED: Relation between the caller-supplied timer object and the this+0x84 sub-object is unverified.
    // UNRESOLVED: WAIT_ABANDONED (128) is treated as success; original intent unconfirmed.
}
