// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585550
// Canonical corpus name: ThreadTerminationWithWaitCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadTerminationWithWaitCleanup_00585550.c

void UnknownObject::ThreadTerminationWithWaitCleanup()
{
    // Thread shutdown and cleanup helper. Retries ThreadResumeWithMutexWait up to 10 times with a 250 ms sleep, then, when a live thread handle exists at this+0x4, acquires the mutex at this+0x10, sets the termination flag at this+0xC to 1, releases the mutex, waits indefinitely on the thread handle, closes it, and clears the handle/ID fields at this+0x4 and this+0x8.
    // LOOP: Retry loop, up to 10 iterations: call ThreadResumeWithMutexWait(this); if it returns non-zero, break out; otherwise Sleep(0xFA) (250 ms) before retrying [callee:0x00585680, global:0x0059E0DC, source:raw]
    // GUARD: Termination and cleanup proceed only when the thread handle at this+0x4 is non-zero [field:this:0x00000004, source:raw]
    // GUARD: When the mutex handle at this+0x10 is non-null and WaitForSingleObject on it with the timeout this+0x14 returns zero or 128, select the termination flag at this+0xC; otherwise select a null pointer [field:this:0x00000010, field:this:0x00000014, global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Write 1 to the selected termination flag (this+0xC when the mutex wait succeeded; the raw source writes through the null pointer on the failure path) [field:this:0x0000000C, source:raw]
    // CALL: If the mutex handle at this+0x10 is non-null, release it via ReleaseMutex [field:this:0x00000010, global:0x0059E1A4, source:raw]
    // CALL: WaitForSingleObject on the thread handle this+0x4 with timeout 0xFFFFFFFF (infinite) until the thread exits [field:this:0x00000004, global:0x0059E1A0, source:raw]
    // CALL: CloseHandle on the thread handle this+0x4; its result becomes the function return value [field:this:0x00000004, global:0x0059E1A8, source:raw]
    // ASSIGNMENT: Clear the thread handle this+0x4 and the thread ID this+0x8 to 0 after the close [field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return the CloseHandle result; the recorded caller AudioStreamingThreadShutdown (0057fde0) drives this during audio thread shutdown [function:0x00585550, caller:0x0057FDE0, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 10; ++i) {
    //     if (ThreadResumeWithMutexWait(this)) break;
    //     Sleep(0xFA);
    //   }
    //   if (this->handle /* +4 * /) {
    //     if (mutex /* +10 * / && WaitForSingleObject(mutex, this->timeout /* +14 * /) in {0, 128})
    //       flag = &this->terminateFlag /* +C * /;
    //     else
    //       flag = NULL;
    //     *flag = 1;
    //     if (mutex) ReleaseMutex(mutex);
    //     WaitForSingleObject(this->handle /* +4 * /, INFINITE);
    //     result = CloseHandle(this->handle);
    //     this->handle = 0; this->threadId = 0;
    //   }
    //   return result;
    // UNRESOLVED: The termination-flag write dereferences a possibly null pointer when the mutex wait fails; the raw source contains no guard for that path
    // UNRESOLVED: The exact semantics of the 128 return code (WAIT_ABANDONED_0 range) are not established from this packet alone
}
