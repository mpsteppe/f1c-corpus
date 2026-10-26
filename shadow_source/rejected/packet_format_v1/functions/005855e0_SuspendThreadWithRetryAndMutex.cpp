// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005855E0
// Canonical corpus name: ThreadSuspendWithMutexWaitLock
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSuspendWithMutexWaitLock_005855e0.c

void UnknownObject::SuspendThreadWithRetryAndMutex()
{
    // Suspends a thread (handle at this+0x4) under mutex protection. Waits on mutex this+0x20 with timeout this+0x24; when acquired and the suspend flag at this+0x1C is clear, retries SuspendThread up to 50 times with increasing Sleep delays until the thread's previous suspend count reaches a positive value, then sets the suspend flag. Always releases the mutex. Returns 1 on success, 0 when the retry limit is reached, and 1 immediately when no thread handle exists.
    // GUARD: If thread handle at this+0x4 is null, return 1 immediately. [field:this:0x00000004]
    // CALL: Wait on mutex at this+0x20 with timeout this+0x24 via WaitForSingleObject; success when result is 0 or 128. [field:this:0x00000032, field:this:0x00000036, global:0x0059E1A0]
    // GUARD: Select suspend-flag pointer only when the mutex exists and the wait succeeded; otherwise no flag access. [field:this:0x00000032]
    // GUARD: Skip the suspend retry loop when the suspend flag at this+0x1C is already set. [field:this:0x00000028]
    // LOOP: Retry SuspendThread(thread handle at this+0x4) up to 50 times, sleeping with the current retry count as delay, while the thread has no prior suspend count (SuspendThread returns -1 or 0); break when a positive previous suspend count is observed. [field:this:0x00000004, global:0x0059E1FC, global:0x0059E0DC]
    // STATE_TRANSITION: Set the suspend flag at this+0x1C to 1 after a successful suspend. [field:this:0x00000028]
    // CALL: Release the mutex at this+0x20 via ReleaseMutex when it exists. [field:this:0x00000032, global:0x0059E1A4]
    // RETURN: Return v8: 1 on success, 0 when the 50-attempt retry limit is reached. [function:0x005855E0]

    // Conservative worker pseudocode:
    //   if (thread_handle == NULL) return 1;
    //   if (mutex && WaitForSingleObject(mutex, timeout) is 0 or 128)
    //       suspend_flag_ptr = &this->suspend_flag;
    //   else
    //       suspend_flag_ptr = NULL;
    //   if (suspend_flag_ptr && *suspend_flag_ptr == 0) {
    //       for (retry = 0; ; retry++) {
    //           prev = SuspendThread(thread_handle);
    //           if (prev != -1 && prev != 0) break;
    //           Sleep(retry);
    //           if (retry >= 50) { ok = 0; goto done; }
    //       }
    //       *suspend_flag_ptr = 1;
    //   }
    //   done:
    //   if (mutex) ReleaseMutex(mutex);
    //   return ok;
    // UNRESOLVED: suspend_flag_ptr would be dereferenced when the mutex wait fails in the raw decompile; presumed a decompiler artifact guarded by the real control flow
    // UNRESOLVED: subsystems flagged ai; owning class identity unknown
}
