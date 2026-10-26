// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406700
// Canonical corpus name: MutexLockWithTimeout
// Owner: MutexSynchronizationObject [DERIVED]
// Raw source: functions/MutexLockWithTimeout_00406700.c

void MutexSynchronizationObject::MutexLockWithTimeout()
{
    // Writes an integer under mutex protection with a bounded wait. If the mutex handle at this[20] (0x50) is null it returns 0. Otherwise it waits on the mutex with the timeout stored at this[21] (0x54) via WaitForSingleObject; a non-zero wait result other than 128 (WAIT_ABANDONED) causes an early 0 return. On success the argument a2 is written into the protected value at this[19] (0x4C), the mutex is released via ReleaseMutex if still non-null, and 1 is returned.
    // GUARD: If the mutex handle at this[20] (offset 0x50) is null, return 0 immediately. [field:this:0x00000050]
    // CALL: Wait on the mutex handle with the timeout stored at this[21] (offset 0x54) via WaitForSingleObject. [global:0x0059E1A0, field:this:0x00000050, field:this:0x00000054]
    // GUARD: If the wait result is non-zero and not 128, return 0; 128 is read as Win32 WAIT_ABANDONED. [global:0x0059E1A0]
    // ASSIGNMENT: Write argument a2 into the protected value at this[19] (offset 0x4C) once the mutex is acquired. [field:this:0x0000004C]
    // CALL: If the mutex handle at this[20] is still non-null, release it via ReleaseMutex. [global:0x0059E1A4, field:this:0x00000050]
    // RETURN: Return 1 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   if (!mutex(this+0x50)) return 0;
    //   r = WaitForSingleObject(mutex(this+0x50), timeout(this+0x54));
    //   if (r != 0 && r != 128) return 0;  // 128 = WAIT_ABANDONED
    //   value(this+0x4C) = a2;
    //   if (mutex(this+0x50)) ReleaseMutex(mutex(this+0x50));
    //   return 1;
    // UNRESOLVED: Constant 128 is read as WAIT_ABANDONED from Win32 API semantics; the packet does not name the constant.
    // UNRESOLVED: The mutex object layout here differs from the MutexCreateRecreate object (handle at a lower offset, flag at a higher offset); class identity is DERIVED and unconfirmed.
    // UNRESOLVED: The meaning of the protected value written to offset 0x4C is unknown; the early-return path when the wait result is 128 implies abandoned-mutex takeover.
}
