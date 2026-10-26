// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005857C0
// Canonical corpus name: MutexProtectedFieldWrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedFieldWrite_005857c0.c

void UnknownObject::MutexProtectedFieldWrite()
{
    // Acquires a mutex (this+0xF0) with timeout this+0xF4, writes parameter a2 to the integer field at this+0xEC, releases the mutex, and returns a pointer to the written field. Thread-safe write accessor for a shared integer field.
    // GUARD: Mutex handle at this+0xF0 must be non-NULL before waiting. [field:this:0x000000F0, source:raw]
    // CALL: WaitForSingleObject(mutexHandle, this+0xF4 timeout); proceed when return is 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), otherwise result is NULL. [global:0x0059E1A0, field:this:0x000000F0, field:this:0x000000F4, source:raw]
    // ASSIGNMENT: Write a2 to the integer field at this+0xEC through the result pointer; a NULL result on a failed wait yields a null-pointer write. [field:this:0x000000EC, source:raw]
    // CALL: ReleaseMutex(mutexHandle at this+0xF0) when the handle is non-NULL. [global:0x0059E1A4, field:this:0x000000F0, source:raw]
    // RETURN: Return pointer to the written field this+0xEC (or ReleaseMutex result). [field:this:0x000000EC, source:raw]

    // Conservative worker pseudocode:
    //   handle = this->mutex_handle;   // this+0xF0
    //   result = NULL;
    //   if (handle != NULL && WaitForSingleObject(handle, this->timeout) in {0, 128})
    //       result = &this->value;      // this+0xEC
    //   *result = a2;                  // null-pointer write if wait blocked
    //   if (this->mutex_handle != NULL) ReleaseMutex(this->mutex_handle);
    //   return result;
    // UNRESOLVED: Identity of the object owning the protected field is unknown (UnknownObject).
    // UNRESOLVED: Null-pointer write to *result when WaitForSingleObject blocks suggests an unchecked caller contract; unproven.
    // UNRESOLVED: Callers NetworkSocketInitializationAndListen (0x005804A0) and sub_584230 (0x00584230) field-write semantics unverified.
}
